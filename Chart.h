// Chart.h: interface for the CChart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHART_H__503612B7_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_CHART_H__503612B7_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CKCOMChartCtrl;

class CChart  
{
public:
	virtual ~CChart();
	void SetCtrl(CKCOMChartCtrl * pCtrl);

protected:
	CChart();
	virtual BOOL Draw(const CRect * pRect, CDC * pDC);
	virtual void FinishDraw(const CRect * pRect, CDC * pDC);

protected:
	CKCOMChartCtrl * m_pCtrl;

	HRGN m_rgnOld;
	CRgn m_rgn;
	CBrush * m_pBrhArr, * m_pBrhOld;
	BOOL m_bBrhDirty, m_bFntDirty;
	CFont * m_pFntOld;
	
	int m_nPieces, m_nSeriesesIncluded, m_nSeriesesToDraw;
	double m_fMaxTotal, m_fMinTotal;
	CArray<double, double> m_arTotal;
	int m_nGroups, m_nSerieses;

	CRect m_rtPic;
};

#endif // !defined(AFX_CHART_H__503612B7_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
