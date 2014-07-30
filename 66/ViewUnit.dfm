object ViewForm: TViewForm
  Left = 166
  Top = 153
  Width = 553
  Height = 452
  BorderIcons = [biSystemMenu]
  Caption = #12461#12515#12483#12471#12517#12504#12483#12480#34920#31034
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnHide = FormHide
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    545
    425)
  PixelsPerInch = 96
  TextHeight = 12
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 530
    Height = 367
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvLowered
    TabOrder = 0
    object ViewGrid: TStringGrid
      Left = 1
      Top = 1
      Width = 528
      Height = 365
      Align = alClient
      BorderStyle = bsNone
      ColCount = 2
      DefaultColWidth = 50
      DefaultRowHeight = 16
      RowCount = 1025
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Options = [goFixedVertLine, goRangeSelect]
      ParentFont = False
      TabOrder = 0
    end
  end
  object CancelButton: TButton
    Left = 459
    Top = 383
    Width = 76
    Height = 27
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = #38281#12376#12427'(&C)'
    TabOrder = 3
    OnClick = CancelButtonClick
  end
  object RefreshButton: TButton
    Left = 379
    Top = 383
    Width = 76
    Height = 27
    Anchors = [akRight, akBottom]
    Caption = #20877#34920#31034'(&R)'
    Default = True
    TabOrder = 2
    OnClick = RefreshButtonClick
  end
  object TitleEdit: TMemo
    Left = 12
    Top = 381
    Width = 283
    Height = 29
    Anchors = [akLeft, akRight, akBottom]
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 1
  end
  object IgnoreButton: TButton
    Left = 299
    Top = 383
    Width = 76
    Height = 27
    Anchors = [akRight, akBottom]
    Caption = #28961#35222#30331#37682'(&I)'
    Default = True
    TabOrder = 4
    OnClick = IgnoreButtonClick
  end
end
