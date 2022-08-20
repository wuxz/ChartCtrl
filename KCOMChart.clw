; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKCOMChartPropPage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "kcomchart.h"
LastPage=0
CDK=Y

ClassCount=11
Class1=CColorWnd
Class2=CGridCtrl
Class3=CGridDropTarget
Class4=CGroupPropPage
Class5=CInPlaceEdit
Class6=CComboEdit
Class7=CInPlaceList
Class8=CInputGrid
Class9=CKCOMChartCtrl
Class10=CKCOMChartPropPage
Class11=CTitleTip

ResourceCount=3
Resource1=IDD_PROPPAGE_GROUP
Resource2=IDD_ABOUTBOX_KCOMCHART
Resource3=IDD_PROPPAGE_KCOMCHART

[CLS:CColorWnd]
Type=0
BaseClass=CWnd
HeaderFile=ColorWnd.h
ImplementationFile=ColorWnd.cpp
LastObject=CColorWnd

[CLS:CGridCtrl]
Type=0
BaseClass=CWnd
HeaderFile=GridCtrl.h
ImplementationFile=GridCtrl.cpp

[CLS:CGridDropTarget]
Type=0
BaseClass=COleDropTarget
HeaderFile=GridDropTarget.h
ImplementationFile=GridDropTarget.cpp

[CLS:CGroupPropPage]
Type=0
BaseClass=COlePropertyPage
HeaderFile=GroupPropPage.h
ImplementationFile=GroupPropPage.cpp
Filter=D
VirtualFilter=idWC
LastObject=CGroupPropPage

[CLS:CInPlaceEdit]
Type=0
BaseClass=CEdit
HeaderFile=InPlaceEdit.h
ImplementationFile=InPlaceEdit.cpp

[CLS:CComboEdit]
Type=0
BaseClass=CEdit
HeaderFile=InPlaceList.h
ImplementationFile=InPlaceList.cpp

[CLS:CInPlaceList]
Type=0
BaseClass=CComboBox
HeaderFile=InPlaceList.h
ImplementationFile=InPlaceList.cpp

[CLS:CInputGrid]
Type=0
BaseClass=CGridCtrl
HeaderFile=InputGrid.h
ImplementationFile=InputGrid.cpp

[CLS:CKCOMChartCtrl]
Type=0
BaseClass=COleControl
HeaderFile=KCOMChartCtl.h
ImplementationFile=KCOMChartCtl.cpp
Filter=W
VirtualFilter=wWC
LastObject=CKCOMChartCtrl

[CLS:CKCOMChartPropPage]
Type=0
BaseClass=COlePropertyPage
HeaderFile=KCOMChartPpg.h
ImplementationFile=KCOMChartPpg.cpp
Filter=D
VirtualFilter=idWC
LastObject=CKCOMChartPropPage

[CLS:CTitleTip]
Type=0
BaseClass=CWnd
HeaderFile=TitleTip.h
ImplementationFile=TitleTip.cpp

[DLG:IDD_PROPPAGE_GROUP]
Type=1
Class=CGroupPropPage
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_COMBO_GROUP,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_GROUPTITLE,edit,1350631552
Control5=IDC_STATIC,button,1342308359
Control6=IDC_COMBO_SERIES,combobox,1344339971
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_SERIESTITLE,edit,1350631552
Control9=IDC_BUTTON_CHOOSECOLOR,button,1342242816
Control10=IDC_RADIO_SHOW,button,1342308361
Control11=IDC_RADIO_HIDE,button,1342177289
Control12=IDC_RADIO_EXCLUDE,button,1342177289
Control13=IDC_COLOR,static,1476591616
Control14=IDC_GRID,MFCGridCtrl,1353777152

[DLG:IDD_PROPPAGE_KCOMCHART]
Type=1
Class=CKCOMChartPropPage
ControlCount=20
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_APPEARANCE,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_BORDERSTYLE,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO_TITLEALIGNMENT,combobox,1344339971
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO_FOOTERALIGNMENT,combobox,1344339971
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO_DATAMODE,combobox,1344339971
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_TITLE,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_FOOTER,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_SERIESCOUNT,edit,1350639744
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_GROUPCOUNT,edit,1350639744
Control19=IDC_CHECK_DRAWLEGEND,button,1342242851
Control20=IDC_CHECK_DRAWGROUPTITLE,button,1342242851

[DLG:IDD_ABOUTBOX_KCOMCHART]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

