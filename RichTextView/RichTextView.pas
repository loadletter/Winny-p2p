unit RichTextView;
(* version 1.6 mod *)
(* version 0.0.5 *)
(* Copyright (C) 2002 Twiddle <hetareprog@hotmail.com> *)
(*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the author be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose
  and to alter it and redistribute it freely.
 *)

interface

uses
  Windows,
  Messages,
  SysUtils,
  Classes,
  Controls,
  Graphics,
  Clipbrd;

type
  (*-------------------------------------------------------*)
  TRichAttribute = 0..31;

  TRichTextView = class;

  (*-------------------------------------------------------*)
  TRichPosition = record
	position: Integer;
	size    : Integer;
  end;

  (*-------------------------------------------------------*)
  TRichTVItem = class(TObject)
  private
	FOffsetLeft: Integer;
	FView: TRichTextView;
	FCharWidth: AnsiString;
	FLogicalLines: Integer;

	procedure CalcCharWidth;
	function GetCharWidth(index: Integer): Integer;
	function GetLogicalLines: Integer;

  public
    FText:   AnsiString;
    FAttrib: AnsiString;

    constructor Create(view: TRichTextView);
    destructor Destroy; override;
    function GetLength: Integer;
    function GetWidthInfo: string;

    function IndexToLogicalPos(index: Integer): TPoint;
    function LogicalPosToIndex(var point: TPoint): Integer;
    function StartsWith(const AString: String; Index: Integer;
                        var matchEnd: Integer): Boolean;

    procedure Insert(index: Integer;
                     str: PChar;
                     cbStr: Integer;
                     attrib: Integer = 0);
    procedure Add(str: PChar;
				  cbStr: Integer;
                  attrib: Integer = 0);

    procedure FontChanged;
    function HasEmbed(index: Integer): Boolean;
	function SkipToEmbed(index: Integer): Integer;
    function FetchEmbed(index: Integer): TRichPosition;
    function GetEmbed(index: Integer): String;
    property OffsetLeft: Integer read FOffsetLeft write FOffsetLeft;
    property CharWidth[index: integer]: Integer read GetCharWidth;
    property LogicalLines: Integer read GetLogicalLines write FLogicalLines;
  end;

  (*-------------------------------------------------------*)
  TRichTVItems = class(TList)
  private
    FParent: TRichTextView;
  protected
    function GetItem(index: Integer): TRichTVitem;
    procedure SetItem(index: Integer; item: TRichTVItem);
  public
    constructor Create(parent: TRichTextView);
    destructor Destroy; override;
    procedure Clear; override;
    procedure Add(Item: Pointer); overload;
    function GetLogicalLines: Integer;

    property Items[index: Integer]: TRichTVitem read GetItem write SetItem; default;
  end;

  (*-------------------------------------------------------*)
  TRichTextAttrib = record
	color: TColor;
	style: TFontStyles;
  end;
  TRichCharWidthTable = record
	Ascii_1 : array[$00..$80] of Byte;
	MB_1    : array[$81..$9F, $00..$FF] of Byte; // $40..$EC, of cource.
	Ascii_2 : array[$A0..$DF] of Byte;
	MB_2    : array[$E0..$FC, $00..$FF] of Byte; // $40..$EC
	Ascii_3 : array[$FD..$FF] of Byte;
  end;
  (*-------------------------------------------------------*)
  TRichTextView = class(TCustomControl)
  private
    { Private éŒ¾ }
	FCharWidthTable: TRichCharWidthTable;
    FBCharWidthTable: TRichCharWidthTable;
  protected
    { Protected éŒ¾ }
    FLeftMargin: Integer;
    FTopMargin: Integer;
    FRightMargin: Integer;
    FExternalLeading: Integer;

    FStrings: TRichTVItems;

    FTopLine: Integer;
    FTopLineOffset: Integer;
    FLogicalTopLine: Integer;
    FBottomLine: Integer;
    FVisibleLines: Integer;

    FVerticalCaretMargin: Integer;
    FVScrollLines: Integer;
    FWheelPageScroll: boolean;

    FCaretPos: TPoint;     (* Client-coordinates *)
    FEditPoint: TPoint;    (* physical line and column *)
    FLogicalCaret: TPoint; (* logical line and client X-coordinate *)
    FCaretSavedX: Integer; (* client X-coordinate *)
    FCaretVisible: Boolean;
    FConfCaretVisible: Boolean; //521

    FSelecting: Boolean;
    FDragging: Boolean;
    FSelStart: TPoint;

    FBitmap: TBitmap;
    FBoldWidthModifier: Integer;

    function CharWidth(p: PChar; attrib: Integer): Integer;

    function BaselineSkip: Integer;
    procedure UpdateVisibleLines;
    function TopForBottom: Integer;
    function GetMargin: Integer;
	function CalcLogicalLine(line, offset: Integer): Integer;

    procedure ModifyLogicalLine(var logicalLine, physicalLine, offset: Integer);
    function  Normalize(point: TPoint): TPoint;
    procedure LogicalNormalize(var logical, physical: TPoint);

    procedure UpdateScreenCaret;
    procedure ScrollToViewCaret(Center: Boolean = False);
    function PhysicalToClient(X, Y: integer): TPoint;

	function NormalizeMinMax(point1, point2: TPoint): TRect;
    function RegionToText(point1, point2: TPoint): string;

    procedure UpdateScrollInfo(redraw: Boolean = True);
    procedure LineUpdated(startLine, endLine: Integer);
    procedure CaretVisible(visibleP: boolean);
    procedure SetSelecting(selectP: boolean);
    procedure SetConfCaretVisible(visibleP: boolean);

    function  RangeVisible(startPos, endPos: TPoint): Boolean;
    procedure InvalidateSize;
    procedure UpdateBottomLine;

    procedure ON_WM_CREATE(var msg: TMsg); message WM_CREATE;
    procedure ON_WM_GETDLGCODE(var msg: TMessage); message WM_GETDLGCODE;
    procedure ON_WM_SIZE(var msg: TMessage); message WM_SIZE;
    procedure DoSize(newWidth, newHeight: Integer);

    procedure ON_WM_SETFOCUS (var msg: TMsg); message WM_SETFOCUS;
    procedure ON_WM_KILLFOCUS(var msg: TMsg); message WM_KILLFOCUS;

    procedure ON_WM_MOUSEACTIVATE(var msg: TWMMouse); message WM_MOUSEACTIVATE;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState;
                        X, Y: Integer); override;
    procedure MouseUp  (Button: TMouseButton; Shift: TShiftState;
                        X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;

    procedure ON_WM_MOUSEWHEEL   (var msg: TMessage); message WM_MOUSEWHEEL;

    procedure KeyDown(var Key: Word; Shift: TShiftState); override;

    procedure ON_WM_HSCROLL(var msg: TMessage); message WM_HSCROLL;
    procedure ON_WM_VSCROLL(var msg: TMessage); message WM_VSCROLL;

    procedure ON_WM_PAINT(var msg: TWMPaint); message WM_PAINT;
    procedure PaintWindow(DC: HDC); override;
  public
    { Public éŒ¾ }
    TextAttrib: array[TRichAttribute] of TRichTextAttrib;

	constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure Clear;

    function  PhysicalToLogical(point: TPoint): TPoint;
    function  LogicalToPhysical(point: TPoint): TPoint;
    function  ClientToPhysicalCharPos(X, Y: integer): TPoint;
    function  ClientToLogical(X, Y: integer): TPoint;

    procedure SetPhysicalCaret(X, Y: integer; opt: Integer = 0); overload;
    procedure SetPhysicalCaret(point: TPoint; opt: Integer = 0); overload;
    procedure SetLogicalCaret(point: TPoint; opt: Integer = 0); overload;
    procedure SetLogicalCaret(X, Y: integer; opt: Integer = 0); overload;

    function InSelection(X, Y: integer): Boolean;

    procedure ForwardLine(advance: integer);
    procedure ForwardChar(advance: integer);
    procedure BeginningOfLine;
    procedure EndOfLine;
    procedure BeginningOfBuffer;
    procedure EndOfBuffer;
    procedure PageDown;
    procedure PageUp;
    procedure SetTop(line: integer);
    procedure ScrollLine(advance: integer);
    procedure CopySelection;
    function  GetSelection: String;
    function  SearchForward (const AString: String): Boolean;
    function  SearchBackward(const AString: String): Boolean;
	procedure SetMarkCommand;

    function  Insert(point: TPoint;
                     const AString: string;
                     attrib: Integer = 0): TPoint;
    function  nInsert(point: TPoint;
                      pstr: PChar;
                      count: Integer;
                      attrib: Integer = 0): TPoint;
    function  Append(const AString: string;
                     attrib: Integer = 0): TPoint;
    function  nAppend(pstr: PChar;
                      count: Integer;
                      attrib: Integer = 0): TPoint;

    procedure SetFont(FaceName: String; Size: Integer);

    property Strings: TRichTVItems read FStrings;
    property TopLine: Integer read FTopLine;
    property LogicalTopLine: Integer read FLogicalTopLine;

    property Selection: String read GetSelection;
    property Caret: TPoint read FEditPoint stored False;
    property LogicalCaret: TPoint read FLogicalCaret;
    property VisibleLines: Integer read FVisibleLines;

  published
    { Published éŒ¾ }
    property LeftMargin: Integer read FLeftMargin write FLeftMargin;
    property TopMargin : Integer read FTopMargin  write FTopMargin;
    property RightMargin: Integer read FRightMargin write FRightMargin;
    property ExternalLeading: Integer read FExternalLeading write FExternalLeading;
    property VerticalCaretMargin: Integer read FVerticalCaretMargin write FVerticalCaretMargin;
    property VScrollLines: Integer read FVScrollLines write FVScrollLines default 3;
    property Selecting: Boolean read FSelecting write SetSelecting stored False;
    property WheelPageScroll: boolean read FWheelPageScroll write FWheelPageScroll;
    property ConfCaretVisible: boolean read FConfCaretVisible write SetConfCaretVisible;
    { inherited }
    property Align;
    property Color;
    property Cursor default crIBeam;
	property Font;
    property Enabled;
    property TabStop;
    property Visible;

    property OnKeyDown;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property PopupMenu;
  end;
  (*-------------------------------------------------------*)

procedure Register;

const
  htvATTMASK  = $1F;

  htvASCII    = $00;
  htvUNICODE  = $40;
  htvCODEMASK = $40;

  htvVISIBLE  = $00;
  htvHIDDEN   = $80;
  htvVMASK    = $80;

  htvUSER     = $20;
  htvUSERMASK = $20;


  hscDONTSAVEX    = $01;
  hscDONTSCROLL   = $02;
  hscSCROLLCENTER = $04;

(*=======================================================*)
implementation
(*=======================================================*)


{$B-}
{$DEFINE IBEAM=1}



procedure Register;
begin
  RegisterComponents('Samples', [TRichTextView]);
end;


(*=======================================================*)

(*=======================================================*)
constructor TRichTVItem.Create(view: TRichTextView);
begin
  inherited Create;
  FOffsetLeft := 0;
  FView := view;
end;

destructor TRichTVItem.Destroy;
begin
  SetLength(FText, 0);
  SetLength(FAttrib, 0);
  SetLength(FCharWidth, 0);
  inherited;
end;

function TRichTVItem.GetLength: Integer;
begin
  result := length(FText);
end;


procedure TRichTVItem.Insert(index: Integer;
                             str: PChar;
                             cbStr: integer;
                             attrib: Integer = 0);
var
  orgLen, insLen, size: integer;
begin
  insLen := cbStr;
  orgLen := length(FText);
  if index <= 0 then
    index := 1
{  else if orgLen < index then }
  else if orgLen <= index then
    index := orgLen + 1;
  size := orgLen + insLen;

  SetLength(FText, size);
  SetLength(FAttrib, size);
  if index <= orgLen then
  begin
    Move(FText[index], FText[index + insLen], orgLen - index +1);
    Move(FAttrib[index], FAttrib[index + insLen], orgLen - index +1);
  end;
  Move(str^, FText[index], insLen);
  FillChar(FAttrib[index], insLen, attrib);
end;

procedure TRichTVItem.Add(str: PChar;
                          cbStr: Integer;
                          attrib: Integer = 0);
begin
  Insert(length(FText), str, cbStr, attrib);
end;


procedure TRichTVItem.CalcCharWidth;
var
  attCode: Integer;
  i, len: integer;
  secondByte: Boolean;
begin
  len := length(FText);
  SetLength(FCharWidth, len);
  if len <= 0 then
    exit;

  secondByte := False;
  for i := 1 to len do
  begin
    attCode := Ord(FAttrib[i]);
	if secondByte then
    begin
      secondByte := False;
      FCharWidth[i] := #0;
    end
    else if attCode and htvVMASK = htvHIDDEN then
      FCharWidth[i] := #0
    else begin
      if attCode and htvCODEMASK = htvUNICODE then
        secondByte := True
      else if FText[i] in LeadBytes then
        secondByte := True;
      FCharWidth[i] := Chr(FView.CharWidth(@FText[i], Ord(FAttrib[i])));
    end;
  end;
end;

function TRichTVItem.GetCharWidth(index: Integer): Integer;
begin
  if length(FCharWidth) <> length(FText) then
  begin
    CalcCharWidth;
    FLogicalLines := 0;
  end;
  result := Ord(FCharWidth[index]);
end;

function TRichTVItem.GetWidthInfo: string;
begin
  if length(FCharWidth) <> length(FText) then
  begin
    CalcCharWidth;
    FLogicalLines := 0;
  end;
  result := FCharWidth;
end;

function TRichTVItem.GetLogicalLines: Integer;
begin
  if FLogicalLines <= 0 then
    FLogicalLines := IndexToLogicalPos(High(integer)).Y + 1;
  result := FLogicalLines;
end;

function TRichTVItem.IndexToLogicalPos(index: Integer): TPoint;
var
  i, len: integer;
  cw: AnsiString;
  nchars, width, maxWidth: integer;
begin
  cw := GetWidthInfo;
  len := length(cw);
  nchars := 0;
  maxWidth := FView.ClientWidth - FView.RightMargin;
  result.X := FView.LeftMargin + FOffsetLeft;
  result.Y := 0;
  for i := 1 to len do
  begin
    width := Ord(cw[i]);
    if width <> 0 then
    begin
      Inc(nchars);
      if (maxWidth < result.X + width) and (1 < nchars) then
      begin
        Inc(result.Y);
        nchars := 0;
        result.X := FView.LeftMargin + FOffsetLeft;
        if index <= i then
          exit;
      end;
      if index <= i then
        exit;
      Inc(result.X, width);
    end;
  end;
end;

function TRichTVItem.LogicalPosToIndex(var point: TPoint): Integer;
var
  len, index, line: integer;
  cw: AnsiString;
  nchars, width, maxWidth: integer;
begin
  cw := GetWidthInfo;
  len := length(cw);
  nchars := 0;
  maxWidth := FView.ClientWidth - FView.RightMargin;
  width := FView.LeftMargin + FOffsetLeft;
  if point.X < width then
    point.X := width;
  if point.Y < 0 then
    point.Y := 0
  else begin
    line := LogicalLines;
    if line <= point.Y then
      point.Y := line - 1;
  end;
  line := 0;
  for index := 1 to len do
  begin
    if cw[index] <> #0 then
    begin
      if (point.Y <= line) and (point.X <= width + (Ord(cw[index]) div 2)) then
      begin
        point.X := width;
        result := index;
        exit;
      end;
      Inc(nchars);
      if (1 < nchars) and (maxWidth < width + Ord(cw[index])) then
      begin
        if point.Y <= line then
        begin
          point.X := width;
          result := index;
          exit;
        end;
        Inc(line);
        nchars := 0;
        width := FView.LeftMargin + FOffsetLeft;
        if (point.Y <= line) and (point.X <= width) then
        begin
          point.X := width;
		  result := index;
          exit;
        end;
      end;
      Inc(width, Ord(cw[index]));
    end;
  end;
  point.X := width;
  result := len + 1;
end;


function TRichTVItem.StartsWith(const AString: String; Index: Integer;
                                var matchEnd: Integer): Boolean;
var
  bufIndex, bufEnd: Integer;
  tgtIndex, tgtEnd: Integer;
  cw: AnsiString;
begin
  result := False;
  bufEnd := length(FText);
  tgtIndex := 1;
  tgtEnd := length(AString);
  if tgtEnd <= 0 then
    exit;
  cw := GetWidthInfo;
  for bufIndex := Index to bufEnd do
  begin
    if (Ord(FAttrib[bufIndex]) and htvVMASK = htvVISIBLE) then
    begin
      if (tgtEnd < tgtIndex) and (cw[bufIndex] <> #0) then
      begin
        matchEnd := bufIndex;
        result := True;
        exit;
      end;
      if cw[bufIndex] <> #0 then
      begin
        if AString[tgtIndex] <> UpCase(FText[bufIndex]) then
          exit;
      end
	  else begin
        if AString[tgtIndex] <> FText[bufIndex] then
          exit;
      end;
      Inc(tgtIndex);
    end;
  end;
  result := (tgtEnd < tgtIndex);
  if result then
    matchEnd := bufEnd + 1;
end;

procedure TRichTVitem.FontChanged;
begin
  FLogicalLines := 0;
  CalcCharWidth;
end;

function TRichTVitem.HasEmbed(index: Integer): Boolean;
begin
  result := (index <= GetLength) and
            (Ord(FAttrib[index]) and htvUSERMASK = htvUSER);
end;

function TRichTVItem.SkipToEmbed(index: Integer): Integer;
var
  i, len: integer;
begin
  result := -1;
  len := GetLength;
  for i := index to len do
  begin
    if (Ord(FAttrib[i]) and htvUSERMASK) <> htvUSER then
    begin
{      if (Ord(FAttrib[i]) and htvVMASK) = htvHIDDEN then}
        result := i;
      exit;
    end;
  end;
end;

function TRichTVItem.FetchEmbed(index: Integer): TRichPosition;
var
  i, len: integer;
{  unknown: Integer;}
  attCode: integer;


begin
  result.position := index;
  result.size := 0;
  len := length(FAttrib);
  if len < index then
	exit;
  attCode := Ord(FAttrib[index]);

{  unknown:=Ord(FAttrib[index]);
  while (result.position>0) and (unknown<Ord(FAttrib[result.position-1])) do
	Dec(result.position);}

  while (result.position>0) and (attCode{Ord(FAttrib[index])}=Ord(FAttrib[result.position-1])) do
	Dec(result.position);


{  for i := index to len do }
{  for i := index to result.position do}
  for i := result.position to len do
  begin
    if Ord(FAttrib[i]) = attCode then
      Inc(result.size)
    else
      break;
  end;
end;

function TRichTVItem.GetEmbed(index: Integer): String;
var
  posInfo: TRichPosition;
begin
  result := '';
  if HasEmbed(index) then
  begin
{    index := SkipToEmbed(index);
    if 0 < index then
    begin}
      posInfo := FetchEmbed(index);
      result := Copy(FText, posInfo.position, posInfo.size);
{    end;}
  end;
end;

(*=======================================================*)
constructor TRichTVItems.Create(parent: TRichTextView);
begin
  inherited Create;
  FParent := parent;
end;

destructor TRichTVItems.Destroy;
begin
  Clear;
  inherited;
end;

procedure TRichTVItems.Clear;
var
  i: integer;
begin
  for i := 0 to Count -1 do
    Items[i].Free;
  inherited;
end;

function TRichTVItems.GetItem(index: Integer): TRichTVitem;
begin
  result := inherited Items[index];
end;

procedure TRichTVItems.SetItem(index: Integer; item: TRichTVItem);
begin
  inherited Items[index] := item;
end;

procedure TRichTVItems.Add(Item: Pointer);
begin
  inherited Add(Item);
end;

function TRichTVItems.GetLogicalLines: Integer;
var
  line: integer;
begin
  result := 0;
  for line := 0 to Count -1 do
    Inc(result, Items[line].LogicalLines);
end;

(*=======================================================*)
(*=======================================================*)
constructor TRichTextView.Create(AOwner: TComponent);
  procedure InitializeAttrib;
  var
    i: integer;
  begin
    for i := 0 to SizeOf(TextAttrib) div SizeOf(TRichTextAttrib) -1 do
    begin
      with TextAttrib[i] do
      begin
        color := Font.Color;
        style := Font.Style;
      end;
    end;
  end;

  procedure CalcWidthModifier;
  var
    wM, wN, wMN: Integer;
    style: TFontStyles;
  begin
    style := FBitmap.Canvas.Font.Style;
    FBitmap.Canvas.Font.Style := [fsBold];
    wM  := FBitmap.Canvas.TextWidth('M');
    wN  := FBitmap.Canvas.TextWidth('N');
    wMN := FBitmap.Canvas.TextWidth('MN');
    FBoldWidthModifier := wMN - (wM + wN);
    FBitmap.Canvas.Font.Style := style;
  end;
var
  item: TRichTVItem;
begin
  FBitmap := TBitmap.Create;

  FillChar(FCharWidthTable,  SizeOf(FCharWidthTable),  0);
  FillChar(FBCharWidthTable, SizeOf(FBCharWidthTable), 0);

  inherited Create(AOwner);
  FCaretPos.x := FLeftMargin;
  FCaretPos.y := FTopMargin;
  FStrings := TRichTVItems.Create(Self);
  FTopLine := 0;
  FBottomLine := 0;
  FVisibleLines := 1;
  if FVScrollLines <= 0 then
    FVScrollLines := 3;
  FWheelPageScroll := false;

  DoubleBuffered := True;
  ParentColor    := False;
  FEditPoint.X := 0;
  FEditPoint.Y := 0;
  FLogicalCaret.X := 0;
  FLogicalCaret.Y := 0;
  FCaretSavedX := 0;
  FCaretVisible := False;

  FSelecting := False;
  FDragging  := False;
  FSelStart.X := 0;
  FSelStart.Y := 0;

  CalcWidthModifier;

  InitializeAttrib;
  item := TRichTVItem.Create(Self);
  FStrings.Add(item);

  Cursor := crIBeam;
end;

destructor TRichTextView.Destroy;
begin
  FStrings.Free;
  FBitmap.Free;
  inherited;
end;

function TRichTextView.BaselineSkip: Integer;
begin
  result := Abs(Font.Height) + FExternalLeading;
end;

procedure TRichTextView.UpdateVisibleLines;
begin
  FVisibleLines := (ClientRect.Bottom - FTopMargin) div BaselineSkip + 1;
  if FVisibleLines < 0 then
    FVisibleLines := 0;
end;

function TRichTextView.TopForBottom: Integer;
begin
  result := FStrings.GetLogicalLines - VisibleLines + 2;
  if result < 0 then
    result := 0;
end;

function TRichTextView.GetMargin: Integer;
var
  vLines: Integer;
begin
  vLines := VisibleLines;
  if vLines < FVerticalCaretMargin * 2 then
    result := vLines div 2
  else
    result := FVerticalCaretMargin;
end;

function TRichTextView.CalcLogicalLine(line, offset: Integer): Integer;
var
  i: integer;
begin
  result := 0;
  for i := 0 to line do
    Inc(result, FStrings[i].LogicalLines);
  Inc(result, offset);
end;

procedure TRichTextView.ModifyLogicalLine(var logicalLine,
                                              physicalLine,
                                              offset: Integer);
var
  i, len, lines: integer;
begin
  if logicalLine < 0 then
    logicalLine := 0;
  lines := 0;
  for i := 0 to FStrings.Count -1 do
  begin
    len := FStrings[i].LogicalLines;
    if logicalLine < lines + len then
    begin
      physicalLine := i;
      offset := logicalLine - lines;
      exit;
    end;
    Inc(lines, len);
  end;
  logicalLine := lines -1;
  physicalLine := FStrings.Count -1;
  offset := FStrings[physicalLine].LogicalLines -1;
end;


function TRichTextView.Normalize(point: TPoint): TPoint;
var
  i, len: integer;
  cw: AnsiString;
begin
  if point.Y < 0 then
  begin
    result.X := 0;
    result.Y := 0;
    exit;
  end
  else if FStrings.Count <= point.Y then
  begin
    result.Y := FStrings.Count -1;
    result.X := FStrings[result.Y].GetLength;
    exit;
  end
  else
    result.Y := point.Y;
  cw := FStrings[result.Y].GetWidthInfo;
  len := length(cw);
  if len <= point.X then
    result.X := len
  else begin
    for i := 1 to len do
    begin
      if (cw[i] <> #0) and (point.X < i) then
      begin
        result.X := i - 1;
        exit;
      end;
    end;
    result.X := len;
  end;
end;

procedure TRichTextView.LogicalNormalize(var logical, physical: TPoint);
var
  offset: Integer;
  point: TPoint;
begin
  ModifyLogicalLine(logical.Y, physical.Y, offset);
  point.X := logical.X;
  point.Y := offset;
  physical.X := FStrings[physical.Y].LogicalPosToIndex(point) -1;
  logical.X := point.X;
end;

function  TRichTextView.PhysicalToLogical(point: TPoint): TPoint;
var
  line, lines: integer;
begin
  lines := 0;
  for line := 0 to point.Y -1 do
    Inc(lines, FStrings[line].GetLogicalLines);
  result := FStrings[point.Y].IndexToLogicalPos(point.X + 1);
  Inc(result.Y, lines);
end;

function  TRichTextView.LogicalToPhysical(point: TPoint): TPoint;
var
  line, offset: Integer;
begin
  ModifyLogicalLine(point.Y, line, offset);
  point.Y := offset;
  result.X := FStrings[line].LogicalPosToIndex(point) -1;
  result.Y := line;
end;

procedure TRichTextView.CaretVisible(visibleP: boolean);
begin
  if FCaretVisible = FConfCaretVisible and visibleP then
    exit;
  FCaretVisible := (FConfCaretVisible and visibleP); //521
  if GetFocus <> Handle then
    exit;
  if FCaretVisible then
  begin
    SetCaretPos(FCaretPos.x, FCaretPos.y);
    ShowCaret(Handle)
  end
  else
    HideCaret(Handle);
end;

procedure TRichTextView.SetSelecting(selectP: boolean);
begin
  if selectP <> FSelecting then
    Invalidate;
  FSelecting := selectP;
end;

procedure TRichTextView.SetConfCaretVisible(visibleP: boolean);
begin
  FConfCaretVisible := visibleP;
  if visibleP then
  begin
    SetPhysicalCaret(0, FTopLine + FVerticalCaretMargin, hscDONTSCROLL);
    SetSelecting(false);
  end;
  CaretVisible(visibleP);
end;

procedure TRichTextView.SetPhysicalCaret(X, Y: integer; opt: Integer);
var
  point: TPoint;
begin
  point.X := X;
  point.Y := Y;
  SetPhysicalCaret(point, opt);
end;

procedure TRichTextView.SetPhysicalCaret(point: TPoint; opt: Integer);
begin
  FEditPoint := Normalize(point);
  FLogicalCaret := PhysicalToLogical(FEditPoint);
  if opt and hscDONTSAVEX <> hscDONTSAVEX then
    FCaretSavedX := FLogicalCaret.X;
  if opt and hscDONTSCROLL <> hscDONTSCROLL then
    ScrollToViewCaret(opt and hscSCROLLCENTER = hscSCROLLCENTER)
  else
    UpdateScreenCaret;
  if FSelecting then
    Invalidate;
end;

procedure TRichTextView.UpdateScreenCaret;
begin
  FCaretPos.X := FLogicalCaret.X;
  FCaretPos.Y := (FLogicalCaret.Y - FLogicalTopLine) * BaselineSkip + FTopMargin;
  {$IFDEF IBEAM}
  Dec(FCaretPos.X);
  {$ENDIF}
  SetCaretPos(FCaretPos.X, FCaretPos.Y);
end;

procedure TRichTextView.SetLogicalCaret(point: TPoint; opt: Integer);
begin
  SetLogicalCaret(point.X, point.Y, opt);
end;

procedure TRichTextView.SetLogicalCaret(X, Y: integer; opt: Integer);
begin
  FLogicalCaret.X := X;
  FLogicalCaret.Y := Y;
  LogicalNormalize(FLogicalCaret, FEditPoint);
  if opt and hscDONTSAVEX <> hscDONTSAVEX then
    FCaretSavedX := X;
  if opt and hscDONTSCROLL <> hscDONTSCROLL then
  begin
    ScrollToViewCaret(opt and hscSCROLLCENTER = hscSCROLLCENTER);
  end
  else begin
    UpdateScreenCaret;
  end;
  if FSelecting then
    Invalidate;
end;

(* Scroll *)
procedure TRichTextView.ScrollToViewCaret(Center: Boolean = False);
var
  vLines: Integer;
  margin: Integer;
  oldTop: Integer;
begin
  margin := GetMargin;
  vLines := VisibleLines;
  Dec(vLines);
  if vLines < 0 then
    vLines := 0;
  oldTop := FLogicalTopLine;
  if Center then
  begin
    FLogicalTopLine := FLogicalCaret.Y - (vLines div 2);
  end;
  
  if (0 < vLines) and (FLogicalTopLine + vLines - margin -1 <= FLogicalCaret.Y) then
    FLogicalTopLine := FLogicalCaret.Y + margin - vLines + 1
  else if FLogicalCaret.Y < FLogicalTopLine + margin then
    FLogicalTopLine := FLogicalCaret.Y - margin;
  if FLogicalTopLine < 0 then
    FLogicalTopLine := 0
  else if TopForBottom < FLogicalTopLine then
    FLogicalTopLine := TopForBottom;

  ModifyLogicalLine(FLogicalTopLine, FTopLine, FTopLineOffset);
  UpdateBottomLine;
  if oldTop <> FLogicalTopLine then
    Invalidate;
  UpdateScreenCaret;
end;

function TRichTextView.PhysicalToClient(X, Y: integer): TPoint;
var
  col: integer;
  wm: string;
begin
  if Y < FStrings.Count then
  begin
    result.X := FLeftMargin + FStrings[Y].OffsetLeft;
    wm := FStrings[Y].GetWidthInfo;
    for col := 1 to X do
      Inc(result.X, Ord(wm[col]));
  end;
  result.Y := FTopMargin + (Y - FTopLine) * BaselineSkip;
end;


function TRichTextView.ClientToPhysicalCharPos(X, Y: integer): TPoint;
var
  logicalLine: integer;
  maxWidth: integer;
  point: TPoint;
  oldLine: integer;
begin
  logicalLine := ((Y - FTopMargin) div BaselineSkip) + FLogicalTopLine;
  if FStrings.GetLogicalLines <= logicalLine then
  begin
    result.Y := -1;
    result.X := -1;
    exit;
  end;
  ModifyLogicalLine(logicalLine, result.Y, point.Y);
  maxWidth := ClientWidth - RightMargin;
  if (maxWidth <= X) or (X < FLeftMargin + FStrings[result.Y].OffsetLeft) then
  begin
    result.Y := -1;
    result.X := -1;
    exit;
  end;
  point.X := X;
  oldLine := point.Y;
  result.X := FStrings[result.Y].LogicalPosToIndex(point) -1;
  if (oldLine <> point.Y) or
     (FStrings[result.Y].GetLength <= result.X) then
  begin
    result.Y := -1;
    result.X := -1;
  end;
end;

function TRichTextView.ClientToLogical(X, Y: integer): TPoint;
begin
  result.Y := (Y - FTopMargin) div BaselineSkip + FLogicalTopLine;
  result.X := X;
end;

procedure TRichTextView.ForwardLine(advance: integer);
begin
  SetLogicalCaret(FCaretSavedX, FLogicalCaret.Y + advance, hscDONTSAVEX);
end;


procedure TRichTextView.ForwardChar(advance: integer);
var
  cw: AnsiString;
  len: integer;
begin
  if advance = 0 then
    exit;
  with FEditPoint do
  begin
    cw := FStrings[Y].GetWidthInfo;
    len := length(cw);
	while 0 < advance do
    begin
      Inc(X);
      if X < len then
      begin
        if cw[X+1] <> #0 then
          Dec(advance);
      end
      else if X = len then
        Dec(advance)
      else if Y < FStrings.Count -1 then
      begin
        Dec(advance);
        Inc(Y);
        X := 0;
        cw := FStrings[Y].GetWidthInfo;
        len := length(cw);
        while (X < len) and (cw[X+1] = #0) do
          Inc(X);
      end
      else begin
        X := len;
        break;
      end;
    end;

    while advance < 0 do
    begin
      if 0 < X then
      begin
        if cw[X] <> #0 then
          Inc(advance);
        Dec(X);
      end
      else if 0 < Y then
      begin
        Inc(advance);
        Dec(Y);
        cw := FStrings[Y].GetWidthInfo;
        len := length(cw);
        X := len;
	  end
      else
        break;
    end;
  end;
  SetPhysicalCaret(FEditPoint);
end;

procedure TRichTextView.BeginningOfLine;
begin
  SetLogicalCaret(0, FLogicalCaret.Y);
end;

procedure TRichTextView.EndOfLine;
begin
  SetLogicalCaret(High(integer), FLogicalCaret.Y);
end;

procedure TRichTextView.BeginningOfBuffer;
begin
  SetLogicalCaret(0, 0);
end;

procedure TRichTextView.EndOfBuffer;
begin
  SetPhysicalCaret(High(integer), FStrings.Count -1);
end;

procedure TRichTextView.ScrollLine(advance: integer);
begin
  Inc(FLogicalCaret.Y, advance);
  Inc(FLogicalTopLine, advance);
  ModifyLogicalLine(FLogicalTopLine, FTopLine, FTopLineOffset);
  UpdateBottomLine;
  FLogicalCaret.X := FCaretSavedX;
  SetLogicalCaret(FLogicalCaret);
  Invalidate;
end;

procedure TRichTextView.PageDown;
begin
{  ScrollLine(VisibleLines - GetMargin);}
  ScrollLine(VisibleLines - GetMargin -3);
end;

procedure TRichTextView.PageUp;
begin
{  ScrollLine(GetMargin - VisibleLines);}
  ScrollLine(GetMargin - VisibleLines +3);
end;

procedure TRichTextView.SetTop(line: integer);
begin
  Inc(FLogicalCaret.Y, line - FLogicalTopLine);
  FLogicalTopLine := line;
  SetLogicalCaret(FCaretSavedX, FLogicalCaret.Y, hscDONTSAVEX);
  Invalidate;
end;

procedure TRichTextView.UpdateScrollInfo(redraw: Boolean);
var
  si: SCROLLINFO;
begin
  si.cbSize := sizeof(si);
  si.fMask  := SIF_PAGE or SIF_RANGE or SIF_POS;
  si.nMin   := 0;
  si.nMax   := FStrings.GetLogicalLines;
  si.nPage  := VisibleLines - 1;
  SetScrollInfo(Handle, SB_VERT, si, redraw);
  SetScrollPos(Handle, SB_VERT, FLogicalTopLine, redraw);
end;


procedure TRichTextView.ON_WM_CREATE(var msg: TMsg);
begin
  SetWindowLong(Handle, GWL_EXSTYLE,
                GetWindowLong(Handle, GWL_EXSTYLE) or WS_EX_CLIENTEDGE);
  ShowScrollBar(Handle, SB_VERT, True);
  FEditPoint.X := 0;
  FEditPoint.Y := 0;
  FLogicalCaret.X := 0;
  FLogicalCaret.Y := 0;
  FCaretSavedX := 0;
end;

procedure TRichTextView.ON_WM_GETDLGCODE(var msg: TMessage);
begin
  msg.Result := DLGC_WANTARROWS or DLGC_WANTALLKEYS (* or DLGC_WANTTAB *);
end;

procedure TRichTextView.ON_WM_SIZE(var msg: TMessage);
begin
  DoSize(msg.LParamLo, msg.LParamHi);
end;

procedure TRichTextView.DoSize(newWidth, newHeight: Integer);
var
  off: integer;
  vl: integer;
begin
  UpdateVisibleLines;
  off := (FLogicalCaret.Y - FLogicalTopLine);
  FBitmap.Width  := newWidth;
  FBitmap.Height := newHeight;
  InvalidateSize;

  FLogicalCaret := PhysicalToLogical(FEditPoint);
  vl := VisibleLines;
  if vl <= off then
    off := vl -1;
  if off < 0 then
    off := 0;
  FLogicalTopLine := FLogicalCaret.Y - off;
  vl := TopForBottom;
  if (vl < FLogicalTopLine) then
    FLogicalTopLine := vl;
  ModifyLogicalLine(FLogicalTopLine, FTopLine, FTopLineOffset);
  UpdateBottomLine;
  UpdateScreenCaret;
end;

procedure TRichTextView.ON_WM_SETFOCUS(var msg: TMsg);
begin
  {$IFDEF IBEAM}
  CreateCaret(Handle, 0, 1, Abs(Font.Height));
  {$ELSE}
  CreateCaret(Handle, 0, Abs(Font.Height) div 3 + 1, Abs(Font.Height));
  {$ENDIF}
  SetCaretPos(FCaretPos.x, FCaretPos.y);
  if FCaretVisible and FConfCaretVisible then
    ShowCaret(Handle);
end;

procedure TRichTextView.ON_WM_KILLFOCUS(var msg: TMsg);
begin
  if FCaretVisible then
    HideCaret(Handle);
  DestroyCaret;
end;

procedure TRichTextView.ON_WM_MOUSEACTIVATE(var msg: TWMMouse);
begin
  try
    Windows.SetFocus(Handle);
  except
  end;
end;


procedure TRichTextView.MouseDown(Button: TMouseButton; Shift: TShiftState;
                                  X, Y: Integer);
begin
  case Button of
  mbLeft:
    begin
      SetLogicalCaret(ClientToLogical(X, Y), hscDONTSCROLL);
      FSelStart := FEditPoint;
      SetSelecting(True);
      FDragging  := True;
      CaretVisible(True);
    end;
  mbRight:
    if (not Selecting) or
       ((FSelStart.X = FEditPoint.X) and (FSelStart.Y = FEditPoint.Y)) then
    begin
      SetLogicalCaret(ClientToLogical(X, Y), hscDONTSCROLL);
      FSelStart := FEditPoint;
      SetSelecting(False);
      FDragging  := False;
      CaretVisible(True);
    end;
  end;
  inherited;
end;

procedure TRichTextView.MouseUp(Button: TMouseButton; Shift: TShiftState;
                                X, Y: Integer);
begin
  case Button of
  mbLeft:
    begin
      FDragging := False;
    end;
  end;
  inherited;
end;

procedure TRichTextView.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  if not FSelecting then
    FDragging := False;
  if FDragging then
  begin
    SetLogicalCaret(ClientToLogical(X, Y));
  end;
  inherited;
end;


procedure TRichTextView.ON_WM_MOUSEWHEEL(var msg: TMessage);
begin
  if FWheelPageScroll then
  case (msg.WParam < 0) of
    true:  PageDown;
    false: PageUp;
  end else
    ScrollLine(-FVScrollLines * SmallInt(HIWORD(msg.wParam)) div WHEEL_DELTA);
  msg.Result := 1;
  SetSelecting(False);
  CaretVisible(False);
end;

procedure TRichTextView.KeyDown(var Key: Word; Shift: TShiftState);
  procedure ProcSelection;
  begin
    if not (ssShift in Shift) then
      SetSelecting(False)
    else if not FSelecting then
    begin
      SetSelecting(True);
      FSelStart := FEditPoint;
    end;
  end;
begin
  CaretVisible(True);
  inherited KeyDown(Key, Shift);
  if Key = 0 then
    exit;
  case Key of
  VK_DELETE, VK_INSERT:
    begin
      SetConfCaretVisible(not FConfCaretVisible);
      Key := 0;
    end;
  VK_DOWN:
    begin
      ProcSelection;
      if FConfCaretVisible then
        ForwardLine(1)
      else
        ScrollLine(FVScrollLines); //521
      Key := 0;
    end;
  VK_UP:
	begin
	  ProcSelection;
	  if FConfCaretVisible then
		ForwardLine(-1)
	  else
		ScrollLine(-FVScrollLines); //521
	  Key := 0;
	end;
  VK_RIGHT: begin ProcSelection; ForwardChar(1);  Key := 0; end;
  VK_LEFT:  begin ProcSelection; ForwardChar(-1); Key := 0; end;
  VK_NEXT:  begin ProcSelection; PageDown;        Key := 0; end;
  VK_SPACE: begin ProcSelection; PageDown;        Key := 0; end; {’Ç‰Á}
  VK_PRIOR: begin ProcSelection; PageUp;          Key := 0; end;
  VK_HOME:
    begin
      ProcSelection;
      if (ssCtrl in Shift) or not FConfCaretVisible then
        BeginningOfBuffer
      else
        BeginningOfLine;
      Key := 0;
    end;
  VK_END:
    begin
      ProcSelection;
      if (ssCtrl in Shift) or not FConfCaretVisible then
        EndOfBuffer
      else
        EndOfLine;
      Key := 0;
    end;
{  Ord('A'):
	begin
	  BeginningOfBuffer;
	  SetMarkCommand;
	  EndOfBuffer;
	  Selecting := True;
	end;
  Ord('C'):
	begin
	  if ssCtrl in Shift then
	  begin
		CopySelection;
		Key := 0;
	  end;
    end;}
  end;
end;

procedure TRichTextView.ON_WM_HSCROLL(var msg: TMessage);
begin
  if not FDragging then
    SetSelecting(False);
  CaretVisible(False);
end;

procedure TRichTextView.ON_WM_VSCROLL(var msg: TMessage);
begin
  if not FDragging then
    SetSelecting(False);
  case msg.WParamLo of
  SB_TOP:      BeginningOfBuffer;
  SB_BOTTOM:   EndOfBuffer;
  SB_LINEDOWN: ScrollLine(FVScrollLines);
  SB_LINEUP:   ScrollLine(-FVScrollLines);
  SB_PAGEDOWN: ScrollLine(VisibleLines - GetMargin);
  SB_PAGEUP:   ScrollLine(GetMargin - VisibleLines);
  SB_THUMBPOSITION,
  SB_THUMBTRACK:
    begin
      SetTop(msg.wParamHi);
    end;
  //SB_ENDSCROLL:
  end;
  msg.Result := 1;
  CaretVisible(False);
end;

procedure TRichTextView.ON_WM_PAINT(var msg: TWMPaint);
begin
  PaintHandler(msg);
end;

function TRichTextView.RangeVisible(startPos, endPos: TPoint): Boolean;
var
  vLines: Integer;
begin
  result := False;
  endPos   := PhysicalToLogical(endPos);
  if endPos.Y < FLogicalTopLine then
    exit;
  startPos := PhysicalToLogical(startPos);
  vLines := VisibleLines;
  if FLogicalTopLine + vLines <= startPos.Y then
    exit;
  result := True;
end;

function TRichTextView.InSelection(X, Y: integer): Boolean;
var
  rect: TRect;
begin
  result := False;
  if not FSelecting then
    exit;
  rect := NormalizeMinMax(FEditPoint, FSelStart);
  if Y < rect.Top then
    exit;
  if rect.Bottom < Y then
    exit;
  if (Y = rect.Top) and (X < rect.Left) then
    exit;
  if (Y = rect.Bottom) and (rect.Right <= X) then
    exit;
  result := True;
end;

procedure TRichTextView.PaintWindow(DC: HDC);
var
  len, screenLine, vLines: Integer;
  bs: Integer;
  X, Y: integer;
  width, maxX: Integer;
  index: Integer;
  point: TPoint;
  attrib, cw: AnsiString;
  item: TRichTVItem;
  next: integer;
  attCode: integer;
  selectionP: boolean;
  nchar: integer;
  physicalLine: integer;
  ws: WideString;
label
  DONE;
begin
  FBitmap.Canvas.Brush  := Brush;
  FBitmap.Canvas.Font   := Font;
  FBitmap.Canvas.FillRect(ClientRect);

  bs := BaselineSkip;
  vLines := VisibleLines;

  physicalLine := FTopLine;
  item := FStrings[physicalLine];
  point.X := 0;
  point.Y := FTopLineOffset;
  index := item.LogicalPosToIndex(point);
  cw := item.GetWidthInfo;
  attrib := item.FAttrib;
  len := length(cw);
  screenLine := 0;
  maxX := ClientWidth - FRightMargin;
  X := FLeftMargin + item.OffsetLeft;
  Y := FTopMargin;
  nchar := 0;
  while screenLine < vLines do
  begin
    while index <= len do
    begin
      attCode := Ord(attrib[index]);
      if attCode and htvVMASK = htvVISIBLE then
      begin
        width := Ord(cw[index]);
        if (maxX < X + width) and (0 < nchar) then
        begin
          Inc(screenLine);
          if vLines <= screenLine then
            goto DONE;
          X := FLeftMargin + item.OffsetLeft;
          Inc(Y, bs);
          nchar := 0;
        end;
        Inc(nchar);
        selectionP := InSelection(index -1, physicalLine);
        next := index + 1;
        while next <= len do
        begin
          if Ord(attrib[next]) <> attCode then
            break;
          if cw[next] <> #0 then
          begin
            if InSelection(next -1, physicalLine) <> selectionP then
              break;
            if (maxX < (X + width + Ord(cw[next]))) then
              break;
          end;
          Inc(width, Ord(cw[next]));
          Inc(next);
        end;
        with TextAttrib[attCode and htvATTMASK] do
        begin
          if selectionP then
          begin
            if FBitmap.Canvas.Font.Color <> clHighlightText then
              FBitmap.Canvas.Font.Color := clHighlightText;
            if FBitmap.Canvas.Brush.Color <> clHighlight then
              FBitmap.Canvas.Brush.Color := clHighlight;
          end
          else begin
            if FBitmap.Canvas.Font.Color <> color then
              FBitmap.Canvas.Font.Color := color;
            if FBitmap.Canvas.Brush.Color <> self.Color then
              FBitmap.Canvas.Brush.Color := self.Color;
          end;
          if FBitmap.Canvas.Font.Style <> style then
            FBitmap.Canvas.Font.Style := style;
        end;
        if attCode and htvCODEMASK = htvASCII then
        begin
          Windows.TextOutA(FBitmap.Canvas.Handle, X, Y, @item.FText[index], next - index);
        end
        else begin
          SetLength(ws, (next - index) div 2);
          Move(item.FText[index], ws[1], next - index);
          Windows.TextOutW(FBitmap.Canvas.Handle , X, Y,
                           @ws[1], (next - index) div 2);
        end;
        Inc(X, width);
        index := next;
      end
      else
        Inc(index);
    end;
    Inc(screenLine);
    if vLines <= screenLine then
      break;
    Inc(physicalLine);
    if FStrings.Count <= physicalLine then
      break;
    Inc(Y, bs);
    item := FStrings[physicalLine];
    X := FLeftMargin + item.OffsetLeft;
    index := 1;
    attrib := item.FAttrib;
    len := length(attrib);
    cw := item.GetWidthInfo;
  end;
DONE:
  Canvas.CopyRect(ClientRect, FBitmap.Canvas, ClientRect);
  UpdateScrollInfo;
end;


procedure TRichTextView.LineUpdated(startLine, endLine: Integer);
begin
  if (startLine <= FTopLine + VisibleLines) and (FTopLine <= endLine) then
    Repaint;
end;

function TRichTextView.RegionToText(point1, point2: TPoint): string;
var
  region: TRect;
  Y, startPos, endPos: integer;
  txt, attr: AnsiString;
  i, code: integer;
  attCode: Integer;
  Position, Size: Integer;
  s: string;
begin
  region := NormalizeMinMax(FSelStart, FEditPoint);
  Size := 0;
  (* calculate size *)
  for Y := region.Top to region.Bottom do
  begin
    if FStrings.Count <= Y then
      break;
    if 0 < Size then
      Inc(Size, 2);
    txt := FStrings[Y].FText;
    attr:= FStrings[Y].FAttrib;
    if Y = region.Top then
      startPos := region.Left + 1
    else
      startPos := 1;
    if region.Bottom <= Y then
      endPos := region.Right
    else
      endPos := length(txt);
    i := startPos;
    while i <= endPos do
    begin
      attCode := Ord(attr[i]);
      if attCode and htvVMASK = htvHIDDEN then
      begin
        if startPos < i then
          Inc(Size, i - startPos);
        startPos := i + 1;
      end
      else if (attCode and htvCODEMASK) = htvUNICODE then
      begin
        if startPos < i then
          Inc(Size, i - startPos);
        code := Ord(txt[i]) + Ord(txt[i+1]) * 256;
        Inc(Size, Length('&#' + IntToStr(code) + ';'));
        startPos := i + 2;
        Inc(i);
      end;
      Inc(i);
    end;
    Inc(Size, endPos - startPos + 1);
  end;

  SetLength(result, Size);
  Position := 1;
  for Y := region.Top to region.Bottom do
  begin
    if FStrings.Count <= Y then
      break;
    if 1 < Position then
    begin
      Move(#13#10[1], result[Position], 2);
      Inc(Position, 2);
    end;
    txt := FStrings[Y].FText;
    attr:= FStrings[Y].FAttrib;
    if Y = region.Top then
      startPos := region.Left + 1
    else
      startPos := 1;
    if region.Bottom <= Y then
      endPos := region.Right
    else
      endPos := length(txt);
    i := startPos;
    while i <= endPos do
    begin
      attCode := Ord(attr[i]);
      if attCode and htvVMASK = htvHIDDEN then
      begin
        if startPos < i then
        begin
          Move(txt[startPos], result[Position], i - startPos);
          Inc(Position, i - startPos);
        end;
        startPos := i + 1;
      end
      else if (attCode and htvCODEMASK) = htvUNICODE then
      begin
        if startPos < i then
        begin
          Move(txt[startPos], result[Position], i - startPos);
          Inc(Position, i - startPos);
        end;
        code := Ord(txt[i]) + Ord(txt[i+1]) * 256;
        s := '&#' + IntToStr(code) + ';';
        Move(s[1], result[Position], length(s));
        Inc(Position, length(s));
        startPos := i + 2;
        Inc(i);
      end;
      Inc(i);
    end;
    Move(txt[startPos], result[Position], endPos - startPos + 1);
    Inc(Position, endPos - startPos + 1);
  end;

end;


procedure TRichTextView.CopySelection;
var
  txt: String;
begin
  if not FSelecting then
    exit;
  txt := RegionToText(FSelStart, FEditPoint);
  Clipboard.AsText := txt;
end;

function TRichTextView.GetSelection: String;
begin
  if not FSelecting then
    exit;
  result := RegionToText(FSelStart, FEditPoint);
end;


function TRichTextView.SearchForward (const AString: String): Boolean;
var
  col, line: integer;
  len, endPos: integer;
  startChar: Char;
  item: TRichTVItem;
  matchEnd: integer;
  cw: AnsiString;
  target: string;
  rect: TRect;
begin
  if FSelecting then
  begin
    rect := NormalizeMinMax(FEditPoint, FSelStart);
    FSelStart := rect.TopLeft;
    FEditPoint := rect.BottomRight;
  end;
  result := False;
  len := length(AString);
  if len <= 0 then
    exit;
  target := AnsiUpperCase(AString);
  startChar := target[1];
  col := FEditPoint.X + 1;
  for line := FEditPoint.Y to FStrings.Count -1 do
  begin
    item := FStrings[line];
    endPos := item.GetLength;
    cw := item.GetWidthInfo;
    if col <= 0 then
      col := 1;
    while col <= endPos do
    begin
      if (cw[col] <> #0) and
         (Ord(item.FAttrib[col]) and htvVMASK = htvVISIBLE) and
         (UpCase(item.FText[col]) = startChar) and
         (item.StartsWith(target, col, matchEnd)) then
      begin
        FSelStart.X := col -1;
        FSelStart.Y := line;
        SetPhysicalCaret(matchEnd - 1, line, hscSCROLLCENTER);
        SetSelecting(True);
        result := True;
        exit;
      end;
      Inc(col);
    end;
    col := 0;
  end;
end;

function TRichTextView.SearchBackward(const AString: String): Boolean;
var
  col, line: integer;
  len: integer;
  startChar: Char;
  item: TRichTVItem;
  matchEnd: integer;
  cw: AnsiString;
  target: String;
  rect: TRect;
begin
  if FSelecting then
  begin
    rect := NormalizeMinMax(FEditPoint, FSelStart);
    FEditPoint := rect.TopLeft;
    FSelStart := rect.BottomRight;
  end;
  result := False;
  len := length(AString);
  if len <= 0 then
    exit;
  target := AnsiUpperCase(AString);
  startChar := target[1];
  col := FEditPoint.X;
  if col <= 0 then
    line := FEditPoint.Y -1
  else
    line := FEditPoint.Y;
  for line := line downto 0 do
  begin
    item := FStrings[line];
    cw := item.GetWidthInfo;
    if col <= 0 then
      col := length(cw);
    while 0 < col do
    begin
      if (cw[col] <> #0) and
         (Ord(item.FAttrib[col]) and htvVMASK = htvVISIBLE) and
         (UpCase(item.FText[col]) = startChar) and
         (item.StartsWith(target, col, matchEnd)) then
      begin
        FSelStart.X := matchEnd - 1;
        FSelStart.Y := line;
        SetPhysicalCaret(col - 1, line, hscSCROLLCENTER);
        SetSelecting(True);
        result := True;
        exit;
      end;
      Dec(col);
    end;
    col := 0;
  end;
end;

procedure TRichTextView.SetMarkCommand;
begin
  FSelStart := FEditPoint;
end;

function TRichTextView.NormalizeMinMax(point1, point2: TPoint): TRect;
var
  tmp: integer;
begin
  if point1.Y <= point2.Y then
  begin
    result.TopLeft := point1;
    result.BottomRight := point2;
  end
  else begin
    result.TopLeft := point2;
    result.BottomRight := point1;
  end;
  if (result.Top = result.Bottom) and (result.Right < result.Left) then
  begin
    tmp := result.Left;
    result.Left := result.Right;
    result.Right := tmp;
  end;
end;



function TRichTextView.nInsert(point: TPoint;
                               pstr: PChar;
                               count: Integer;
                               attrib: Integer = 0): TPoint;
var
  item: TRichTVItem;
  startPos, endPos, len: integer;
  p: PChar;
  wp: PWideChar;
  org: TPoint;
  startLine: integer;
begin
  if count <= 0 then
    exit;
  point := Normalize(point);
  org := point;
  len := count;
  startLine := point.Y;
  if (attrib and htvCODEMASK) = htvASCII then
  begin
    item := FStrings[point.Y];
    p := pstr;
    startPos := 0;
    endPos := startPos;
    while endPos < len do
    begin
      if p^ = #10 then
      begin
        if (startPos < endPos) and ((p -1)^ = #13) then
        begin
          item.Insert(point.X + 1, pstr + startPos, endPos - startPos -1,
                      attrib);
        end
        else begin
          item.Insert(point.X + 1, pstr + startPos, endPos - startPos,
                      attrib);
        end;
        Inc(point.Y);
        point.X := 0;
        item := TRichTVItem.Create(Self);
        FStrings.Insert(point.Y, item);
        startPos := endPos + 1;
      end
      else begin
        Inc(point.X);
      end;
      Inc(p);
      Inc(endPos);
    end;
    if startPos < endPos then
      item.Insert(point.X + 1, pstr + startPos, endPos - startPos,
                  attrib);
  end
  else begin
    item := FStrings[point.Y];
    wp := PWideChar(pstr);
    startPos := 0;
    endPos := startPos;
    while endPos < len do
    begin
      if wp^ = WideChar(#10) then
      begin
        if (startPos < endPos) and ((wp -1)^ = WideChar(#13)) then
        begin
          item.Insert(point.X + 1, pstr + startPos, endPos - startPos -2,
                      attrib);
        end
        else begin
          item.Insert(point.X + 1, pstr + startPos, endPos - startPos,
                      attrib);
        end;
        Inc(point.Y);
        point.X := 0;
        item := TRichTVItem.Create(Self);
        FStrings.Insert(point.Y, item);
        startPos := endPos + 2;
      end
      else begin
        Inc(point.X, 2);
      end;
      Inc(wp);
      Inc(endPos, 2);
    end;
    if startPos < endPos then
      item.Insert(point.X + 1, pstr + startPos, endPos - startPos,
                  attrib);
  end;
  if (startLine <= FBottomLine) and (FTopLine <= point.Y) then
    Invalidate;
  result := point;
end;

function TRichTextView.Insert(point: TPoint;
                              const AString: string;
                              attrib: Integer = 0): TPoint;
begin
  result := nInsert(point, @AString[1], length(AString), attrib);
end;

function TRichTextView.nAppend(pstr: PChar;
                               count: Integer;
                               attrib: Integer = 0): TPoint;
var
  point: TPoint;
begin
  point.Y := FStrings.Count -1;
  point.X := length(FStrings[point.Y].FText);
  result := nInsert(point, pstr, count, attrib);
end;


function TRichTextView.Append(const AString: string;
                              attrib: Integer = 0): TPoint;
begin
  result := nAppend(@AString[1], length(AString), attrib);
end;

procedure TRichTextView.Clear;
var
  item: TRichTVItem;
begin
  FStrings.Clear;
  item := TRichTVItem.Create(Self);
  FStrings.Add(item);
  SetPhysicalCaret(0, 0);
  FSelStart := FEditPoint;
  SetSelecting(False);
  CaretVisible(False);
end;

function TRichTextView.CharWidth(p: PChar; attrib: Integer): Integer;
var
  style: TFontStyles;
  tbl: ^TRichCharWidthTable;
  size: TSize;
  code: Word;
  modifier: Integer;

  function GetCharWidth(ptr: PByte; len: integer): integer;
  begin
    if ptr^ <> 0 then
      result := ptr^
    else begin
      if FBitmap.Canvas.Font.Style <> style then
        FBitmap.Canvas.Font.Style := style;
      GetTextExtentPoint32A(FBitmap.Canvas.Handle, p, len, size);
      result := size.cx + modifier;
      ptr^ := result;
    end;
  end;
begin
  style := TextAttrib[attrib and htvATTMASK].style;
  if attrib and htvCODEMASK = htvUNICODE then
  begin
    if FBitmap.Canvas.Font.Style <> style then
      FBitmap.Canvas.Font.Style := style;
    code := PWord(p)^;
    GetTextExtentPoint32W(FBitmap.Canvas.Handle, PWideChar(@code), 1, size);
    result := size.cx;
    exit;
  end;
  if fsBold in style then
  begin
    tbl := @FBCharWidthTable;
    modifier := FBoldWidthModifier;
  end
  else begin
    tbl := @FCharWidthTable;
    modifier := 0;
  end;
  case p^ of
  #$00..#$80: result := GetCharWidth(@(tbl^.Ascii_1[Ord(p^)]), 1);
  #$81..#$9F: result := GetCharWidth(@(tbl^.MB_1[Ord(p^)][Ord((p+1)^)]), 2);
  #$A0..#$DF: result := GetCharWidth(@(tbl^.Ascii_2[Ord(p^)]), 1);
  #$E0..#$FC: result := GetCharWidth(@(tbl^.MB_2[Ord(p^)][Ord((p+1)^)]), 2);
  #$FD..#$FF: result := GetCharWidth(@(tbl^.Ascii_3[Ord(p^)]), 1);
  else        result := 0;
  end;
end;


procedure TRichTextView.InvalidateSize;
var
  i: integer;
begin
  for i := 0 to FStrings.Count -1 do
    with FStrings[i] do
    begin
      LogicalLines := 0;
      GetLogicalLines;
    end;
end;

procedure TRichTextView.UpdateBottomLine;
var
  i, vLines: integer;
begin
  vLines := VisibleLines;
  FBottomLine := FTopLine;
  for i := FTopLine to FStrings.Count -1 do
  begin
    FBottomLine := i;
    Dec(vLines, FStrings[i].LogicalLines);
    if vLines <= 0 then
      break;
  end;
end;



procedure TRichTextView.SetFont(FaceName: String; Size: Integer);
var
  i: integer;
begin
  if (FBitmap.Canvas.Font.Name = FaceName) and (FBitmap.Canvas.Font.Size = Size) then
    exit;
  Font.Name := FaceName;
  Font.Size := Size;
  FBitmap.Canvas.Font.Name := FaceName;
  FBitmap.Canvas.Font.Size := Size;
  FillChar(FCharWidthTable,  SizeOf(FCharWidthTable),  0);
  FillChar(FBCharWidthTable, SizeOf(FBCharWidthTable), 0);
  for i := 0 to FStrings.Count -1 do
    FStrings[i].FontChanged;
  if FCaretVisible and FConfCaretVisible then
  begin
    DestroyCaret;
    HideCaret(Handle);
    CreateCaret(Handle, 0, 1, Abs(Font.Height));
    ShowCaret(Handle);
  end;
  DoSize(Width, Height);
end;


end.
