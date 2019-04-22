#pragma once
#include "imaging.h"
#include <windows.h>
#include <atlstr.h>

namespace NewForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	protected:

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		int Width, Height;
		long Size, new_size;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private: System::Windows::Forms::ToolStripMenuItem^  zoomToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  rawÝnstentitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cannyEdgeDetectorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  segmantasyonToolStripMenuItem;



			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Tasarýmcý desteði için gerekli metot - bu metodun 
			 ///içeriðini kod düzenleyici ile deðiþtirmeyin.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->zoomToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->rawÝnstentitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->cannyEdgeDetectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->segmantasyonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->menuStrip1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
					 this->fileToolStripMenuItem,
						 this->zoomToolStripMenuItem1, this->rawÝnstentitToolStripMenuItem, this->histogramToolStripMenuItem, this->cannyEdgeDetectorToolStripMenuItem,
						 this->segmantasyonToolStripMenuItem
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(906, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
				 this->fileToolStripMenuItem->Text = L"Open";
				 this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fileToolStripMenuItem_Click);
				 // 
				 // zoomToolStripMenuItem1
				 // 
				 this->zoomToolStripMenuItem1->Name = L"zoomToolStripMenuItem1";
				 this->zoomToolStripMenuItem1->Size = System::Drawing::Size(82, 20);
				 this->zoomToolStripMenuItem1->Text = L"Convolision";
				 this->zoomToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::zoomToolStripMenuItem1_Click);
				 // 
				 // rawÝnstentitToolStripMenuItem
				 // 
				 this->rawÝnstentitToolStripMenuItem->Name = L"rawÝnstentitToolStripMenuItem";
				 this->rawÝnstentitToolStripMenuItem->Size = System::Drawing::Size(86, 20);
				 this->rawÝnstentitToolStripMenuItem->Text = L"RawIntensity";
				 this->rawÝnstentitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rawÝnstentitToolStripMenuItem_Click);
				 // 
				 // histogramToolStripMenuItem
				 // 
				 this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
				 this->histogramToolStripMenuItem->Size = System::Drawing::Size(61, 20);
				 this->histogramToolStripMenuItem->Text = L"Kmeans";
				 this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramToolStripMenuItem_Click);
				 // 
				 // cannyEdgeDetectorToolStripMenuItem
				 // 
				 this->cannyEdgeDetectorToolStripMenuItem->Name = L"cannyEdgeDetectorToolStripMenuItem";
				 this->cannyEdgeDetectorToolStripMenuItem->Size = System::Drawing::Size(124, 20);
				 this->cannyEdgeDetectorToolStripMenuItem->Text = L"CannyEdgeDetector";
				 this->cannyEdgeDetectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cannyEdgeDetectorToolStripMenuItem_Click);
				 // 
				 // segmantasyonToolStripMenuItem
				 // 
				 this->segmantasyonToolStripMenuItem->Name = L"segmantasyonToolStripMenuItem";
				 this->segmantasyonToolStripMenuItem->Size = System::Drawing::Size(97, 20);
				 this->segmantasyonToolStripMenuItem->Text = L"Segmantasyon";
				 this->segmantasyonToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::segmantasyonToolStripMenuItem_Click);
				 // 
				 // openToolStripMenuItem
				 // 
				 this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
				 this->openToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				 this->openToolStripMenuItem->Text = L"eski";
				 this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(26, 38);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(386, 368);
				 this->pictureBox1->TabIndex = 1;
				 this->pictureBox1->TabStop = false;
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Location = System::Drawing::Point(418, 38);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(424, 368);
				 this->pictureBox2->TabIndex = 2;
				 this->pictureBox2->TabStop = false;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(906, 444);
				 this->Controls->Add(this->pictureBox2);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		LPCTSTR input;
		CString str;
		int Width, Height;
		long Size;


		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;

			BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
			BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

			Bitmap^ surface = gcnew Bitmap(Width, Height);

			pictureBox2->Image = surface;

			Color c;

			for (int row = 0; row < Height; row++)
			{
				for (int column = 0; column < Width; column++)
				{
					c = Color::FromArgb(raw_intensity[row*Width + column], raw_intensity[row*Width + column], raw_intensity[row*Width + column]);
					surface->SetPixel(column, row, c);
				}
			}
			this->pictureBox1->ImageLocation = openFileDialog1->FileName;

		}
	}

private: System::Void zoomToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

		LPCTSTR input;
		CString str;

		int Width, Height;
		long Size;

		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;

		BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

		//BYTE* kirp = Kirp(raw_intensity, &Width, &Height, 68, 150, 175, 275);
		double* mask = new double[9]{ 0.25,0.5,0.25,0.5,1,0.5,0.25,0.5,0.25 };
		BYTE* convalisyon = Convolisyon_348379(raw_intensity, &Width, &Height, mask, 3, 3);

		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;

		Color c;

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				c = Color::FromArgb(convalisyon[row * Width + column], convalisyon[row * Width + column], convalisyon[row * Width + column]);
				surface->SetPixel(column, row, c);
			}
		}

}
	private: System::Void rawÝnstentitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		LPCTSTR input;
		CString str;
		int Width, Height;
		long Size;

		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;

		BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

		Bitmap^ surface = gcnew Bitmap(Width, Height);

		pictureBox2->Image = surface;

		Color c;

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				c = Color::FromArgb(raw_intensity[row*Width + column], raw_intensity[row*Width + column], raw_intensity[row*Width + column]);
				surface->SetPixel(column, row, c);
			}
		}

	}
	private: System::Void fileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			LPCTSTR input;
			CString str;

			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;

			this->pictureBox1->ImageLocation = openFileDialog1->FileName;

	}

}
	private: System::Void histogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {	

		LPCTSTR input;
		CString str;

		int Width, Height;
		long Size;

		str = openFileDialog1->FileName;
		input = (LPCTSTR)str;

		BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
		BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

		INT* histogram = Histogram(raw_intensity, &Width, &Height);
		DOUBLE* kmeans = Kmeans(histogram,2);
		BYTE* image = Binary_Image(raw_intensity, &Width, &Height, kmeans);
		

		Bitmap^ surface = gcnew Bitmap(Width, Height);
		pictureBox2->Image = surface;

		Color c;

		for (int row = 0; row < Height; row++)
		{
			for (int column = 0; column < Width; column++)
			{
				c = Color::FromArgb(image[row * Width + column], image[row * Width + column], image[row * Width + column]);
				surface->SetPixel(column, row, c);
			}
		}
	
	}
private: System::Void cannyEdgeDetectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	LPCTSTR input;
	CString str;

	int Width, Height;
	int buf_Width, buf_Height;
	long Size;

	buf_Width = Width;
	buf_Height = Height;

	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;

	BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height); 

	double* yatay_mask = new double[9]{ 1,2,1,0,0,0,-1,-2,-1};
	double* dikey_mask = new double[9]{ 1,0,1,2,0,-2,1,0, -1 };
	
	BYTE* yatay_turev = Convolisyon_348379(raw_intensity, &Width, &Height, yatay_mask, 3, 3);
    Width = Width/2;
	Height = Height/2;
	BYTE* dikey_turev = Convolisyon_348379(raw_intensity, &Width, &Height, dikey_mask, 3, 3);

	BYTE* edge_image = Raw_Sum(yatay_turev, dikey_turev, &Width, &Height);


	Bitmap^ surface = gcnew Bitmap(Width, Height);
	pictureBox2->Image = surface;

	Color c;

	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			c = Color::FromArgb(edge_image[row * Width + column], edge_image[row * Width + column], edge_image[row * Width + column]);
			surface->SetPixel(column, row, c);
		}
	}

}
private: System::Void segmantasyonToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	LPCTSTR input;
	CString str;

	int Width, Height;
	long Size;

	str = openFileDialog1->FileName;
	input = (LPCTSTR)str;

	BYTE* buffer = LoadBMP(&Width, &Height, &Size, input);
	BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

	INT* histogram = Histogram(raw_intensity, &Width, &Height);
	DOUBLE* kmeans = Kmeans(histogram, 2);
	BYTE* image = Binary_Image(raw_intensity, &Width, &Height, kmeans);
	BYTE* segmentation = Segmentasyon(image, &Width, &Height);
	BYTE* tags = Tag_Edit(image, &Width, &Height);
	BYTE* fiils = Fill(segmentation, &Width, &Height,tags);
	//BYTE* object = Show_Object(segmentation, &Width, &Height, tags);
	//BYTE* crop = Kirp(segmentation, &Width, &Height, object[0], object[1], object[2], object[3]);
	MessageBox::Show(Convert::ToString(tags[10]));

	Bitmap^ surface = gcnew Bitmap(Width, Height);
	pictureBox2->Image = surface;

	Color c;

	for (int row = 0; row < Height; row++)
	{
		for (int column = 0; column < Width; column++)
		{
			c = Color::FromArgb(fiils[row * Width + column], fiils[row * Width + column], fiils[row * Width + column]);
			surface->SetPixel(column, row, c);
			
		}
	}
}
};
}