#pragma once

#include "stdio.h"
#include "iso9660.h"
#include "memory.h"
#include "string.h"
#include "des.h"

unsigned long crc32(const unsigned char *s, unsigned int len,unsigned int initcrc);
namespace NaoIso {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			offset=0x2f000;
			start=0xb800;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::OpenFileDialog^  srcISODialog;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->srcISODialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(18, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(299, 180);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Source Game";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(6, 134);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(202, 20);
			this->textBox5->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(106, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Source game info file";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(202, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Source Key";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(268, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(28, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(6, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(256, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"GD Track ISO Image";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(6, 95);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(202, 20);
			this->textBox3->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Location = System::Drawing::Point(323, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(299, 180);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Destination Game";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(6, 134);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(202, 20);
			this->textBox6->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(125, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Destination game info file";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Destination Key (leave blank for decrypted)";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(6, 43);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(287, 20);
			this->textBox4->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Destination ISO";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(271, 204);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 26);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(18, 238);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(600, 19);
			this->progressBar1->TabIndex = 3;
			// 
			// srcISODialog
			// 
			this->srcISODialog->Filter = L"ISO Files|*.iso";
			this->srcISODialog->Title = L"Select ISO Image";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(642, 271);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Naomi GD ISO Converter 1.02";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(srcISODialog->ShowDialog()==System::Windows::Forms::DialogResult::OK)
				 {
					 textBox1->Text=srcISODialog->FileName;
					 textBox4->Text=srcISODialog->FileName+".new";

					 IntPtr hFile=Marshal::StringToHGlobalAnsi(textBox1->Text);

					 FILE *f;
					 fopen_s(&f,(const char *) hFile.ToPointer(),"rb");
					 Marshal::FreeHGlobal(hFile);

					 if(f==NULL)
					 {
						 fclose(f);
						 MessageBox::Show("Can't open ISO image","Error",System::Windows::Forms::MessageBoxButtons::OK);
						 return;
					 }

					 const unsigned char sync[12]={0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00};
					unsigned char Sector[0x800];
					unsigned int SectorSize=2048;

					fread(Sector,12,1,f);
					if(memcmp(Sector,sync,12)==0)
					{
						SectorSize=2352;
						fseek(f,16,SEEK_SET);
					}
					else
						fseek(f,0,SEEK_SET);

					int SectorNum=0x10;
					while(SectorNum<200)
					{
						if(SectorSize==2352)
							fseek(f,SectorNum*2352+16,SEEK_SET);
						else
							fseek(f,SectorNum*2048,SEEK_SET);
						fread(Sector,2048,1,f);
						if(memcmp(Sector,"\x01""CD001""\x01",7)==0)
							break;
						++SectorNum;
					}
					if(SectorNum==200)
					{
						fclose(f);
						MessageBox::Show("Can't find ISO header","Error",System::Windows::Forms::MessageBoxButtons::OK);
						return ;
					}

					_rootdirrecord rootdirrecord;
					_iso_primary_record primaryrecord;
					memcpy(&primaryrecord,Sector,sizeof(primaryrecord));
					memcpy(&rootdirrecord,&primaryrecord.rootrecord,sizeof(rootdirrecord));

					SectorNum=rootdirrecord.FirstFile.l-0xafc8;
					if(SectorSize==2352)
						fseek(f,SectorNum*2352+16,SEEK_SET);
					else
						fseek(f,SectorNum*2048,SEEK_SET);
					fread(Sector,2048,1,f);
					unsigned char *ptSec=Sector;
					_rootdirrecord *rec=(_rootdirrecord *) ptSec;
					sz=0;
					bool bFound=false;
					while(1)
					{
						rec=(_rootdirrecord *) ptSec;
						if(rec->Size==0)
						{
							if(!bFound)
								MessageBox::Show("Can't find Game Info File","Error",System::Windows::Forms::MessageBoxButtons::OK);
							break;
						}
						char Name[256];
						memcpy(Name,ptSec+sizeof(_rootdirrecord),rec->Length);
						Name[rec->Length]=0;
						sz+=rec->FileLength.l;
						if((strstr(Name,".bin") || strstr(Name,".BIN")) && rec->FileLength.l<0x1000)
						{
							char *c=strchr(Name,';');
							if(c)
								*c=0;
							textBox5->Text=gcnew String (Name);
							textBox6->Text=gcnew String (Name);
							bFound=true;
						}

						ptSec+=rec->Size;
					}
					
					fclose(f);
				 }
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
					IntPtr hFile=Marshal::StringToHGlobalAnsi(textBox1->Text);

					FILE *f,*f2;
					fopen_s(&f,(const char *) hFile.ToPointer(),"rb");
					if(f==NULL)
					{
						MessageBox::Show("Can't open ISO image","Error",System::Windows::Forms::MessageBoxButtons::OK);
						return;
					}
					Marshal::FreeHGlobal(hFile);

					hFile=Marshal::StringToHGlobalAnsi(textBox4->Text);
					fopen_s(&f2,(const char *) hFile.ToPointer(),"w+b");
					if(f2==NULL)
					{
						fclose(f);
						MessageBox::Show("Can't open destination file","Error",System::Windows::Forms::MessageBoxButtons::OK);
						return;
					}
					Marshal::FreeHGlobal(hFile);


					start=0xb800;
					csz=0;
					int InfoFile=-1;
					{
						unsigned char security[0x20*0x800];
						unsigned char sector[0x800];

						int SectorNum;
						struct _rootdirrecord rootdirrecord;
						struct _iso_primary_record primaryrecord;

						fread(security,0x20,0x800,f);

						memcpy(&primaryrecord,security+0x10*0x800,sizeof(primaryrecord));
						memcpy(&rootdirrecord,&primaryrecord.rootrecord,sizeof(rootdirrecord));

						SectorNum=rootdirrecord.FirstFile.l-0xafc8;
						progressBar1->Maximum=sz;
						progressBar1->Minimum=0;
						progressBar1->Value=0;
						{
							unsigned char *ptSec=security+SectorNum*0x800;
							struct _rootdirrecord *rec=(struct _rootdirrecord *) ptSec;
							while(1)
							{
								rec=(struct _rootdirrecord *) ptSec;
								if(rec->Size==0)
									break;
								if(rec->FirstFile.l<0xb000)
								{
									ptSec+=rec->Size;
									continue;
								}

								char Name[256];
								memcpy(Name,ptSec+sizeof(_rootdirrecord),rec->Length);
								Name[rec->Length]=0;
								char *c=strchr(Name,';');
								if(c)
									*c=0;
								
								printf("%s ",Name);
								printf("%X->",rec->FirstFile.l);
								if(rec->FirstFile.l>0xb000)
								{
									if(rec->FileLength.l>0x100000)
										relocatebigfile(f,f2,rec);
									else
										relocatefile(f,f2,rec);
									rec->FirstFile.b=bswap32(rec->FirstFile.l);
									printf("%X\n",rec->FirstFile.l);
								}
								else
									printf("Skipped\n");
						
								if((strstr(Name,".bin") || strstr(Name,".BIN")) && rec->FileLength.l<0x1000)
								{
									InfoFile=rec->FirstFile.l;
									if(textBox6->Text!="")
									{
										hFile=Marshal::StringToHGlobalAnsi(textBox6->Text);
										memcpy(ptSec+sizeof(_rootdirrecord),hFile.ToPointer(),strlen((const char *) hFile.ToPointer())-1);
										Marshal::FreeHGlobal(hFile);
									}
								}


								ptSec+=rec->Size;
							}
						}

						//fseek(f2,0,SEEK_SET);
						//fwrite(security,0x20,0x800,f2);


						fseek(f2,(0xB05E-150)*0x800,SEEK_SET);
						fwrite(security,0x20,0x800,f2);

						fseek(f2,(0xB05E)*0x800,SEEK_SET);
						fwrite(security,0x20,0x800,f2);

						if(InfoFile!=-1)
						{
							int cc=crc;
							int flag=0xFF;
							fseek(f2,InfoFile*0x800,SEEK_SET);
							fread(sector,0x800,1,f2);
							memcpy(sector+12,&cc,4);
							//sets the LBA check skip flag
							memcpy(sector + 20, &flag, 1);
							fseek(f2,InfoFile*0x800,SEEK_SET);
							fwrite(sector,0x800,1,f2);
						}
					}
					


					
					fclose(f);
					fclose(f2);

					MessageBox::Show("Done","Done",System::Windows::Forms::MessageBoxButtons::OK);
		 }

		 unsigned int inline bswap32(unsigned int v)
		 {
			return (v<<24)|((v&0xFF0000)>>8)|((v&0xFF00)<<8)|(v>>24);
		 }

		void relocatefile(FILE *f,FILE *f2,_rootdirrecord *rec)
		{
			

			unsigned char sector2[0x800];
			int Size=rec->FileLength.l;
			fseek(f,(rec->FirstFile.l-0xb05e + 150)*0x800,SEEK_SET);
			rec->FirstFile.l-=offset;
			fseek(f2,(rec->FirstFile.l/*+150*/)*0x800,SEEK_SET);

			while(Size)
			{
				int sz=0x800;
				if(Size<0x800)
					sz=Size;
				fread(sector2,sz,1,f);
				fwrite(sector2,sz,1,f2);
				++start;
				csz+=0x800;
				progressBar1->Value=csz;

				if(Size>0x800)
					Size-=0x800;
				else
					Size=0;
			}
		}
		
		void byterev(unsigned char *p1,unsigned char *p2)
		{
			for(int i=0;i<8;++i)
			{
				p2[i]=p1[7-i];
			}
		}

		void relocatebigfile(FILE *f,FILE *f2,_rootdirrecord *rec)
		{
			unsigned char sector2[0x800];
			int Size=rec->FileLength.l;
			fseek(f,(rec->FirstFile.l-0xb05e + 150)*0x800,SEEK_SET);
			rec->FirstFile.l-=offset;
			fseek(f2,(rec->FirstFile.l/*+150*/)*0x800,SEEK_SET);

			crc=0xffffffff;
			bool endec=false;
			bool dec = false;
			_des_ctx ctx1,ctx2;

			if(textBox2->Text!="" && textBox3->Text!="")
			{
				unsigned char key[8];
				unsigned char key2[8];
				IntPtr hTxt;
				char *aux;
				int i;

				hTxt=Marshal::StringToHGlobalAnsi(textBox2->Text);
				aux=(char *) hTxt.ToPointer();
				for(i=0;i<8;++i)
				{
					unsigned int v;
					char a[3];
					a[0]=aux[2*i+0];
					a[1]=aux[2*i+1];
					a[2]=0;
					sscanf_s(a,"%X",&v);
					key[i]=v&0xFF;
				}
				Marshal::FreeHGlobal(hTxt);
				byterev(key,key2);
				des_setkey(&ctx1,key2);

				hTxt=Marshal::StringToHGlobalAnsi(textBox3->Text);
				aux=(char *) hTxt.ToPointer();
				for(i=0;i<8;++i)
				{
					unsigned int v;
					char a[3];
					a[0]=aux[2*i+0];
					a[1]=aux[2*i+1];
					a[2]=0;
					sscanf_s(a,"%X",&v);
					key[i]=v&0xFF;
				}
				Marshal::FreeHGlobal(hTxt);
				byterev(key,key2);
				des_setkey(&ctx2,key2);

				endec=true;
			}

			if(textBox2->Text!="" && textBox3->Text=="")
			{
				unsigned char key[8];
				unsigned char key2[8];
				IntPtr hTxt;
				char *aux;
				int i;

				hTxt=Marshal::StringToHGlobalAnsi(textBox2->Text);
				aux=(char *) hTxt.ToPointer();
				for(i=0;i<8;++i)
				{
					unsigned int v;
					char a[3];
					a[0]=aux[2*i+0];
					a[1]=aux[2*i+1];
					a[2]=0;
					sscanf_s(a,"%X",&v);
					key[i]=v&0xFF;
				}
				Marshal::FreeHGlobal(hTxt);
				byterev(key,key2);
				des_setkey(&ctx1,key2);

				hTxt=Marshal::StringToHGlobalAnsi(textBox3->Text);
				aux=(char *) hTxt.ToPointer();
				for(i=0;i<8;++i)
				{
					unsigned int v;
					char a[3];
					a[0]=aux[2*i+0];
					a[1]=aux[2*i+1];
					a[2]=0;
					sscanf_s(a,"%X",&v);
					key[i]=v&0xFF;
				}
				Marshal::FreeHGlobal(hTxt);
				byterev(key,key2);
				des_setkey(&ctx2,key2);

				dec=true;
			}

			while(Size)
			{
				int sz;
				if(Size<0x800)
					sz=Size;
				else
					sz=0x800;
				fread(sector2,sz,1,f);
				//Decrypt
				if(endec)
				{
					for(int i=0;i<sz;i+=8)
					{
						unsigned char buf[8],buf2[8];
						byterev(sector2+i,buf);
						des_ecb_decrypt(&ctx1,buf,buf2);
						des_ecb_encrypt(&ctx2,buf2,buf);
						byterev(buf,sector2+i);
					}
				}
//	Adds support for decrypted images			
				if(dec)
				{
					for(int i=0;i<sz;i+=8)
					{
						unsigned char buf[8],buf2[8];
						byterev(sector2+i,buf);
						des_ecb_decrypt(&ctx1,buf,buf2);
//						des_ecb_encrypt(&ctx2,buf2,buf);
						byterev(buf2,sector2+i);
					}	
				}
				
				//Encrypt
				crc=crc32(sector2,sz,crc);
				fwrite(sector2,sz,1,f2);
				++start;
				csz+=sz;
				progressBar1->Value=csz;

				if(Size>0x800)
					Size-=0x800;
				else
					Size=0;
			}
		}


		unsigned int offset;
		unsigned int start;
		unsigned int sz,csz;
		unsigned int crc;
};
}

