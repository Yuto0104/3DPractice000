//=============================================================================
//
// デバック表示クラス(debug_proc.cpp)
// Author : 唐�ｱ結斗
// 概要 : デバック表示生成を行う
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

#include "debug_proc.h"
#include "application.h"
#include "renderer.h"

//--------------------------------------------------------------------
// 静的メンバ変数の定義
//--------------------------------------------------------------------
LPD3DXFONT CDebugProc::m_pFont = nullptr;			// フォント情報
char CDebugProc::m_aStr[0xfff] = {};				// 登録文字列

//=============================================================================
// 文字列の登録
// Author : 唐�ｱ結斗
// 概要 : 引数に設定された文字列を登録する
//=============================================================================
void CDebugProc::Print(const char *pFormat, ...)
{
	// 変数
	char aStrCpy[0xfff] = {};

	// リストの作成
	va_list args;
	va_start(args, pFormat);
	vsprintf(&aStrCpy[0], pFormat, args);
	va_end(args);

	strcat(&m_aStr[0], &aStrCpy[0]);
}

//=============================================================================
// 文字列の描画
// Author : 唐�ｱ結斗
// 概要 : 登録された文字列を描画する
//=============================================================================
void CDebugProc::Draw(void)
{
	RECT rect = { 0, 0, 1280, 720 };

	// テキスト描画
	m_pFont->DrawText(NULL, m_aStr, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));
	m_aStr[0] = '\0';
}

//=============================================================================
// コンストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス生成時に行う処理
//=============================================================================
CDebugProc::CDebugProc()
{

}

//=============================================================================
// デストラクタ
// Author : 唐�ｱ結斗
// 概要 : インスタンス終了時に行う処理
//=============================================================================
CDebugProc::~CDebugProc()
{

}

//=============================================================================
// 初期化
// Author : 唐�ｱ結斗
// 概要 : メンバ変数の初期値を設定
//=============================================================================
void CDebugProc::Init()
{// デバイスへのポインタの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// デバッグ情報表示用フォントの生成
	D3DXCreateFont(pDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Terminal"), &m_pFont);
}

//=============================================================================
// 終了
// Author : 唐�ｱ結斗
// 概要 : テクスチャのポインタと頂点バッファの解放
//=============================================================================
void CDebugProc::Uninit()
{
	// デバッグ情報表示用フォントの破棄
	if (m_pFont != nullptr)
	{
		m_pFont->Release();
		m_pFont = nullptr;
	}
}