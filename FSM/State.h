#pragma once


template <typename Entity>
class State
{
public:
	virtual ~State() {}
	virtual void Enter(Entity*) = 0;
	virtual void Execute(Entity*) = 0;
	virtual void Exit(Entity*) = 0;
};
