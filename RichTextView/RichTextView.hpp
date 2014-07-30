// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'RichTextView.pas' rev: 6.00

#ifndef RichTextViewHPP
#define RichTextViewHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Richtextview
{
//-- type declarations -------------------------------------------------------
typedef Shortint TRichAttribute;

#pragma pack(push, 4)
struct TRichPosition
{
	int position;
	int size;
} ;
#pragma pack(pop)

class DELPHICLASS TRichTVItem;
class DELPHICLASS TRichTextView;
#pragma pack(push, 1)
struct TRichCharWidthTable
{
	Byte Ascii_1[129];
	Byte MB_1[31][256];
	Byte Ascii_2[64];
	Byte MB_2[29][256];
	Byte Ascii_3[3];
} ;
#pragma pack(pop)

class DELPHICLASS TRichTVItems;
class PASCALIMPLEMENTATION TRichTVItems : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TRichTVItem* operator[](int index) { return Items[index]; }
	
private:
	TRichTextView* FParent;
	
protected:
	TRichTVItem* __fastcall GetItem(int index);
	void __fastcall SetItem(int index, TRichTVItem* item);
	
public:
	__fastcall TRichTVItems(TRichTextView* parent);
	__fastcall virtual ~TRichTVItems(void);
	virtual void __fastcall Clear(void);
	HIDESBASE void __fastcall Add(void * Item)/* overload */;
	int __fastcall GetLogicalLines(void);
	__property TRichTVItem* Items[int index] = {read=GetItem, write=SetItem/*, default*/};
};


struct TRichTextAttrib;
class PASCALIMPLEMENTATION TRichTextView : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	#pragma pack(push, 1)
	TRichCharWidthTable FCharWidthTable;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	TRichCharWidthTable FBCharWidthTable;
	#pragma pack(pop)
	
	
protected:
	int FLeftMargin;
	int FTopMargin;
	int FRightMargin;
	int FExternalLeading;
	TRichTVItems* FStrings;
	int FTopLine;
	int FTopLineOffset;
	int FLogicalTopLine;
	int FBottomLine;
	int FVisibleLines;
	int FVerticalCaretMargin;
	int FVScrollLines;
	bool FWheelPageScroll;
	#pragma pack(push, 1)
	Types::TPoint FCaretPos;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FEditPoint;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FLogicalCaret;
	#pragma pack(pop)
	
	int FCaretSavedX;
	bool FCaretVisible;
	bool FConfCaretVisible;
	bool FSelecting;
	bool FDragging;
	#pragma pack(push, 1)
	Types::TPoint FSelStart;
	#pragma pack(pop)
	
	Graphics::TBitmap* FBitmap;
	int FBoldWidthModifier;
	int __fastcall CharWidth(char * p, int attrib);
	int __fastcall BaselineSkip(void);
	void __fastcall UpdateVisibleLines(void);
	int __fastcall TopForBottom(void);
	int __fastcall GetMargin(void);
	int __fastcall CalcLogicalLine(int line, int offset);
	void __fastcall ModifyLogicalLine(int &logicalLine, int &physicalLine, int &offset);
	Types::TPoint __fastcall Normalize(const Types::TPoint &point);
	void __fastcall LogicalNormalize(Types::TPoint &logical, Types::TPoint &physical);
	void __fastcall UpdateScreenCaret(void);
	void __fastcall ScrollToViewCaret(bool Center = false);
	Types::TPoint __fastcall PhysicalToClient(int X, int Y);
	Types::TRect __fastcall NormalizeMinMax(const Types::TPoint &point1, const Types::TPoint &point2);
	AnsiString __fastcall RegionToText(const Types::TPoint &point1, const Types::TPoint &point2);
	void __fastcall UpdateScrollInfo(bool redraw = true);
	void __fastcall LineUpdated(int startLine, int endLine);
	void __fastcall CaretVisible(bool visibleP);
	void __fastcall SetSelecting(bool selectP);
	void __fastcall SetConfCaretVisible(bool visibleP);
	bool __fastcall RangeVisible(const Types::TPoint &startPos, const Types::TPoint &endPos);
	void __fastcall InvalidateSize(void);
	void __fastcall UpdateBottomLine(void);
	MESSAGE void __fastcall ON_WM_CREATE(tagMSG &msg);
	MESSAGE void __fastcall ON_WM_GETDLGCODE(Messages::TMessage &msg);
	MESSAGE void __fastcall ON_WM_SIZE(Messages::TMessage &msg);
	void __fastcall DoSize(int newWidth, int newHeight);
	MESSAGE void __fastcall ON_WM_SETFOCUS(tagMSG &msg);
	MESSAGE void __fastcall ON_WM_KILLFOCUS(tagMSG &msg);
	MESSAGE void __fastcall ON_WM_MOUSEACTIVATE(Messages::TWMMouse &msg);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	MESSAGE void __fastcall ON_WM_MOUSEWHEEL(Messages::TMessage &msg);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	MESSAGE void __fastcall ON_WM_HSCROLL(Messages::TMessage &msg);
	MESSAGE void __fastcall ON_WM_VSCROLL(Messages::TMessage &msg);
	MESSAGE void __fastcall ON_WM_PAINT(Messages::TWMPaint &msg);
	virtual void __fastcall PaintWindow(HDC DC);
	
public:
	TRichTextAttrib TextAttrib[32];
	__fastcall virtual TRichTextView(Classes::TComponent* AOwner);
	__fastcall virtual ~TRichTextView(void);
	void __fastcall Clear(void);
	Types::TPoint __fastcall PhysicalToLogical(const Types::TPoint &point);
	Types::TPoint __fastcall LogicalToPhysical(const Types::TPoint &point);
	Types::TPoint __fastcall ClientToPhysicalCharPos(int X, int Y);
	Types::TPoint __fastcall ClientToLogical(int X, int Y);
	void __fastcall SetPhysicalCaret(int X, int Y, int opt = 0x0)/* overload */;
	void __fastcall SetPhysicalCaret(const Types::TPoint &point, int opt = 0x0)/* overload */;
	void __fastcall SetLogicalCaret(const Types::TPoint &point, int opt = 0x0)/* overload */;
	void __fastcall SetLogicalCaret(int X, int Y, int opt = 0x0)/* overload */;
	bool __fastcall InSelection(int X, int Y);
	void __fastcall ForwardLine(int advance);
	void __fastcall ForwardChar(int advance);
	void __fastcall BeginningOfLine(void);
	void __fastcall EndOfLine(void);
	void __fastcall BeginningOfBuffer(void);
	void __fastcall EndOfBuffer(void);
	void __fastcall PageDown(void);
	void __fastcall PageUp(void);
	HIDESBASE void __fastcall SetTop(int line);
	void __fastcall ScrollLine(int advance);
	void __fastcall CopySelection(void);
	AnsiString __fastcall GetSelection();
	bool __fastcall SearchForward(const AnsiString AString);
	bool __fastcall SearchBackward(const AnsiString AString);
	void __fastcall SetMarkCommand(void);
	HIDESBASE Types::TPoint __fastcall Insert(const Types::TPoint &point, const AnsiString AString, int attrib = 0x0);
	Types::TPoint __fastcall nInsert(const Types::TPoint &point, char * pstr, int count, int attrib = 0x0);
	Types::TPoint __fastcall Append(const AnsiString AString, int attrib = 0x0);
	Types::TPoint __fastcall nAppend(char * pstr, int count, int attrib = 0x0);
	HIDESBASE void __fastcall SetFont(AnsiString FaceName, int Size);
	__property TRichTVItems* Strings = {read=FStrings};
	__property int TopLine = {read=FTopLine, nodefault};
	__property int LogicalTopLine = {read=FLogicalTopLine, nodefault};
	__property AnsiString Selection = {read=GetSelection};
	__property Types::TPoint Caret = {read=FEditPoint, stored=false};
	__property Types::TPoint LogicalCaret = {read=FLogicalCaret};
	__property int VisibleLines = {read=FVisibleLines, nodefault};
	
__published:
	__property int LeftMargin = {read=FLeftMargin, write=FLeftMargin, nodefault};
	__property int TopMargin = {read=FTopMargin, write=FTopMargin, nodefault};
	__property int RightMargin = {read=FRightMargin, write=FRightMargin, nodefault};
	__property int ExternalLeading = {read=FExternalLeading, write=FExternalLeading, nodefault};
	__property int VerticalCaretMargin = {read=FVerticalCaretMargin, write=FVerticalCaretMargin, nodefault};
	__property int VScrollLines = {read=FVScrollLines, write=FVScrollLines, default=3};
	__property bool Selecting = {read=FSelecting, write=SetSelecting, stored=false, nodefault};
	__property bool WheelPageScroll = {read=FWheelPageScroll, write=FWheelPageScroll, nodefault};
	__property bool ConfCaretVisible = {read=FConfCaretVisible, write=SetConfCaretVisible, nodefault};
	__property Align  = {default=0};
	__property Color  = {default=-2147483643};
	__property Cursor  = {default=-4};
	__property Font ;
	__property Enabled  = {default=1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnKeyDown ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property PopupMenu ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRichTextView(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TRichTVItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FOffsetLeft;
	TRichTextView* FView;
	AnsiString FCharWidth;
	int FLogicalLines;
	void __fastcall CalcCharWidth(void);
	int __fastcall GetCharWidth(int index);
	int __fastcall GetLogicalLines(void);
	
public:
	AnsiString FText;
	AnsiString FAttrib;
	__fastcall TRichTVItem(TRichTextView* view);
	__fastcall virtual ~TRichTVItem(void);
	int __fastcall GetLength(void);
	AnsiString __fastcall GetWidthInfo();
	Types::TPoint __fastcall IndexToLogicalPos(int index);
	int __fastcall LogicalPosToIndex(Types::TPoint &point);
	bool __fastcall StartsWith(const AnsiString AString, int Index, int &matchEnd);
	void __fastcall Insert(int index, char * str, int cbStr, int attrib = 0x0);
	void __fastcall Add(char * str, int cbStr, int attrib = 0x0);
	void __fastcall FontChanged(void);
	bool __fastcall HasEmbed(int index);
	int __fastcall SkipToEmbed(int index);
	TRichPosition __fastcall FetchEmbed(int index);
	AnsiString __fastcall GetEmbed(int index);
	__property int OffsetLeft = {read=FOffsetLeft, write=FOffsetLeft, nodefault};
	__property int CharWidth[int index] = {read=GetCharWidth};
	__property int LogicalLines = {read=GetLogicalLines, write=FLogicalLines, nodefault};
};


#pragma pack(push, 4)
struct TRichTextAttrib
{
	Graphics::TColor color;
	Graphics::TFontStyles style;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint htvATTMASK = 0x1f;
static const Shortint htvASCII = 0x0;
static const Shortint htvUNICODE = 0x40;
static const Shortint htvCODEMASK = 0x40;
static const Shortint htvVISIBLE = 0x0;
static const Byte htvHIDDEN = 0x80;
static const Byte htvVMASK = 0x80;
static const Shortint htvUSER = 0x20;
static const Shortint htvUSERMASK = 0x20;
static const Shortint hscDONTSAVEX = 0x1;
static const Shortint hscDONTSCROLL = 0x2;
static const Shortint hscSCROLLCENTER = 0x4;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Richtextview */
using namespace Richtextview;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// RichTextView
