#if !defined(AFX_INPUTGRID_H__42B6F564_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_INPUTGRID_H__42B6F564_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputGrid.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputGrid window
#include "gridctrl.h"

class CGroupPropPage;

class CInputGrid : public CGridCtrl
{
// Construction
public:
	CInputGrid();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputGrid)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetPage(CGroupPropPage * pPage);
	virtual void SetModified(BOOL bModified = TRUE, int nRow = -1, int nCol = -1);
	virtual ~CInputGrid();

	// Generated message map functions
protected:
	CGroupPropPage * m_pPage;
	//{{AFX_MSG(CInputGrid)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTGRID_H__42B6F564_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
