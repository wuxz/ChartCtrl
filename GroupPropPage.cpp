// GroupPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "KCOMChart.h"
#include "GroupPropPage.h"
#include "kcomchartctl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage dialog

IMPLEMENT_DYNCREATE(CGroupPropPage, COlePropertyPage)

#define pComboGroup ((CComboBox *)GetDlgItem(IDC_COMBO_GROUP))
#define pGroupTitle (GetDlgItem(IDC_EDIT_GROUPTITLE))

#define pComboSeries ((CComboBox *)GetDlgItem(IDC_COMBO_SERIES))
#define pSeriesTitle (GetDlgItem(IDC_EDIT_SERIESTITLE))
#define pUsageShow ((CButton *)GetDlgItem(IDC_RADIO_SHOW))
#define pUsageHide ((CButton *)GetDlgItem(IDC_RADIO_HIDE))
#define pUsageExclude ((CButton *)GetDlgItem(IDC_RADIO_EXCLUDE))
#define pSeriesTitle (GetDlgItem(IDC_EDIT_SERIESTITLE))
#define pChooseColor ((CButton *)GetDlgItem(IDC_BUTTON_CHOOSECOLOR))
#define pColor (GetDlgItem(IDC_COLOR))

/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CGroupPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CGroupPropPage)
	ON_CBN_SELENDOK(IDC_COMBO_GROUP, OnSelendokComboGroup)
	ON_CBN_SELENDOK(IDC_COMBO_SERIES, OnSelendokComboSeries)
	ON_EN_KILLFOCUS(IDC_EDIT_GROUPTITLE, OnKillfocusEditGrouptitle)
	ON_EN_KILLFOCUS(IDC_EDIT_SERIESTITLE, OnKillfocusEditSeriestitle)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSECOLOR, OnButtonChoosecolor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

// {42B6F561-54A5-11D3-A7FE-0080C8763FA4}
IMPLEMENT_OLECREATE_EX(CGroupPropPage, "KCOMChart.CGroupPropPage",
	0x42b6f561, 0x54a5, 0x11d3, 0xa7, 0xfe, 0x0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage::CGroupPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CGroupPropPage

BOOL CGroupPropPage::CGroupPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Define string resource for page type; replace '0' below with ID.

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_KCOMCHART_GROUP_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage::CGroupPropPage - Constructor

// TODO: Define string resource for page caption; replace '0' below with ID.

CGroupPropPage::CGroupPropPage() :
	COlePropertyPage(IDD, IDS_KCOMCHART_GROUP_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CGroupPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT

	m_pCtrl = NULL;
	m_wndGrid.SetPage(this);
}


/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage::DoDataExchange - Moves data between page and properties

void CGroupPropPage::DoDataExchange(CDataExchange* pDX)
{
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_DATA_MAP(CGroupPropPage)
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
	DDX_GridControl(pDX, IDC_GRID, m_wndGrid);

	int i, j;
	CString strItem;

	if (pDX->m_bSaveAndValidate)
	{
		m_pCtrl->m_arGroupTitle.RemoveAll();
		m_pCtrl->m_arGroupTitle.Append(m_arGroupTitle);
		m_pCtrl->m_arSeriesTitle.RemoveAll();
		m_pCtrl->m_arSeriesTitle.Append(m_arSeriesTitle);
		m_pCtrl->m_arUsage.RemoveAll();
		m_pCtrl->m_arUsage.Append(m_arUsage);
		m_pCtrl->m_arSeriesColor.RemoveAll();
		m_pCtrl->m_arSeriesColor.Append(m_arSeriesColor);

		double * pData;

		for (i = 0; i < m_wndGrid.GetRowCount() - 1; i ++)
		{
			pData = m_pCtrl->m_arDatas[i];

			for (j = 0; j < m_wndGrid.GetColumnCount() - 1; j ++)
			{
				strItem = m_wndGrid.GetItemText(i + 1, j + 1);
				pData[j] = atof(strItem);
			}
		}

		m_pCtrl->InvalidateControl();
	}
	else if (m_pCtrl && m_pCtrl->GetDataMode())
	{
		InitControls();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGroupPropPage message handlers

BOOL CGroupPropPage::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();

	ULONG Ulong;
	LPDISPATCH FAR *m_lpDispatch = GetObjectArray(&Ulong);
	
	if (Ulong)
		m_pCtrl = (CKCOMChartCtrl *) CCmdTarget::FromIDispatch(m_lpDispatch[0]);

	if (!m_pCtrl || m_pCtrl->GetDataMode() == 0)
	{
		DisableMe();

		return TRUE;
	}

	m_wndColor.SubclassDlgItem(IDC_COLOR, this);

	m_wndGrid.SetEditable(TRUE);
	m_wndGrid.SetListMode(FALSE);
	m_wndGrid.EnableDragAndDrop(TRUE);
	m_wndGrid.SetRowCount(m_pCtrl->GetGroupCount() + 1);
	m_wndGrid.SetColumnCount(m_pCtrl->GetSeriesCount() + 1);
	m_wndGrid.SetFixedRowCount(1);
	m_wndGrid.SetFixedColumnCount(1);
	m_wndGrid.SetColumnWidth(0, 15);
	
	InitControls();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGroupPropPage::CheckRadio(CButton *pButton, int nValue)
{
	CWnd * pCtrl = pButton;

	ASSERT(::GetWindowLong(pCtrl->m_hWnd, GWL_STYLE) & WS_GROUP);
	ASSERT(::SendMessage(pCtrl->m_hWnd, WM_GETDLGCODE, 0, 0L) & DLGC_RADIOBUTTON);

	// walk all children in group
	int iButton = 0;
	do
	{
		if (::SendMessage(pCtrl->m_hWnd, WM_GETDLGCODE, 0, 0L) & DLGC_RADIOBUTTON)
		{
			// control in group is a radio button
			// select button
			::SendMessage(pCtrl->m_hWnd, BM_SETCHECK, (iButton == nValue), 0L);
			iButton++;
		}
		else
		{
			TRACE0("Warning: skipping non-radio button in group.\n");
		}
		pCtrl = pCtrl->GetWindow(GW_HWNDNEXT);

	} while (pCtrl != NULL && !(GetWindowLong(pCtrl->m_hWnd, GWL_STYLE) 
		& WS_GROUP));
}

void CGroupPropPage::DisableMe()
{
	pComboGroup->EnableWindow(FALSE);
	pGroupTitle->EnableWindow(FALSE);
	
	pComboSeries->EnableWindow(FALSE);
	pSeriesTitle->EnableWindow(FALSE);

	pChooseColor->EnableWindow(FALSE);
	
	GetDlgItem(IDC_GRID)->EnableWindow(FALSE);
	
	pUsageShow->EnableWindow(FALSE);
	pUsageHide->EnableWindow(FALSE);
	pUsageExclude->EnableWindow(FALSE);
}

void CGroupPropPage::InitControls()
{
	int nGroups = m_pCtrl->GetGroupCount();
	int nSeries = m_pCtrl->GetSeriesCount();

	CString strName, strTitle;
	
	m_arGroupTitle.RemoveAll();
	m_arSeriesTitle.RemoveAll();
	m_arUsage.RemoveAll();
	m_arSeriesColor.RemoveAll();
	
	pComboGroup->ResetContent();
	pComboSeries->ResetContent();

	m_wndGrid.SetRowCount(m_pCtrl->GetGroupCount() + 1);
	m_wndGrid.SetColumnCount(m_pCtrl->GetSeriesCount() + 1);

	for (int i = 0; i < nGroups; i ++)
	{
		strName.Format("R%d", i);
		pComboGroup->AddString(strName);
	}

	for (i = 0; i < nSeries; i ++)
	{
		strName.Format("C%d", i);
		pComboSeries->AddString(strName);
	}

	double * pData;
	int j;
	CString strItem;

	for (i = 0; i < nGroups; i ++)
	{
		pData = m_pCtrl->m_arDatas[i];

		for (j = 0; j < nSeries; j ++)
		{
			strItem.Format("%f", pData[j]);
			m_wndGrid.SetItemText(i + 1, j + 1, strItem);
		}
	}

	m_arGroupTitle.Append(m_pCtrl->m_arGroupTitle);
	m_arSeriesTitle.Append(m_pCtrl->m_arSeriesTitle);
	m_arUsage.Append(m_pCtrl->m_arUsage);
	m_arSeriesColor.Append(m_pCtrl->m_arSeriesColor);

	pComboGroup->SetCurSel(0);
	pComboSeries->SetCurSel(0);

	pGroupTitle->SetWindowText(m_arGroupTitle[0]);
	pSeriesTitle->SetWindowText(m_arSeriesTitle[0]);

	CheckRadio(pUsageShow, m_arUsage[0]);

	m_wndColor.SetColor(m_arSeriesColor[0]);
}

void CGroupPropPage::OnSelendokComboGroup() 
{
	int nGroup = pComboGroup->GetCurSel();
	if (nGroup < 0 || nGroup >= m_arGroupTitle.GetSize())
		return;

	pGroupTitle->SetWindowText(m_arGroupTitle[nGroup]);
}

void CGroupPropPage::OnSelendokComboSeries() 
{
	int nSeries = pComboSeries->GetCurSel();
	if (nSeries < 0 || nSeries >= m_arSeriesTitle.GetSize())
		return;

	pSeriesTitle->SetWindowText(m_arSeriesTitle[nSeries]);
	CheckRadio(pUsageShow, m_arUsage[nSeries]);
	m_wndColor.SetColor(m_arSeriesColor[nSeries]);
}

void CGroupPropPage::OnKillfocusEditGrouptitle() 
{
	int nGroup = pComboGroup->GetCurSel();
	if (nGroup < 0 || nGroup >= m_arGroupTitle.GetSize())
		return;

	pGroupTitle->GetWindowText(m_arGroupTitle[nGroup]);
}

void CGroupPropPage::OnKillfocusEditSeriestitle() 
{
	int nSeries = pComboSeries->GetCurSel();
	if (nSeries < 0 || nSeries >= m_arSeriesTitle.GetSize())
		return;

	pSeriesTitle->GetWindowText(m_arSeriesTitle[nSeries]);
}

void CGroupPropPage::OnButtonChoosecolor() 
{
	int nSeries = pComboSeries->GetCurSel();
	if (nSeries < 0 || nSeries >= m_arSeriesTitle.GetSize())
		return;

	CColorDialog clrDlg(m_arSeriesColor[nSeries], CC_FULLOPEN | CC_RGBINIT | CC_SOLIDCOLOR);

	if (clrDlg.DoModal() == IDOK)
	{
		m_arSeriesColor[nSeries] = (OLE_COLOR) clrDlg.GetColor();
		m_wndColor.SetColor(m_arSeriesColor[nSeries]);
	}
}
