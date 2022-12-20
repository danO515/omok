
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_START, &CMFCApplication1Dlg::OnClickedButtonStart)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CClientDC dc(this);

	CBrush white;
	white.CreateSolidBrush(RGB(255, 255, 255));
	CBrush black;
	black.CreateSolidBrush(RGB(0, 0, 0));


	x = point.x / 50;
	y = point.y / 50;

	//바둑알
	CDC WhiteDC;
	CBitmap White;
	White.LoadBitmapA(IDC_STONE);
	WhiteDC.CreateCompatibleDC(&dc);
	WhiteDC.SelectObject(&White);

	CDC BlackDC;
	CBitmap Black;
	Black.LoadBitmapA(IDC_STONE);
	BlackDC.CreateCompatibleDC(&dc);
	BlackDC.SelectObject(&Black);


	//투명 바둑알 배경
	CDC StoneDC;
	CBitmap Stone;
	Stone.LoadBitmapA(IDC_STONE);
	StoneDC.CreateCompatibleDC(&dc);
	StoneDC.SelectObject(&Stone);

	if (on == 1 &&
		check == 0 &&
		coordinate_filled[y][x] == 0 &&
		point.x % 50 < 40 &&
		point.y % 50 < 40 ) {

		if (color == 1) {

			dc.SelectObject(&white);
			dc.SetStretchBltMode(HALFTONE);
			dc.StretchBlt(x * 50 - 15, y * 50 - 15, 50, 50, &StoneDC, 1000, 0, 500, 500, SRCAND);
			dc.StretchBlt(x * 50 - 15, y * 50 - 15, 50, 50, &WhiteDC, 500, 0, 500, 500, SRCPAINT);

			coordinate_filled[y][x] = 1;
			color = 2;


			int direction_check[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
			int a, b;
			int count_W[8] = {};
			int xx = 0;
			int yy = 0;

			for (int i = 0; i < 8; i++) {

				winpoint_W = 0;
				a = direction_check[i][0];
				b = direction_check[i][1];
				
				xx = x + a;
				yy = y + b;


				while (	coordinate_filled[yy][xx] != 0 || coordinate_filled[yy][xx] != 2 )
				{
					if (yy <= 0 || xx <= 0 || yy >= 14 || xx >= 14)
						break;

					winpoint_W += 1;
					xx += a;
					yy += b;
				}

				count_W[i] = winpoint_W;
			} //가나다라

			/*
			char szText[100];
			sprintf(szText, "0:%d 1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d",
				count_W[0], count_W[1], count_W[2], count_W[3], count_W[4], count_W[5], count_W[6], count_W[7]);
			MessageBox(szText);
			*/

			if (count_W[0] + count_W[7] >= 4 || count_W[1] + count_W[6] >= 4 ||
				count_W[2] + count_W[5] >= 4 || count_W[3] + count_W[4] >= 4) {
				MessageBox("백 승리");
			}

		}

		else if (color == 2) {

			dc.SelectObject(&black);
			dc.SetStretchBltMode(HALFTONE);
			dc.StretchBlt(x * 50 - 15, y * 50 - 15, 50, 50, &StoneDC, 1000, 0, 500, 500, SRCAND);
			dc.StretchBlt(x * 50 - 15, y * 50 - 15, 50, 50, &BlackDC, 0, 0, 500, 500, SRCPAINT);

			coordinate_filled[y][x] = 2;
			color = 1;
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication1Dlg::OnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (on == 1) {
		Invalidate();
		color = 0;
		check = 0;
		for (x = 0; x < 15; x++) {
			for (y = 0; y < 15; y++) {
				coordinate_filled[y][x] = {};
			}
		}
	}
	on = 1;

	CClientDC dc(this);

	int x = 0, y = 0;
	y = 10;

	if (on == 1)
		MessageBox("시작");

	// 뒷배경
	CDC cBackDC;
	CBitmap cBack;
	cBackDC.CreateCompatibleDC(&dc);
	cBack.LoadBitmapA(IDC_BACK);
	cBackDC.SelectObject(&cBack);
	dc.StretchBlt(0, 0, 800, 800, &cBackDC, 0, 0, 400, 400, SRCCOPY);


	for (x = 10; x < 750; x += 50) {
		dc.MoveTo(x, y);
		dc.LineTo(x, y + 700);
	}
	x = 10;
	for (y = 10; y < 750; y += 50) {
		dc.MoveTo(x, y);
		dc.LineTo(x + 700, y);
	}
}

CDC * CMFCApplication1Dlg::DCDefine()
{
	// TODO: 여기에 구현 코드 추가.
	return nullptr;
}
