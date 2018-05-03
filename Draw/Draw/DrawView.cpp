
// DrawView.cpp : CDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"
#include "LineWidthDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_DOT, &CDrawView::OnDot)
	ON_COMMAND(IDM_ELLIPESE, &CDrawView::OnEllipese)
	ON_COMMAND(IDM_ERASER, &CDrawView::OnEraser)
	ON_COMMAND(IDM_FILL, &CDrawView::OnFill)
	ON_COMMAND(IDM_PEN, &CDrawView::OnPen)
	ON_COMMAND(IDM_RECTANGLE, &CDrawView::OnRectangle)
	ON_COMMAND(IDM_COLOR, &CDrawView::OnColor)
//	ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_COMMAND(IDM_LINE, &CDrawView::OnLine)
ON_WM_MOUSEMOVE()
ON_COMMAND(IDM_JDHS, &CDrawView::OnJdhs)
ON_COMMAND(IDM_TMHS, &CDrawView::OnTmhs)
ON_COMMAND(IDM_LINEWITDH, &CDrawView::OnLinewitdh)
END_MESSAGE_MAP()

// CDrawView ����/����

CDrawView::CDrawView()
{
	// TODO: �ڴ˴���ӹ������

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawView ����

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CDrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawView ���

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView ��Ϣ�������


void CDrawView::OnDot()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 1;
}

void CDrawView::OnLine()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 2;
}


void CDrawView::OnEllipese()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 7;
}


void CDrawView::OnEraser()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 3;
}


void CDrawView::OnFill()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 4;
}


void CDrawView::OnPen()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 6;
}


void CDrawView::OnRectangle()
{
	// TODO: �ڴ���������������
	m_nDrawTpye = 5;
}


void CDrawView::OnColor()
{
	// TODO: �ڴ���������������
	CColorDialog dlg;
	if (IDOK==dlg.DoModal())
	{
		m_clr = dlg.m_cc.rgbResult;
	}
}





void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin = point;
	m_LButtonDown = TRUE;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_LButtonDown = FALSE;
	//������ˢ ��ȡDC
	CClientDC dc(this);
	CPen pen(PS_SOLID, m_nLineWidth, m_clr);
	CBrush brush(m_clr);
	CBrush *nlbrush = CBrush::FromHandle((HBRUSH)(GetStockObject(NULL_BRUSH)));
	dc.SelectObject(pen);
	if (m_BrushStyle==0)
	{
		dc.SelectObject(brush);
	}
	else
	{
		dc.SelectObject(nlbrush);
	}
	switch (m_nDrawTpye)
	{
	case 1:
		dc.SetPixel(point, m_clr);
		break;
	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 5:
		dc.Rectangle(m_ptOrigin.x, m_ptOrigin.y, point.x, point.y);
		//������
		//dc.FillRect(CRect(m_ptOrigin, point), &brush);
		break;
	case 7:
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}




void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_nDrawTpye == 6)
	{
		CClientDC dc(this);
		CPen pen(PS_SOLID, m_nLineWidth, m_clr);
		CPen *OldPen = dc.SelectObject(&pen);
		if (m_LButtonDown == TRUE)
		{
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);
			m_ptOrigin = point;
		}
		dc.SelectObject(OldPen);

	}
	else if (m_nDrawTpye == 3)
	{
		CClientDC dc(this);
		CPen pen(PS_SOLID, m_nLineWidth, RGB(255,255,255));
		CPen *OldPen = dc.SelectObject(&pen);
		if (m_LButtonDown == TRUE)
		{
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);
			m_ptOrigin = point;
		}
		dc.SelectObject(OldPen);
	}
	CView::OnMouseMove(nFlags, point);
}


void CDrawView::OnJdhs()
{
	// TODO: �ڴ���������������
	m_BrushStyle = 0;
}


void CDrawView::OnTmhs()
{
	// TODO: �ڴ���������������
	m_BrushStyle = 1;
}


void CDrawView::OnLinewitdh()
{
	// TODO: �ڴ���������������
	CLineWidthDlg dlg;
	dlg.m_nLineWidth = m_nLineWidth;
	if (IDOK == dlg.DoModal())
	{
		m_nLineWidth = dlg.m_nLineWidth;
	}

}
