#if !defined(AFX_GROUPPROPPAGE_H__42B6F562_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_GROUPPROPPAGE_H__42B6F562_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_

#include "ColorWnd.h"	// Added by ClassView
#include "InputGrid.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GroupPropPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage : Property page dialog
class CKCOMChartCtrl;

class CGroupPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CGroupPropPage)
	DECLARE_OLECREATE_EX(CGroupPropPage)

// Constructors
public:
	CGroupPropPage();

// Dialog Data
	//{{AFX_DATA(CGroupPropPage)
	enum { IDD = IDD_PROPPAGE_GROUP };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV support

// Message maps
protected:
	void InitControls();
	void DisableMe();
	void CheckRadio(CButton *pButton, int nValue);
	CInputGrid m_wndGrid;
	CColorWnd m_wndColor;
	CKCOMChartCtrl * m_pCtrl;

	CStringArray m_arGroupTitle, m_arSeriesTitle;
	CArray<int, int> m_arUsage;
	CArray<COLORREF, COLORREF> m_arSeriesColor;

	//{{AFX_MSG(CGroupPropPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokComboGroup();
	afx_msg void OnSelendokComboSeries();
	afx_msg void OnKillfocusEditGrouptitle();
	afx_msg void OnKillfocusEditSeriestitle();
	afx_msg void OnButtonChoosecolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPPROPPAGE_H__42B6F562_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
