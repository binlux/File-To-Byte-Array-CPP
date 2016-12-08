// ---------------------------------------------------------------------------

#ifndef MainH
#define MainH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ushldlg.hpp"
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include "Gauges.hpp"

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // Composants gérés par l'EDI

	TButton *btnFile;
	TButton *btnConvert;
	TEdit *edtFile;
	TOpenDialog *dlgOpen1;
	TGauge *sgFile;

	bool __fastcall ConvertFile(String sFile, String dFile);
	void __fastcall btnFileClick(TObject *Sender);
	void __fastcall btnConvertClick(TObject *Sender);

private: // Déclarations utilisateur
		public : // Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
