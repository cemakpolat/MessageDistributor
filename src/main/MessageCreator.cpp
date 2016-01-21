/*
 * MessageCreator.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */

#include "MessageCreator.h"
#include "MessageDistributor.h"
using namespace std;
 string MessageCreator::HEADER="HEADER";
 string MessageCreator::H_UPDATE="UPDATE";
 string MessageCreator::H_DECLARATION="DECLARATION";
 string MessageCreator::H_MESSAGETOUSER="MESSAGETOUSER";
 string MessageCreator::H_ERROR="ERROR";
 string MessageCreator::H_SUCCESS="SUCCESS";
 string MessageCreator::H_USERLIST="USERLIST";

 string MessageCreator::CONTENT="CONTENT";
 string MessageCreator::FROMUSER="FROMUSER";
 string MessageCreator::TOUSER="TOUSER";
 string MessageCreator::NODATA="NODATA";
 string MessageCreator::MESSAGE="MESSAGE";

 string MessageCreator::MESSAGEUNKNOWN="MESSAGEUNKOWN";
 string MessageCreator::USERNOTAVAILABLE="User not available";
MessageCreator::MessageCreator() {
	// TODO Auto-generated constructor stub

}

MessageCreator::~MessageCreator() {
	// TODO Auto-generated destructor stub
}
// call either only



string MessageCreator::createMessage(string header, string content, string fromUser, string toUser){

	json::Object message;
	message[HEADER]=json::String(header);
	message[CONTENT]=json::String(content);
	message[FROMUSER]=json::String(fromUser);
	message[TOUSER]=json::String(toUser);
	JSONIO *jio=new JSONIO();
	return jio->convertJSONToString(message) ;
}
string MessageCreator::createMessage(string header, json::Object data, string fromUser, string toUser){
	json::Object message;
	message[HEADER]=json::String(header);
	message[CONTENT]=data;
	message[FROMUSER]=json::String(fromUser);
	message[TOUSER]=json::String(toUser);
	JSONIO *jio=new JSONIO();
	return jio->convertJSONToString(message) ;
}
void MessageCreator::preapareUserList(json::Object& userJSONList){
	vector<User> userList;
	MessageDistributor::Instance()->getUserList(userList);
	json::Object message;
	json::Array users;
	for(int i=0;i<userList.size();i++){
		json::Object user;
		user["IP"]=json::String(userList[i].ip);
		user["NICKNAME"]=json::String(userList[i].nickName);
		users.Insert(user);
	}
	userJSONList["USERLIST"]=users;
}
