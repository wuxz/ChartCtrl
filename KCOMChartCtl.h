#if !defined(AFX_KCOMCHARTCTL_H__503612B3_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_KCOMCHARTCTL_H__503612B3_50B5_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// KCOMChartCtl.h : Declaration of the CKCOMChartCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl : See KCOMChartCtl.cpp for implementation.

#include "pie.h"
#include <msdatsrc.h>

class CKCOMChartCtrl : public COleControl
{
	DECLARE_DYNCREATE(CKCOMChartCtrl)

// Constructor
public:
	CKCOMChartCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKCOMChartCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual BOOL OnGetDisplayString(DISPID dispid, CString& strValue);
	virtual BOOL OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray);
	virtual BOOL OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CArray<double * , double * > m_arDatas;
	CArray<int, int> m_arUsage;
	CArray<COLORREF, COLORREF> m_arSeriesColor;
	CStringArray m_arGroupTitle, m_arSeriesTitle;
	int m_nGroupOrdinalUsed, m_nSeriesOrdinalUsed;
	CArray<CRect, CRect> m_arGroupRect;

	CPie pie;
	BOOL m_bDrawGroupTitle;

	// the number of the manually input columns data
	int m_nColsPreset;

	// the handle of the blob data serialize columns prop
	HGLOBAL m_hBlob;
protected:
	CString m_strTitle;
	CString m_strFooter;
	long m_nTitleAlignment;
	long m_nFooterAlignment;
	BOOL m_bDrawLegend;
	BOOL m_bCanRedraw;
	CFontHolder m_fntTitle, m_fntFooter, m_fntLegend;
	long m_nGroupCount, m_nSeriesCount;

	long m_nDataMode;
	IDataSource * m_spDataSource;
	CString m_strDataMember;

protected:
	void ClearData();
	void InitData();
	void ExchangeStockProps(CPropExchange *pPX);
	~CKCOMChartCtrl();

	DECLARE_OLECREATE_EX(CKCOMChartCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CKCOMChartCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CKCOMChartCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CKCOMChartCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CKCOMChartCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CKCOMChartCtrl)
	afx_msg BSTR GetTitle();
	afx_msg void SetTitle(LPCTSTR lpszNewValue);
	afx_msg BSTR GetFooter();
	afx_msg void SetFooter(LPCTSTR lpszNewValue);
	afx_msg long GetTitleAlignment();
	afx_msg void SetTitleAlignment(long nNewValue);
	afx_msg long GetFooterAlignment();
	afx_msg void SetFooterAlignment(long nNewValue);
	afx_msg BOOL GetDrawLegend();
	afx_msg void SetDrawLegend(BOOL bNewValue);
	afx_msg BOOL GetDrawGroupTitle();
	afx_msg void SetDrawGroupTitle(BOOL bNewValue);
	afx_msg BOOL GetCanRedraw();
	afx_msg void SetCanRedraw(BOOL bNewValue);
	afx_msg LPFONTDISP GetTitleFont();
	afx_msg void SetTitleFont(LPFONTDISP newValue);
	afx_msg LPFONTDISP GetFooterFont();
	afx_msg void SetFooterFont(LPFONTDISP newValue);
	afx_msg LPFONTDISP GetLegendFont();
	afx_msg void SetLegendFont(LPFONTDISP newValue);
	afx_msg long GetSeriesCount();
	afx_msg void SetSeriesCount(long nNewValue);
	afx_msg long GetGroupCount();
	afx_msg void SetGroupCount(long nNewValue);
	afx_msg BSTR GetDataMember();
	afx_msg void SetDataMember(LPCTSTR lpszNewValue);
	afx_msg LPUNKNOWN GetDataSource();
	afx_msg void SetDataSource(LPUNKNOWN newValue);
	afx_msg long GetDataMode();
	afx_msg void SetDataMode(long nNewValue);
	afx_msg long GetGroupPointed();
	afx_msg void AddGroup(const VARIANT FAR& GroupIndex);
	afx_msg void RemoveGroup(const VARIANT FAR& GroupIndex);
	afx_msg void AddSeries(const VARIANT FAR& SeriesIndex);
	afx_msg void RemoveSeries(const VARIANT FAR& SeriesIndex);
	afx_msg void ReBind();
	afx_msg double GetValue(long GroupIndex, long SeriesIndex);
	afx_msg void SetValue(long GroupIndex, long SeriesIndex, double newValue);
	afx_msg OLE_COLOR GetSeriesColor(long SeriesIndex);
	afx_msg void SetSeriesColor(long SeriesIndex, OLE_COLOR nNewValue);
	afx_msg long GetSeriesUsage(long SeriesIndex);
	afx_msg void SetSeriesUsage(long SeriesIndex, long nNewValue);
	afx_msg BSTR GetGroupTitle(long GroupIndex);
	afx_msg void SetGroupTitle(long GroupIndex, LPCTSTR lpszNewValue);
	afx_msg BSTR GetSeriesTitle(long SeriesIndex);
	afx_msg void SetSeriesTitle(long SeriesIndex, LPCTSTR lpszNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CKCOMChartCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	void DeleteSeries(long nIndex = -1);
	void InsertSeries(long nIndex = -1);
	void DeleteGroup(long nIndex = -1);
	void InsertGroup(long nIndex = -1);
	long GetIndexFromVariant(const VARIANT& Index);

	enum {
	//{{AFX_DISP_ID(CKCOMChartCtrl)
	dispidTitle = 1L,
	dispidFooter = 2L,
	dispidTitleAlignment = 3L,
	dispidFooterAlignment = 4L,
	dispidDrawLegend = 5L,
	dispidDrawGroupTitle = 6L,
	dispidCanRedraw = 7L,
	dispidTitleFont = 8L,
	dispidFooterFont = 9L,
	dispidLegendFont = 10L,
	dispidSeriesCount = 11L,
	dispidGroupCount = 12L,
	dispidDataMember = 13L,
	dispidDataSource = 14L,
	dispidDataMode = 15L,
	dispidGroupPointed = 16L,
	dispidValue = 22L,
	dispidAddGroup = 17L,
	dispidRemoveGroup = 18L,
	dispidAddSeries = 19L,
	dispidRemoveSeries = 20L,
	dispidSeriesColor = 23L,
	dispidSeriesUsage = 24L,
	dispidGroupTitle = 25L,
	dispidSeriesTitle = 26L,
	dispidReBind = 21L,
	//}}AFX_DISP_ID
	};

	friend class CChart;
	friend class CPie;
	friend class CGroupPropPage;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KCOMCHARTCTL_H__503612B3_50B5_11D3_A7FE_0080C8763FA4__INCLUDED)
