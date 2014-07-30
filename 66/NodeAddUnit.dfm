object NodeAddForm: TNodeAddForm
  Left = 284
  Top = 602
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12494#12540#12489#36861#21152
  ClientHeight = 129
  ClientWidth = 421
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
    Top = 64
    Width = 84
    Height = 12
    Alignment = taRightJustify
    Caption = #12494#12540#12489#12450#12489#12524#12473'(&N)'
    FocusControl = NodeEdit
    Layout = tlCenter
  end
  object OkButton: TBitBtn
    Left = 236
    Top = 92
    Width = 81
    Height = 25
    Caption = #36861#21152'(&A)'
    Default = True
    TabOrder = 1
    OnClick = OkButtonClick
  end
  object CancelButton: TBitBtn
    Left = 324
    Top = 92
    Width = 81
    Height = 25
    Cancel = True
    Caption = #38281#12376#12427'(&C)'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 32
    Width = 331
    Height = 16
    Caption = #12507#12473#12488#21517#65306'Port'#30058#21495' '#12414#12383#12399' 127.0.0.1:Port'#30058#21495#12398#24418#24335#12391#25351#23450#12375#12414#12377
    TabOrder = 3
  end
  object StaticText2: TStaticText
    Left = 16
    Top = 8
    Width = 176
    Height = 16
    Caption = #25509#32154#12395#34892#12367#21021#26399#12494#12540#12489#12434#36861#21152#12375#12414#12377
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsUnderline]
    ParentFont = False
    TabOrder = 4
  end
  object NodeEdit: TEdit
    Left = 104
    Top = 60
    Width = 305
    Height = 20
    ImeMode = imClose
    MaxLength = 512
    TabOrder = 0
  end
end
