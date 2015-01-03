// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

template<typename T>
std::string toString(T val ) { // not terribly efficient, but works...
   std::ostringstream myostringstream;
   myostringstream << val;
   return myostringstream.str();
}
std::vector<std::string> split(const std::string &str, const std::string &separator = " " );
std::string trim( const std::string &target );
std::string toLower(std::string in );
inline double atof( std::string stringvalue ) {
   return std::atof(stringvalue.c_str());
}
inline double atoi( std::string stringvalue ) {
   return std::atoi(stringvalue.c_str());
}

