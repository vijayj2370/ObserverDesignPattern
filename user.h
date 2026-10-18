#pragma once
#include <iostream>
#include <list>
#include "ISubscriber.h"

using namespace std;

class User : public ISubscriber
{
private:
	int mUserId;
public:
	User(int pUserId) {
		mUserId = pUserId;
	}

	void notify(std::string pMsg) {
		std::cout << "user " << mUserId << " notified " << pMsg << std::endl;
	}
};


class Group : public ISubscriber
{
private:
	std::list<ISubscriber*> mUsers;
	
public:

	void subscribe(ISubscriber* pUser) {
		mUsers.push_back(pUser);
	}

	void unsubscribe(ISubscriber* pUser) {
		mUsers.remove(pUser);
	}

	void notify(std::string pMsg) {
		for (auto user : mUsers) {
			user->notify(pMsg);
		}
	}
};
