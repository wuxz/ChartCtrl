#if !defined(AFX_STDAFX_H__503612A9_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_STDAFX_H__503612A9_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxtempl.h>
#include <math.h>

#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#define pi 3.1415926

// the function used in mfc source file, stolen by me :)
#define STOCKPROP_BACKCOLOR     0x00000001
#define STOCKPROP_CAPTION       0x00000002
#define STOCKPROP_FONT          0x00000004
#define STOCKPROP_FORECOLOR     0x00000008
#define STOCKPROP_TEXT          0x00000010
#define STOCKPROP_BORDERSTYLE   0x00000020
#define STOCKPROP_ENABLED       0x00000040
#define STOCKPROP_APPEARANCE    0x00000080

void AFXAPI _AfxToggleBorderStyle(CWnd* pWnd);
void AFXAPI _AfxToggleAppearance(CWnd* pWnd);

// the default funt data used to initialize the head font property, stolen by me from mfc source codes :)
AFX_STATIC_DATA const FONTDESC _KCOMFontDescDefault =
	{ sizeof(FONTDESC), OLESTR("MS Sans Serif"), FONTSIZE(8), FW_NORMAL,
	  DEFAULT_CHARSET, FALSE, FALSE, FALSE };

// the class used friend class defination, so it's protected "m_bAutoDelete" member can be access from these classes.
class __CMemFile : public CMemFile
{
	friend class CKCOMRichGridCtrl;
	friend class CKCOMRichComboCtrl;
	friend class CKCOMRichDropDownCtrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__503612A9_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
