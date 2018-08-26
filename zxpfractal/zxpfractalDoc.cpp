
// zxpfractalDoc.cpp : implementation of the CzxpfractalDoc class
//

#include "stdafx.h"
#include "zxpfractal.h"

#include "zxpfractalDoc.h"
#include "CompEditorDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzxpfractalDoc

IMPLEMENT_DYNCREATE(CzxpfractalDoc, CDocument)

BEGIN_MESSAGE_MAP(CzxpfractalDoc, CDocument)
	ON_COMMAND(ID_ZNEXT, &CzxpfractalDoc::OnZnext)
	ON_COMMAND(IDC_EDITVC, &CzxpfractalDoc::OnEditvc)
END_MESSAGE_MAP()


// CzxpfractalDoc construction/destruction

CzxpfractalDoc::CzxpfractalDoc()
:  m_c(-0.75, 0.0),m_i(0),m_num(2)
{
   m_i=-1;
   OnZnext();
	// TODO: add one-time construction code here

}

CzxpfractalDoc::~CzxpfractalDoc()
{
}

BOOL CzxpfractalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CzxpfractalDoc serialization

void CzxpfractalDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CzxpfractalDoc diagnostics

#ifdef _DEBUG
void CzxpfractalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CzxpfractalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CzxpfractalDoc commands

void CzxpfractalDoc::OnZnext()
{
	// TODO: Add your command handler code here
	CComplex xc[]={
		CComplex(-1.0, -0.3),//龙-美 
    	CComplex(-0.8, -0.25),//虫-美 
		CComplex(-0.8, 0.0),//乌龟-合口  
		CComplex(-0.75, 0.0),//乌龟-开一点口  
		CComplex(-0.65, -0.00),//乌龟-开大点口  
		CComplex(0.3,  -0.48), //2狮 -炫 
		CComplex(0.4, 0.250),//huashi 闪 
		CComplex(0.6, 0.0), //xiyao
		CComplex(0.7, 0.0),  //shuitongyao		
		CComplex(0.9, 0.0),   //xiyao 
		CComplex(0.45, -0.1428),//shen
		CComplex(0.255, 0.0),//facemask
		CComplex(0.285, 0.0),//hudie
		CComplex(0.6, -0.3), //exp=3
		CComplex(0.29, 0.74),
		CComplex(0.63, -0.34), //三龙
		CComplex(-0.8, 0.1)    //exp=4

	};
	int ic=sizeof(xc)/sizeof(CComplex);
	m_i++;
	m_i=m_i%ic;
	m_c=xc[m_i];
	if(m_i<13) m_num=2;
	else if(m_i<16) m_num=3;
	else m_num=4;
    redrawbmp();
}
 void  CzxpfractalDoc::redrawbmp()
 {
	 //this->UpdateAllViews(NULL);
	 POSITION pos= this->GetFirstViewPosition();
	 CView*pview= this->GetNextView(pos);
	 if(pview)::PostMessage(pview->m_hWnd,ID_DRAWBMP,0,0);

 }
void CzxpfractalDoc::OnEditvc()
{
	// TODO: Add your command handler code here

	CCompEditorDlg dlg(NULL);
	dlg.SetComplex(this);
	int idb= dlg.DoModal();
		if(idb ==IDOK)
		{
           //this->UpdateAllViews(NULL);
			  redrawbmp();
		}
}
