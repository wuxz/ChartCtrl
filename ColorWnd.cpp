// ColorWnd.cpp : implementation file
//

#include "stdafx.h"
#include "KCOMChart.h"
#include "ColorWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorWnd

CColorWnd::CColorWnd()
{
	m_clrDraw = RGB(255, 255, 255);
}

CColorWnd::~CColorWnd()
{
}


BEGIN_MESSAGE_MAP(CColorWnd, CWnd)
	//{{AFX_MSG_MAP(CColorWnd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CColorWnd message handlers

void CColorWnd::SetColor(COLORREF clr)
{
	m_clrDraw = clr;

	Invalidate();
}

void CColorWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rt;
	GetClientRect(&rt);

	dc.FillSolidRect(rt, m_clrDraw);
}
