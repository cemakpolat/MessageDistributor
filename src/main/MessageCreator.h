/*
 * MessageCreator.h
 *
 *  Created on: Jan 11, 2015
 *      Author: cem
 */

#ifndef MESSAGECREATOR_H_
#define MESSAGECREATOR_H_
#include <string>
#include "JSONIO.h"
using namespace std;

class MessageCreator {
public:
	MessageCreator();
	virtual ~MessageCreator();

	static string HEADER;
	static string H_UPDATE;
	static string H_DECLARATION;
	static string H_MESSAGETOUSER;
	static string H_ERROR;
	static string H_SUCCESS;
	static string H_USERLIST;

	static string CONTENT;
	static string FROMUSER;
	static string TOUSER;
	static string NODATA;
	static string MESSAGEUNKNOWN;
	static string MESSAGE;
	static string USERNOTAVAILABLE;

	string createMessage(string header, string content, string fromUser, string toUser);
	string createMessage(string header, json::Object, string fromUser, string toUser);
	void  preapareUserList(json::Object& userJSONList);

};

#endif /* MESSAGECREATOR_H_ */
