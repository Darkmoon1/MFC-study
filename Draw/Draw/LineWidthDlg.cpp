// LineWidthDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "LineWidthDlg.h"
#include "afxdialogex.h"


// CLineWidthDlg 对话框

IMPLEMENT_DYNAMIC(CLineWidthDlg, CDialog)

CLineWidthDlg::CLineWidthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LINEWIDTHDLG, pParent)
	, m_nLineWidth(0)
{

}

CLineWidthDlg::~CLineWidthDlg()
{
}

void CLineWidthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDM_SETTING, m_nLineWidth);
}


BEGIN_MESSAGE_MAP(CLineWidthDlg, CDialog)
END_MESSAGE_MAP()


// CLineWidthDlg 消息处理程序
