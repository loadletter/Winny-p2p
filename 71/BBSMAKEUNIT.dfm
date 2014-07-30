object BbsMakeForm: TBbsMakeForm
  Left = 327
  Top = 177
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'BBS'#26032#35215#20316#25104
  ClientHeight = 163
  ClientWidth = 498
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 117
    Height = 21
    Alignment = taRightJustify
    AutoSize = False
    Caption = #12473#12524#12483#12489#12434#31435#12390#12427#26495'(&B)'
    FocusControl = BoardListCombo
    Layout = tlCenter
  end
  object Label2: TLabel
    Left = 32
    Top = 56
    Width = 109
    Height = 21
    Alignment = taRightJustify
    AutoSize = False
    Caption = #12473#12524#12483#12489#12479#12452#12488#12523'(&T)'
    FocusControl = TitleEdit
    Layout = tlCenter
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 133
    Height = 21
    Alignment = taRightJustify
    AutoSize = False
    Caption = #12488#12522#12483#12503#29983#25104#25991#23383#21015'(&R)'
    FocusControl = TripCombo
    Layout = tlCenter
  end
  object BoardListCombo: TComboBox
    Left = 152
    Top = 24
    Width = 321
    Height = 20
    AutoComplete = False
    Style = csDropDownList
    DropDownCount = 50
    ItemHeight = 12
    TabOrder = 0
  end
  object TitleEdit: TEdit
    Left = 152
    Top = 56
    Width = 321
    Height = 20
    MaxLength = 230
    TabOrder = 1
  end
  object OkButton: TButton
    Left = 284
    Top = 128
    Width = 93
    Height = 21
    Caption = #20316#25104'(&M)'
    TabOrder = 2
    OnClick = OkButtonClick
  end
  object Button1: TButton
    Left = 384
    Top = 128
    Width = 93
    Height = 21
    Cancel = True
    Caption = #12461#12515#12531#12475#12523'(&C)'
    TabOrder = 3
    OnClick = Button1Click
  end
  object TripCombo: TComboBox
    Left = 152
    Top = 88
    Width = 321
    Height = 20
    AutoComplete = False
    DropDownCount = 50
    ItemHeight = 12
    MaxLength = 120
    TabOrder = 4
  end
end
