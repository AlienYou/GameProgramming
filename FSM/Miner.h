#pragma once

#include "BaseEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include "MinerState.h"

constexpr int ComfortLevel = 5;
constexpr int MaxNuggets = 3;
constexpr int ThirstLevel = 5;
constexpr int TirednessThreshold = 5;

class Miner : public BaseGameEntity 
{
private:
	StateMachine<Miner>* m_pStateMachine;

	Location m_Location;

	int m_iGoldCarried;
	int m_iMoneyInBank;
	int m_iThirst;
	int m_iFatigue;
public:
	Miner(EntityID id) : BaseGameEntity(id),
		m_Location(Location::Shack),
		m_iGoldCarried(0),
		m_iMoneyInBank(0),
		m_iFatigue(0)
	{
		m_pStateMachine = new StateMachine<Miner>(this);
		m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());
	}

	~Miner() {
		delete m_pStateMachine;
	}

	void Update();

	Location GetLocation() { return m_Location; }
	void ChangeLocation(const Location loc) { m_Location = loc; }

	int GoldCarried() { return m_iGoldCarried; }
	void SetGoldCarried(int val) { m_iGoldCarried = val; }
	void AddToGoldCarried(int val);
	bool PocketsFull() { return m_iGoldCarried >= MaxNuggets; }

	bool Fatigued() const;
	void DecreaseFatigue() { m_iFatigue -= 1; }
	void IncreseFatigue() { m_iFatigue += 1; }

	int Wealth() const { return m_iMoneyInBank; }
	void SetWealth(const int val) { m_iMoneyInBank = val; }
	void AddToWealth(const int val);

	bool Thirsty() const;
	void BuyAndDrinkWhiskey() { m_iThirst = 0; m_iMoneyInBank -= 2; }

	StateMachine<Miner>* GetFSM() const { return m_pStateMachine; }
};
