/*
 * Main.h
 *
 *  Created on: Jan 19, 2015
 *      Author: cem
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <string>
#include <vector>

#include "ConnectionObserver.h"
#include "MessageListener.h"
#include "MessageSender.h"
#include "Utilities.h"
#include "MessageDistributor.h"
class Main {

private:
	static Main* m_mdInstance;
public:
	static  std::string className;						/**< Class Name */

	pthread_t cObserver;
	pthread_t mListener;
	pthread_t mSender;

	ConnectionObserver *co;								/**< Connection Observer */
	MessageListener *ml;								/**< MessageListener  */
	MessageSender *ms;



	Main();
	virtual ~Main();
	/**
	* Create only one instance of this class
	* \return the same reference of the created object in case it is invoked by other objects.
	*/
	static Main* Instance();
	/**
	 * Activates all components: QoS Improver, Window Manager, Transmission Power Controller, Connection Tracker, D-ITG Tool.
	 */
	void run();
	bool getUser(string&,User& );



	template <class T,class U,class B>
		void runCenter (T& a, U& b,B* data);
};

#endif /* MAIN_H_ */
