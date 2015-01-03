#include <fstream>
#include <vector>
#include <stdexcept>
#ifdef WIN32
#include "windows.h"
#include "io.h"
#else
#include <unistd.h>
#include <sys/stat.h>
#endif
using namespace std;

#include "cpp-batteries/FileHelper.h"
#include "cpp-batteries/StringHelper.h"

bool FileHelper::fileExists( const string filepath ) {
   ifstream testifstream(filepath.c_str() );
   bool exists = testifstream.good();
   testifstream.close();
   return exists;
}

void FileHelper::deleteFile( const string filepath ) {
   remove(filepath.c_str());
}

long FileHelper::getFileLength(std::string filepath ) {
   FILE *file = fopen(filepath.c_str(), "r");
   if( file == 0 ) {
      throw std::runtime_error( "File " + std::string( filepath ) + " couldn't be opened" );
   }
   fseek(file, 0L, SEEK_END);  /* Position to end of file */
   long len = ftell(file);     /* Get file length */
   fclose(file);
   return len;
}

void FileHelper::createDirectory( const std::string dirpath ) { // make directory, platform independent, hopefully
   #ifdef WIN32
      ::CreateDirectoryA(dirpath.c_str(), NULL);
   #else
      mkdir( dirpath.c_str(), S_IRWXU );
   #endif
}

