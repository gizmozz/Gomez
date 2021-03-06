#include "GameStateManager.h"
#include "../GameStd.h"
#include "../Event/EventManager.h"
#include "../Event/Events/Evt_StateChange.h"
#include "MenuState.h"
#include "IntroState.h"
#include "PauseState.h"
#include "MainGameState.h"

GameStateManager::GameStateManager():
m_pCurrentState(NULL),
m_pPausedState(NULL)
{
}

GameStateManager::~GameStateManager()
{
	DestroyState(m_pCurrentState);
	DestroyState(m_pPausedState);
	EventManager::Get()->RemoveListener(MakeDelegate(this, &GameStateManager::StateChangeDelegate), ET_STATECHANGE);
}

bool GameStateManager::Init()
{
	EventManager::Get()->AddListener(MakeDelegate(this, &GameStateManager::StateChangeDelegate), ET_STATECHANGE);
		
	ChangeState(GS_INTRO);
	
	return true;
}

void GameStateManager::Update(unsigned int elapsedTime)
{
	m_pCurrentState->VUpdate(elapsedTime);
}

void GameStateManager::StateChangeDelegate(EventSharedPtr pEvent)
{
	shared_ptr<Evt_StateChange> pEvt = static_pointer_cast<Evt_StateChange>(pEvent);
	ChangeState(pEvt->GetState());
}

IGameState* GameStateManager::CreateState(const eGameState gameState)
{
	if(gameState == GS_PAUSE)
	{		
		return new PauseState();
	}
	if(gameState == GS_INTRO)
	{
		return new IntroState();
	}
	else if(gameState == GS_MENU)
	{
		return new MenuState();
	}
	else if(gameState == GS_MAINGAME)
	{
		return new MainGameState();
	}

	ERROR("Invalid game state type");
	return NULL;
}

void GameStateManager::ChangeState(const eGameState gameState)
{		
	if(m_pCurrentState != NULL) 			
	{
		if(gameState == GS_PAUSE)
		{
			if(m_pPausedState != NULL)
			{
				ERROR("Game has already been paused");
				return;
			}
				
			m_pPausedState = m_pCurrentState;
		}
		else
		{
			m_pCurrentState->VOnLeave(); 	
			DestroyState(m_pCurrentState);
		} 	
	}
	
	if(gameState == GS_PREVIOUS)
	{
		m_pCurrentState = m_pPausedState;
		m_pPausedState = NULL;
	}
	else
	{
		if(m_pPausedState != NULL && gameState != GS_PAUSE)
			DestroyState(m_pPausedState);
			
		m_pCurrentState = CreateState(gameState);
	}
	
	m_pCurrentState->VOnEnter(); 			
}

void GameStateManager::DestroyState(IGameState* &pGameState)
{
	SAFE_DELETE(pGameState);
}
