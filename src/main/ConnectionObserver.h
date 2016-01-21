/*
 * ConnectionObserver.h
 *
 *  Created on: Jan 7, 2015
 *      Author: cem
 */

#ifndef CONNECTIONOBSERVER_H_
#define CONNECTIONOBSERVER_H_

#include <string>
#include <vector>
#include "MessageDistributor.h"
#include "User.h"
using namespace std;
class ConnectionObserver {
private:
	static ConnectionObserver* m_coInstance;
	static string className;
	int sleepDuration;
public:
	ConnectionObserver();
	virtual ~ConnectionObserver();

	static ConnectionObserver* Instance();
	static void* run(void* data);
	void getAvailableUsers(vector<User>&);
	bool removeUserIP(std::string);

};

#endif /* CONNECTIONOBSERVER_H_ */
