#pragma once


// CLineWidthDlg �Ի���

class CLineWidthDlg : public CDialog
{
	DECLARE_DYNAMIC(CLineWidthDlg)

public:
	CLineWidthDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLineWidthDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINEWIDTHDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// �߿�
	UINT m_nLineWidth;
};
