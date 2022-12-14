//=============================================================================
//
// �A�v���P�[�V�����N���X(application.h)
// Author : �������l
// �T�v : �e�N���X�̌Ăяo�����s���N���X
//
//=============================================================================
#ifndef _APPLICATION_H_		// ���̃}�N����`������ĂȂ�������
#define _APPLICATION_H_		// ��d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CRenderer;
class CDebugProc;
class CKeyboard;
class CMouse;
class CTexture;
class CModelManager;
class CCameraManager;
class CCamera;
class CSceneMode;
class CFade;

//=============================================================================
// �A�v���P�[�V�����N���X
// Author : �������l
// �T�v : �e�N���X�̌Ăяo�����s���N���X
//=============================================================================
class CApplication
{
public:
	//--------------------------------------------------------------------
	// �V�[�����[�h�̗񋓌^
	// Author : �������l
	// �T�v : �V�[�����[�h�����ʂ���
	//--------------------------------------------------------------------
	enum SCENE_MODE
	{
		MODE_TITLE = 0,			// �^�C�g��
		MODE_GAME,				// �Q�[��
		MODE_RESULT,			// ���U���g
		MAX_MODE,				// �V�[���̍ő吔
		MODE_NONE,				// �V�[������
	};

	//--------------------------------------------------------------------
	// �ÓI�����o�֐�
	//--------------------------------------------------------------------
	static HWND GetWnd() { return m_hWnd; }												// �E�B���h�E�̎擾
	static CRenderer *GetRenderer() { return m_pRenderer; }								// �����_���[�̃Q�b�^�[
	static CKeyboard *GetKeyboard() { return m_pKeyboard; }								// �L�[�{�[�h�̃Q�b�^�[
	static CMouse *GetMouse() { return m_pMouse; }										// �}�E�X�̃Q�b�^�[
	static CTexture *GetTexture() { return m_pTexture; }								// �e�N�X�`���̃Q�b�^�[
	static CModelManager *GetModelManager() { return m_pModelManager; }					// ���f���}�l�[�W���[�̃Q�b�^�[
	static CCameraManager *GetCameraManager() { return m_pCameraManager; }				// �J�����}�l�[�W���[�̃Q�b�^�[
	static CCamera *GetCamera() { return m_pCamera; }									// �J�����̃Q�b�^�[
	static D3DXVECTOR3 ScreenCastWorld(const D3DXVECTOR3 &pos);							// ���[���h���W���X�N���[�����W�ɃL���X�g����
	static D3DXVECTOR3 WorldCastScreen(const D3DXVECTOR3 &pos);							// ���[���h���W���X�N���[�����W�ɃL���X�g����
	static float RotNormalization(float fRot);											// �p�x�̐ݒ�
	static float RotNormalization(float fRot,float fMin,float fMax);					// �p�x�̐ݒ�
	static void SetNextMode(SCENE_MODE mode) { m_nextMode = mode; }						// ���̃��[�h�̐ݒ�
	static void SetMode(SCENE_MODE mode);												// ���[�h�̐ݒ�
	static SCENE_MODE GetMode() { return m_mode; }										// ���[�h�̎擾

	//--------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//--------------------------------------------------------------------
	CApplication();
	~CApplication();

	//--------------------------------------------------------------------
	// �����o�֐�
	//--------------------------------------------------------------------
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);					// ������
	void Uninit();													// �I��
	void Update();													// �X�V
	void Draw();													// �`��

private:
	//--------------------------------------------------------------------
	// �ÓI�����o�ϐ�
	//--------------------------------------------------------------------
	static HWND	m_hWnd;							// �E�B���h�E
	static CDebugProc *m_pDebugProc;			// �f�o�b�N�\��
	static CRenderer *m_pRenderer;				// renderer�N���X
	static CKeyboard *m_pKeyboard;				// �L�[�{�[�h�N���X
	static CMouse *m_pMouse;					// �}�E�X�N���X
	static CTexture *m_pTexture;				// �e�N�X�`���N���X
	static CModelManager *m_pModelManager;		// ���f���}�l�[�W���[�N���X
	static CCameraManager *m_pCameraManager;	// �J�����}�l�[�W���[�N���X
	static CCamera *m_pCamera;					// �Q�[���J�����N���X
	static SCENE_MODE m_mode;					// ���݂̃��[�h�̊i�[
	static SCENE_MODE m_nextMode;				// ���ɐݒ肷�郂�[�h
	static CSceneMode *pSceneMode;				// �V�[�����[�h���i�[
	static CFade *m_pFade;						// �t�F�[�h�N���X
	static int m_nPriority;						// �v���C�I���e�B�ԍ�
};

#endif
