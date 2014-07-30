object AutoDownForm: TAutoDownForm
  Left = 255
  Top = 154
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12480#12454#12531#12539#28961#35222#26465#20214
  ClientHeight = 555
  ClientWidth = 458
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 20
    Top = 24
    Width = 388
    Height = 12
    Caption = #26465#20214#12395#21512#12358#12461#12540#12434#20445#25345#12461#12540#20869#12395#35211#12388#12369#12383#12425#33258#21205#30340#12395#12480#12454#12531#12418#12375#12367#12399#28961#35222#12375#12414#12377
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
    Width = 239
    Height = 12
    Caption = #12539' '#12461#12540#12527#12540#12489#12399#31354#30333#21306#20999#12426#12391'and'#26465#20214#12392#12394#12426#12414#12377
  end
  object Label3: TLabel
    Left = 28
    Top = 64
    Width = 297
    Height = 12
    Caption = #12539' '#12461#12540#12527#12540#12489#21336#35486#12398#20808#38957#12434' '#39'-'#39' '#12395#12377#12427#12392#21542#23450#26465#20214#12395#12394#12426#12414#12377
  end
  object Label4: TLabel
    Left = 28
    Top = 80
    Width = 231
    Height = 12
    Caption = #12539' '#12469#12452#12474#25351#23450#12364'0'#12394#12425#12469#12452#12474#28961#21046#38480#12395#12394#12426#12414#12377
  end
  object Label5: TLabel
    Left = 28
    Top = 96
    Width = 389
    Height = 12
    Caption = #12539' '#12480#12454#12531#26465#20214#12398#12358#12385#20808#38957#19977#12388#65288#12495#12483#12471#12517#28961#12375#65289#12364#12494#12540#12489#12463#12521#12473#12479#21270#12395#21033#29992#12373#12428#12414#12377
  end
  object Label6: TLabel
    Left = 28
    Top = 112
    Width = 390
    Height = 12
    Caption = #12539' '#12480#12454#12531#12434#25233#21046#12377#12427#65288#12463#12521#12473#12479#25351#23450#29992#65289#12395#12399#12469#12452#12474#19979#38480#12395'4096'#12394#12393#12434#25351#23450#12375#12414#12377
  end
  object GroupBox1: TGroupBox
    Left = 12
    Top = 136
    Width = 433
    Height = 373
    Caption = #26908#32034#26465#20214
    TabOrder = 0
    object Label7: TLabel
      Left = 51
      Top = 36
      Width = 70
      Height = 12
      Alignment = taRightJustify
      Caption = #12461#12540#12527#12540#12489'(&K)'
      FocusControl = KeywordCombo
    end
    object Label8: TLabel
      Left = 69
      Top = 64
      Width = 52
      Height = 12
      Alignment = taRightJustify
      Caption = #12488#12522#12483#12503'(&T)'
      FocusControl = TripCombo
    end
    object Label9: TLabel
      Left = 63
      Top = 92
      Width = 58
      Height = 12
      Alignment = taRightJustify
      Caption = #12495#12483#12471#12517'(&H)'
      FocusControl = HashEdit
    end
    object Label10: TLabel
      Left = 6
      Top = 120
      Width = 115
      Height = 12
      Alignment = taRightJustify
      Caption = #12469#12452#12474#19978#38480'(&U)(MByte)'
      FocusControl = UpperSizeEdit
    end
    object Label11: TLabel
      Left = 8
      Top = 148
      Width = 113
      Height = 12
      Alignment = taRightJustify
      Caption = #12469#12452#12474#19979#38480'(&L)(MByte)'
      FocusControl = LowerSizeEdit
    end
    object HashEdit: TEdit
      Left = 132
      Top = 88
      Width = 281
      Height = 20
      ImeMode = imClose
      MaxLength = 65
      TabOrder = 2
    end
    object UpperSizeEdit: TEdit
      Left = 132
      Top = 116
      Width = 281
      Height = 20
      ImeMode = imClose
      TabOrder = 3
    end
    object LowerSizeEdit: TEdit
      Left = 132
      Top = 144
      Width = 281
      Height = 20
      ImeMode = imClose
      TabOrder = 4
    end
    object BbsCheck: TCheckBox
      Left = 40
      Top = 172
      Width = 89
      Height = 21
      Caption = 'BBS'#12461#12540'(&B)'
      TabOrder = 6
    end
    object AutoDeleteCheck: TCheckBox
      Left = 40
      Top = 200
      Width = 353
      Height = 21
      Caption = #12480#12454#12531#12418#12375#12367#12399#12461#12540#21066#38500#23436#20102#12375#12383#12425#12371#12398#26465#20214#12434#21066#38500#12377#12427'(&A)'
      TabOrder = 7
    end
    object GroupBox2: TGroupBox
      Left = 16
      Top = 232
      Width = 401
      Height = 121
      Caption = #28961#35222#26465#20214
      TabOrder = 8
      object DisconnectLabel: TLabel
        Left = 40
        Top = 100
        Width = 294
        Height = 12
        Caption = #65288#12495#12483#12471#12517#25351#23450#12373#12428#12390#12356#12427#22580#21512#12461#12540#12395#25423#36896#35686#21578#12434#36861#21152#12377#12427#65289
      end
      object IgnoreCheck: TCheckBox
        Left = 24
        Top = 24
        Width = 281
        Height = 21
        Caption = #26465#20214#19968#33268#12375#12383#12461#12540#12399#12480#12454#12531#12375#12394#12356'(&I)'
        TabOrder = 0
        OnClick = IgnoreCheckClick
      end
      object DeleteCheck: TCheckBox
        Left = 24
        Top = 48
        Width = 357
        Height = 21
        Caption = #26465#20214#19968#33268#12375#12383#12461#12540#12434#21066#38500#12377#12427'(&D) '#65288#12461#12515#12483#12471#12517#12394#12425#12463#12522#12450#12377#12427#65289
        TabOrder = 1
      end
      object DisconnectCheck: TCheckBox
        Left = 24
        Top = 72
        Width = 357
        Height = 25
        Caption = #26465#20214#19968#33268#12375#12383#12461#12540#12434#22823#37327#12395#36865#12387#12390#12367#12427#12494#12540#12489#25509#32154#12434#20999#26029' (&Q)'
        TabOrder = 2
      end
    end
    object TripCombo: TComboBox
      Left = 132
      Top = 60
      Width = 281
      Height = 20
      AutoComplete = False
      DropDownCount = 50
      ImeMode = imClose
      ItemHeight = 12
      MaxLength = 32
      TabOrder = 1
    end
    object KeywordCombo: TComboBox
      Left = 132
      Top = 32
      Width = 281
      Height = 20
      AutoComplete = False
      DropDownCount = 50
      ItemHeight = 12
      MaxLength = 255
      TabOrder = 0
    end
    object ClusterButton: TButton
      Left = 132
      Top = 172
      Width = 281
      Height = 21
      Caption = #12463#12521#12473#12479#25351#23450#29992#12395#12480#12454#12531#19981#21487#33021#12394#26465#20214#12434#35373#23450'(&L)'
      TabOrder = 5
      OnClick = ClusterButtonClick
    end
  end
  object OkButton: TButton
    Left = 252
    Top = 524
    Width = 85
    Height = 25
    Caption = #26356#26032'(&U)'
    Default = True
    TabOrder = 1
    OnClick = OkButtonClick
  end
  object CancelButton: TButton
    Left = 348
    Top = 524
    Width = 93
    Height = 25
    Cancel = True
    Caption = #12461#12515#12531#12475#12523'(&C)'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
end
