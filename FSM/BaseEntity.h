#pragma once
#include "EntityNames.h"

class BaseGameEntity
{
private:
	EntityID m_ID;
	static int m_iNextValidId;

	void SetID(EntityID val);

public: 
	BaseGameEntity(EntityID id) {
		SetID(id);
	}

	virtual ~BaseGameEntity() { }

	virtual void Update() = 0;

	EntityID ID() const { return m_ID; }
};
