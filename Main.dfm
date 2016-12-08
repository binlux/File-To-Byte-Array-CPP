object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 64
  ClientWidth = 480
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object sgFile: TGauge
    Left = 8
    Top = 35
    Width = 386
    Height = 21
    ForeColor = clLime
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Progress = 0
  end
  object btnFile: TButton
    Left = 400
    Top = 10
    Width = 75
    Height = 21
    Caption = '&File'
    TabOrder = 0
    OnClick = btnFileClick
  end
  object btnConvert: TButton
    Left = 400
    Top = 36
    Width = 75
    Height = 21
    Caption = '&Convert'
    TabOrder = 1
    OnClick = btnConvertClick
  end
  object edtFile: TEdit
    Left = 8
    Top = 10
    Width = 386
    Height = 21
    TabOrder = 2
  end
  object dlgOpen1: TOpenDialog
    Left = 32
  end
end
