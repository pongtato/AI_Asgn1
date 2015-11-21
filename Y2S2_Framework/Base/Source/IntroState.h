#pragma once

#include "gamestate.h"
#include "SceneManager.h"
#include "SceneManager2D.h"
#include "timer.h"

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

#define TYPE_INTRO_OF_VIEW 2	// 2 = 2D, 3 = 3D

class CIntroState : public CGameState
{
public:
	void Init();
	void Init(const int width, const int height);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(CGameStateManager* theGSM);
	void HandleEvents(CGameStateManager* theGSM, const unsigned char key, const bool status = true);
	void HandleEvents(CGameStateManager* theGSM, const double mouse_x, const double mouse_y,
							  const int button_Left, const int button_Middle, const int button_Right);
	void Update(CGameStateManager* theGSM);
	void Update(CGameStateManager* theGSM, const double m_dElapsedTime);
	void Draw(CGameStateManager* theGSM);

	static CIntroState* Instance() {
		return &theIntroState;
	}

protected:
	CIntroState() { }

private:
	static CIntroState theIntroState;

	GLFWwindow* m_window;

	// The handler for the scene
	#if TYPE_INTRO_OF_VIEW == 3
		CSceneManager *scene;	// Use this for 3D gameplay
	#else
		CSceneManager2D *scene;	// Use this for 2D gameplay
	#endif
};
