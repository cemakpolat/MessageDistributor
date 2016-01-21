/*
 * APDME.cpp
 *
 *  Created on: Mar 12, 2013
 *      Author: cem
 */

#include "MessageDistributor.h"

std::string MessageDistributor::className="MessageDistributor";
std::vector<User> MessageDistributor::userList;
std::vector<Message> MessageDistributor::messageQueue;

int MessageDistributor::DEFAULT_TIMEOUT=60;

//singleton pattern required
MessageDistributor* MessageDistributor::m_mdInstance = NULL;
MessageDistributor* MessageDistributor::Instance() {
	if (!m_mdInstance)   // Only allow one instance of class to be generated.
		m_mdInstance = new MessageDistributor();
	return m_mdInstance;
}

MessageDistributor::MessageDistributor() {
	Utilities::writeOutputInFile("===============================================");
	Utilities::writeOutputInFile("Message Distributor is started");
	Utilities::writeOutputInFile("===============================================");

	this->mutex_user = PTHREAD_MUTEX_INITIALIZER;
	this->mutex_message = PTHREAD_MUTEX_INITIALIZER;

}

MessageDistributor::~MessageDistributor() {

}



///////////////////////////// GLOBAL FUNCTIONS ////////////////////////

void MessageDistributor::getUserList(vector<User>& list){
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);
	list=MessageDistributor::Instance()->userList;
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);
}

void MessageDistributor::getMessageList(vector<Message>& list){
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_message);
	list=MessageDistributor::Instance()->messageQueue;
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_message);
}
void MessageDistributor::addMessage(Message message){
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_message);
	MessageDistributor::Instance()->messageQueue.push_back(message);
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_message);
}

bool MessageDistributor::getUser(string& IP, User& user ) {
	bool state=false;
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);
	for (unsigned int i = 0; i < MessageDistributor::Instance()->userList.size(); i++) {
		if (MessageDistributor::Instance()->userList[i].ip==IP  ) {
			user=MessageDistributor::Instance()->userList[i];
			state=true;
			break;
		}
	}
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);
	return state;
}

bool MessageDistributor::isUserIPAvailable(string& IP){
	bool state=false;
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);
	for (unsigned int i = 0; i < MessageDistributor::Instance()->userList.size(); i++) {
		if (MessageDistributor::Instance()->userList[i].ip==IP  ) {
			state=true;
			break;
		}
	}
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);
	return state;
}
bool MessageDistributor::updateUserTimeoutDuration(string& IP){
	bool state=false;
		pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);
		for (unsigned int i = 0; i < MessageDistributor::Instance()->userList.size(); i++) {
			if (MessageDistributor::Instance()->userList[i].ip==IP  ) {
				MessageDistributor::Instance()->userList[i].timeout=DEFAULT_TIMEOUT;
				state=true;
				break;
			}
		}
		pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);
		return state;
}
void MessageDistributor::removeUser(string& IP){
	Utilities::writeOutputInFile("MessageDistributor: User is deleted...");

	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);//mutex list
	int index=0;
	for (unsigned int i = 0; i < MessageDistributor::Instance()->userList.size(); i++) {
		if (MessageDistributor::Instance()->userList[i].ip==IP  ) {
			index=i;
			break;
		}
	}
	MessageDistributor::Instance()->userList.erase(MessageDistributor::Instance()->userList.begin() + index);
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);//mutex list

}
void MessageDistributor::addUser(User user){
	Utilities::writeOutputInFile("MessageDistributor: New user is added...");
	pthread_mutex_lock(&MessageDistributor::Instance()->mutex_user);//mutex list
	MessageDistributor::Instance()->userList.push_back(user);
	pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_user);//mutex list
}

