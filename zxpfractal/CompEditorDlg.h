#pragma once


// CCompEditorDlg dialog
#include "zxpfractalDoc.h"
class CCompEditorDlg : public CDialog
{
	DECLARE_DYNAMIC(CCompEditorDlg)

public:
	CCompEditorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCompEditorDlg();
   void SetComplex(CzxpfractalDoc  *pc);
// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   CComplex  *m_pc;
   CzxpfractalDoc  *m_pdoc;
	DECLARE_MESSAGE_MAP()
public:
	double m_r;
	double m_i;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_num;
};
