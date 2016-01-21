
/*
 *
 *  Version 1.0
 * Copyright Master Thesis project - 2013
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by  the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * APDME.h
 *
 *  Created on: 01.10.2013
 *      Author: Cem Akpolat
 */


#ifndef MESSAGEDISTRIBUTOR_H_
#define MESSAGEDISTRIBUTOR_H_
#include <string>
#include <vector>

#include "Utilities.h"
#include "Message.h"
#include "User.h"

class MessageDistributor {
private:
	static MessageDistributor* m_mdInstance;
public:
	static  std::string className;						/**< Class Name */
	pthread_mutex_t mutex_user;						/**< Pthread Mutex for window synchronization */
	pthread_mutex_t mutex_message;						/**< Pthread Mutex for window synchronization */


	static std::vector<User> userList;				/**< Average Delay Window */
	static std::vector<Message> messageQueue;

	static int DEFAULT_TIMEOUT;

	MessageDistributor();
	virtual ~MessageDistributor();
	/**
	* Create only one instance of this class
	* \return the same reference of the created object in case it is invoked by other objects.
	*/
	static MessageDistributor* Instance();
	/**
	 * Activates all components: QoS Improver, Window Manager, Transmission Power Controller, Connection Tracker, D-ITG Tool.
	 */
	void run();
	bool getUser(string&,User& );

	void removeUser(string& );
	void addUser(User );
	void getMessageList(vector<Message>&);
	void getUserList(vector<User>&);
	bool updateUserTimeoutDuration(string& IP);
	bool isUserIPAvailable(string& IP);
	void addMessage(Message message);


};
//typedef struct {
//	string header;
//	string message;
//	string fromIP;
//	string toIP;
//	int messageTrial;
//}Message;
//
//typedef struct {
//	string ip;
//	int timeout;
//	string message;
//	string nickName;
//}User;

#endif /* MESSAGEDISTRIBUTOR_H_ */
