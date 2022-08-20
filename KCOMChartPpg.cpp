// KCOMChartPpg.cpp : Implementation of the CKCOMChartPropPage property page class.

#include "stdafx.h"
#include "KCOMChart.h"
#include "KCOMChartPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CKCOMChartPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CKCOMChartPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CKCOMChartPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CKCOMChartPropPage, "KCOMCHART.KCOMChartPropPage.1",
	0x503612a6, 0x50b5, 0x11d3, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartPropPage::CKCOMChartPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CKCOMChartPropPage

BOOL CKCOMChartPropPage::CKCOMChartPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_KCOMCHART_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartPropPage::CKCOMChartPropPage - Constructor

CKCOMChartPropPage::CKCOMChartPropPage() :
	COlePropertyPage(IDD, IDS_KCOMCHART_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CKCOMChartPropPage)
	m_sAppearance = -1;
	m_sBorderStyle = -1;
	m_nTitleAlignment = -1;
	m_nFooterAlignment = -1;
	m_bDrawLegend = FALSE;
	m_strTitle = _T("");
	m_strFooter = _T("");
	m_nSeriesCount = 0;
	m_nGroupCount = 0;
	m_bDrawGroupTitle = FALSE;
	m_nDataMode = -1;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartPropPage::DoDataExchange - Moves data between page and properties

void CKCOMChartPropPage::DoDataExchange(CDataExchange* pDX)
{
	int nMode = GetDataMode();

	GetDlgItem(IDC_EDIT_GROUPCOUNT)->EnableWindow(nMode);
	GetDlgItem(IDC_EDIT_SERIESCOUNT)->EnableWindow(nMode);

	//{{AFX_DATA_MAP(CKCOMChartPropPage)
	DDP_CBIndex(pDX, IDC_COMBO_APPEARANCE, m_sAppearance, _T("Appearance") );
	DDX_CBIndex(pDX, IDC_COMBO_APPEARANCE, m_sAppearance);
	DDP_CBIndex(pDX, IDC_COMBO_BORDERSTYLE, m_sBorderStyle, _T("BorderStyle") );
	DDX_CBIndex(pDX, IDC_COMBO_BORDERSTYLE, m_sBorderStyle);
	DDP_CBIndex(pDX, IDC_COMBO_TITLEALIGNMENT, m_nTitleAlignment, _T("TitleAlignment") );
	DDX_CBIndex(pDX, IDC_COMBO_TITLEALIGNMENT, m_nTitleAlignment);
	DDP_CBIndex(pDX, IDC_COMBO_FOOTERALIGNMENT, m_nFooterAlignment, _T("FooterAlignment") );
	DDX_CBIndex(pDX, IDC_COMBO_FOOTERALIGNMENT, m_nFooterAlignment);
	DDP_Check(pDX, IDC_CHECK_DRAWLEGEND, m_bDrawLegend, _T("DrawLegend") );
	DDX_Check(pDX, IDC_CHECK_DRAWLEGEND, m_bDrawLegend);
	DDP_Text(pDX, IDC_EDIT_TITLE, m_strTitle, _T("Title") );
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDP_Text(pDX, IDC_EDIT_FOOTER, m_strFooter, _T("Footer") );
	DDX_Text(pDX, IDC_EDIT_FOOTER, m_strFooter);
	DDP_Text(pDX, IDC_EDIT_SERIESCOUNT, m_nSeriesCount, _T("SeriesCount") );
	DDX_Text(pDX, IDC_EDIT_SERIESCOUNT, m_nSeriesCount);
	DDV_MinMaxLong(pDX, m_nSeriesCount, 1, 255);
	DDP_Text(pDX, IDC_EDIT_GROUPCOUNT, m_nGroupCount, _T("GroupCount") );
	DDX_Text(pDX, IDC_EDIT_GROUPCOUNT, m_nGroupCount);
	DDV_MinMaxLong(pDX, m_nGroupCount, 1, 255);
	DDP_Check(pDX, IDC_CHECK_DRAWGROUPTITLE, m_bDrawGroupTitle, _T("DrawGroupTitle") );
	DDX_Check(pDX, IDC_CHECK_DRAWGROUPTITLE, m_bDrawGroupTitle);
	DDP_CBIndex(pDX, IDC_COMBO_DATAMODE, m_nDataMode, _T("DataMode") );
	DDX_CBIndex(pDX, IDC_COMBO_DATAMODE, m_nDataMode);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CKCOMChartPropPage message handlers

BOOL CKCOMChartPropPage::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int CKCOMChartPropPage::GetDataMode()
{
	ULONG Ulong;
	LPDISPATCH FAR *m_lpDispatch = GetObjectArray(&Ulong);

	// Get the CCmdTarget object associated to any one of the above
	// array elements
	if (Ulong == 0)
		return 0;

	DISPPARAMS tParam;
	tParam.rgdispidNamedArgs = NULL;
	tParam.cArgs = 0;
	tParam.cNamedArgs = 0;
	tParam.rgvarg = 0;
	COleVariant va;

	HRESULT hr = m_lpDispatch[0]->Invoke(15, IID_NULL, LOCALE_USER_DEFAULT,
		DISPATCH_METHOD | DISPATCH_PROPERTYGET, &tParam, &va, NULL, NULL);

	return va.lVal;
}
