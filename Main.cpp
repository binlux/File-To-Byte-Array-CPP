// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <System.hpp>

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgauges"
#pragma link "ushldlg"
#pragma link "Gauges"
#pragma resource "*.dfm"

TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

bool __fastcall TForm1::ConvertFile(String sFile, String dFile) {
	DWORD EFile, I, c, BytesRead;
	Byte *FBytes;
	HANDLE HFile;
	HFile = CreateFileW(sFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (HFile == INVALID_HANDLE_VALUE) {
		MessageBoxA(Application->Handle, (char *)"File does not exist",
			(char *)"me&delphi", MB_OK | MB_ICONERROR);
		return false;
	}
	TStringBuilder *S = new TStringBuilder();
	TStringList *List = new TStringList();
	EFile = GetFileSize(HFile, NULL);
	FBytes = new Byte[EFile];
	try {
		c = 0;
		btnFile->Enabled = false;
		btnConvert->Enabled = false;
		ReadFile(HFile, (void *)FBytes, EFile, &BytesRead, NULL);
		S->Append(" const XM : array[1..");
		S->Append(int(EFile));
		S->Append("] of Byte = (");
		S->AppendLine();
		sgFile->MinValue = 0;
		sgFile->MaxValue = EFile; // Error here if big file
		for (I = 0; I <= EFile; I++) {
			_asm {
				INC c // c += 1;
				}
			if (c == 16) {
				if (I == EFile) {
					S->Append("$");
					S->Append(IntToHex(FBytes[I], 2));
					S->AppendLine();
				}
				else {
					S->Append("$");
					S->Append(IntToHex(FBytes[I], 2));
					S->Append(",");
					S->AppendLine();
				}
				c = 0;
			}
			else if (I == EFile) {
				S->Append("$");
				S->Append(IntToHex(FBytes[I], 2));
				S->AppendLine();
			}
			else {
				S->Append("$");
				S->Append(IntToHex(FBytes[I], 2));
				S->Append(", ");
			}
			sgFile->Progress = I; // Error here if big file
			// Application->ProcessMessages();
		}
		S->Append(");");
		List->Add(S->ToString());
		MessageBoxA(Application->Handle,
			(char *)"File successfully converted and now copying it to disk ",
			(char *)"me&delphi", MB_OK | MB_ICONINFORMATION);
		CloseHandle(HFile);
		List->SaveToFile(dFile);
	}
	__finally {
		delete S;
		delete List;
		delete[]FBytes;
	}
	return true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnFileClick(TObject *Sender) {
	if (dlgOpen1->Execute(this->Handle)) {
		edtFile->Text = dlgOpen1->FileName;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnConvertClick(TObject *Sender) {
	if (ConvertFile(edtFile->Text, ExtractFilePath(Application->ExeName) +
		"DumpedFile.dmp"))
		MessageBoxA(Application->Handle, (char *)"File copied and ready to use",
		(char *)("me&delphi"), MB_OK | MB_ICONINFORMATION);
	btnConvert->Enabled = true;
	btnFile->Enabled = true;
}
// ---------------------------------------------------------------------------
