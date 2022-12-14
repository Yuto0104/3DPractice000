//=============================================================================
//
// όΝ(input.cpp)
// Author : ϊ±l
// Tv : IuWFNgΆ¬πs€
//
//=============================================================================

//***************************************************************************
// CN[h
//***************************************************************************
#include <assert.h>
#include <stdio.h>

#include "keyboard.h"

//=============================================================================
// RXgN^
// Author : ϊ±l
// Tv : CX^XΆ¬Ιs€
//=============================================================================
CKeyboard::CKeyboard()
{
	for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
	{
		m_aKeyState[nCntKey] = NULL;
		m_aKeyStateTrigger[nCntKey] = NULL;
		m_aKeyStateRelease[nCntKey] = NULL;
	}
}

//=============================================================================
// fXgN^
// Author : ϊ±l
// Tv : CX^XIΉΙs€
//=============================================================================
CKeyboard::~CKeyboard()
{

}

//=============================================================================
// ϊ»
// Author : ϊ±l
// Tv : L[{[hΜANZX πlΎΕ«½κAπp±·ι
//=============================================================================
HRESULT CKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	// eNXΜoΟπζΎ
	LPDIRECTINPUTDEVICE8 pDevice = GetDevice();
	LPDIRECTINPUT8 pInput = GetInput();

	// DirectInputIuWFNgΜΆ¬
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pInput, NULL)))
	{
		return E_FAIL;
	}

	// όΝfoCX(L[{[h)ΜΆ¬
	if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &pDevice, NULL)))
	{
		return E_FAIL;
	}

	// f[^tH[}bgπέθ
	if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// ¦²[hπέθ
	if (FAILED(pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	// DeviceΦΜANZX πlΎ
	pDevice->Acquire();

	// DeviceΜέθ
	SetDevice(pDevice);

	// CvbgΜέθ
	SetInput(pInput);

	return S_OK;
}

//=============================================================================
// IΉ
// Author : ϊ±l
// Tv : L[{[hΜANZX ππϊ΅AfoCXΖIuWFNgππϊ·ι
//=============================================================================
void CKeyboard::Uninit(void)
{
	// CvbgΜIΉ
	CInput::Uninit();
}

//=============================================================================
// XV
// Author : ϊ±l
// Tv : L[{[hΜόΝ³κ½ξρπΫΆ·ι
//=============================================================================
void CKeyboard::Update(void)
{
	// eNXΜoΟπζΎ
	LPDIRECTINPUTDEVICE8 pDevice = GetDevice();

	//ΟιΎ
	BYTE aKeyState[NUM_KEY_MAX];	//L[{[hΜόΝξρ
	int nCntKey;

	//όΝfoCX©ηf[^πζΎ
	if (SUCCEEDED(pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			// L[{[hΜgK[ξρπΫΆ
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];

			// L[{[hΜ[XξρπΫΆ
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & m_aKeyState[nCntKey];

			// L[{[hΜvXξρπΫΆ
			m_aKeyState[nCntKey] = aKeyState[nCntKey];
		}
	}
	else
	{
		// L[{[hΦΜANZX πlΎ
		pDevice->Acquire();
	}

	// DeviceΜέθ
	SetDevice(pDevice);
}

//=============================================================================
//  L[{[hvXξρΜζΎ
// Author : ϊ±l
// Tv : ψΜL[ΜξρπΤ·
//=============================================================================
bool CKeyboard::GetPress(int nKey)
{
	return (m_aKeyState[nKey] & 0x80) ? true : false;
}

//=============================================================================
// L[{[hgK[ξρΜζΎ
// Author : ϊ±l
// Tv : ψΜL[ΜξρπΤ·
//=============================================================================
bool CKeyboard::GetTrigger(int nKey)
{
	return (m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//=============================================================================
// L[{[h[XξρΜζΎ
// Author : ϊ±l
// Tv : ψΜL[ΜξρπΤ·
//=============================================================================
bool CKeyboard::GetRelease(int nKey)
{
	return (m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}

