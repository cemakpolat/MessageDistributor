/*
 * MessageSender.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */

#include "MessageSender.h"
#include "MessageDistributor.h"
#include "MessageCreator.h"
using namespace std;
MessageSender::MessageSender() {
	// TODO Auto-generated constructor stub

}

MessageSender::~MessageSender() {
	// TODO Auto-generated destructor stub
	this->portNumber=12001;
}
std::string MessageSender::className="MessageSender";

//singleton pattern required
MessageSender* MessageSender::m_msInstance = NULL;
MessageSender* MessageSender::Instance() {
	if (!m_msInstance)   // Only allow one instance of class to be generated.
		m_msInstance = new MessageSender();
	return m_msInstance;
}

void MessageSender::getAllMessages(vector<Message>& list){
	MessageDistributor::Instance()->getMessageList(list);
}

void* MessageSender::run(void* data) {

	int sleepDuration=20;
	MessageSender *ms=(MessageSender*)data;
	MessageCreator *mcreator=new MessageCreator();
	while (true) {
		try {

			pthread_mutex_lock(&MessageDistributor::Instance()->mutex_message);

			for(int i=0;i<MessageDistributor::Instance()->messageQueue.size();i++){
				if(MessageDistributor::Instance()->messageQueue[i].messageTrial==2){
					MessageDistributor::Instance()->messageQueue.erase(MessageDistributor::Instance()->messageQueue.begin() + i);
				}else{
					Message *message=&MessageDistributor::Instance()->messageQueue[i];
					// send message
					if(!ms->sendMessageToUser(message->toIP,mcreator->createMessage(mcreator->MESSAGE,message->message,message->fromIP,message->toIP))){
						MessageDistributor::Instance()->messageQueue[i].messageTrial++;
					}

				}
			}
			pthread_mutex_unlock(&MessageDistributor::Instance()->mutex_message);

			Utilities::writeConsole(" Message Repeater is running...");
			sleep(sleepDuration);
		}  catch (std::exception& e) {
			std::cerr<<className << e.what() << std::endl;
		}
	}
	pthread_exit(NULL);
}

bool MessageSender::sendMessageToUser(string ip,string message){
	// convert message to json and sent it
	 // send
	TCPConnection *con=new TCPConnection();
	bool result= con->sendMessageInSmallChunks(ip,message,this->portNumber);
	delete con;
	return result;

}
