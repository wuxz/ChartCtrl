#if !defined(AFX_COLORWND_H__42B6F563_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_COLORWND_H__42B6F563_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorWnd window

class CColorWnd : public CWnd
{
// Construction
public:
	CColorWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetColor(COLORREF clr);
	virtual ~CColorWnd();

	// Generated message map functions
protected:
	COLORREF m_clrDraw;
	//{{AFX_MSG(CColorWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORWND_H__42B6F563_54A5_11D3_A7FE_0080C8763FA4__INCLUDED_)
