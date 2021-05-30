#include <iostream>
#include "Miner.h"
#include <Windows.h>

int main()
{
	Miner Bob(EntityID::Entity_Miner_Bober);

	for (int i = 0; i < 20; ++i) {
		Bob.Update();

		Sleep(800);
	}
	return 0;
}
