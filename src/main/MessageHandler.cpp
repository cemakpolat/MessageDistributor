/*
 * MessageHandler.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */

#include "MessageHandler.h"
#include "MessageCreator.h"
#include "MessageDistributor.h"
using namespace std;
std::string MessageHandler::className="MessageHandler";
int MessageHandler::portNumber=12001;


MessageHandler::MessageHandler() {
	// TODO Auto-generated constructor stub

}

MessageHandler::~MessageHandler() {
	// TODO Auto-generated destructor stub
}

void* MessageHandler::run(void* data) {
	MessageHandler *ml = (MessageHandler*) data;
	Message *message=&ml->incomingMessage;
	ml->message=ml->incomingMessage;
	MessageCreator *mcreator=new MessageCreator();

	json::Object json;
	try {
		if(message->header==mcreator->H_DECLARATION){

			if(!ml->isUserIPAvailable(message->fromIP)){
				ml->addNewUser(message->fromIP);
				//MESSAGE:{"HEADER:","CONTENT:",USERLIST:{}}
				mcreator->preapareUserList(json);
				//mcreator->createMessage(mcreator->H_USERLIST,json,"","");
				ml->sendMessageToUser(message->fromIP,	mcreator->createMessage(mcreator->H_USERLIST,json,"",""));
			}else{
				//MESSAGE:{"HEADER:ERROR","CONTENT:",USERLIST:{}}
				ml->sendMessageToUser(message->fromIP,	mcreator->createMessage(mcreator->H_USERLIST,json,"",""));

				//ml->sendMessageToUser(message->fromIP,mcreator->createMessage(mcreator->H_ERROR,mcreator->NODATA,"",""));
			}

		}else if(message->header==mcreator->H_MESSAGETOUSER){
			if(ml->isUserIPAvailable(message->toIP)){
				//MESSAGE is user message//std::string DECLERATION="DECLERATION";
				//std::string MESSAGETOUSER="MESSAGETOUSER";
				//std::string UPDATE="UPDATE";
				ml->sendMessageToUser(message->toIP,mcreator->createMessage(mcreator->H_MESSAGETOUSER,message->message,message->fromIP,message->toIP));

			}else{
				//ERRORMESSAGE=User isn't available anymore!
				ml->sendMessageToUser(message->fromIP,mcreator->createMessage(mcreator->H_ERROR,mcreator->USERNOTAVAILABLE,"",""));
			}
		}else if(message->header==mcreator->H_UPDATE){
			bool success=false;
			//ERRORMESSAGE: This message couldn't be recognized by our system!
			if(ml->isUserIPAvailable(message->fromIP)){
				success=ml->updateUserTimeoutDuration(message->fromIP);
			}
			if(success){
				//MESSAGE:{"HEADER:","CONTENT:",USERLIST:{}}
				ml->sendMessageToUser(message->fromIP,	mcreator->createMessage(mcreator->H_USERLIST,json,"",""));
			}else{
				//MESSAGE:{"HEADER:ERROR","CONTENT:",USERLIST:{}}
				ml->sendMessageToUser(message->fromIP,mcreator->createMessage(mcreator->H_ERROR,mcreator->NODATA,"",""));
			}
		}else{
			ml->sendMessageToUser(message->fromIP,mcreator->createMessage(mcreator->H_ERROR,mcreator->MESSAGEUNKNOWN,"",""));
		}
		delete mcreator;
		Utilities::writeConsole(" Check connectivity");
		//sleep(updateDuration);
	}  catch (std::exception& e) {
		std::cerr<<className  << e.what() << std::endl;
	}
	pthread_exit(NULL);

}
bool MessageHandler::isUserIPAvailable(string& IP){
	return  MessageDistributor::Instance()->isUserIPAvailable(IP);
}
bool MessageHandler::updateUserTimeoutDuration(string& IP){
	return MessageDistributor::Instance()->updateUserTimeoutDuration(IP);
}

bool MessageHandler::sendMessageToUser(string ip,string message){
	// convert message to json and sent it
	 // send
	bool result=false;
	TCPConnection *con=new TCPConnection();
	result= con->sendMessageInSmallChunks(ip,message,portNumber);
	if(result==false){
		this->addMessageToQueue(this->message); // Adding message queue is performed here
	}
	delete con;
	return result;
}
void MessageHandler::addNewUser(string IP){

	User user;
	user.ip=IP;
	user.nickName="CEM";// TODO: this info should be provided by User
	user.timeout=60;
	MessageDistributor::Instance()->addUser(user);

}
void MessageHandler::addMessageToQueue(Message message){
	MessageDistributor::Instance()->addMessage(message);
}

