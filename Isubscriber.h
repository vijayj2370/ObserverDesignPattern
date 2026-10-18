#pragma once
#include <string>

class ISubscriber
{
public: 
	virtual void notify(std::string pMsg) = 0;

};
