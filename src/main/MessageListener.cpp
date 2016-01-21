/*
 * MessageListener.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: cem
 */

#include "MessageListener.h"
#include "JSONIO.h"
using namespace std;

std::string MessageListener::className="MessageListener";


//singleton pattern required
MessageListener* MessageListener::m_mlInstance = NULL;
MessageListener* MessageListener::Instance() {
	if (!m_mlInstance)   // Only allow one instance of class to be generated.
		m_mlInstance = new MessageListener();
	return m_mlInstance;
}
MessageListener::MessageListener() {
	// TODO Auto-generated constructor stub

}

MessageListener::~MessageListener() {
	// TODO Auto-generated destructor stub
}


void* MessageListener::run(void* data) {
	int portNumber = 12000;

	int updateDuration=5;
	MessageListener *ml = (MessageListener*) data;
	Message message;
	MessageHandler *mhandler;

	//create socket and begin to listen
	ml->sock=new TCPServerSocket(portNumber);
	while (true) {
		try {
			ml->getMessageFromClient(message);
			// start here the new task
			mhandler=new MessageHandler();
			mhandler->incomingMessage=message;
			ml->callMessageHandler(mhandler);
		}  catch (std::exception& e) {
			std::cerr<<className  << e.what() << std::endl;
		}
	}
	pthread_exit(NULL);
}
void MessageListener::callMessageHandler(MessageHandler* handler){
		int rc;
		pthread_t mHandler;
		if ((rc = pthread_create(&mHandler, NULL, &MessageHandler::run, handler))) {
			printf("MessageDistributor : Connection Observer thread creation failed: %d\n", rc);
		}
		pthread_join(mHandler, NULL);
}

void MessageListener::getMessageFromClient(Message& message){
		string mess="";

		//This below code block works without issue, please do not remove
		TCPConnection *con=new TCPConnection();
		 mess=con->getMessageInSmallChunks(sock->accept());
		delete con;
		// Alternative function is below
		//string message=this->getMessageInSmallChunks(sock->accept());
		//	cout<<"Received Message From CNM:\n"<<message<<endl;
		JSONIO *jio=new JSONIO();
		json::Object jsonData= jio->convertStringToJSON(mess) ;//this->convertStringToJSON(mess);
	    json::String& mHeader = jsonData["header"];
	    json::String& mMessage=jsonData["message"];
	    json::String& fromIP=jsonData["fromIP"];
	    json::String& toIP=jsonData["toIP"];

	    std::cout<<"sent message"<<mHeader.Value() <<" "<<
	    		mMessage.Value()+" \n"<< "FROM:"+ fromIP.Value()<<" TO:"+toIP.Value()<<std::endl;
	    if(mHeader.Value()!=""){
			message.header=mHeader.Value();
			message.message=mMessage.Value();
			message.fromIP=fromIP.Value();
			message.toIP=toIP.Value();
			message.messageTrial=0;
	    }

	    delete jio;
}
//Convert the json format string to JSON Object
json::Object convertStringToJSON(std::string& str) {
	try {
		std::istringstream sBadDocument(str);
		json::Object jsonObj;
		json::Reader::Read(jsonObj, sBadDocument);
		return jsonObj;
	} catch (json::Reader::ParseException& e) {
		std::cout << "json::ParseException: " << e.what()
				<< ", Line/offset: " << e.m_locTokenBegin.m_nLine + 1 << '/'
				<< e.m_locTokenBegin.m_nLineOffset + 1 << std::endl
				<< std::endl;
	} catch (json::Exception& e) {
		e.what();
	}
	json::Object *obj = NULL;
	return *obj;
}

//std::string QoSTracker::getMessageInSmallChunks(TCPSocket *sock) {
//	 const unsigned int RCVBUFSIZE = 32;
//	std::string str="";
//		try {
//			// Establish connection with the echo server
//			//	TCPSocket sock(servAddress, echoServPort);
//			this->userIP=sock->getForeignAddress();
//			cout << sock->getForeignAddress() << ":";
//			cout << sock->getForeignPort()<<endl;
//			char echoBuffer[RCVBUFSIZE];
//			int recvMsgSize;
//			while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) { // Zero means// end of transmission
//
//				// Echo message back to client
//				//cout<<":received Message Size "<<recvMsgSize<<endl;
//				echoBuffer[recvMsgSize] = '\0';
//				//cout << ":echo " << echoBuffer << endl;
//				str.append(echoBuffer);
//				//sock->send(echoBuffer, recvMsgSize);
//			}
//			//cout << ":all " << str << endl;
//			delete sock;
//		} catch (SocketException &e) {
//			cerr << e.what() << endl;
//
//		}
//		return str;
//}
