/*
 * MessageHandler.h
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_
#include <string>
#include "MessageDistributor.h"
#include "Message.h"
#include "PracticalSocket.h"
#include "TCPConnection.h"

class MessageHandler {
private:
	//static std::string DECLERATION;
	//static std::string MESSAGETOUSER;
	//static std::string UPDATE;
	static  std::string className;					/**< Class Name */

public:
	MessageHandler();
	virtual ~MessageHandler();
	static void* run(void* data);
	static int portNumber;
	bool isUserIPAvailable(std::string& );
	bool updateUserTimeoutDuration(std::string& );
	void addNewUser(std::string );
	Message incomingMessage;
	Message message;
	bool sendMessageToUser(std::string,std::string);
	void addMessageToQueue(Message message);

};

#endif /* MESSAGEHANDLER_H_ */
