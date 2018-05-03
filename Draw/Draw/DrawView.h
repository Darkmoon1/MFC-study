
// DrawView.h : CDrawView 类的接口
//

#pragma once


class CDrawView : public CView
{
protected: // 仅从序列化创建
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// 特性
public:
	CDrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	UINT m_nDrawTpye = 0;//初始化绘图类型
	CPoint m_ptOrigin = 0;//坐标初始点
	UINT m_nLineWidth = 0;//初始线宽为0
	INT m_nLineStyle = 0;
	UINT m_BrushStyle = 0;
	BOOL m_pen = FALSE;
	BOOL m_Eraser = FALSE;
	BOOL m_LButtonDown = FALSE;
	BOOL m_FIll = FALSE;
	COLORREF m_clr = RGB(0, 0, 0);//黑色
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

#ifndef _DEBUG  // DrawView.cpp 中的调试版本
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

