object BbsWriteForm: TBbsWriteForm
  Left = 161
  Top = 323
  Width = 580
  Height = 374
  Caption = 'BBS'#26360#12365#36796#12415
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 572
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    DesignSize = (
      572
      57)
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 61
      Height = 21
      Alignment = taCenter
      AutoSize = False
      Caption = #21517#21069'(&N)'
      FocusControl = NameCombo
      Layout = tlCenter
    end
    object Label2: TLabel
      Left = 276
      Top = 32
      Width = 93
      Height = 21
      Alignment = taCenter
      AutoSize = False
      Caption = #12488#12522#12483#12503#29983#25104'(&T)'
      FocusControl = TripCombo
      Layout = tlCenter
    end
    object TitlePanel: TPanel
      Left = 0
      Top = 0
      Width = 572
      Height = 25
      Align = alTop
      BevelOuter = bvLowered
      TabOrder = 0
      object TitleLabel: TLabel
        Left = 1
        Top = 1
        Width = 570
        Height = 23
        Align = alClient
        AutoSize = False
        Layout = tlCenter
      end
    end
    object NameCombo: TComboBox
      Left = 76
      Top = 32
      Width = 197
      Height = 20
      AutoComplete = False
      DropDownCount = 50
      ItemHeight = 12
      TabOrder = 1
    end
    object TripCombo: TComboBox
      Left = 372
      Top = 32
      Width = 192
      Height = 20
      Hint = #12488#12522#12483#12503#12434#29983#25104#12377#12427#12383#12417#12398#25991#23383#21015#12434#25351#23450#12375#12414#12377
      AutoComplete = False
      Anchors = [akLeft, akTop, akRight]
      Constraints.MaxWidth = 200
      DropDownCount = 50
      ItemHeight = 12
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 296
    Width = 572
    Height = 39
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    DesignSize = (
      572
      39)
    object StateLabel: TLabel
      Left = 8
      Top = 8
      Width = 360
      Height = 29
      Anchors = [akLeft, akTop, akRight]
      AutoSize = False
      Layout = tlCenter
    end
    object WriteButton: TButton
      Left = 378
      Top = 8
      Width = 85
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #26360#12365#36796#12416'(&W)'
      TabOrder = 0
      OnClick = WriteButtonClick
    end
    object CloseButton: TButton
      Left = 474
      Top = 8
      Width = 85
      Height = 25
      Anchors = [akTop, akRight]
      Cancel = True
      Caption = #38281#12376#12427'(&C)'
      TabOrder = 1
      OnClick = CloseButtonClick
    end
  end
  object MainPanel: TPanel
    Left = 0
    Top = 57
    Width = 572
    Height = 239
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 1
    object MessageEdit: TMemo
      Left = 1
      Top = 1
      Width = 570
      Height = 237
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object BbsCheckTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = BbsCheckTimerTimer
    Left = 340
    Top = 312
  end
  object CloseTimer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = CloseTimerTimer
    Left = 304
    Top = 312
  end
end
