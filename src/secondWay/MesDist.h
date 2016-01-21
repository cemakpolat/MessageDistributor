
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


#ifndef MESDIST_H_
#define MESDIST_H_
#include <string>
#include <vector>
#include "PracticalSocket.h"
#include "TCPConnection.h"
#include "User.h"


class MesDist {
private:
	static MesDist* m_mdInstance;
public:
	static  std::string className;						/**< Class Name */
	ConnectionObserver *co;								/**< Connection Observer */
	pthread_mutex_t mutex_user;						/**< Pthread Mutex for window synchronization */
	MessageListener *ml;								/**< MessageListener  */
	static std::vector<User> userList;				/**< Average Delay Window */



	static int selectedDevice;							/**< indicates the selected router */
	static int itgRestartDuration;						/**< ITG Restart Time */
	MesDist();
	virtual ~MesDist();
	/**
	* Create only one instance of this class
	* \return the same reference of the created object in case it is invoked by other objects.
	*/
	static MesDist* Instance();
	/**
	 * Activates all components: QoS Improver, Window Manager, Transmission Power Controller, Connection Tracker, D-ITG Tool.
	 */
	void run();
	bool getUser(string& );
	void removeUser(string& );
	void addUser(User );



};


#endif /* MESDIST_H_ */
