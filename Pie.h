// Pie.h: interface for the CPie class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIE_H__51FB95C1_50C8_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_PIE_H__51FB95C1_50C8_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Chart.h"

class CPie : public CChart  
{
public:
	CPie();
	virtual ~CPie();

	virtual BOOL Draw(const CRect * pRect, CDC * pDC);

protected:
	CArray<double, double> m_arSum;
	POINT * m_pPtArr;

protected:
	virtual void FinishDraw(const CRect * pRect, CDC * pDC);
};

#endif // !defined(AFX_PIE_H__51FB95C1_50C8_11D3_A7FE_0080C8763FA4__INCLUDED_)
