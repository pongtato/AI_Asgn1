#include <iostream>
using namespace std;

#include "GameStateManager.h"
#include "gamestate.h"
#include "menustate.h"
#include "introstate.h"
#include "playstate.h"

CIntroState CIntroState::theIntroState;

void CIntroState::Init()
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Init\n" << endl;
#endif

#if TYPE_INTRO_OF_VIEW == 3
	scene = new CSceneManager(800, 600);	// Use this for 3D gameplay
#else
	scene = new CSceneManager2D();	// Use this for 2D gameplay
#endif
	scene->Init();
}

void CIntroState::Init(const int width, const int height)
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Init\n" << endl;
#endif

#if TYPE_INTRO_OF_VIEW == 3
	scene = new CSceneManager(width, height);	// Use this for 3D gameplay
#else
	scene = new CSceneManager2D();	// Use this for 2D gameplay
#endif
	scene->Init();
}

void CIntroState::Cleanup()
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Cleanup\n" << endl;
#endif
	// Delete the scene
	scene->Exit();
	delete scene;
	scene = NULL;
}

void CIntroState::Pause()
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Pause\n" << endl;
#endif
}

void CIntroState::Resume()
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Resume\n" << endl;
#endif
}

void CIntroState::HandleEvents(CGameStateManager* theGSM)
{
#if GSM_DEBUG_MODE
	/*int m_iUserChoice = -1;

	do {
		cout << "CIntroState: Choose one <0> Go to Menu State, <1> Go to Play State : " ;
		cin >> m_iUserChoice;
		cin.get();

		switch (m_iUserChoice) {
			case 0:
				theGSM->ChangeState( CMenuState::Instance() );
				break;
			case 1:
				theGSM->ChangeState( CPlayState::Instance() );
				break;
			default:
				cout << "Invalid choice!\n";
				m_iUserChoice = -1;
				break;
		}
	} while (m_iUserChoice == -1);*/
#endif
}

void CIntroState::HandleEvents(CGameStateManager* theGSM, const unsigned char key, const bool status)
{
#if GSM_DEBUG_MODE
	/*int m_iUserChoice = -1;

	do {
		cout << "CIntroState: Choose one <0> Go to Menu State, <1> Go to Play State : " ;
		cin >> m_iUserChoice;
		cin.get();

		switch (m_iUserChoice) {
			case 0:
				theGSM->ChangeState( CMenuState::Instance() );
				break;
			case 1:
				theGSM->ChangeState( CPlayState::Instance() );
				break;
			default:
				cout << "Invalid choice!\n";
				m_iUserChoice = -1;
				break;
		}
	} while (m_iUserChoice == -1);*/
#endif
	if (key == 32)
	{
		theGSM->ChangeState(CMenuState::Instance());
	}
}

void CIntroState::HandleEvents(CGameStateManager* theGSM, const double mouse_x, const double mouse_y,
							   const int button_Left, const int button_Middle, const int button_Right)
{
#if GSM_DEBUG_MODE
	/*int m_iUserChoice = -1;

	do {
		cout << "CIntroState: Choose one <0> Go to Menu State, <1> Go to Play State : " ;
		cin >> m_iUserChoice;
		cin.get();

		switch (m_iUserChoice) {
			case 0:
				theGSM->ChangeState( CMenuState::Instance() );
				break;
			case 1:
				theGSM->ChangeState( CPlayState::Instance() );
				break;
			default:
				cout << "Invalid choice!\n";
				m_iUserChoice = -1;
				break;
		}
	} while (m_iUserChoice == -1);*/
#endif
}

void CIntroState::Update(CGameStateManager* theGSM) 
{
#if GSM_DEBUG_MODE
	cout << "CIntroState::Update\n" << endl;
#endif
	// Update the scene
	scene->Update(0.16667);
}

void CIntroState::Update(CGameStateManager* theGSM, const double m_dElapsedTime)
{
	// Update the scene
	scene->Update(m_dElapsedTime);
}

void CIntroState::Draw(CGameStateManager* theGSM) 
{
#if GSM_DEBUG_MODE
	//cout << "CIntroState::Draw\n" << endl;
#endif

	// Render the scene
	scene->Render();
}
