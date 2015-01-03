// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "cpp-batteries/StringHelper.h"

vector<string> split(const string &str, const string &separator ) {
	vector<string> splitstring;
	int start = 0;
	int npos = str.find(separator);
	while (npos != (int)str.npos ) {
		splitstring.push_back( str.substr(start, npos-start) );
		start = npos + 1;
		npos = str.find(separator, start);
	}
	splitstring.push_back( str.substr( start ) );
   return splitstring;
}

string trim( const string &target ) {

   int origlen = target.size();
   int startpos = -1;
   for( int i = 0; i < origlen; i++ ) {
      if( target[i] != ' ' && target[i] != '\r' && target[i] != '\n' ) {
         startpos = i;
         break;
      }
   }
   int endpos = -1;
   for( int i = origlen - 1; i >= 0; i-- ) {
      if( target[i] != ' ' && target[i] != '\r' && target[i] != '\n' ) {
         endpos = i;
         break;
      }      
   }
   if( startpos == -1 || endpos == -1 ) {
      return "";
   }
   return target.substr(startpos, endpos-startpos + 1 );
}

std::string toLower(std::string in ) {
   int len = in.size();
   char buffer[len + 1];
   for( int i = 0; i < len; i++ ) {
      char thischar = in[i];
      thischar = tolower(thischar);
      buffer[i] = thischar;
   }
   buffer[len] = 0;
   return std::string(buffer);
}

