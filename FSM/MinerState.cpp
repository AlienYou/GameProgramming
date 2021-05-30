#include "MinerState.h"
#include "Miner.h"
#include "EntityNames.h"
#include <iostream>
using std::cout;

EnterMinerAndPigForNugget* EnterMinerAndPigForNugget::Instanc() {
	static EnterMinerAndPigForNugget instance;
	return &instance;
}

void EnterMinerAndPigForNugget::Enter(Miner* pMiner) {
	if (pMiner->GetLocation() != Location::Goldmine) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the goldminer";
		
		pMiner->ChangeLocation(Location::Goldmine);
	}
}

void EnterMinerAndPigForNugget::Execute(Miner* pMiner) {
	pMiner->AddToGoldCarried(1);
	pMiner->IncreseFatigue();

	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget";

	if (pMiner->PocketsFull())
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	
	if (pMiner->Thirsty()) {
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMinerAndPigForNugget::Exit(Miner* pMiner) {
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold";
}

VisitBankAndDepositGold* VisitBankAndDepositGold::Instance() {
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner) {
	if (pMiner->GetLocation() != Location::Bank) {
		pMiner->ChangeLocation(Location::Bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner* pMiner) {
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Depositing gold. Total savings now: " << pMiner->Wealth();

	if (pMiner->Wealth() >= ComfortLevel) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "WooHoo! Rich enough for now. Back home to mah li'lle lady.";
		
		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else {
		pMiner->GetFSM()->ChangeState(EnterMinerAndPigForNugget::Instanc());
	}
}

void VisitBankAndDepositGold::Exit(Miner* pMiner) {
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank.";
}

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance() {
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner) {
	if (pMiner->GetLocation() != Location::Shack) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home";

		pMiner->ChangeLocation(Location::Shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{
	if (!pMiner->Fatigued()) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "What a God darn fantastic nap! Time to find more gold";

		pMiner->GetFSM()->ChangeState(EnterMinerAndPigForNugget::Instanc());
	}
	else
	{
		pMiner->DecreaseFatigue();

		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZ...";
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner) {
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house";
}

QuenchThirst* QuenchThirst::Instance() {
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner* pMiner) {
	if (pMiner->GetLocation() != Location::Salmoon) {
		pMiner->ChangeLocation(Location::Salmoon);

		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the salmoon";
	}
}

void QuenchThirst::Execute(Miner* pMiner) {
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkWhiskey();
		
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin' liquer";

		pMiner->GetFSM()->ChangeState(EnterMinerAndPigForNugget::Instanc());
	}
	else
	{
		cout << "\nERROR!\nERRPR!\nERROR";
	}
}

void QuenchThirst::Exit(Miner* pMiner) {
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good";
}


