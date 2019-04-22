#include "imaging.h"
#include "math.h"

BYTE* LoadBMP(int* width, int* height, long* size, LPCTSTR bmpfile)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

	// read file header
	if (ReadFile(file, &bmpheader, sizeof(BITMAPFILEHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof(BITMAPINFOHEADER), &bytesread, NULL) == false) {
		CloseHandle(file);
		return NULL;
	}
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB') {
		CloseHandle(file);
		return NULL;
	}
	// get image measurements
	*width = bmpinfo.biWidth;
	*height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB) {
		CloseHandle(file);
		return NULL;
	}
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		CloseHandle(file);
		return NULL;
	}

	// create buffer to hold the data
	*size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[*size];
	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);
	// read bmp data
	if (ReadFile(file, Buffer,*size, &bytesread, NULL) == false) {
		delete[] Buffer;
		CloseHandle(file);
		return NULL;
	}
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}//LOADPMB
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++) {
			newpos = row * (width) + column;
			bufpos = (height - row - 1) * psw + column * 3;
			newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
		}

	return newbuf;
}//ConvetBMPToIntensity
BYTE* Kirp(BYTE* raw, int *width, int *height, int x1, int y1, int x2, int y2)
{
	if ((NULL == raw) || (*width == 0) || (*height == 0))
		return NULL;


	// find the number of padding bytes
	//  newbuf = wwidth * height 

	int padding = 0;
	int scanlinebytes = *width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes     32 Bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	int w = abs(x2 - x1);
	int h = abs(y2 - y1);
	BYTE* newbuf = new BYTE[w*h];    //  3 Bytes

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines


	long bufpos = 0;
	long newpos = 0;

	int satir = 0;
	int sutun = 0;
	for (int row = y1; row < y2; row++)
	{
		sutun = 0;
		for (int column = x1; column < x2; column++)
		{

			newpos = row * (*width) + column;

			newbuf[satir*w + sutun] = raw[newpos];
			sutun = sutun + 1;
		}
		satir = satir + 1;
	}
	*width = w;
	*height = h;
	return newbuf;
}
BYTE* Convolisyon_348379(BYTE* buffer, int *genislik, int* yukseklik, double* mask, int mask_yukseklik, int mask_genislik)
{
	if ((NULL == buffer) || (yukseklik == 0) || (genislik == 0))
		return NULL;

	int yeni_yukseklik = 2 * (*yukseklik) + 1; 
	int yeni_genislik = 2 * (*genislik) + 1;

	BYTE* sonuc = new BYTE[(yeni_yukseklik-2)*(yeni_genislik-2)]{}; //2n-1
	BYTE* new_buffer = new BYTE[yeni_yukseklik*yeni_genislik]{};

	for (int satir = 0; satir <= yeni_yukseklik; satir++)
	{
		for (int sutun = 0; sutun <= yeni_genislik; sutun++)
		{
			new_buffer[satir*(yeni_genislik)+sutun] = 0;
		}
	}

	for (int satir = 0; satir <= *yukseklik; satir++)
	{
		for (int sutun = 0; sutun <= *genislik; sutun++) 
		{
			new_buffer[((2*satir)+1)*yeni_genislik + ((2 * sutun) + 1)] = buffer[satir**genislik + sutun];
		}
	}


	for (int satir = 1; satir < yeni_yukseklik- 1; satir++) 
	{
		for (int sutun = 1; sutun < yeni_genislik - 1; sutun++)
		{
			int toplam = 0;

			for (int mask_satir = 0; mask_satir < mask_yukseklik; mask_satir++)
			{
				for (int mask_sutun = 0; mask_sutun < mask_genislik; mask_sutun++)
				{
					toplam += new_buffer[(satir + mask_satir - 1)*yeni_genislik + (sutun + mask_sutun - 1)] * mask[mask_satir *mask_genislik + mask_sutun];
				}
			}
			sonuc[satir*yeni_genislik + sutun] = toplam;
		}

	}

	*genislik = yeni_genislik;
	*yukseklik = yeni_yukseklik;
	new_buffer = NULL;
	return sonuc;

}
INT* Histogram(BYTE* raw, int *genislik, int *yukseklik)
{
	if ((NULL == raw) || (yukseklik == 0) || (genislik == 0))
		return NULL;

	INT* histogram = new INT[256]{};
	/*for (int sayac = 0; sayac < 256; sayac++)
	{
		histogram[sayac] = 0;
	}
*/
	for (int i = 0; i < *genislik**yukseklik; i++)
	{
		histogram[raw[i]]++;
	}

	return histogram;
}
DOUBLE* Kmeans(INT* histogram, int adet)
{

	double k1=5.0, k2=250.0, k1_new=0.0, k2_new=0.0;
	double k1_new_payda=0.0, k2_new_payda=0.0;

	DOUBLE* k = new DOUBLE[2];

	while (1)
	{
		for (int sayac = 0; sayac < 256; sayac++)
		{
			if (fabs(k1 - sayac) < fabs(k2 - sayac))
			{
				if (sayac == 0)
				{
					k1_new += histogram[sayac] * 1;
					k1_new_payda += histogram[sayac];
				}
				else
				{
					k1_new += histogram[sayac] * sayac;
					k1_new_payda += histogram[sayac];
				}

			}
			else if (fabs(k1 - sayac) > fabs(k2 - sayac))
			{
				if (sayac == 0)
				{
					k2_new += histogram[sayac] * 1;
					k2_new_payda += histogram[sayac];
				}
				else
				{
					k2_new += histogram[sayac] * sayac;
					k2_new_payda += histogram[sayac];
				}

			}

		}
		
		if (k1_new != 0)
		{
			k1_new = k1_new / (double)k1_new_payda;
		}
		if (k2_new != 0)
		{
			k2_new = k2_new / (double)k2_new_payda;
		}
		
	
		if (fabs(k1 - k1_new)<00.5 && fabs(k2 - k2_new)<00.5)
		{
			k[0] = k1;
			k[1] = k2;
			break;
		}
		else
		{
			k1 = k1_new;
			k2 = k2_new;
			k1_new = 0;
			k2_new = 0;
			k1_new_payda = 0;
			k2_new_payda = 0;
		}

	}

	return k;

}
BYTE* Binary_Image(BYTE* raw, int *genislik, int *yukseklik, DOUBLE* k)
{
	BYTE* sonuc = new BYTE[*genislik**yukseklik];

	for (int sayac = 0; sayac < *genislik**yukseklik; sayac++)
	{
		
		if (fabs(raw[sayac] - k[0]) < fabs(raw[sayac] - k[1]))
			sonuc[sayac] = 0; //siyah
		else
			sonuc[sayac] = 255; //beyaz
	}
	return sonuc;
}
BYTE* Raw_Sum(BYTE* raw1, BYTE* raw2, int *genislik, int *yukseklik)
{
	BYTE* new_buffer= new BYTE[*genislik**yukseklik]{};

	for (int satir = 0; satir <= *yukseklik; satir++)
	{
		for (int sutun = 0; sutun <= *genislik; sutun++)
		{
			new_buffer[satir**genislik + sutun] = raw1[satir**genislik + sutun] + raw2[satir**genislik + sutun];
		}
	}

	return new_buffer;
}
BYTE* Segmentasyon(BYTE* dizi, int *genislik, int *yukseklik)
{

	int etiket = 2;
	int j_n, i_n;


	for (int i = 0; i < *yukseklik; i++)
	{
		for (int j = 0; j < *genislik; j++)
		{
			
			if (i == 0)
			{
				if (j == 0)
				{
					if (dizi[i**genislik+j] == 255)
					{
						dizi[i**genislik+j] = etiket;
						etiket++;
					}

				}
				else
				{
					if (dizi[i**genislik+j] == 255)
					{
						if (dizi[i**genislik+(j-1)] == 0)
						{
							dizi[i**genislik+j] = etiket;
							etiket++;
						}
						else
							dizi[i**genislik+j] = dizi[i**genislik+(j-1)];
					}
				}
			}
			else
			{
				if (j == 0)
				{
					if (dizi[i**genislik+j] == 255)
					{
						if (dizi[(i-1)**genislik+j] == 0)
						{
							dizi[i**genislik+j] = etiket;
							etiket++;
						}
						else
						{
							dizi[i**genislik+j] = dizi[(i-1)**genislik+j];
						}
					}
				}
				else // i,j 0 deðil 
				{
					if (dizi[i**genislik+j] == 255)
					{
						if (dizi[(i-1)**genislik+j] == 0 && dizi[i**genislik+(j-1)] == 0) //ikisi de 1 
						{
							dizi[i**genislik+j] = etiket;
							etiket++;
						}
						else if (dizi[(i-1)**genislik+j] == 0 && dizi[i**genislik+(j-1)] != 0)// solundaki etikete sahip
						{
							dizi[i**genislik+j] = dizi[i**genislik+(j-1)];
						}
						else if (dizi[i**genislik+(j-1)] == 0 && dizi[(i-1)**genislik+j] != 0)// saðýndaki etikete sahip
						{
							dizi[i**genislik+j] = dizi[(i-1)**genislik+j];
						}
						else if (dizi[i**genislik+(j-1)] == dizi[(i-1)**genislik+j])
						{
							dizi[i**genislik+j] = dizi[(i-1)**genislik+j];
						}
						else //collision
						{
							if (dizi[i**genislik+(j-1)] > dizi[(i-1)**genislik+j])//üstteki soldakinden küçükse
							{
								dizi[i**genislik+j] = dizi[(i-1)**genislik+j];
								dizi[i**genislik+(j-1)] = dizi[i**genislik+j];
								j_n = j;
								j_n--;
								while (j_n != 0) //soldaki etiketleri yenisiyle deðiþtir
								{
									if (dizi[i**genislik+j_n - 1] == 0)
									{
										break;
									}
									else
									{
										dizi[i**genislik+j_n - 1] = dizi[i**genislik+j];
									}
									j_n--;

								}
							}
							else
							{
								dizi[i**genislik+j] = dizi[i**genislik+(j-1)];
								dizi[(i-1)**genislik+j] = dizi[i**genislik+j];
								j_n = j;

								while (j_n != *genislik)//saðdaki etiketleri yenisiyle deðiþtir
								{
									if (dizi[(i- 1)**genislik+j_n + 1] == 0)
									{
										break;
									}
									else
									{
										dizi[(i- 1)**genislik+j_n + 1] = dizi[i**genislik+j];
									}
									j_n++;
								}

								i_n = i;
								i_n--;
								while (i_n != 0)
								{
									if (dizi[(i_n - 1)**genislik+j] == 0)
									{
										break;
									}
									else
									{
										dizi[(i_n - 1)**genislik+j] = dizi[i**genislik+j];
									}
									i_n--;
								}



							}
						}

					}

				}


			}
		
		}
	}
	
	return dizi;

}
BYTE* Tag_Edit(BYTE* dizi, int *genislik, int *yukseklik)
{
	int a = 0,i;
	int flag = 1;
	BYTE* sonuc = new BYTE[10];
	for (i = 0; i < *yukseklik**genislik; i++)
	{
		if (dizi[i] != 0)
		{
	
			for (int sayac = 0; sayac < a; sayac++)
			{
			   if (sonuc[sayac] == dizi[i])
					flag = 0;
			}
			if (flag == 1)
			{
				sonuc[a] = dizi[i];
				a++;
			}
			flag = 1;
		}
	
	}
	sonuc[10] = a;
	return sonuc;
}
BYTE* Fill(BYTE* dizi, int *genislik, int *yukseklik, BYTE* tag)
{
	for (int i = 0; i < *yukseklik**genislik; i++)
	{
		
		if (dizi[i] == tag[0])
		{
			dizi[i] = 30;
		}
		else if (dizi[i] == tag[1])
		{
			dizi[i] = 60;
		}
		else if (dizi[i] == tag[2])
		{
			dizi[i] = 90;
		}
		else if (dizi[i] == tag[3])
		{
			dizi[i] = 120;
		}
		else if (dizi[i] == tag[4])
		{
			dizi[i] = 150;
		}
		else if (dizi[i] == tag[5])
		{
			dizi[i] = 180;
		}
		else if (dizi[i] == tag[6])
		{
			dizi[i] = 210;
		}
		else if (dizi[i] == tag[7])
		{
			dizi[i] = 240;
		}
		else if (dizi[i] == tag[8])
		{
			dizi[i] = 255;
		}
		else
			dizi[i] = 0;
	}
	return dizi;
}
BYTE* Show_Object(BYTE* dizi, int *genislik, int *yukseklik, BYTE* tag)
{
	int n_j, n_i, flag = 0, sayac = 0;
	BYTE *koordinant = new BYTE[8];
	for (int i = 0; i < *yukseklik; i++)
	{
		for (int j = 0; j < *genislik; j++)
		{
			if (dizi[i**genislik + j] == tag[0])
			{
				koordinant[0] = i;
				koordinant[1] = j;
				n_i = i;
				n_j = j;
				while (1)
				{
					n_i++;
					flag = 0;
					while (n_j < *genislik)
					{
						if (dizi[n_i**genislik + n_j + 1] == tag[0])
						{
							flag = 1;
						}
						n_j++;
						
					}
					if (flag == 0)
					{
						koordinant[2] = i+500;
						n_j = j;
						while (dizi[n_i-1**genislik + n_j + 1] != 0)
						{
							n_j++;
						}
						koordinant[3] = j + 400;
						break;
					}

				}
			
			}
			else
			{
				sayac++;
			}

		}
	
	}
	return koordinant;
}