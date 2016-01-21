/*
 * MessageListener.h
 *
 *  Created on: Jan 7, 2015
 *      Author: cem
 */

#ifndef MESSAGELISTENER_H_
#define MESSAGELISTENER_H_
#include <string>
#include "MessageHandler.h"
#include "PracticalSocket.h"
#include "TCPConnection.h"
class MessageListener {
	private:
	static MessageListener* m_mlInstance;
public:
	static  std::string className;					/**< Class Name */
	TCPServerSocket *sock;

	MessageListener();
	virtual ~MessageListener();

	static MessageListener* Instance();

	static void* run(void* data);
	void callMessageHandler(MessageHandler* handler);

	bool isUserIPAvailable(std::string );
	bool updateUserTimeoutDuration(std::string );
	bool addNewUser(std::string );
	bool isRequestedUserIPAvaible(std::string );
	void sendMessageToUser(std::string,std::string);
	std::string extractMessageHeader(std::string);
	void getMessageFromClient(Message&);


};

#endif /* MESSAGELISTENER_H_ */
