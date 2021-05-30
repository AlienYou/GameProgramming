#pragma once

#include "State.h"

class Miner;

class EnterMinerAndPigForNugget : public State<Miner>
{
private:
	EnterMinerAndPigForNugget() {}

	EnterMinerAndPigForNugget(const EnterMinerAndPigForNugget&) {}
	EnterMinerAndPigForNugget& operator=(const EnterMinerAndPigForNugget&);
	
	~EnterMinerAndPigForNugget() {}
public:
	static EnterMinerAndPigForNugget* Instanc();

public:
	virtual void Enter(Miner* miner) override;

	virtual void Execute(Miner* miner) override;

	virtual void Exit(Miner* miner) override;
};

class VisitBankAndDepositGold : public State<Miner>
{
private:
	VisitBankAndDepositGold() {}
	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator= (const VisitBankAndDepositGold&);
	~VisitBankAndDepositGold() {}
public:
	static VisitBankAndDepositGold* Instance();

public:
	virtual void Enter(Miner* miner) override;

	virtual void Execute(Miner* miner) override;

	virtual void Exit(Miner* miner) override;
};

class GoHomeAndSleepTilRested : public State<Miner>
{
private:

	GoHomeAndSleepTilRested() {}

	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator= (const GoHomeAndSleepTilRested&);
	~GoHomeAndSleepTilRested() {}
public:

	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Miner* miner) override;

	virtual void Execute(Miner* miner) override;

	virtual void Exit(Miner* miner) override;
};


class QuenchThirst : public State<Miner>
{
private:

	QuenchThirst() {}

	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator=(const QuenchThirst&);
	~QuenchThirst() {}

public:

	static QuenchThirst* Instance();

	virtual void Enter(Miner* miner) override;

	virtual void Execute(Miner* miner) override;

	virtual void Exit(Miner* miner) override;
};
