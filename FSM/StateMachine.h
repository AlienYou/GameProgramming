#pragma once

#include "State.h"
#include <typeinfo>
#include <cassert>

template <typename Entity>
class StateMachine
{
private:
	Entity* m_pOwner;
	State<Entity>* m_pCurrentState;
	State<Entity>* m_pPreviousState;
	State<Entity>* m_pGlobalState;

public:
	StateMachine(Entity* owner) : m_pOwner(owner),
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pGlobalState(nullptr)
	{

	}

	virtual ~StateMachine() { }

	void SetCurrentState(State<Entity>* s) { m_pCurrentState = s; }
	void SetGlobalState(State<Entity>* s) { m_pGlobalState = s; }
	void SetPreviousState(State<Entity>* s) { m_pPreviousState = s; }

	void Update() {
		if (m_pGlobalState) m_pGlobalState->Execute(m_pOwner);
		if (m_pCurrentState) m_pCurrentState->Execute(m_pOwner);
	}

	void ChangeState(State<Entity>* pNewState) {
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to NULL state");

		m_pPreviousState = m_pCurrentState;

		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;


		m_pCurrentState->Enter(m_pOwner);
	}

	void RevertToPreviousState() {
		ChangeState(m_pPreviousState);
	}

	bool isInState(State<Entity>* s) {
		return typied(*m_pCurrentState) == typied(s);
	}

	State<Entity>* CurrentState() const { return m_pCurrentState; }
	State<Entity>* PreviousState() const { return m_pPreviousState; }
	State<Entity>* GlobalState() const { return m_pPreviousState; }
};

