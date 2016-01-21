/*
 * JSONIO.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef JSONIO_H_
#define JSONIO_H_
#include <string>
#include <vector>
#include "writer.h"
#include "elements.h"
#include "reader.h"
#include <fstream>

/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

class JSONIO {
public:
	JSONIO();
	~JSONIO();

	//Read JSON file and return as JSON Object.
	static json::Object readJSONFile(std::string& fileName1) ;

	// Write the given object in a file as a JSON object.
	static void fileJSONWrite(const json::Object& tobeWritten,
			const std::string& fileName) ;

	//Convert the json format string to JSON Object
	static json::Object convertStringToJSON(std::string& str);

	//Convert the given the json object to String
	static std::string convertJSONToString(json::Object jo) ;
};

#endif /* JSONIO_H_ */
