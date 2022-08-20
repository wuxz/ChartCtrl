#if !defined(AFX_KCOMCHART_H__503612AB_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_KCOMCHART_H__503612AB_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// KCOMChart.h : main header file for KCOMCHART.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKCOMChartApp : See KCOMChart.cpp for implementation.

class CKCOMChartApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KCOMCHART_H__503612AB_50B5_11D3_A7FE_0080C8763FA4__INCLUDED)
