
// 4장 공용대화상자 연습Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "4장 공용대화상자 연습.h"
#include "4장 공용대화상자 연습Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy4장공용대화상자연습Dlg 대화 상자



CMy4장공용대화상자연습Dlg::CMy4장공용대화상자연습Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY4___DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy4장공용대화상자연습Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox1);
	DDX_Control(pDX, IDC_LIST2, m_listBox2);
}

BEGIN_MESSAGE_MAP(CMy4장공용대화상자연습Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy4장공용대화상자연습Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy4장공용대화상자연습Dlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy4장공용대화상자연습Dlg::OnClickedButton3)
END_MESSAGE_MAP()


// CMy4장공용대화상자연습Dlg 메시지 처리기

BOOL CMy4장공용대화상자연습Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_fontTitle.CreatePointFont(160, _T("맑은 고딕"));
	GetDlgItem(IDC_STATIC_TITLE)->SetFont(&m_fontTitle);
	m_fontTitle.Detach();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy4장공용대화상자연습Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy4장공용대화상자연습Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy4장공용대화상자연습Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}









void CMy4장공용대화상자연습Dlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Filter = _T("Text File(*.txt)| *.txt|모든 파일(*.*)");
		CFileDialog pDlg(TRUE, _T("text file(*.txt)"), _T("*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, Filter, NULL);
		if (pDlg.DoModal() == IDOK)
		{
			CString fname = pDlg.GetPathName();
			m_listBox1.AddString(fname);

		}
}


void CMy4장공용대화상자연습Dlg::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog colorDlg;
	if(colorDlg.DoModal()==IDOK)
	{
		COLORREF color = colorDlg.GetColor();
		CString stdColorName;
		stdColorName.Format(_T("RGB( %d, %d, %d)"), GetRValue(color), GetGValue(color), GetBValue(color));
		m_listBox2.AddString(stdColorName);
	}
}


void CMy4장공용대화상자연습Dlg::OnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		CClientDC ds(this);

		CRect rect(CPoint(160, 280), CSize(350, 80));

		CFont font;
		LOGFONT lf;
		dlg.GetCurrentFont(&lf);
		font.CreateFontIndirectW(&lf);

		COLORREF color = dlg.GetColor();
		ds.SetTextColor(color);
		
		CString strInfo, strType, strSize;
		HDC hDC = ::GetDC(this->m_hWnd);
		strType.Format(_T("%s%s"), ((lf.lfWeight <= FW_NORMAL) ? _T("N") : _T("B")), (lf.lfItalic ? _T("I") : _T("")));
		strSize.Format(_T("%d"), MulDiv(-lf.lfHeight, 72, GetDeviceCaps(hDC, LOGPIXELSY)));
		strInfo = CString(lf.lfFaceName) + _T("-") + strType + _T("-") + strSize + _T("  ") + CString(_T("한국어 English"));
		rect.left += 10; rect.right -= 10;
		ds.DrawTextW(strInfo, &rect, DT_SINGLELINE | DT_LEFT | DT_CENTER);
		font.DeleteObject();
	}
}
