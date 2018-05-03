#pragma once


// CLineWidthDlg 对话框

class CLineWidthDlg : public CDialog
{
	DECLARE_DYNAMIC(CLineWidthDlg)

public:
	CLineWidthDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLineWidthDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEWIDTHDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 线宽
	UINT m_nLineWidth;
};
