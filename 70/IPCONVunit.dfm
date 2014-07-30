object IpConvForm: TIpConvForm
  Left = 267
  Top = 169
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'DNS'#12450#12489#12524#12473#26263#21495#21270
  ClientHeight = 198
  ClientWidth = 417
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 12
    Top = 16
    Width = 340
    Height = 12
    Caption = #33258#12494#12540#12489#12434#21021#26399#12494#12540#12489#12392#12375#12390#20844#38283#12377#12427#12383#12417#12395#26263#21495#21270#25991#23383#21015#12434#27714#12417#12414#12377
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 52
    Width = 260
    Height = 12
    Caption = 'DNS'#12450#12489#12524#12473'(&D) ( '#12501#12457#12540#12510#12483#12488#12399' host'#65306#12509#12540#12488#30058#21495' '#65289
    FocusControl = OriginalEdit
  end
  object Label3: TLabel
    Left = 212
    Top = 104
    Width = 12
    Height = 12
    Caption = #8595
  end
  object Label4: TLabel
    Left = 16
    Top = 108
    Width = 124
    Height = 12
    Caption = #26263#21495#21270#12373#12428#12383#12450#12489#12524#12473'(&G)'
    FocusControl = CryptEdit
  end
  object OriginalEdit: TEdit
    Left = 28
    Top = 76
    Width = 373
    Height = 20
    ImeMode = imClose
    MaxLength = 255
    TabOrder = 0
  end
  object CryptEdit: TEdit
    Left = 28
    Top = 128
    Width = 373
    Height = 20
    ImeMode = imClose
    TabOrder = 1
  end
  object Button1: TButton
    Left = 236
    Top = 160
    Width = 81
    Height = 25
    Caption = #22793#25563'(&M)'
    Default = True
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 324
    Top = 160
    Width = 77
    Height = 25
    Cancel = True
    Caption = #38281#12376#12427'(&C)'
    TabOrder = 3
    OnClick = Button2Click
  end
end
