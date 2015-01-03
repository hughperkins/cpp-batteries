cpp-batteries
=============

'batteries included' for C++.  Lightweight, commonly-used methods, not specific to any one project

Compared to 'boost':
* lightweight
* easy to compile

To be accepted for inclusion in this library, methods should be:
* not project specific
* fast to #include
* easy to build
* ideally, should work on at least linux-64, and windows-64

cpp-batteries/gtest_supp
------------------------

Googletest is one of the best unit-testing frameworks for C++.   This include provides an additional googletest assert for floats:
```
EXPECT_FLOAT_NEAR(var1, var2);
```

This will compare the absolute difference of (var1-var2) with var1, and only if the difference is 10,000 times smaller than var1, will the expect pass.  Also, the error message truncates var1 and var2 to several decimal places, rather than displaying it as around 15 or so.

cpp-batteries/Timer.h
---------------------

Use to measure elapsed time during your applications, for testing performance.  Use like this:
```
Timer timer;
// do some work here
// ...
timer.timeCheck("did some work");
// do some work here
// ...
timer.timeCheck("did some more work");
```

cpp-batteries/stringhelper.h
----------------------------

Provides standard string functionalities:
```
vector<string> split( string targetString, string splitCharacter ); // split someString by splitCharacter
string toString<T>( T target ); // converts `target` to a string, using `operator<<`
std::string trim( const std::string &target );
double atof( std::string stringvalue ); // since atof and atoi dont work on string by default, only on char *
double atoi( std::string stringvalue );
string toLower(std::string in );
```

cpp-batteries/filehelper.h
--------------------------

```
long FileHelper::getFileLength(std::string filepath );
void FileHelper::createDirectory( const std::string dirpath );
bool FileHelper::fileExists( const std::string filepath );
void FileHelper::deleteFile( const std::string filepath );
```


