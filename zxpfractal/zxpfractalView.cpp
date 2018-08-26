
// zxpfractalView.cpp : implementation of the CzxpfractalView class
//

#include "stdafx.h"
#include "zxpfractal.h"

#include "zxpfractalDoc.h"
#include "zxpfractalView.h"
#include "MainFrm.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CzxpfractalView

IMPLEMENT_DYNCREATE(CzxpfractalView, CView)

BEGIN_MESSAGE_MAP(CzxpfractalView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CzxpfractalView::OnFilePrintPreview)
	ON_MESSAGE( ID_DRAWBMP,&CzxpfractalView::OnDrawBmp)
END_MESSAGE_MAP()

// CzxpfractalView construction/destruction

CzxpfractalView::CzxpfractalView()
{
	// TODO: add construction code here
	memset(m_map,0,sizeof(m_map));
 
}

CzxpfractalView::~CzxpfractalView()
{
}

BOOL CzxpfractalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CzxpfractalView drawing
CString lfft(double lf){
	CString str,s2;
	str.Format(_T("%lf"),lf);
	CString zf=_T("0");
	s2=str.TrimRight(zf[0]);
	return str;

}
LRESULT CzxpfractalView::OnDrawBmp(WPARAM, LPARAM){
	CMainFrame *pMFrm=(CMainFrame *)theApp.GetMainWnd();
	CString str=_T("Waiting!!!");
	pMFrm->SetExSBText(str);
	CClientDC clidc(this);
	CzxpfractalDoc* pDoc = GetDocument();
	drawdc(&clidc,pDoc);
	pDoc->UpdateAllViews(NULL);
	return 0;
}
void CzxpfractalView::drawdc(CDC*pDC,CzxpfractalDoc* pDoc){
	CDC dcMemory;   
	BITMAP bmpInfo;
	// bmp.GetObject(sizeof(bmpInfo),&bmpInfo); //获取位图信息
	int nWidth,nHeight;
	CRect rt;
	GetClientRect(rt);   //获取视图窗口的大小
	nWidth=rt.Width();
	nHeight=rt.Height();
	 if(m_bmp.GetSafeHandle()!=NULL )m_bmp.DeleteObject();
	dcMemory.CreateCompatibleDC(pDC);  //创建兼容内存环境
	m_bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);
	CBitmap *oldmap= dcMemory.SelectObject(&m_bmp);       //将位图选入兼容内存环境
	DrawFractal(&dcMemory,pDoc);
	//  pdc->BitBlt(0,0,rt.Width(),rt.Height(),&dcCompatible,0,0,SRCCOPY);
	//pDC->BitBlt(0,0,rt.Width(),rt.Height(),&dcMemory,0,0,SRCCOPY);       //位图贴图（拉伸式），BitBlt则不拉伸
	dcMemory.SelectObject(oldmap);
	//m_bmp.DeleteObject();     //这两句清除资源
	dcMemory.DeleteDC(); 
}
void CzxpfractalView::drawtmp(){
	
}

void CzxpfractalView::OnDraw(CDC* pDC/*pDC*/)
{
	CzxpfractalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame *pMFrm=(CMainFrame *)theApp.GetMainWnd();
   CString str;
   CComplex c=pDoc->m_c;
   str.Format(L"c=(%s,%s),exp=%d",lfft(c.m_real),lfft(c.m_imag),pDoc->m_num);
   pMFrm->SetExSBText(str);
   if(m_cur!=str){
	   m_cur=str;
    // m_bmp.DeleteObject();
   }

       //声明位图类
   if(m_bmp.GetSafeHandle()==NULL){
		// bmp.LoadBitmap(IDB_BITMAP1);      //载入位图
	   CDC dcMemory;   
	   BITMAP bmpInfo;
	   // bmp.GetObject(sizeof(bmpInfo),&bmpInfo); //获取位图信息
	   int nWidth,nHeight;
	   CRect rt;
	   GetClientRect(rt);   //获取视图窗口的大小
	   nWidth=rt.Width();
	   nHeight=rt.Height();
	   dcMemory.CreateCompatibleDC(pDC);  //创建兼容内存环境
	   m_bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);
	   CBitmap *oldmap= dcMemory.SelectObject(&m_bmp);       //将位图选入兼容内存环境
	   DrawFractal(&dcMemory,pDoc);
	   //  pdc->BitBlt(0,0,rt.Width(),rt.Height(),&dcCompatible,0,0,SRCCOPY);

	   pDC->BitBlt(0,0,rt.Width(),rt.Height(),&dcMemory,0,0,SRCCOPY);       //位图贴图（拉伸式），BitBlt则不拉伸
	   dcMemory.SelectObject(oldmap);
	   //m_bmp.DeleteObject();     //这两句清除资源
	   dcMemory.DeleteDC(); 	
   }else{
	   // bmp.LoadBitmap(IDB_BITMAP1);      //载入位图
	   CDC dcMemory;   
	   BITMAP bmpInfo;
	   // bmp.GetObject(sizeof(bmpInfo),&bmpInfo); //获取位图信息
	   int nWidth,nHeight;
	  // CRect rt;
	  // GetClientRect(rt);   //获取视图窗口的大小

	   dcMemory.CreateCompatibleDC(pDC);  //创建兼容内存环境
	   m_bmp.GetObject(sizeof(bmpInfo),&bmpInfo); //获取位图信息
	   nWidth=bmpInfo.bmWidth;
	   nHeight=bmpInfo.bmHeight;
	  // m_bmp.CreateCompatibleBitmap(pDC,nWidth,nHeight);
	   CBitmap *oldmap= dcMemory.SelectObject(&m_bmp);       //将位图选入兼容内存环境
	  // DrawFractal(&dcMemory,pDoc);
	   //  pdc->BitBlt(0,0,rt.Width(),rt.Height(),&dcCompatible,0,0,SRCCOPY);

	   pDC->BitBlt(0,0,nWidth,nHeight,&dcMemory,0,0,SRCCOPY);       //位图贴图（拉伸式），BitBlt则不拉伸
	   dcMemory.SelectObject(oldmap);
	   //m_bmp.DeleteObject();     //这两句清除资源
	   dcMemory.DeleteDC(); 
   }
	// TODO: add draw code for native data here
}


COLORREF  HSVtoRGB( int h, int s, int v)
{
	// convert from HSV/HSB to RGB color
	// R,G,B from 0-255, H from 0-260, S,V from 0-100
	// ref http://colorizer.org/

	// The hue (H) of a color refers to which pure color it resembles
	// The saturation (S) of a color describes how white the color is
	// The value (V) of a color, also called its lightness, describes how dark the color is

	int i;
    unsigned char  r, g,  b;

	float RGB_min, RGB_max;
	RGB_max = v*2.55f;
	RGB_min = RGB_max*(100 - s)/ 100.0f;
    h=h%360;
	s=s%100;
	v=v%100;
	i = h / 60;
	int difs = h % 60; // factorial part of h

	// RGB adjustment amount by hue 
	float RGB_Adj = (RGB_max - RGB_min)*difs / 60.0f;

	switch (i) {
	case 0:
		 r = RGB_max;
		 g = RGB_min + RGB_Adj;
		 b = RGB_min;
		break;
	case 1:
		 r = RGB_max - RGB_Adj;
		 g = RGB_max;
		 b = RGB_min;
		break;
	case 2:
		 r = RGB_min;
		 g = RGB_max;
		 b = RGB_min + RGB_Adj;
		break;
	case 3:
		 r = RGB_min;
		 g = RGB_max - RGB_Adj;
		 b = RGB_max;
		break;
	case 4:
		 r = RGB_min + RGB_Adj;
		 g = RGB_min;
		 b = RGB_max;
		break;
	default:		// case 5:
		 r = RGB_max;
		 g = RGB_min;
		 b = RGB_max - RGB_Adj;
		break;
	}
	 return RGB(r,g,b);
}
 
COLORREF  CzxpfractalView::getcolor(int k){
	int ic=sizeof(m_map)/sizeof(COLORREF);
	int i=k%ic;
	COLORREF tt=m_map[i];
	if(tt==0) 
	{
		tt=HSVtoRGB(200+k*20,70,50+k);
		m_map[i]=tt;
	}
	return tt;

}
void CzxpfractalView::InitPallette(double h1 /* = 137.0 */, double h2 /* = 30.0 */)
{
#define MAXCOLOR   128
	for (int i = 0; i < MAXCOLOR / 2; ++i)
	{
		m_map[i] = HSVtoRGB(h1, 1.0, i * 2.0 / double(MAXCOLOR));
		m_map[MAXCOLOR - 1 - i] = HSVtoRGB(h2, 1.0, i * 2.0 / double(MAXCOLOR));
	}
}
void CzxpfractalView::DrawFractal(CDC* pdc,CzxpfractalDoc* pDoc) 
{ 
	double cr,ci,zr,zi,pr,pi;
	int i,j,k;
    bool inside;
	CComplex c(pDoc->m_c);
	//cr= pDoc->m_c.m_real;
	//ci= pDoc->m_c.m_imag;
    COLORREF xc=0;
	for(i=-320;i<=320;i++)
	{
		for(j=-300;j<=300;j++)
		{
			CComplex z(zr=i/200.0,zi=j/200.0);
			
			inside=true;
			for(k=0;k<=255;k++)
			{   
				//if((zr*zr+zi*zi)>4.0)
				if(modulus_square(z)>4.0)
				{
					inside=false;
					break;
				}
				else
				{
					/*pr=zr*zr-zi*zi;
					pi=2.0*zr*zi;
					zr=pr+cr;
					zi=pi+ci;*/
					CComplex zt=z;
					for(int num=1;num<pDoc->m_num;num++)
						zt=zt*z;
					z=zt+c;
				}
			}
			//PutPixel(i+320, j+240, k);  
			xc=(inside?0:getcolor(k) );
			pdc->SetPixel(i+320,j+240,xc);
		}
	}

}

// CzxpfractalView printing


void CzxpfractalView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CzxpfractalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CzxpfractalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CzxpfractalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CzxpfractalView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CzxpfractalView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CzxpfractalView diagnostics

#ifdef _DEBUG
void CzxpfractalView::AssertValid() const
{
	CView::AssertValid();
}

void CzxpfractalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CzxpfractalDoc* CzxpfractalView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CzxpfractalDoc)));
	return (CzxpfractalDoc*)m_pDocument;
}
#endif //_DEBUG


// CzxpfractalView message handlers
