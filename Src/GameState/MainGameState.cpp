#include "MainGameState.h"
#include "../GameStd.h"
#include "../Event/EventManager.h"
#include "../Event/Events/Evt_StateChange.h"
#include "../Event/Events/Evt_LostFocus.h"
#include "../Resource/ResourceManager.h"

MainGameState::MainGameState()
{
	EventManager::Get()->AddListener(MakeDelegate(this, &MainGameState::LostFocusDelegate), ET_LOSTFOCUS);
}

MainGameState::~MainGameState()
{
	EventManager::Get()->RemoveListener(MakeDelegate(this, &MainGameState::LostFocusDelegate), ET_LOSTFOCUS);
}

void MainGameState::LostFocusDelegate(EventSharedPtr pEvent)
{
	//Toggle Pause
}

void MainGameState::VUpdate(unsigned int elapsedTime)
{ 
}

void MainGameState::VOnEnter()
{
	INFO("Entering MAINGAME state");
	LOG("Entering MAINGAME state");
	ResourceManager::Get()->Clear();
}
