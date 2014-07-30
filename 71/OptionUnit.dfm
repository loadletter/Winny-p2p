object OptionForm: TOptionForm
  Left = 1358
  Top = 110
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12471#12473#12486#12512#35373#23450
  ClientHeight = 477
  ClientWidth = 519
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
  object OkButton: TButton
    Left = 312
    Top = 446
    Width = 97
    Height = 24
    Caption = #35373#23450'(&U)'
    Default = True
    TabOrder = 1
    OnClick = OkButtonClick
  end
  object CancelButton: TButton
    Left = 418
    Top = 446
    Width = 96
    Height = 24
    Cancel = True
    Caption = #12461#12515#12531#12475#12523'(&C)'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object SystemPage: TPageControl
    Left = 8
    Top = 12
    Width = 505
    Height = 425
    ActivePage = DownloadSheet
    TabIndex = 2
    TabOrder = 0
    object ComSheet: TTabSheet
      Caption = #36890#20449
      object Label1: TLabel
        Left = 16
        Top = 20
        Width = 388
        Height = 12
        Caption = #33258#12494#12540#12489#12398#30003#35531#24773#22577#12420#20182#12494#12540#12489#12363#12425#12398#25509#32154#24453#12385#21463#12369#12395#29992#12356#12425#12428#12427#12509#12540#12488#12398#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 88
        Top = 108
        Width = 207
        Height = 12
        Caption = #12501#12449#12452#12523#36578#36865#12395#29992#12356#12427#12509#12540#12488#12398#12509#12540#12488#30058#21495
      end
      object Label3: TLabel
        Left = 88
        Top = 140
        Width = 209
        Height = 12
        Caption = 'BBS'#24453#12385#12358#12369#65288'LAN'#29992#65289#12395#29992#12356#12427#12509#12540#12488#30058#21495
      end
      object Label4: TLabel
        Left = 52
        Top = 212
        Width = 380
        Height = 12
        Caption = 'DDNS'#21517#65288#22806#37096#12494#12540#12489#12395#21029#12450#12489#12524#12473#12391#12398#25509#32154#12434#25351#31034#12373#12379#12383#12356#12392#12365#12395#35373#23450#12375#12414#12377#65289
      end
      object Label12: TLabel
        Left = 104
        Top = 72
        Width = 170
        Height = 12
        Caption = #33258#12494#12540#12489#12398'UP'#38480#30028#36895#24230#65288'KByte/s'#65289
      end
      object Label5: TLabel
        Left = 16
        Top = 40
        Width = 137
        Height = 12
        Caption = 'Winny'#12398#20877#36215#21205#12364#24517#35201#12391#12377
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clRed
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 124
        Top = 280
        Width = 142
        Height = 12
        Caption = #20445#25345#12377#12427#20206#24819#12461#12540#12398#26368#22823#25968
      end
      object FilePortEdit: TEdit
        Left = 344
        Top = 100
        Width = 101
        Height = 20
        ImeMode = imClose
        TabOrder = 1
        OnChange = FilePortEditChange
      end
      object BbsPortEdit: TEdit
        Left = 344
        Top = 132
        Width = 101
        Height = 20
        ImeMode = imClose
        TabOrder = 2
        OnChange = BbsPortEditChange
      end
      object Port0Check: TCheckBox
        Left = 56
        Top = 176
        Width = 397
        Height = 17
        Caption = #12501#12449#12452#12523#36578#36865#29992#12509#12540#12488#12395#23550#12377#12427#22806#37096#12363#12425#12398#25509#32154#12364#19981#21487#33021#65288'Port0'#35373#23450#65289
        TabOrder = 3
        OnClick = Port0CheckClick
      end
      object DdnsEdit: TEdit
        Left = 72
        Top = 236
        Width = 373
        Height = 20
        ImeMode = imClose
        MaxLength = 255
        TabOrder = 4
        OnChange = DdnsEditChange
      end
      object LineSpeedCombo: TComboBox
        Left = 280
        Top = 68
        Width = 165
        Height = 20
        AutoComplete = False
        ImeMode = imClose
        ItemHeight = 12
        TabOrder = 0
        OnChange = LineSpeedComboChange
        Items.Strings = (
          '1000 (T3, '#20809')'
          '120 (ADSL 24M, 12M, 8M)'
          '50 (ADSL 1.5M)'
          '15 (ISDN 128K)'
          '7 (ISDN 64K)'
          '5 ('#12514#12487#12512')')
      end
      object VirtualKeyCombo: TComboBox
        Left = 308
        Top = 276
        Width = 137
        Height = 20
        AutoComplete = False
        ImeMode = imClose
        ItemHeight = 12
        TabOrder = 5
        OnChange = VirtualKeyComboChange
        Items.Strings = (
          '35000'
          '30000'
          '25000'
          '20000'
          '15000'
          '10000'
          '5000')
      end
    end
    object FolderSheet: TTabSheet
      Caption = #12501#12457#12523#12480
      ImageIndex = 1
      object Label6: TLabel
        Left = 16
        Top = 20
        Width = 166
        Height = 12
        Caption = 'Winny'#12364#29992#12356#12427#21508#12501#12457#12523#12480#12398#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 28
        Top = 88
        Width = 133
        Height = 16
        Alignment = taRightJustify
        AutoSize = False
        Caption = #12461#12515#12483#12471#12517#12501#12457#12523#12480#12497#12473
        Layout = tlCenter
      end
      object Label8: TLabel
        Left = 28
        Top = 120
        Width = 133
        Height = 16
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'BBS'#12501#12457#12523#12480#12497#12473
        Layout = tlCenter
      end
      object Label9: TLabel
        Left = 28
        Top = 152
        Width = 133
        Height = 16
        Alignment = taRightJustify
        AutoSize = False
        Caption = #12480#12454#12531#12501#12457#12523#12480#12497#12473
        Layout = tlCenter
      end
      object Label13: TLabel
        Left = 16
        Top = 40
        Width = 137
        Height = 12
        Caption = 'Winny'#12398#20877#36215#21205#12364#24517#35201#12391#12377
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clRed
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object CachePathEdit: TEdit
        Left = 172
        Top = 84
        Width = 257
        Height = 20
        AutoSelect = False
        MaxLength = 512
        TabOrder = 0
        OnChange = CachePathEditChange
      end
      object CachePathReferButton: TButton
        Left = 436
        Top = 84
        Width = 41
        Height = 21
        Caption = #21442#29031
        TabOrder = 1
        OnClick = CachePathReferButtonClick
      end
      object BbsPathEdit: TEdit
        Left = 172
        Top = 116
        Width = 257
        Height = 20
        AutoSelect = False
        MaxLength = 512
        TabOrder = 2
        OnChange = BbsPathEditChange
      end
      object BbsPathReferButton: TButton
        Left = 436
        Top = 116
        Width = 41
        Height = 21
        Caption = #21442#29031
        TabOrder = 3
        OnClick = BbsPathReferButtonClick
      end
      object DownPathEdit: TEdit
        Left = 172
        Top = 148
        Width = 257
        Height = 20
        AutoSelect = False
        MaxLength = 512
        TabOrder = 4
        OnChange = DownPathEditChange
      end
      object DownPathReferButton: TButton
        Left = 436
        Top = 148
        Width = 41
        Height = 21
        Caption = #21442#29031
        TabOrder = 5
        OnClick = DownPathReferButtonClick
      end
    end
    object DownloadSheet: TTabSheet
      Caption = #12480#12454#12531#12525#12540#12489
      ImageIndex = 4
      object Label10: TLabel
        Left = 20
        Top = 20
        Width = 146
        Height = 12
        Caption = #12480#12454#12531#12525#12540#12489#21205#20316#38306#36899#12398#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label28: TLabel
        Left = 48
        Top = 264
        Width = 239
        Height = 12
        Hint = #35079#25968#12398#12461#12540#12527#12540#12489#12395#12498#12483#12488#12377#12427#12461#12540#12434#28961#35222#12377#12427#12383#12417#12398#35373#23450#12391#12377
        Caption = #38263#12377#12366#12427#21517#21069#12398#12461#12540#12434#30772#26820#12377#12427#65288'32'#65374'255'#25991#23383#65289
        ParentShowHint = False
        ShowHint = True
      end
      object NotConvertCheck: TCheckBox
        Left = 48
        Top = 68
        Width = 433
        Height = 17
        Hint = #12371#12428#12364'OFF'#12398#22580#21512#12289#12480#12454#12531#26465#20214#12398#12300#26410#22793#25563#12481#12455#12483#12463#12301#12508#12479#12531#12391#24460#22793#25563#12375#12414#12377
        Caption = #12480#12454#12531#23436#20102#26178#12395#22793#25563#12479#12473#12463#12434#36215#21205#12375#12394#12356
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object AutoDisconnectCheckBox: TCheckBox
        Left = 48
        Top = 148
        Width = 413
        Height = 17
        Hint = #12463#12521#12473#12479#12434#26089#12417#12395#22793#12360#12383#12356#22580#21512#12395#29992#12356#12414#12377
        Caption = #26908#32034#12522#12531#12463#12398#33258#21205#20999#26029#38971#24230#12434#19978#12370#12427
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
      object FastDownCheckBox: TCheckBox
        Left = 48
        Top = 121
        Width = 421
        Height = 17
        Hint = #12480#12454#12531#26465#20214#12391#12398#26465#20214#26908#32034#36895#24230#12364#26089#12367#12394#12426#12414#12377#12364#36000#33655#12364#39640#12367#12394#12426#12414#12377
        Caption = #12480#12454#12531#35430#34892#38971#24230#12434#19978#12370#12427
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
      end
      object InitButton: TButton
        Left = 276
        Top = 356
        Width = 201
        Height = 25
        Caption = #21021#26399#29366#24907#12395#25147#12377
        TabOrder = 8
        OnClick = InitButtonClick
      end
      object V4CacheNotDownCheck: TCheckBox
        Left = 48
        Top = 228
        Width = 285
        Height = 17
        Hint = #26087#12496#12540#12472#12519#12531#12398#12461#12515#12483#12471#12517#12395#23550#12375#12390#26908#32034#12420#12480#12454#12531#12525#12540#12489#12434#12363#12369#12427#12363#12393#12358#12363#12398#35373#23450#12391#12377
        Caption = #26087'Version4'#12461#12515#12483#12471#12517#12434#26908#32034#12539#33258#21205#12480#12454#12531#12525#12540#12489#12375#12394#12356
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
      end
      object MakeMarkCheck: TCheckBox
        Left = 48
        Top = 94
        Width = 285
        Height = 17
        Hint = #12300#12480#12454#12531#23436#20102#26178#12395#22793#25563#12479#12473#12463#12434#36215#21205#12375#12394#12356#12301#12364'ON'#12398#26178#12395#12510#12540#12463#12501#12449#12452#12523#12434#20316#25104#12375#12414#12377
        Caption = #12461#12515#12483#12471#12517#22793#25563#30465#30053#26178#12395#12510#12540#12463#12501#12449#12452#12523#12434#20316#25104#12377#12427
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
      object MaxNameLengthEdit: TEdit
        Left = 308
        Top = 260
        Width = 121
        Height = 20
        MaxLength = 3
        TabOrder = 7
        Text = '255'
      end
      object DownloadIgnoreKeyCheck: TCheckBox
        Left = 48
        Top = 174
        Width = 337
        Height = 21
        Hint = #25423#36896#35686#21578#65288#21442#29031#37327#12364#36196#12367#12394#12387#12390#12356#12427#12461#12540#65289#12395#23550#12377#12427#33258#21205#12480#12454#12531#12525#12540#12489#12434#34892#12356#12414#12377
        Caption = #25423#36896#35686#21578#12398#20184#12356#12383#12461#12540#12418#33258#21205#12480#12454#12531#12525#12540#12489#12377#12427
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
      end
      object IgnoreSortCheck: TCheckBox
        Left = 48
        Top = 201
        Width = 385
        Height = 17
        Caption = #21442#29031#37327#12477#12540#12488#34920#31034#26178#12395#25423#36896#35686#21578#12434#32771#24942#12377#12427
        TabOrder = 5
      end
    end
    object TaskSheet: TTabSheet
      Caption = #12501#12449#12452#12523#25805#20316
      ImageIndex = 3
      object Label23: TLabel
        Left = 20
        Top = 20
        Width = 149
        Height = 12
        Caption = #12501#12449#12452#12523#20849#26377#38306#36899#12398#25805#20316#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label24: TLabel
        Left = 36
        Top = 88
        Width = 185
        Height = 25
        Alignment = taRightJustify
        AutoSize = False
        Caption = #12501#12449#12452#12523#20849#26377#34920#31034#12479#12502#12398#34920#31034#26041#24335
        Layout = tlCenter
      end
      object AutoTabChangeCheckBox: TCheckBox
        Left = 48
        Top = 60
        Width = 189
        Height = 17
        Caption = #33258#21205#30340#12395#34920#31034#12479#12502#12434#20999#12426#26367#12360#12427
        TabOrder = 0
      end
      object SearchTabGroupBox: TGroupBox
        Left = 44
        Top = 124
        Width = 333
        Height = 177
        Caption = #26908#32034#12479#12502
        TabOrder = 2
        object Label27: TLabel
          Left = 12
          Top = 137
          Width = 145
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          Caption = #26908#32034#12479#12502#12398#34920#31034#26041#24335
          Layout = tlCenter
        end
        object SearchTabUseCheck: TCheckBox
          Left = 16
          Top = 28
          Width = 189
          Height = 17
          Caption = #26908#32034#12479#12502#12434#29992#12356#12427
          TabOrder = 0
        end
        object UpperSearchTabCheck: TCheckBox
          Left = 16
          Top = 60
          Width = 237
          Height = 17
          Caption = #26908#32034#12479#12502#12434#12499#12517#12540#12398#19978#26041#12395#37197#32622
          TabOrder = 1
          OnClick = UpperSearchTabCheckClick
        end
        object AlwaysShowSearchTabCheck: TCheckBox
          Left = 16
          Top = 84
          Width = 225
          Height = 17
          Caption = #26908#32034#12479#12502#12434#24120#12395#34920#31034#12373#12379#12427
          TabOrder = 2
        end
        object SearchTabModeCombo: TComboBox
          Left = 180
          Top = 137
          Width = 121
          Height = 20
          AutoComplete = False
          Style = csDropDownList
          ItemHeight = 12
          TabOrder = 4
          OnChange = SearchTabModeComboChange
          Items.Strings = (
            #12508#12479#12531
            #12501#12521#12483#12488#12508#12479#12531
            #12479#12502)
        end
        object AutoCopyDownInfoCheck: TCheckBox
          Left = 16
          Top = 108
          Width = 309
          Height = 17
          Caption = #12480#12454#12531#26465#20214#36861#21152#26178#12395#12480#12454#12531#24773#22577#12434#26908#32034#12479#12502#12395#12467#12500#12540#12377#12427
          TabOrder = 3
        end
      end
      object FileTabModeCombo: TComboBox
        Left = 232
        Top = 88
        Width = 121
        Height = 20
        AutoComplete = False
        Style = csDropDownList
        ItemHeight = 12
        TabOrder = 1
        OnChange = FileTabModeComboChange
        Items.Strings = (
          #12508#12479#12531
          #12501#12521#12483#12488#12508#12479#12531
          #12479#12502)
      end
      object KeepSearchHistoryCheck: TCheckBox
        Left = 44
        Top = 324
        Width = 337
        Height = 17
        Caption = #12501#12449#12452#12523#26908#32034#26178#12395#26908#32034#23653#27508#12398#38918#30058#12434#22793#12360#12394#12356#12391#21336#32020#36861#21152#12377#12427
        TabOrder = 3
      end
    end
    object BbsSheet: TTabSheet
      Caption = 'BBS'#25805#20316
      ImageIndex = 4
      object Label16: TLabel
        Left = 20
        Top = 20
        Width = 107
        Height = 12
        Caption = 'BBS'#38306#36899#12398#25805#20316#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label25: TLabel
        Left = 72
        Top = 84
        Width = 185
        Height = 20
        Alignment = taRightJustify
        AutoSize = False
        Caption = #12473#12524#12483#12489#12479#12452#12488#12523#12479#12502#12398#34920#31034#26041#24335
        Layout = tlCenter
      end
      object Label26: TLabel
        Left = 84
        Top = 112
        Width = 171
        Height = 20
        Alignment = taRightJustify
        AutoSize = False
        Caption = #12473#12524#12483#12489#20869#23481#12479#12502#12398#34920#31034#26041#24335
        Layout = tlCenter
      end
      object BbsOnlyCheckBox: TCheckBox
        Left = 36
        Top = 56
        Width = 181
        Height = 21
        Caption = 'BBS'#23554#29992#12398#12494#12540#12489#12395#35373#23450#12377#12427
        TabOrder = 0
      end
      object BbsClickGroupBox: TGroupBox
        Left = 36
        Top = 140
        Width = 413
        Height = 133
        Caption = 'BBS'#12463#12522#12483#12463#21205#20316
        TabOrder = 3
        object Label18: TLabel
          Left = 16
          Top = 24
          Width = 201
          Height = 21
          Alignment = taRightJustify
          AutoSize = False
          Caption = #26495#12484#12522#12540#12471#12531#12464#12523#12463#12522#12483#12463#26178
          Layout = tlCenter
        end
        object Label19: TLabel
          Left = 16
          Top = 48
          Width = 201
          Height = 21
          Alignment = taRightJustify
          AutoSize = False
          Caption = #26495#12484#12522#12540#12480#12502#12523#12463#12522#12483#12463#26178
          Layout = tlCenter
        end
        object Label20: TLabel
          Left = 32
          Top = 72
          Width = 185
          Height = 21
          Alignment = taRightJustify
          AutoSize = False
          Caption = #12473#12524#12483#12489#12479#12452#12488#12523#12471#12531#12464#12523#12463#12522#12483#12463#26178
          Layout = tlCenter
        end
        object Label21: TLabel
          Left = 16
          Top = 96
          Width = 201
          Height = 21
          Alignment = taRightJustify
          AutoSize = False
          Caption = #12473#12524#12483#12489#12479#12452#12488#12523#12480#12502#12523#12463#12522#12483#12463#26178
          Layout = tlCenter
        end
        object ThreadDoubleClickCombo: TComboBox
          Left = 228
          Top = 97
          Width = 169
          Height = 20
          AutoComplete = False
          Style = csDropDownList
          ItemHeight = 12
          TabOrder = 3
          Items.Strings = (
            #36984#25246#12377#12427#12384#12369
            #12473#12524#12483#12489#12434#38283#12367
            #12473#12524#12483#12489#12434#26032#12375#12367#38283#12367)
        end
        object ThreadClickCombo: TComboBox
          Left = 228
          Top = 73
          Width = 169
          Height = 20
          AutoComplete = False
          Style = csDropDownList
          ItemHeight = 12
          TabOrder = 2
          Items.Strings = (
            #36984#25246#12377#12427#12384#12369
            #12473#12524#12483#12489#12434#38283#12367
            #12473#12524#12483#12489#12434#26032#12375#12367#38283#12367)
        end
        object TreeDoubleClickCombo: TComboBox
          Left = 228
          Top = 49
          Width = 169
          Height = 20
          AutoComplete = False
          Style = csDropDownList
          ItemHeight = 12
          TabOrder = 1
          Items.Strings = (
            #36984#25246#12377#12427#12384#12369
            #26495#12434#38283#12367
            #26495#12434#26032#12375#12367#38283#12367)
        end
        object TreeClickCombo: TComboBox
          Left = 228
          Top = 25
          Width = 169
          Height = 20
          AutoComplete = False
          Style = csDropDownList
          ItemHeight = 12
          TabOrder = 0
          Items.Strings = (
            #36984#25246#12377#12427#12384#12369
            #26495#12434#38283#12367
            #26495#12434#26032#12375#12367#38283#12367)
        end
      end
      object BoardTabModeCombo: TComboBox
        Left = 276
        Top = 84
        Width = 125
        Height = 20
        AutoComplete = False
        Style = csDropDownList
        ItemHeight = 12
        TabOrder = 1
        OnChange = BoardTabModeComboChange
        Items.Strings = (
          #12508#12479#12531
          #12501#12521#12483#12488#12508#12479#12531
          #12479#12502)
      end
      object BbsTabModeCombo: TComboBox
        Left = 276
        Top = 112
        Width = 125
        Height = 20
        AutoComplete = False
        Style = csDropDownList
        ItemHeight = 12
        TabOrder = 2
        OnChange = BbsTabModeComboChange
        Items.Strings = (
          #12508#12479#12531
          #12501#12521#12483#12488#12508#12479#12531
          #12479#12502)
      end
    end
    object FileColorSheet: TTabSheet
      Caption = #12501#12449#12452#12523#37197#33394
      ImageIndex = 5
      DesignSize = (
        497
        398)
      object Label11: TLabel
        Left = 20
        Top = 20
        Width = 125
        Height = 12
        Caption = #12501#12449#12452#12523#20849#26377#20596#12398#33394#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object StaticText2: TStaticText
        Left = 22
        Top = 60
        Width = 110
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #12484#12540#12523#12496#12540#12398#32972#26223#33394
        TabOrder = 5
      end
      object StaticText5: TStaticText
        Left = 22
        Top = 88
        Width = 100
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #26908#32034#12496#12540#12398#32972#26223#33394
        TabOrder = 6
      end
      object ToolbarColorBox: TColorBox
        Left = 144
        Top = 56
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = cl3DDkShadow
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 0
        OnChange = ToolbarColorBoxChange
      end
      object SearchBarColorBox: TColorBox
        Left = 144
        Top = 84
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = cl3DDkShadow
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 2
        OnChange = ToolbarColorBoxChange
      end
      object StaticText3: TStaticText
        Left = 290
        Top = 60
        Width = 40
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #25991#23383#33394
        TabOrder = 7
      end
      object StaticText6: TStaticText
        Left = 290
        Top = 88
        Width = 40
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #25991#23383#33394
        TabOrder = 8
      end
      object ToolStringColorBox: TColorBox
        Left = 340
        Top = 56
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = clWhite
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 1
        OnChange = ToolbarColorBoxChange
      end
      object SearchStringColorBox: TColorBox
        Left = 340
        Top = 84
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = clWhite
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 3
        OnChange = ToolbarColorBoxChange
      end
      object CacheVersionCheck: TCheckBox
        Left = 40
        Top = 364
        Width = 301
        Height = 17
        Caption = #12461#12515#12483#12471#12517#12496#12540#12472#12519#12531#12391#12501#12449#12452#12523#21517#12398#33394#12434#22793#12360#12390#34920#31034
        TabOrder = 12
      end
      object GroupBox1: TGroupBox
        Left = 28
        Top = 184
        Width = 437
        Height = 165
        Caption = #12501#12449#12452#12523#12499#12517#12540#12398#33394#35373#23450
        TabOrder = 11
        DesignSize = (
          437
          165)
        object Label14: TLabel
          Left = 16
          Top = 77
          Width = 45
          Height = 12
          Caption = #33394#12398#28611#12373
        end
        object WindowColorBox: TColorBox
          Left = 76
          Top = 35
          Width = 141
          Height = 22
          DefaultColorColor = clWindowText
          Selected = clWhite
          Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
          BevelInner = bvNone
          ItemHeight = 16
          TabOrder = 0
          OnChange = WindowColorBoxChange
        end
        object ListFontButton: TButton
          Left = 248
          Top = 36
          Width = 125
          Height = 25
          Caption = #12501#12457#12531#12488#35373#23450
          TabOrder = 1
          OnClick = ListFontButtonClick
        end
        object ColorTrackBar: TTrackBar
          Left = 72
          Top = 64
          Width = 149
          Height = 41
          Max = 8
          Min = 1
          Orientation = trHorizontal
          Frequency = 1
          Position = 3
          SelEnd = 0
          SelStart = 0
          TabOrder = 2
          TickMarks = tmTopLeft
          TickStyle = tsAuto
          OnChange = ColorTrackBarChange
        end
        object WhiteColorButton: TButton
          Left = 64
          Top = 116
          Width = 165
          Height = 29
          Caption = #32972#26223#12434#30333#31995#12395#32113#19968
          TabOrder = 3
          OnClick = WhiteColorButtonClick
        end
        object BlackColorButton: TButton
          Left = 240
          Top = 116
          Width = 165
          Height = 29
          Caption = #32972#26223#12434#40658#31995#12395#32113#19968
          TabOrder = 4
          OnClick = BlackColorButtonClick
        end
        object StaticText1: TStaticText
          Left = 20
          Top = 41
          Width = 40
          Height = 16
          Alignment = taRightJustify
          Anchors = [akTop, akRight]
          Caption = #32972#26223#33394
          TabOrder = 5
        end
      end
      object FlatToolBarCheck: TCheckBox
        Left = 32
        Top = 148
        Width = 201
        Height = 17
        Caption = #12484#12540#12523#12496#12540#12434#12501#12521#12483#12488#12508#12479#12531#12395#12377#12427
        TabOrder = 9
        OnClick = FlatToolBarCheckClick
      end
      object TransparentToolBarCheck: TCheckBox
        Left = 244
        Top = 148
        Width = 229
        Height = 17
        Caption = #12484#12540#12523#12496#12540#12434#36879#26126#12508#12479#12531#12395#12377#12427
        TabOrder = 10
        OnClick = FlatToolBarCheckClick
      end
      object StaticText11: TStaticText
        Left = 200
        Top = 117
        Width = 130
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #36890#20449#12473#12486#12540#12479#12473#12398#25991#23383#33394
        TabOrder = 13
      end
      object SubStatusColorBox: TColorBox
        Left = 340
        Top = 111
        Width = 141
        Height = 22
        DefaultColorColor = clWindowText
        Selected = clWhite
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 4
        OnChange = ToolbarColorBoxChange
      end
    end
    object BbsColorSheet: TTabSheet
      Caption = 'BBS'#37197#33394
      ImageIndex = 6
      DesignSize = (
        497
        398)
      object Label15: TLabel
        Left = 20
        Top = 20
        Width = 83
        Height = 12
        Caption = 'BBS'#20596#12398#33394#35373#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Label29: TLabel
        Left = 40
        Top = 360
        Width = 195
        Height = 12
        Caption = 'BBS'#34920#31034#34892#38291#12398#12473#12506#12540#12473#37327#65288#12500#12463#12475#12523#65289
      end
      object StaticText7: TStaticText
        Left = 22
        Top = 60
        Width = 110
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #12484#12540#12523#12496#12540#12398#32972#26223#33394
        TabOrder = 4
      end
      object StaticText10: TStaticText
        Left = 22
        Top = 92
        Width = 100
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #26908#32034#12496#12540#12398#32972#26223#33394
        TabOrder = 5
      end
      object BbsToolbarColorBox: TColorBox
        Left = 144
        Top = 56
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = cl3DDkShadow
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 0
        OnChange = ToolbarColorBoxChange
      end
      object BbsSearchBarColorBox: TColorBox
        Left = 144
        Top = 88
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = cl3DDkShadow
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 2
        OnChange = ToolbarColorBoxChange
      end
      object StaticText8: TStaticText
        Left = 290
        Top = 60
        Width = 40
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #25991#23383#33394
        TabOrder = 6
      end
      object StaticText9: TStaticText
        Left = 290
        Top = 92
        Width = 40
        Height = 16
        Alignment = taRightJustify
        Anchors = [akTop, akRight]
        Caption = #25991#23383#33394
        TabOrder = 7
      end
      object BbsToolStringColorBox: TColorBox
        Left = 340
        Top = 56
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = clWhite
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 1
        OnChange = ToolbarColorBoxChange
      end
      object BbsSearchStringColorBox: TColorBox
        Left = 340
        Top = 88
        Width = 141
        Height = 22
        DefaultColorColor = cl3DDkShadow
        Selected = clWhite
        Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
        BevelInner = bvNone
        ItemHeight = 16
        TabOrder = 3
        OnChange = ToolbarColorBoxChange
      end
      object GroupBox2: TGroupBox
        Left = 28
        Top = 164
        Width = 437
        Height = 181
        Caption = 'BBS'#12499#12517#12540#12398#33394#35373#23450
        TabOrder = 10
        DesignSize = (
          437
          181)
        object Label22: TLabel
          Left = 24
          Top = 85
          Width = 45
          Height = 12
          Caption = #33394#12398#28611#12373
        end
        object StaticText4: TStaticText
          Left = 21
          Top = 44
          Width = 40
          Height = 16
          Alignment = taRightJustify
          Anchors = [akTop, akRight]
          Caption = #32972#26223#33394
          TabOrder = 0
        end
        object BbsWindowColorBox: TColorBox
          Left = 80
          Top = 40
          Width = 141
          Height = 22
          DefaultColorColor = clWindowText
          Selected = clWhite
          Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbCustomColor, cbPrettyNames]
          BevelInner = bvNone
          ItemHeight = 16
          TabOrder = 1
          OnChange = BbsWindowColorBoxChange
        end
        object BoardFontButton: TButton
          Left = 228
          Top = 40
          Width = 181
          Height = 25
          Caption = #12473#12524#12483#12489#12479#12452#12488#12523#12501#12457#12531#12488#35373#23450
          TabOrder = 2
          OnClick = BoardFontButtonClick
        end
        object BbsFontButton: TButton
          Left = 228
          Top = 76
          Width = 181
          Height = 25
          Caption = #12473#12524#12483#12489#20869#23481#34920#31034#12501#12457#12531#12488#35373#23450
          TabOrder = 4
          OnClick = BbsFontButtonClick
        end
        object BbsColorTrackBar: TTrackBar
          Left = 72
          Top = 72
          Width = 149
          Height = 41
          Max = 8
          Min = 1
          Orientation = trHorizontal
          Frequency = 1
          Position = 3
          SelEnd = 0
          SelStart = 0
          TabOrder = 3
          TickMarks = tmTopLeft
          TickStyle = tsAuto
          OnChange = BbsColorTrackBarChange
        end
        object BbsWhiteColorButton: TButton
          Left = 56
          Top = 128
          Width = 165
          Height = 29
          Caption = 'BBS'#32972#26223#12434#30333#31995#12395#32113#19968
          TabOrder = 5
          OnClick = BbsWhiteColorButtonClick
        end
        object BbsBlackColorButton: TButton
          Left = 228
          Top = 128
          Width = 165
          Height = 29
          Caption = 'BBS'#32972#26223#12434#40658#31995#12395#32113#19968
          TabOrder = 6
          OnClick = BbsBlackColorButtonClick
        end
      end
      object BbsFlatToolBarCheck: TCheckBox
        Left = 32
        Top = 128
        Width = 201
        Height = 17
        Caption = #12484#12540#12523#12496#12540#12434#12501#12521#12483#12488#12508#12479#12531#12395#12377#12427
        TabOrder = 8
        OnClick = FlatToolBarCheckClick
      end
      object BbsTransparentToolBarCheck: TCheckBox
        Left = 244
        Top = 128
        Width = 229
        Height = 17
        Caption = #12484#12540#12523#12496#12540#12434#36879#26126#12508#12479#12531#12395#12377#12427
        TabOrder = 9
        OnClick = FlatToolBarCheckClick
      end
      object BbsInterLineSpaceEdit: TEdit
        Left = 272
        Top = 356
        Width = 133
        Height = 20
        TabOrder = 11
      end
    end
  end
  object FontDialog: TFontDialog
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Options = [fdEffects, fdNoStyleSel]
    Left = 20
    Top = 444
  end
end
