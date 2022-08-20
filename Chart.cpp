// Chart.cpp: implementation of the CChart class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "KCOMChart.h"
#include "Chart.h"
#include "kcomchartctl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChart::CChart()
{

}

CChart::~CChart()
{

}

BOOL CChart::Draw(const CRect *pRect, CDC *pDC)
{
	m_rgnOld = NULL;
	m_pFntOld = NULL;
	
	double fTotal;
	m_fMaxTotal = 0, m_fMinTotal = 0;

	int i, j;
	m_bBrhDirty = FALSE;
	m_bFntDirty = FALSE;
	m_pBrhArr = NULL;
	m_pBrhOld = NULL;

	m_rgn.CreateRectRgnIndirect(pRect);
	GetClipRgn(pDC->m_hDC, m_rgnOld);
	pDC->SelectClipRgn(&m_rgn);

	m_rtPic.SetRect(0, 0, 0, 0);

	m_nGroups = m_pCtrl->m_arDatas.GetSize();
	m_nSeriesesToDraw = 0;
	m_nSeriesesIncluded = 0;

	if (m_nGroups == 0)
		return FALSE;

	m_nSerieses = m_pCtrl->m_arUsage.GetSize();

	for (j = 0; j < m_nGroups; j ++)
	{
		fTotal = 0;

		for (i = 0, m_nSeriesesToDraw = 0, m_nSeriesesIncluded = 0; i < m_nSerieses; i ++)
		{
			if (m_pCtrl->m_arUsage[i] != 2)
			{
				m_nSeriesesIncluded ++;
		
				if (m_pCtrl->m_arUsage[i] == 0)
					m_nSeriesesToDraw ++;

				fTotal += m_pCtrl->m_arDatas[j][i];
			}
		}

		m_arTotal.Add(fTotal);
		
		if (fTotal > m_fMaxTotal)
			m_fMaxTotal = fTotal;
		else if (fTotal < m_fMinTotal)
			m_fMinTotal = fTotal;
	}

	if (m_nSeriesesToDraw == 0 || m_fMaxTotal == 0.0)
		return FALSE;

	m_pBrhArr = new CBrush[m_nSeriesesToDraw];

	for (i = 0, j = 0; i < m_nSerieses; i ++)
	{
		if (m_pCtrl->m_arUsage[i] == 0)
			m_pBrhArr[j ++].CreateSolidBrush(m_pCtrl->m_arSeriesColor[i]);
	}

	CSize szChar;
	CRect rtMid, rtTitle, rtFooter;
	int nLegendHeight;
	CString strLegend;
	CRect rtPiece, rtLegendDraw, rtLegend;
	POINT ptCenter;

	rtMid.CopyRect(pRect);

	if (m_pCtrl->m_strTitle.GetLength())
	{
		switch (m_pCtrl->GetTitleAlignment())
		{
		case 0:
			pDC->SetTextAlign(TA_LEFT);
			break;

		case 1:
			pDC->SetTextAlign(TA_RIGHT);
			break;

		case 2:
			pDC->SetTextAlign(TA_CENTER);
			break;
		}

		szChar = pDC->GetOutputTextExtent(m_pCtrl->m_strTitle);
		rtTitle.CopyRect(pRect);
		rtTitle.bottom = rtTitle.top + 20 + szChar.cy;
	
		if (rtTitle.top < pRect->top || rtTitle.bottom > pRect->bottom)
			return FALSE;

		rtMid.top = rtTitle.bottom;

//		pDC->MoveTo(rtTitle.left - 10, rtTitle.top + 15);
//		pDC->LineTo(rtTitle.right + 10, rtTitle.top + 15);
//		pDC->LineTo(rtTitle.right + 10, rtTitle.bottom - 15);
//		pDC->LineTo(rtTitle.left - 10, rtTitle.bottom - 15);
//		pDC->LineTo(rtTitle.left - 10, rtTitle.top + 15);
		
		if (!m_bFntDirty)
		{
			m_pFntOld = m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntTitle);
			m_bFntDirty = TRUE;
		}
		else
			m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntTitle);

		switch (m_pCtrl->GetTitleAlignment())
		{
		case 0:
			rtTitle.right = rtTitle.left + szChar.cx;
			rtTitle.right = min(rtTitle.right, pRect->right);

			pDC->TextOut(rtTitle.left, rtTitle.top + 10, m_pCtrl->m_strTitle);

			break;

		case 1:
			rtTitle.left = rtTitle.right - szChar.cx;
			rtTitle.left = min(rtTitle.left, pRect->left);

			pDC->TextOut(rtTitle.right, rtTitle.top + 10, m_pCtrl->m_strTitle);

			break;

		case 2:
			ptCenter = rtTitle.CenterPoint();
			rtTitle.left = max(ptCenter.x - szChar.cx / 2, pRect->left);
			rtTitle.right = min(ptCenter.x + szChar.cx / 2, pRect->right);

			pDC->TextOut(ptCenter.x, rtTitle.top + 10, m_pCtrl->m_strTitle);

			break;
		}

		if (rtMid.right <= rtMid.left || rtMid.bottom <= rtMid.top)
			return FALSE;
	}

	if (m_pCtrl->m_strFooter.GetLength())
	{
		switch (m_pCtrl->GetFooterAlignment())
		{
		case 0:
			pDC->SetTextAlign(TA_LEFT);
			break;

		case 1:
			pDC->SetTextAlign(TA_RIGHT);
			break;

		case 2:
			pDC->SetTextAlign(TA_CENTER);
			break;
		}

		szChar = pDC->GetOutputTextExtent(m_pCtrl->m_strFooter);
		rtFooter.CopyRect(pRect);
		rtFooter.top = rtFooter.bottom - 20 - szChar.cy;

		if (rtFooter.top < rtTitle.bottom || rtFooter.bottom > pRect->bottom)
		{
			rtFooter.left = rtFooter.right = rtFooter.top = rtFooter.bottom = 0;
			goto exitTitle;
		}

		rtMid.bottom = rtFooter.top;

//		pDC->MoveTo(rtFooter.left - 10, rtFooter.top + 15);
//		pDC->LineTo(rtFooter.right + 10, rtFooter.top + 15);
//		pDC->LineTo(rtFooter.right + 10, rtFooter.bottom - 15);
//		pDC->LineTo(rtFooter.left - 10, rtFooter.bottom - 15);
//		pDC->LineTo(rtFooter.left - 10, rtFooter.top + 15);

		if (!m_bFntDirty)
		{
			m_pFntOld = m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntFooter);
			m_bFntDirty = TRUE;
		}
		else
			m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntFooter);

		switch (m_pCtrl->GetFooterAlignment())
		{
		case 0:
			rtFooter.right = rtFooter.left + szChar.cx;
			rtFooter.right = min(rtFooter.right, pRect->right);

			pDC->TextOut(rtFooter.left, rtFooter.top + 10, m_pCtrl->m_strFooter);

			break;

		case 1:
			rtFooter.left = rtFooter.right - szChar.cx;
			rtFooter.left = min(rtFooter.left, pRect->left);

			pDC->TextOut(rtFooter.right, rtFooter.top + 10, m_pCtrl->m_strFooter);

			break;

		case 2:
			ptCenter = rtFooter.CenterPoint();
			rtFooter.left = max(ptCenter.x - szChar.cx / 2, pRect->left);
			rtFooter.right = min(ptCenter.x + szChar.cx / 2, pRect->right);

			pDC->TextOut(ptCenter.x, rtFooter.top + 10, m_pCtrl->m_strFooter);

			break;
		}

		if (rtMid.right <= rtMid.left || rtMid.bottom <= rtMid.top)
			return FALSE;
	}

exitTitle:
	
	m_rtPic.CopyRect(&rtMid);

	if (m_pCtrl->m_bDrawLegend)
	{
		pDC->SetTextAlign(TA_LEFT);

		szChar = pDC->GetOutputTextExtent(_T("C"));

		rtLegend.CopyRect(&rtMid);
		rtLegend.left = rtLegend.right - szChar.cx * 7;
		rtLegend.right -= szChar.cx;
		m_rtPic.right = rtLegend.left - szChar.cx * 2;

		nLegendHeight = szChar.cy * m_nSeriesesToDraw;
		if (m_nSeriesesIncluded > 1)
			nLegendHeight += (m_nSeriesesToDraw - 1) * 5;

		rtPiece.left = rtLegend.left + szChar.cx;
		rtPiece.right = rtPiece.left + szChar.cx;
		rtLegendDraw.left = rtPiece.left;
		rtLegendDraw.right = rtPiece.right;
		rtLegendDraw.top = rtMid.top + (rtMid.Height() - nLegendHeight) / 2;
		rtLegendDraw.bottom = rtLegendDraw.top + nLegendHeight; 

		rtLegendDraw.top = max(rtLegendDraw.top, rtMid.top);
		rtLegendDraw.top = min(rtLegendDraw.top, rtMid.bottom);
		rtLegendDraw.bottom = min(rtLegendDraw.bottom, rtMid.bottom);

		if (rtLegendDraw.right <= rtLegendDraw.left)
			return FALSE;

//		if (m_pCtrl->m_strTitle.GetLength() && (rtLegendDraw.left < rtTitle.right + 10 || rtLegendDraw.left < rtFooter.right + 10))
//			return FALSE;

		if (!m_bFntDirty)
		{
			m_pFntOld = m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntLegend);
			m_bFntDirty = TRUE;
		}
		else
			m_pCtrl->SelectFontObject(pDC, m_pCtrl->m_fntLegend);

		for (i = 0, j = 0; i < m_nSerieses; i ++)
		{
			if (m_pCtrl->m_arUsage[i] == 0)
			{
				rtPiece.top = rtLegendDraw.top + (szChar.cy + 5) * j;
				rtPiece.bottom = rtPiece.top + szChar.cy;

				strLegend = m_pCtrl->m_arSeriesTitle[i];

				if (!m_bBrhDirty)
				{
					m_pBrhOld = pDC->SelectObject(&m_pBrhArr[j]);
					m_bBrhDirty = TRUE;
				}
				else
					pDC->SelectObject(&m_pBrhArr[j]);

				pDC->Rectangle(&rtPiece);
				pDC->TextOut(rtPiece.right + szChar.cx, rtPiece.top, strLegend);

				j ++;
			}
		}
	}

	return TRUE;
}

void CChart::SetCtrl(CKCOMChartCtrl *pCtrl)
{
	m_pCtrl = pCtrl;
}

void CChart::FinishDraw(const CRect *pRect, CDC *pDC)
{
	m_arTotal.RemoveAll();

	if (m_bBrhDirty)
		pDC->SelectObject(m_pBrhOld);

	if (m_bFntDirty)
		pDC->SelectObject(m_pFntOld);

	if (m_pBrhArr)
	{
		delete[] m_pBrhArr;
		m_pBrhArr = NULL;
	}

	pDC->SetTextAlign(TA_LEFT);
	SelectClipRgn(pDC->m_hDC, m_rgnOld);

	m_rgn.DeleteObject();

}
