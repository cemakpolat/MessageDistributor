/*
 * User.h
 *
 *  Created on: Jan 19, 2015
 *      Author: cem
 */

#ifndef USER_H_
#define USER_H_
#include <string>

class User {
public:
	std::string ip;
	int timeout;
	std::string message;
	std::string nickName;
	User();
	virtual ~User();
};


#endif /* USER_H_ */
