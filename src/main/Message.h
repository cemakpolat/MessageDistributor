/*
 * Messae.h
 *
 *  Created on: Jan 19, 2015
 *      Author: cem
 */

#ifndef MESSAE_H_
#define MESSAE_H_
#include <string>
class Message {
public:
		std::string header;
		std::string message;
		std::string fromIP;
		std::string toIP;
		int messageTrial;
	Message();
	virtual ~Message();
};

#endif /* MESSAE_H_ */
