// InputGrid.cpp : implementation file
//

#include "stdafx.h"
#include "KCOMChart.h"
#include "InputGrid.h"
#include "groupproppage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputGrid

CInputGrid::CInputGrid()
{
	m_pPage = NULL;
}

CInputGrid::~CInputGrid()
{
}


BEGIN_MESSAGE_MAP(CInputGrid, CGridCtrl)
	//{{AFX_MSG_MAP(CInputGrid)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInputGrid message handlers

void CInputGrid::SetModified(BOOL bModified, int nRow, int nCol)
{
	CGridCtrl::SetModified(bModified, nRow, nCol);

	if (bModified)
		m_pPage->SetModifiedFlag(TRUE);
}

void CInputGrid::SetPage(CGroupPropPage *pPage)
{
	m_pPage = pPage;
}
