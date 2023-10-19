
// WinOGLView.cpp : CWinOGLView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "WinOGL.h"
#endif

#include "WinOGLDoc.h"
#include "WinOGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinOGLView

IMPLEMENT_DYNCREATE(CWinOGLView, CView)

BEGIN_MESSAGE_MAP(CWinOGLView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CWinOGLView コンストラクション/デストラクション

CWinOGLView::CWinOGLView() noexcept
{
	// TODO: 構築コードをここに追加します。

}

CWinOGLView::~CWinOGLView()
{
}

BOOL CWinOGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CWinOGLView 描画

void CWinOGLView::OnDraw(CDC* pDC)
{
	CWinOGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	wglMakeCurrent(pDC->m_hDC, m_hRC);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT /* | GL_DEPTH_BUFFER_BIT
	*/);
	AC.Draw();
	glFlush();
	SwapBuffers(pDC->m_hDC);
	wglMakeCurrent(pDC->m_hDC, NULL);
	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CWinOGLView の診断

#ifdef _DEBUG
void CWinOGLView::AssertValid() const
{
	CView::AssertValid();
}

void CWinOGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinOGLDoc* CWinOGLView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinOGLDoc)));
	return (CWinOGLDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinOGLView メッセージ ハンドラー


void CWinOGLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect rect;
	GetClientRect(rect);


	//左クリックの座標

	double x = (double)point.x;
	double y = (double)point.y;

	//画面サイズの取得
	double rect_x = (double)rect.Width();
	double rect_y = (double)rect.Height();

	//デバイス座標系→正規化座標系

	x = x / rect_x;
	y = (rect_y - y) / rect_y;

	//正規化座標系→ワールド座標系

		x = (x - 0.5) * 2;
		y = (y - 0.5) * 2;

	//縦横比を合わせる
	if (rect_x > rect_y) {

		x = x * rect_x / rect_y;
		
	}
	else {
		y = y * rect_y / rect_x;
		
	}

	AC.L_Click(x, y);


	RedrawWindow();

	CView::OnLButtonDown(nFlags, point);
}


int CWinOGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	PIXELFORMATDESCRIPTOR pfd =
	{
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DRAW_TO_WINDOW |
	PFD_SUPPORT_OPENGL |
	PFD_DOUBLEBUFFER,
	PFD_TYPE_RGBA,
	32,
	0,0,0,0,0,0,
	0,0,0,0,0,0,0,
	24,
	0,0,
	PFD_MAIN_PLANE,
	0,
	0,0,0
	};
	CClientDC clientDC(this);
	int pixelFormat = ChoosePixelFormat(clientDC.m_hDC,
		&pfd);
	SetPixelFormat(clientDC.m_hDC, pixelFormat, &pfd);
	m_hRC = wglCreateContext(clientDC.m_hDC);
	return 0;
}


void CWinOGLView::OnDestroy()
{
	CView::OnDestroy();
	wglDeleteContext(m_hRC);
	// TODO: ここにメッセージ ハンドラー コードを追加します。
}


BOOL CWinOGLView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	return true;
}


void CWinOGLView::OnSize(UINT nType, int cx, int cy) //cxとcyが画面サイズ
{
	double ratio;
	CView::OnSize(nType, cx, cy);
	CClientDC clientDC(this);
	wglMakeCurrent(clientDC.m_hDC, m_hRC);
	glViewport(0, 0, cx, cy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (cx > cy) {
		ratio = (double)cx / cy;
		glOrtho(-1 * ratio, 1 * ratio, -1, 1, -100, 100);
	}
	else {
		ratio = (double)cy / cx;
		glOrtho(-1, 1, -1 * ratio, 1 * ratio, -100, 100);
	}
	// glOrtho(-1,1,-1,1,-100,100); // 問 5.2 で考える内容 glOrthoは体積を表していている
	glMatrixMode(GL_MODELVIEW);
	RedrawWindow();
	wglMakeCurrent(clientDC.m_hDC, NULL);
}
