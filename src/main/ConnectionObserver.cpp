/*
 * ConnectionObserver.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: cem
 */

#include "ConnectionObserver.h"
std::string ConnectionObserver::className="ConnectionObserver";

ConnectionObserver::ConnectionObserver() {
	// TODO Auto-generated constructor stub
   this->sleepDuration=10;
}

ConnectionObserver::~ConnectionObserver() {
	// TODO Auto-generated destructor stub
}

//singleton pattern required
ConnectionObserver* ConnectionObserver::m_coInstance = NULL;
ConnectionObserver* ConnectionObserver::Instance() {
	if (!m_coInstance)   // Only allow one instance of class to be generated.
		m_coInstance = new ConnectionObserver();
	return m_coInstance;
}

void* ConnectionObserver::run(void* data) {
	ConnectionObserver *co=(ConnectionObserver*)data;
	co->sleepDuration=10;
	while (true) {
		try {
			Utilities::writeConsole(" Check connectivity");
			pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);
			for(int i=0;i<MessageDistributor::Instance()->userList.size();i++){
				if(MessageDistributor::Instance()->userList[i].timeout==0){
					MessageDistributor::Instance()->userList.erase(MessageDistributor::Instance()->userList.begin() + i);
					// remove the message of the deleted user in the message Queue
				}else{
					MessageDistributor::Instance()->userList[i].timeout=MessageDistributor::Instance()->userList[i].timeout-co->sleepDuration;
				}
			}
			pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);
			sleep(co->sleepDuration);
		}  catch (std::exception& e) {
			std::cerr<<className << e.what() << std::endl;
		}
	}
	pthread_exit(NULL);
}

