///*
// * APDME.cpp
// *
// *  Created on: Mar 12, 2013
// *      Author: cem
// */
//
//#include "ConnectionObserver.h"
//#include "MessageListener.h"
//#include "MesDist.h"
//
//#include "Utilities.h"
//
//
//std::string MesDist::className="MesDist";
//std::vector<User> MesDist::userList;
//using namespace std;
////singleton pattern required
//MesDist* MesDist::m_mdInstance = NULL;
//MesDist* MesDist::Instance() {
//	if (!m_mdInstance)   // Only allow one instance of class to be generated.
//		m_mdInstance = new MesDist();
//	return m_mdInstance;
//}
//
//MesDist::MesDist() {
//	Utilities::writeOutputInFile("===============================================");
//	Utilities::writeOutputInFile("Message Distributor is started");
//	Utilities::writeOutputInFile("===============================================");
//
//	this->mutex_user = PTHREAD_MUTEX_INITIALIZER;
//}
//
//MesDist::~MesDist() {
//	delete co;
//	delete ml;
//
//}
//
//string MesDist:getUserList(){
//	readAuthentiationFile();
//	readDHCPFiles();
//	createJSONUserList();
//	//{header:USERS,message:{Users:[User:{Nickname:cem,IP:192.0.0.1},...]}}
//	string jsonData="";
//	return jsonData
//}
//bool MesDist:sendMessageToRequester(string str,string ip){
//
//}
//void MesDist:prepareMessage(string message,string fromIp,string toIP, string header){}
//
//void MesDist::run() {
//	string ERRORMESSAGE="{header:ERROR,message:User has left the network}";
//	vector<User> messageQueue;
//	while(true){
//		string json=getUserMessage();
//		string fromUserIP="";
//		string toUserIP="";
//		string header="";
//		string message="";
//		if(header==DECLERATION){
//			sendMessageToRequester(getUserList(),fromUserIP);
//		}else if(header==MESSAGETOUSER){
//			if(isRequestedUserIPAvailable(toUserIP)){
//				if(!sendMessageToRequester(prepareMessage(message,fromUserIP,toUserIP,header),toUserIP)){
//					ERRORMESSAGE="{header:ERROR,message:Message couldn't be sent to the user, will be tried again}";
//					messageQueue.push_back("User Message","IP");
//					sendMessageToRequester(ERRORMESSAGE,toUserIP);
//				}
//			}else{
//				sendMessageToRequester(ERRORMESSAGE,fromUserIP);
//			}
//		}
//	}
//	this->co = ConnectionObserver::Instance();
//	this->ml =MessageListener::Instance();
//
//	pthread_t cobserver, mlistener;
//	//pthread_t bwObs;
//	int rc;
//
//	//run SNR measurement of the users
//	if ((rc = pthread_create(&cobserver, NULL, &ConnectionObserver::run, co))) {
//		printf("MessageDistributor : Connection Observer thread creation failed: %d\n", rc);
//	}
//	//run Traffic Measurement of the user
//	if ((rc = pthread_create(&mlistener, NULL, &MessageListener::run,ml))) {
//		printf("MessageDistributor : MessageListener thread creation failed: %d\n", rc);
//	}
//
//	pthread_join(cobserver, NULL);
//	pthread_join(mlistener, NULL);
//
//	cout<<"-----------------------------------------"<<endl;
//}
//bool MesDist::getUser(string& IP ) {
//	bool state=false;
//	pthread_mutex_lock(&MesDist::Instance()->mutex_user);
//	for (unsigned int i = 0; i < MesDist::Instance()->userList.size(); i++) {
//		if (MesDist::Instance()->userList[i].ip==IP  ) {
//			state=true;
//			break;
//		}
//	}
//	pthread_mutex_unlock(&MesDist::Instance()->mutex_user);
//	return state;
//}
//void MesDist::removeUser(string& IP){
//	Utilities::writeOutputInFile("MessageDistributor: User is deleted...");
//
//	pthread_mutex_lock(&MesDist::Instance()->mutex_user);//mutex list
//	int index=0;
//	for (unsigned int i = 0; i < MesDist::Instance()->userList.size(); i++) {
//		if (MesDist::Instance()->userList[i].ip==IP  ) {
//			index=i;
//			break;
//		}
//	}
//	MessageDistributor::Instance()->userList.erase(MesDist::Instance()->userList.begin() + index);
//	pthread_mutex_unlock(&MesDist::Instance()->mutex_user);//mutex list
//
//}
//void MesDist::addUser(User user){
//	Utilities::writeOutputInFile("MessageDistributor: New user is added...");
//	pthread_mutex_lock(&MesDist::Instance()->mutex_user);//mutex list
//	MesDist::Instance()->userList.push_back(user);
//	pthread_mutex_unlock(&MesDist::Instance()->mutex_user);//mutex list
//
//}
//int main(int argc, char* argv[]) {
//
//	MesDist *md=MesDist::Instance();
//	md->run();
//}
//
//
