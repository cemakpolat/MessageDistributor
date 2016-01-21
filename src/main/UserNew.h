/*
 * UserNew.h
 *
 *  Created on: Jan 19, 2015
 *      Author: cem
 */

#ifndef USERNEW_H_
#define USERNEW_H_
#include <string>

class UserNew {
public:
		std::string ip;
		int timeout;
		std::string message;
		std::string nickName;
	UserNew();
	virtual ~UserNew();
};

#endif /* USERNEW_H_ */
