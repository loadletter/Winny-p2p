object FolderAddForm: TFolderAddForm
  Left = 228
  Top = 197
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12501#12457#12523#12480#36861#21152
  ClientHeight = 264
  ClientWidth = 491
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
  OnHide = FormHide
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 16
    Top = 20
    Width = 218
    Height = 12
    Caption = #22806#37096#12494#12540#12489#12395#20844#38283#12377#12427#12501#12457#12523#12480#12434#36861#21152#12375#12414#12377
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 28
    Top = 48
    Width = 331
    Height = 12
    Caption = #12539' '#12501#12457#12523#12480#20869#12398#12501#12457#12523#12480#12399#36861#21152#26178#12395#21029#12501#12457#12523#12480#12392#12375#12390#23637#38283#12373#12428#12414#12377
  end
  object Label3: TLabel
    Left = 28
    Top = 68
    Width = 288
    Height = 12
    Caption = #12539' '#12488#12522#12483#12503#12399#21516#12475#12483#12488#12398#12501#12449#12452#12523#12434#35672#21029#12377#12427#12383#12417#12395#29992#12356#12414#12377
  end
  object OkButton: TButton
    Left = 308
    Top = 224
    Width = 81
    Height = 25
    Caption = #36861#21152'(&A)'
    Default = True
    TabOrder = 1
    OnClick = OkButtonClick
  end
  object CancelButton: TButton
    Left = 396
    Top = 224
    Width = 81
    Height = 25
    Cancel = True
    Caption = #38281#12376#12427'(&C)'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 96
    Width = 477
    Height = 113
    Caption = #36861#21152#12501#12457#12523#12480
    TabOrder = 0
    object Label4: TLabel
      Left = 32
      Top = 24
      Width = 97
      Height = 21
      Alignment = taRightJustify
      AutoSize = False
      Caption = #12501#12457#12523#12480#21517'(&N)'
      FocusControl = NameEdit
      Layout = tlCenter
    end
    object Label5: TLabel
      Left = 32
      Top = 52
      Width = 97
      Height = 21
      Alignment = taRightJustify
      AutoSize = False
      Caption = #12501#12457#12523#12480#12497#12473'(&P)'
      FocusControl = PathEdit
      Layout = tlCenter
    end
    object Label6: TLabel
      Left = 8
      Top = 80
      Width = 121
      Height = 21
      Alignment = taRightJustify
      AutoSize = False
      Caption = #12488#12522#12483#12503#29983#25104#25991#23383#21015'(&T)'
      FocusControl = TripCombo
      Layout = tlCenter
    end
    object NameEdit: TEdit
      Left = 144
      Top = 24
      Width = 317
      Height = 20
      MaxLength = 255
      TabOrder = 0
    end
    object PathEdit: TEdit
      Left = 144
      Top = 52
      Width = 249
      Height = 20
      ImeMode = imClose
      MaxLength = 512
      TabOrder = 1
    end
    object ReferButton: TButton
      Left = 400
      Top = 52
      Width = 61
      Height = 21
      Caption = #21442#29031'(&R)'
      TabOrder = 2
      OnClick = ReferButtonClick
    end
    object TripCombo: TComboBox
      Left = 144
      Top = 80
      Width = 317
      Height = 20
      AutoComplete = False
      DropDownCount = 50
      ItemHeight = 12
      MaxLength = 200
      TabOrder = 3
    end
  end
end
