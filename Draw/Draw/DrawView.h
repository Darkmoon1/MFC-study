
// DrawView.h : CDrawView ��Ľӿ�
//

#pragma once


class CDrawView : public CView
{
protected: // �������л�����
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// ����
public:
	CDrawDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnEllipese();
	afx_msg void OnEraser();
	afx_msg void OnFill();
	afx_msg void OnPen();
	afx_msg void OnRectangle();
	afx_msg void OnColor();
private:
	UINT m_nDrawTpye = 0;//��ʼ����ͼ����
	CPoint m_ptOrigin = 0;//�����ʼ��
	UINT m_nLineWidth = 0;//��ʼ�߿�Ϊ0
	INT m_nLineStyle = 0;
	UINT m_BrushStyle = 0;
	BOOL m_pen = FALSE;
	BOOL m_Eraser = FALSE;
	BOOL m_LButtonDown = FALSE;
	BOOL m_FIll = FALSE;
	COLORREF m_clr = RGB(0, 0, 0);//��ɫ
public:
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnJdhs();
	afx_msg void OnTmhs();
	afx_msg void OnLinewitdh();
};

#ifndef _DEBUG  // DrawView.cpp �еĵ��԰汾
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

