//=============================================================================
//
// ゲームクラス(game.cpp)
// Author : 唐﨑結斗
// 概要 : ゲームクラスの管理を行う
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include <assert.h>

#include "game.h"
#include "keyboard.h"
#include "mouse.h"
#include "application.h"
#include "model_manager.h"
#include "camera_manager.h"
#include "renderer.h"
#include "object.h"
#include "object3D.h"
#include "player.h"
#include "model3D.h"
#include "mesh.h"
#include "sphere.h"

//*****************************************************************************
// 静的メンバ変数宣言
//*****************************************************************************
CPlayer *CGame::m_pPlayer = nullptr;				// プレイヤークラス
bool CGame::m_bGame = false;							// ゲームの状況

//=============================================================================
// コンストラクタ
// Author : 唐﨑結斗
// 概要 : インスタンス生成時に行う処理
//=============================================================================
CGame::CGame()
{

}

//=============================================================================
// デストラクタ
// Author : 唐﨑結斗
// 概要 : インスタンス終了時に行う処理
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// 初期化
// Author : 唐﨑結斗
// 概要 : 頂点バッファを生成し、メンバ変数の初期値を設定
//=============================================================================
HRESULT CGame::Init()
{// マウスの取得
	CMouse *pMouse = CApplication::GetMouse();

	// 背景モデルの設置
	CApplication::GetModelManager()->SetModelBG();

	// 地面の設定
	CMesh3D *pMesh3D = CMesh3D::Create();
	pMesh3D->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	pMesh3D->SetSize(D3DXVECTOR3(100000.0f, 0, 100000.0f));
	pMesh3D->SetBlock(CMesh3D::DOUBLE_INT(100, 100));
	pMesh3D->SetSplitTex(true);
	pMesh3D->LoadTex(13);

	// スカイボックスの設定
	CSphere *pSphere = CSphere::Create();
	pSphere->SetRot(D3DXVECTOR3(D3DX_PI, 0.0f, 0.0f));
	pSphere->SetSize(D3DXVECTOR3(100.0f, 0, 100.0f));
	pSphere->SetBlock(CMesh3D::DOUBLE_INT(100, 100));
	pSphere->SetRadius(50000.0f);
	pSphere->SetSphereRange(D3DXVECTOR2(D3DX_PI * 2.0f, D3DX_PI * -0.5f));
	pSphere->LoadTex(12);

	// プレイヤーの設定
	m_pPlayer = CPlayer::Create("data/MOTION/motion.txt");
	m_pPlayer->SetPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// カメラの追従設定(目標 : プレイヤー)
	CApplication::GetCamera()->SetFollowTarget(m_pPlayer, D3DXVECTOR3(0.0f, 100.0f, 0.0f), 300.0f);
	
	// マウスカーソルを消す
	pMouse->SetShowCursor(false);

	m_bGame = true;

	return S_OK;
}

//=============================================================================
// 終了
// Author : 唐﨑結斗
// 概要 : テクスチャのポインタと頂点バッファの解放
//=============================================================================
void CGame::Uninit()
{// マウスの取得
	CMouse *pMouse = CApplication::GetMouse();

	// マウスカーソルを出す
	pMouse->SetShowCursor(true);

	// スコアの解放
	Release();
}

//=============================================================================
// 更新
// Author : 唐﨑結斗
// 概要 : 更新を行う
//=============================================================================
void CGame::Update()
{// キーボードの取得
	CKeyboard *pKeyboard = CApplication::GetKeyboard();

	if (pKeyboard->GetTrigger(DIK_F3))
	{
		CApplication::SetNextMode(CApplication::MODE_RESULT);
		CApplication::GetCamera()->SetFollowTarget(nullptr, D3DXVECTOR3(0.0f, 20.0f, 0.0f), 300.0f);
	}
}

//=============================================================================
// 描画
// Author : 唐﨑結斗
// 概要 : 描画を行う
//=============================================================================
void CGame::Draw()
{

}
