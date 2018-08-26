// CompEditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zxpfractal.h"
#include "CompEditorDlg.h"


// CCompEditorDlg dialog

IMPLEMENT_DYNAMIC(CCompEditorDlg, CDialog)

CCompEditorDlg::CCompEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCompEditorDlg::IDD, pParent)
	, m_r(0.75)
	, m_i(0)
	, m_num(0)
{
  m_pc=NULL;
}

CCompEditorDlg::~CCompEditorDlg()
{
}

void CCompEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITR, m_r);
	DDX_Text(pDX, IDC_EDITI, m_i);
	DDX_Text(pDX, IDC_EDITR2, m_num);
}
  void  CCompEditorDlg::SetComplex(CzxpfractalDoc  *pdoc)
  {
	  m_pdoc=pdoc;
	  m_pc=&pdoc->m_c;
	  m_num=pdoc->m_num;
	  if(m_pc){
        m_r=m_pc->m_real;
	    m_i=m_pc->m_imag;
	  }
    
  }

BEGIN_MESSAGE_MAP(CCompEditorDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CCompEditorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCompEditorDlg message handlers

void CCompEditorDlg::OnBnClickedOk()
{
	UpdateData();
	if(m_pc){
		m_pc->m_real=m_r;
		m_pc->m_imag=m_i;
		m_pdoc->m_num=m_num;
	}
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL CCompEditorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    UpdateData(FALSE);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
