#pragma once
#include <string>

using std::string;

enum class EntityID {
	Entity_Miner_Bober,
	Entity_Elsa
};

inline string GetNameOfEntity(EntityID n) {

	switch (n) {
	case EntityID::Entity_Miner_Bober:
		return "Miner Bob";
	case EntityID::Entity_Elsa:
		return "Elsa";
	default:
		return "UNKNOWN";
	}
}

