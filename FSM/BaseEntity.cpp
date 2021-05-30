#include "BaseEntity.h"
#include <cassert>

int BaseGameEntity::m_iNextValidId = 0;

void BaseGameEntity::SetID(EntityID val) {
	m_ID = val;
}
