#if !defined(AFX_KCOMCHARTPPG_H__503612B5_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_KCOMCHARTPPG_H__503612B5_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// KCOMChartPpg.h : Declaration of the CKCOMChartPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CKCOMChartPropPage : See KCOMChartPpg.cpp.cpp for implementation.

class CKCOMChartPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CKCOMChartPropPage)
	DECLARE_OLECREATE_EX(CKCOMChartPropPage)

// Constructor
public:
	CKCOMChartPropPage();

// Dialog Data
	//{{AFX_DATA(CKCOMChartPropPage)
	enum { IDD = IDD_PROPPAGE_KCOMCHART };
	int		m_sAppearance;
	int		m_sBorderStyle;
	int		m_nTitleAlignment;
	int		m_nFooterAlignment;
	BOOL	m_bDrawLegend;
	CString	m_strTitle;
	CString	m_strFooter;
	long	m_nSeriesCount;
	long	m_nGroupCount;
	BOOL	m_bDrawGroupTitle;
	int		m_nDataMode;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	int GetDataMode();
	//{{AFX_MSG(CKCOMChartPropPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KCOMCHARTPPG_H__503612B5_50B5_11D3_A7FE_0080C8763FA4__INCLUDED)
