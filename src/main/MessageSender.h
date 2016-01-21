/*
 * MessageSender.h
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */


#ifndef MESSAGESENDER_H_
#define MESSAGESENDER_H_
#include <string>
#include <vector>
#include "MessageDistributor.h"
#include "PracticalSocket.h"
#include "TCPConnection.h"

class MessageSender {
private:
	static MessageSender* m_msInstance;
	static string className;
	 int portNumber;

public:
	MessageSender();
	virtual ~MessageSender();
	static MessageSender* Instance();
	static void* run(void* data);
	void getAllMessages(std::vector<Message>&);
	bool sendMessageToUser(std::string ip,std::string message);

};

#endif /* MESSAGESENDER_H_ */
