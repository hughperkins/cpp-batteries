#pragma once

#include <string>

class FileHelper {
public:
    static long getFileLength(std::string filepath );
    static void createDirectory( const std::string dirpath ); // make directory, platform independent, hopefully
    static bool fileExists( const std::string filepath );
    static void deleteFile( const std::string filepath );
};

