#pragma once
#include <windows.h>

BYTE* LoadBMP(int* width, int* height, long* size, LPCTSTR bmpfile);
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);
BYTE* Kirp(BYTE* raw, int *width, int *height, int x1, int y1, int x2, int y2);
BYTE* Convolisyon_348379(BYTE* buffer, int *genislik, int* yukseklik, double* mask, int mask_yukseklik, int mask_genislik);
INT*  Histogram(BYTE* raw, int *genislik, int *yukseklik);
DOUBLE* Kmeans(INT* histogram, int adet);
BYTE* Binary_Image(BYTE* raw, int *genislik, int *yukseklik, DOUBLE* kmeans);
BYTE* Raw_Sum(BYTE* raw1, BYTE* raw2, int *genislik, int *yukseklik);
BYTE* Segmentasyon(BYTE* dizi, int *genislik, int *yukseklik);
BYTE* Tag_Edit(BYTE* dizi, int *genislik, int *yukseklik);
BYTE* Fill(BYTE* dizi, int *genislik, int *yukseklik,BYTE* tag);
BYTE* Show_Object(BYTE* dizi, int *genislik, int *yukseklik, BYTE* tag);
