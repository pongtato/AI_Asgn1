#include <iostream>
using namespace std;

#include "GameStateManager.h"
#include "introstate.h"
#include "playstate.h"
#include "gamestate.h"
#include "menustate.h"

CMenuState CMenuState::theMenuState;

void CMenuState::Init()
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Init\n" << endl;
#endif

#if TYPE_MENU_OF_VIEW == 3
	scene = new CSceneManager(800, 600);	// Use this for 3D gameplay
#else
	scene = new CSceneManagerMenu();	// Use this for 2D gameplay
#endif
	scene->Init();
}

void CMenuState::Init(const int width, const int height)
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Init\n" << endl;
#endif

#if TYPE_MENU_OF_VIEW == 3
	scene = new CSceneManager(800, 600);	// Use this for 3D gameplay
#else
	scene = new CSceneManagerMenu();	// Use this for 2D gameplay
#endif
	scene->Init();
}

void CMenuState::Cleanup()
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Cleanup\n" << endl;
#endif
	// Delete the scene
	scene->Exit();
	delete scene;
	scene = NULL;
}

void CMenuState::Pause()
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Pause\n" << endl;
#endif
}

void CMenuState::Resume()
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Resume\n" << endl;
#endif
}

void CMenuState::HandleEvents(CGameStateManager* theGSM)
{
#if GSM_DEBUG_MODE
	/*int m_iUserChoice = -1;

	do {
		cout << "CMenuState: Choose one <0> Go to Intro State, <1> Go to Play State : " ;
		cin >> m_iUserChoice;
		cin.get();

		switch (m_iUserChoice) {
			case 0:
				theGSM->ChangeState( CIntroState::Instance() );
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

void CMenuState::HandleEvents(CGameStateManager* theGSM, const unsigned char key, const bool status)
{
#if GSM_DEBUG_MODE
	//int m_iUserChoice = -1;

	//do {
	//	cout << "CMenuState: Choose one <0> Go to Intro State, <1> Go to Play State : " ;
	//	cin >> m_iUserChoice;
	//	cin.get();

	//	switch (m_iUserChoice) {
	//		case 0:
	//			theGSM->ChangeState( CIntroState::Instance() );
	//			break;

	//		case 1:
	//			theGSM->ChangeState( CPlayState::Instance() );
	//			break;
	//		default:
	//			cout << "Invalid choice!\n";
	//			m_iUserChoice = -1;
	//			break;
	//	}
	//} while (m_iUserChoice == -1);
#endif
	if (key == 32)
	{
		theGSM->ChangeState(CPlayState::Instance());
	}
}

void CMenuState::HandleEvents(CGameStateManager* theGSM, const double mouse_x, const double mouse_y,
							  const int button_Left, const int button_Middle, const int button_Right)
{
#if GSM_DEBUG_MODE
	/*int m_iUserChoice = -1;

	do {
		cout << "CMenuState: Choose one <0> Go to Intro State, <1> Go to Play State : " ;
		cin >> m_iUserChoice;
		cin.get();

		switch (m_iUserChoice) {
			case 0:
				theGSM->ChangeState( CIntroState::Instance() );
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

void CMenuState::Update(CGameStateManager* theGSM) 
{
#if GSM_DEBUG_MODE
	cout << "CMenuState::Update\n" << endl;
#endif
	// Update the scene
	scene->Update(0.16667);
}

void CMenuState::Update(CGameStateManager* theGSM, const double m_dElapsedTime)
{
	// Update the scene
	scene->Update(m_dElapsedTime);
}

void CMenuState::Draw(CGameStateManager* theGSM) 
{
#if GSM_DEBUG_MODE
	//cout << "CMenuState::Draw\n" << endl;
#endif

	// Render the scene
	scene->Render();
}
