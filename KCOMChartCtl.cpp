// KCOMChartCtl.cpp : Implementation of the CKCOMChartCtrl ActiveX Control class.

#include "stdafx.h"
#include <msstkppg.h>
#include <atlconv.h>
#include "KCOMChart.h"
#include "KCOMChartCtl.h"
#include "KCOMChartPpg.h"
#include "GroupPropPage.h"
#include "oleimpl2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CKCOMChartCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CKCOMChartCtrl, COleControl)
	//{{AFX_MSG_MAP(CKCOMChartCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CKCOMChartCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CKCOMChartCtrl)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "Title", GetTitle, SetTitle, VT_BSTR)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "Footer", GetFooter, SetFooter, VT_BSTR)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "TitleAlignment", GetTitleAlignment, SetTitleAlignment, VT_I4)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "FooterAlignment", GetFooterAlignment, SetFooterAlignment, VT_I4)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "DrawLegend", GetDrawLegend, SetDrawLegend, VT_BOOL)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "DrawGroupTitle", GetDrawGroupTitle, SetDrawGroupTitle, VT_BOOL)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "CanRedraw", GetCanRedraw, SetCanRedraw, VT_BOOL)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "TitleFont", GetTitleFont, SetTitleFont, VT_FONT)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "FooterFont", GetFooterFont, SetFooterFont, VT_FONT)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "LegendFont", GetLegendFont, SetLegendFont, VT_FONT)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "SeriesCount", GetSeriesCount, SetSeriesCount, VT_I4)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "GroupCount", GetGroupCount, SetGroupCount, VT_I4)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "DataMember", GetDataMember, SetDataMember, VT_BSTR)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "DataSource", GetDataSource, SetDataSource, VT_UNKNOWN)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "DataMode", GetDataMode, SetDataMode, VT_I4)
	DISP_PROPERTY_EX(CKCOMChartCtrl, "GroupPointed", GetGroupPointed, SetNotSupported, VT_I4)
	DISP_FUNCTION(CKCOMChartCtrl, "AddGroup", AddGroup, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CKCOMChartCtrl, "RemoveGroup", RemoveGroup, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CKCOMChartCtrl, "AddSeries", AddSeries, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CKCOMChartCtrl, "RemoveSeries", RemoveSeries, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CKCOMChartCtrl, "ReBind", ReBind, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_PARAM(CKCOMChartCtrl, "Value", GetValue, SetValue, VT_R8, VTS_I4 VTS_I4)
	DISP_PROPERTY_PARAM(CKCOMChartCtrl, "SeriesColor", GetSeriesColor, SetSeriesColor, VT_COLOR, VTS_I4)
	DISP_PROPERTY_PARAM(CKCOMChartCtrl, "SeriesUsage", GetSeriesUsage, SetSeriesUsage, VT_I4, VTS_I4)
	DISP_PROPERTY_PARAM(CKCOMChartCtrl, "GroupTitle", GetGroupTitle, SetGroupTitle, VT_BSTR, VTS_I4)
	DISP_PROPERTY_PARAM(CKCOMChartCtrl, "SeriesTitle", GetSeriesTitle, SetSeriesTitle, VT_BSTR, VTS_I4)
	DISP_STOCKFUNC_REFRESH()
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_APPEARANCE()
	DISP_STOCKPROP_BORDERSTYLE()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CKCOMChartCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CKCOMChartCtrl, COleControl)
	//{{AFX_EVENT_MAP(CKCOMChartCtrl)
	EVENT_STOCK_CLICK()
	EVENT_STOCK_DBLCLICK()
	EVENT_STOCK_KEYDOWN()
	EVENT_STOCK_KEYPRESS()
	EVENT_STOCK_KEYUP()
	EVENT_STOCK_MOUSEMOVE()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CKCOMChartCtrl, 4)
	PROPPAGEID(CKCOMChartPropPage::guid)
	PROPPAGEID(CGroupPropPage::guid)
	PROPPAGEID(CLSID_StockColorPage)
	PROPPAGEID(CLSID_StockFontPage)
END_PROPPAGEIDS(CKCOMChartCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CKCOMChartCtrl, "KCOMCHART.KCOMChartCtrl.1",
	0x503612a5, 0x50b5, 0x11d3, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CKCOMChartCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DKCOMChart =
		{ 0x503612a3, 0x50b5, 0x11d3, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };
const IID BASED_CODE IID_DKCOMChartEvents =
		{ 0x503612a4, 0x50b5, 0x11d3, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwKCOMChartOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CKCOMChartCtrl, IDS_KCOMCHART, _dwKCOMChartOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::CKCOMChartCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CKCOMChartCtrl

BOOL CKCOMChartCtrl::CKCOMChartCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_KCOMCHART,
			IDB_KCOMCHART,
			afxRegApartmentThreading,
			_dwKCOMChartOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::CKCOMChartCtrl - Constructor

CKCOMChartCtrl::CKCOMChartCtrl() : m_fntTitle(NULL), m_fntFooter(NULL), m_fntLegend(NULL)
{
	InitializeIIDs(&IID_DKCOMChart, &IID_DKCOMChartEvents);

	m_bDrawGroupTitle = TRUE;
	m_spDataSource = NULL;
	
//	srand(GetTickCount());

	pie.SetCtrl(this);
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::~CKCOMChartCtrl - Destructor

CKCOMChartCtrl::~CKCOMChartCtrl()
{
	ClearData();

	if (m_spDataSource)
	{
		m_spDataSource->Release();
		m_spDataSource = NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::OnDraw - Drawing function

void CKCOMChartCtrl::OnDraw(
			CDC* pDC, const CRect& rcBounds, const CRect& rcInvalid)
{
	COLORREF clrBack = TranslateColor(GetBackColor());

	pDC->FillSolidRect(&rcBounds, clrBack);
	pDC->SetBkColor(clrBack);

	pie.Draw(&rcBounds, pDC);
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::DoPropExchange - Persistence support

void CKCOMChartCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	ASSERT_POINTER(pPX, CPropExchange);

	ExchangeExtent(pPX);
	ExchangeStockProps(pPX);

	PX_Bool(pPX, _T("DrawLegend"), m_bDrawLegend, TRUE);
	PX_Bool(pPX, _T("DrawGroupTitle"), m_bDrawGroupTitle, TRUE);
	PX_String(pPX, _T("Title"), m_strTitle, _T("Title"));
	PX_String(pPX, _T("Footer"), m_strFooter, _T("Footer"));
	PX_Long(pPX, _T("TitleAlignment"), m_nTitleAlignment, 2);
	PX_Long(pPX, _T("FooterAlignment"), m_nFooterAlignment, 2);
	PX_Font(pPX, "TitleFont", m_fntTitle, &_KCOMFontDescDefault);
	PX_Font(pPX, "FooterFont", m_fntFooter, &_KCOMFontDescDefault);
	PX_Font(pPX, "LegendFont", m_fntLegend, &_KCOMFontDescDefault);
	PX_Long(pPX, _T("GroupCount"), m_nGroupCount, 1);
	PX_Long(pPX, _T("SeriesCount"), m_nSeriesCount, 3);
	PX_Long(pPX, "DataMode", m_nDataMode, 0);

	if (pPX->IsLoading())
		InitData();
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::OnResetState - Reset control to default state

void CKCOMChartCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl::AboutBox - Display an "About" box to the user

void CKCOMChartCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_KCOMCHART);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartCtrl message handlers

BSTR CKCOMChartCtrl::GetTitle() 
{
	return m_strTitle.AllocSysString();
}

void CKCOMChartCtrl::SetTitle(LPCTSTR lpszNewValue) 
{
	m_strTitle = lpszNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidTitle);
	InvalidateControl();
}

BSTR CKCOMChartCtrl::GetFooter() 
{
	return m_strFooter.AllocSysString();
}

void CKCOMChartCtrl::SetFooter(LPCTSTR lpszNewValue) 
{
	m_strFooter = lpszNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidFooter);
	InvalidateControl();
}

long CKCOMChartCtrl::GetTitleAlignment() 
{
	return m_nTitleAlignment;
}

void CKCOMChartCtrl::SetTitleAlignment(long nNewValue) 
{
	m_nTitleAlignment = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidTitleAlignment);
	InvalidateControl();
}

long CKCOMChartCtrl::GetFooterAlignment() 
{
	return m_nFooterAlignment;
}

void CKCOMChartCtrl::SetFooterAlignment(long nNewValue) 
{
	m_nFooterAlignment = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidFooterAlignment);
	InvalidateControl();
}

BOOL CKCOMChartCtrl::GetDrawLegend() 
{
	return m_bDrawLegend;
}

void CKCOMChartCtrl::SetDrawLegend(BOOL bNewValue) 
{
	m_bDrawLegend = bNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidDrawLegend);
	InvalidateControl();
}

BOOL CKCOMChartCtrl::GetDrawGroupTitle() 
{
	return m_bDrawGroupTitle;
}

void CKCOMChartCtrl::SetDrawGroupTitle(BOOL bNewValue) 
{
	m_bDrawGroupTitle = bNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidDrawGroupTitle);
	InvalidateControl();
}

BOOL CKCOMChartCtrl::GetCanRedraw() 
{
	if (!AmbientUserMode())
		GetNotSupported();

	return m_bCanRedraw;
}

void CKCOMChartCtrl::SetCanRedraw(BOOL bNewValue) 
{
	if (!AmbientUserMode())
		GetNotSupported();

	m_bCanRedraw = bNewValue;
	SetRedraw(m_bCanRedraw);
}

void CKCOMChartCtrl::ExchangeStockProps(CPropExchange *pPX)
{
	BOOL bLoading = pPX->IsLoading();
	DWORD dwStockPropMask = GetStockPropMask();
	DWORD dwPersistMask = dwStockPropMask;

	PX_ULong(pPX, _T("_StockProps"), dwPersistMask);

	if (dwStockPropMask & (STOCKPROP_CAPTION | STOCKPROP_TEXT))
	{
		CString strText;

		if (dwPersistMask & (STOCKPROP_CAPTION | STOCKPROP_TEXT))
		{
			if (!bLoading)
				strText = InternalGetText();
			if (dwStockPropMask & STOCKPROP_CAPTION)
				PX_String(pPX, _T("Caption"), strText, _T(""));
			if (dwStockPropMask & STOCKPROP_TEXT)
				PX_String(pPX, _T("Text"), strText, _T(""));
		}
		if (bLoading)
		{
			TRY
				SetText(strText);
			END_TRY
		}
	}

	if (dwStockPropMask & STOCKPROP_FORECOLOR)
	{
		if (dwPersistMask & STOCKPROP_FORECOLOR)
			PX_Color(pPX, _T("ForeColor"), m_clrForeColor, AmbientForeColor());
		else if (bLoading)
			m_clrForeColor = AmbientForeColor();
	}

	if (dwStockPropMask & STOCKPROP_BACKCOLOR)
	{
		if (dwPersistMask & STOCKPROP_BACKCOLOR)
			PX_Color(pPX, _T("BackColor"), m_clrBackColor, AmbientBackColor());
		else if (bLoading)
			m_clrBackColor = AmbientBackColor();
	}

	if (dwStockPropMask & STOCKPROP_FONT)
	{
		LPFONTDISP pFontDispAmbient = AmbientFont();
		BOOL bChanged = TRUE;

		if (dwPersistMask & STOCKPROP_FONT)
			bChanged = PX_Font(pPX, _T("Font"), m_font, NULL, pFontDispAmbient);
		else if (bLoading)
			m_font.InitializeFont(NULL, pFontDispAmbient);

		if (bLoading && bChanged)
			OnFontChanged();

		RELEASE(pFontDispAmbient);
	}

	if (dwStockPropMask & STOCKPROP_BORDERSTYLE)
	{
		short sBorderStyle = m_sBorderStyle;

		if (dwPersistMask & STOCKPROP_BORDERSTYLE)
			PX_Short(pPX, _T("BorderStyle"), m_sBorderStyle, 1);
		else if (bLoading)
			m_sBorderStyle = 0;

		if (sBorderStyle != m_sBorderStyle)
			_AfxToggleBorderStyle(this);
	}

	if (dwStockPropMask & STOCKPROP_ENABLED)
	{
		BOOL bEnabled = m_bEnabled;

		if (dwPersistMask & STOCKPROP_ENABLED)
			PX_Bool(pPX, _T("Enabled"), m_bEnabled, TRUE);
		else if (bLoading)
			m_bEnabled = TRUE;

		if ((bEnabled != m_bEnabled) && (m_hWnd != NULL))
			::EnableWindow(m_hWnd, m_bEnabled);
	}

	if (dwStockPropMask & STOCKPROP_APPEARANCE)
	{
		short sAppearance = m_sAppearance;

		if (dwPersistMask & STOCKPROP_APPEARANCE)
			PX_Short(pPX, _T("Appearance"), m_sAppearance, 0);
		else if (bLoading)
			m_sAppearance = AmbientAppearance();

		if (sAppearance != m_sAppearance)
			_AfxToggleAppearance(this);
	}
}

LPFONTDISP CKCOMChartCtrl::GetTitleFont() 
{
	return m_fntTitle.GetFontDispatch();
}

void CKCOMChartCtrl::SetTitleFont(LPFONTDISP newValue) 
{
	m_fntTitle.InitializeFont(NULL, newValue);

	SetModifiedFlag();
	BoundPropertyChanged(dispidTitleFont);
	InvalidateControl();
}

LPFONTDISP CKCOMChartCtrl::GetFooterFont() 
{
	return m_fntFooter.GetFontDispatch();
}

void CKCOMChartCtrl::SetFooterFont(LPFONTDISP newValue) 
{
	m_fntFooter.InitializeFont(NULL, newValue);

	SetModifiedFlag();
	BoundPropertyChanged(dispidFooterFont);
	InvalidateControl();
}

LPFONTDISP CKCOMChartCtrl::GetLegendFont() 
{
	return m_fntLegend.GetFontDispatch();
}

void CKCOMChartCtrl::SetLegendFont(LPFONTDISP newValue) 
{
	m_fntLegend.InitializeFont(NULL, newValue);

	SetModifiedFlag();
	BoundPropertyChanged(dispidLegendFont);
	InvalidateControl();
}

BOOL CKCOMChartCtrl::OnGetDisplayString(DISPID dispid, CString& strValue) 
{
	if (dispid == DISPID_APPEARANCE)
	{
		strValue.LoadString(GetAppearance() ? IDS_APPEARANCE_3D : IDS_APPEARANCE_FLAT);

		return TRUE;
	}
	
	return COleControl::OnGetDisplayString(dispid, strValue);
}

BOOL CKCOMChartCtrl::OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray) 
{
	if (dispid == DISPID_APPEARANCE)
	{
		CString strAppearance;
		strAppearance.LoadString(IDS_APPEARANCE_FLAT);
		pStringArray->Add(strAppearance);
		strAppearance.LoadString(IDS_APPEARANCE_3D);
		pStringArray->Add(strAppearance);

		pCookieArray->Add(0);
		pCookieArray->Add(1);

		return TRUE;
	}
	
	return COleControl::OnGetPredefinedStrings(dispid, pStringArray, pCookieArray);
}

BOOL CKCOMChartCtrl::OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut) 
{
	if (dispid == DISPID_APPEARANCE)
	{
		VariantInit(lpvarOut);
		lpvarOut->vt = VT_I4;
		lpvarOut->lVal = dwCookie;

		return TRUE;
	}
	
	return COleControl::OnGetPredefinedValue(dispid, dwCookie, lpvarOut);
}

long CKCOMChartCtrl::GetSeriesCount() 
{
	return m_arUsage.GetSize();
}

void CKCOMChartCtrl::SetSeriesCount(long nNewValue) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_READONLYINBOUNDMODE);

	if (nNewValue <= 0)
		nNewValue = 1;

	if (nNewValue < GetSeriesCount())
	{
		while (GetSeriesCount() > nNewValue)
			DeleteSeries();
	}
	else
	{
		while (GetSeriesCount() < nNewValue)
			InsertSeries();
	}

	m_nSeriesCount = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidSeriesCount);
	InvalidateControl();
}

double CKCOMChartCtrl::GetValue(long GroupIndex, long SeriesIndex) 
{
	if (GroupIndex < 0 || GroupIndex >= GetGroupCount() || SeriesIndex < 0 
		|| SeriesIndex >= GetSeriesCount())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return m_arDatas[GroupIndex][SeriesIndex];
}

void CKCOMChartCtrl::SetValue(long GroupIndex, long SeriesIndex, double newValue) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_READONLYINBOUNDMODE);

	if (GroupIndex < 0 || GroupIndex >= GetGroupCount() || SeriesIndex < 0 
		|| SeriesIndex >= GetSeriesCount())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	m_arDatas[GroupIndex][SeriesIndex] = fabs(newValue);
}

long CKCOMChartCtrl::GetGroupCount() 
{
	return m_arDatas.GetSize();
}

void CKCOMChartCtrl::SetGroupCount(long nNewValue) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_READONLYINBOUNDMODE);

	if (nNewValue <= 0)
		nNewValue = 1;

	if (nNewValue < GetGroupCount())
	{
		while (GetGroupCount() > nNewValue)
			DeleteGroup();
	}
	else
	{
		while (GetGroupCount() < nNewValue)
			InsertGroup();
	}

	m_nGroupCount = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidSeriesCount);
	InvalidateControl();
}

void CKCOMChartCtrl::InitData()
{
	ClearData();

	while(GetGroupCount() < m_nGroupCount)
		InsertGroup();
	
	while (GetSeriesCount() < m_nSeriesCount)
		InsertSeries();
}

void CKCOMChartCtrl::ClearData()
{
	for (int i = 0; i < m_arDatas.GetSize(); i ++)
		delete[] m_arDatas[i];

	m_arDatas.RemoveAll();
	m_arUsage.RemoveAll();
	m_arSeriesColor.RemoveAll();
	m_arGroupTitle.RemoveAll();
	m_arSeriesTitle.RemoveAll();
	m_nGroupOrdinalUsed = m_nSeriesOrdinalUsed = 0;
	m_arGroupRect.RemoveAll();
}

void CKCOMChartCtrl::AddGroup(const VARIANT FAR& GroupIndex) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_UNAVAILABLEINBOUNDMODE);

	InsertGroup(GetIndexFromVariant(GroupIndex));

	m_nGroupCount ++;
	InvalidateControl();
}

long CKCOMChartCtrl::GetIndexFromVariant(const VARIANT &Index)
{
	if (Index.vt == VT_ERROR)
		return -1;

	COleVariant vaNew = Index;
	vaNew.ChangeType(VT_BSTR);
	vaNew.ChangeType(VT_I4);

	return vaNew.lVal;
}

void CKCOMChartCtrl::InsertGroup(long nIndex)
{
	if (nIndex > m_arDatas.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	double * pData = new double[m_nSeriesCount];

	for (int i = 0; i < m_nSeriesCount; i ++)
		pData[i] = rand() % 10;

	if (nIndex < 0)
		nIndex = m_arDatas.GetSize();

	m_arDatas.InsertAt(nIndex, pData);

	CString strTitle;
	strTitle.Format("R%3d", ++ m_nGroupOrdinalUsed);
	m_arGroupTitle.InsertAt(nIndex, strTitle);
}

void CKCOMChartCtrl::DeleteGroup(long nIndex)
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_UNAVAILABLEINBOUNDMODE);

	if (nIndex >= m_arDatas.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	if (nIndex < 0)
		nIndex = m_arDatas.GetSize() - 1;

	delete[] m_arDatas[nIndex];
	m_arDatas.RemoveAt(nIndex);
	m_arGroupTitle.RemoveAt(nIndex);
}

void CKCOMChartCtrl::RemoveGroup(const VARIANT FAR& GroupIndex) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_UNAVAILABLEINBOUNDMODE);

	DeleteGroup(GetIndexFromVariant(GroupIndex));

	m_nGroupCount --;
	InvalidateControl();
}

void CKCOMChartCtrl::AddSeries(const VARIANT FAR& SeriesIndex) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_UNAVAILABLEINBOUNDMODE);

	InsertSeries(GetIndexFromVariant(SeriesIndex));

	m_nSeriesCount ++;
	InvalidateControl();
}

void CKCOMChartCtrl::RemoveSeries(const VARIANT FAR& SeriesIndex) 
{
	if (m_nDataMode == 0)
		ThrowError(CTL_E_SETNOTPERMITTED, IDS_E_UNAVAILABLEINBOUNDMODE);

	DeleteSeries(GetIndexFromVariant(SeriesIndex));

	m_nSeriesCount --;
	InvalidateControl();
}

void CKCOMChartCtrl::InsertSeries(long nIndex)
{
	if (nIndex > m_arUsage.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	if (nIndex < 0)
		nIndex = m_arUsage.GetSize();

	m_arUsage.InsertAt(nIndex, 0);
	m_arSeriesColor.InsertAt(nIndex, RGB(rand() % 256, rand() % 256, rand() % 256));

	int i, j, k, nSeriesCount = m_arUsage.GetSize();
	double * pData, * pNewData;
		
	for (i = 0; i < m_arDatas.GetSize(); i ++)
	{
		pData = m_arDatas[i];
		pNewData = new double[nSeriesCount];

		for (j = 0, k = 0; j < nIndex; j ++)
			pNewData[k ++] = pData[j];

		pNewData[k ++] = rand() % 10;

		for (j = nIndex; j < nSeriesCount - 1; j ++)
			pNewData[k ++] = pData[j];

		delete[] pData;
		m_arDatas.SetAt(i, pNewData);
	}

	CString strTitle;
	strTitle.Format("C%3d", ++ m_nSeriesOrdinalUsed);
	m_arSeriesTitle.InsertAt(nIndex, strTitle);
}

void CKCOMChartCtrl::DeleteSeries(long nIndex)
{
	if (nIndex >= m_arUsage.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	int i, j, k, nSeriesCount = m_arUsage.GetSize();
	double * pData, * pNewData;
		
	if (nIndex < 0)
		nIndex = nSeriesCount - 1;

	m_arUsage.RemoveAt(nIndex);
	m_arSeriesColor.RemoveAt(nIndex);

	for (i = 0; i < m_arDatas.GetSize(); i ++)
	{
		pData = m_arDatas[i];
		pNewData = new double[nSeriesCount];

		for (j = 0, k = 0; j < nIndex; j ++)
			pNewData[k ++] = pData[j];

		j ++;

		for (; j < nSeriesCount; j ++)
			pNewData[k ++] = pData[j];

		delete pData;
		m_arDatas.SetAt(i, pNewData);
	}

	m_arSeriesTitle.RemoveAt(nIndex);
}

OLE_COLOR CKCOMChartCtrl::GetSeriesColor(long SeriesIndex) 
{
	if (SeriesIndex <0 || SeriesIndex >= m_arSeriesColor.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return (OLE_COLOR)m_arSeriesColor[SeriesIndex];
}

void CKCOMChartCtrl::SetSeriesColor(long SeriesIndex, OLE_COLOR nNewValue) 
{
	if (SeriesIndex < 0 || SeriesIndex >= m_arSeriesColor.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	m_arSeriesColor[SeriesIndex] = TranslateColor(nNewValue);

	InvalidateControl();
}

long CKCOMChartCtrl::GetSeriesUsage(long SeriesIndex) 
{
	if (SeriesIndex < 0 || SeriesIndex >= m_arUsage.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return m_arUsage[SeriesIndex];
}

void CKCOMChartCtrl::SetSeriesUsage(long SeriesIndex, long nNewValue) 
{
	if (SeriesIndex < 0 || SeriesIndex >= m_arUsage.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	if (nNewValue < 0 || nNewValue > 2)
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, AFX_IDP_E_INVALIDPROPERTYVALUE);

	m_arUsage[SeriesIndex] = nNewValue;

	InvalidateControl();
}

BSTR CKCOMChartCtrl::GetGroupTitle(long GroupIndex) 
{
	if (GroupIndex < 0 || GroupIndex >= m_arGroupTitle.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return m_arGroupTitle[GroupIndex].AllocSysString();
}

void CKCOMChartCtrl::SetGroupTitle(long GroupIndex, LPCTSTR lpszNewValue) 
{
	if (GroupIndex < 0 || GroupIndex >= m_arGroupTitle.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	m_arGroupTitle[GroupIndex] = lpszNewValue;

	InvalidateControl();
}

BSTR CKCOMChartCtrl::GetSeriesTitle(long SeriesIndex) 
{
	if (SeriesIndex < 0 || SeriesIndex >= m_arSeriesTitle.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	return m_arSeriesTitle[SeriesIndex].AllocSysString();
}

void CKCOMChartCtrl::SetSeriesTitle(long SeriesIndex, LPCTSTR lpszNewValue)
{
	if (SeriesIndex < 0 || SeriesIndex >= m_arSeriesTitle.GetSize())
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, AFX_IDP_E_INVALIDPROPERTYARRAYINDEX);

	m_arSeriesTitle[SeriesIndex] = lpszNewValue;

	InvalidateControl();
}

BSTR CKCOMChartCtrl::GetDataMember() 
{
	return m_strDataMember.AllocSysString();
}

void CKCOMChartCtrl::SetDataMember(LPCTSTR lpszNewValue) 
{
	if (m_nDataMode != 0)
		ThrowError(CTL_E_SETNOTSUPPORTED, _T("Can not set datasource in manual mode"));

	if (m_strDataMember == lpszNewValue)
		return;

	m_strDataMember = lpszNewValue;

	ReBind();
}

LPUNKNOWN CKCOMChartCtrl::GetDataSource() 
{
	if (m_spDataSource)
		m_spDataSource->AddRef();

	return m_spDataSource;
}

void CKCOMChartCtrl::SetDataSource(LPUNKNOWN newValue) 
{
	if (m_spDataSource)
	{
		m_spDataSource->Release();
		m_spDataSource = NULL;
	}

	if (m_nDataMode != 0 && newValue)
	{
		ThrowError(CTL_E_SETNOTSUPPORTED, _T("Can not set datasource in manual mode"));
		return;
	}

	if (newValue == m_spDataSource)
		return;

	if (!newValue)
	{
		m_spDataSource = NULL;
		ReBind();
		return;
	}

	newValue->QueryInterface(__uuidof(m_spDataSource), (void **)&m_spDataSource);
	ReBind();
}

long CKCOMChartCtrl::GetDataMode() 
{
	return m_nDataMode;
}

void CKCOMChartCtrl::SetDataMode(long nNewValue) 
{
	if (AmbientUserMode())
		ThrowError(CTL_E_SETNOTSUPPORTEDATRUNTIME);

	if (nNewValue == 0)
		m_nDataMode = 0;
	else
	{
		if (m_spDataSource)
			ThrowError(CTL_E_SETNOTSUPPORTED, IDS_ERROR_NOCHANGETOMANUALMODE);
		else
			m_nDataMode = 1;
	}

	SetModifiedFlag();
	BoundPropertyChanged(dispidDataMode);
}

void CKCOMChartCtrl::ReBind() 
{
	USES_CONVERSION;

	if (m_nDataMode || !AmbientUserMode())
		return;

	ClearData();

	_RecordsetPtr pRs;
	FieldPtr pField[255], pFldCurr;
	int nFields, nFieldsBound;
	long i;
	double * pData;

	if (!m_spDataSource)
		goto exit;

	if (FAILED(pRs.CreateInstance(__uuidof(Recordset))))
		goto exit;

	pRs->putref_DataSource(m_spDataSource);

	nFields = pRs->Fields->GetCount();
	if (nFields == 0)
		goto exit;

	for (i = 0, nFieldsBound = 0; i < nFields; i ++)
	{
		pFldCurr = pRs->Fields->GetItem(_variant_t(i));
		
		switch (pFldCurr->GetType())
		{
		case adTinyInt:
		case adSmallInt:
		case adInteger:
		case adBigInt:
		case adUnsignedTinyInt:
		case adUnsignedSmallInt:
		case adUnsignedInt:
		case adUnsignedBigInt:
		case adSingle:
		case adDouble:
		case adCurrency:
		case adDecimal:
		case adNumeric:
			pField[nFieldsBound ++] = pFldCurr;
		}
	}

	m_nSeriesCount = nFieldsBound;

	for (i = 0; i < m_nSeriesCount; i ++)
	{
		m_arUsage.Add(0);
		m_arSeriesColor.Add(RGB(rand() % 256, rand() % 256, rand() % 256));
		m_arSeriesTitle.Add(OLE2T(pField[i]->Name));
	}

	if (FAILED(pRs->MoveFirst()))
		goto exit;

	m_nGroupCount = 0;

	while (VARIANT_FALSE == pRs->EndOfFile)
	{
		pData = new double[m_nSeriesCount];

		for (i = 0; i < m_nSeriesCount; i ++)
			pData[i] = (double)pField[i]->Value;

		m_arDatas.Add(pData);
		m_nGroupCount ++;

		pRs->MoveNext();
	}

exit:

	InvalidateControl();
}

long CKCOMChartCtrl::GetGroupPointed() 
{
	POINT pt;
	
	if (!GetCursorPos(&pt))
		return -1;

	ScreenToClient(&pt);

	for (int i = 0; i < m_arGroupRect.GetSize(); i ++)
	{
		if (m_arGroupRect[i].left != -1 && m_arGroupRect[i].PtInRect(pt))
			return i;
	}

	return -1;
}
