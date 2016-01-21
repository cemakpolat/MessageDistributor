/*
 * Main.cpp
 *
 *  Created on: Jan 19, 2015
 *      Author: cem
 */

#include "Main.h"

Main::Main() {
	// TODO Auto-generated constructor stub
}

std::string Main::className="Main";

//singleton pattern required
Main* Main::m_mdInstance = NULL;
Main* Main::Instance() {
	if (!m_mdInstance)   // Only allow one instance of class to be generated.
		m_mdInstance = new Main();
	return m_mdInstance;
}

Main::~Main() {
	delete co;
	delete ml;
	delete ms;

}

void Main::run() {
	this->co = ConnectionObserver::Instance();
	this->ml =MessageListener::Instance();
	this->ms =MessageSender::Instance();

	this->runCenter(this->cObserver,ConnectionObserver::run,this->co);
	this->runCenter(this->mListener,MessageListener::run,this->ml);
	this->runCenter(this->mSender,MessageSender::run,this->ms);

	pthread_join(cObserver, NULL);
	pthread_join(mListener, NULL);
	pthread_join(mSender, NULL);

	cout<<"-----------------------------------------"<<endl;
}
template <class T,class U,class B>
void Main::runCenter(T& a, U& b, B* data) {// T MainDME::runCenter (T& a, U& b,B* data )
	int rc1;
	//start related thread

	if ((rc1 = pthread_create(&a, NULL, &b, data))) {
		printf("MainDME: Thread creation failed: %d\n", rc1);
		int attempt = 0;
		while (attempt < 3) {
			bool success = true;
			Utilities::randomBackOfftime(7);
			if ((rc1 = pthread_create(&a, NULL, &b, data))) {
				success = false;
				printf("MainDME:Thread creation failed: %d\n", rc1);
				if (attempt == 2) {
					printf("MAinDME:Thread creation failed,please re-start the program. \n");
				}
			}
			if (success == true) {
				attempt = 3;
			}
		}
	}
}


int main(int argc, char* argv[]) {

	Main *md=Main::Instance();
	md->run();
}


//	pthread_t cObserver, mListener, mSender;
//
//	int rc;
//
//	//run
//	if ((rc = pthread_create(&cObserver, NULL, &ConnectionObserver::run, co))) {
//		printf("MessageDistributor : Connection Observer thread creation failed: %d\n", rc);
//	}
//	//run
//	if ((rc = pthread_create(&mListener, NULL, &MessageListener::run,ml))) {
//		printf("MessageDistributor : MessageListener thread creation failed: %d\n", rc);
//	}
//	//run
//	if ((rc = pthread_create(&mSender, NULL, &MessageSender::run,ms))) {
//		printf("MessageDistributor : MessageListener thread creation failed: %d\n", rc);
//	}
