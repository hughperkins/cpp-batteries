#include "gtest/gtest.h"

#include "cpp-batteries/StringHelper.h"

using namespace std;

TEST( testStringHelper, main ) {
    string input = "This is a test";
    vector<string> splitinput = split( input, " " );
    EXPECT_EQ( "This", splitinput[0] );
    EXPECT_EQ( "test", splitinput[3] );
    EXPECT_EQ( 4, splitinput.size() );
    EXPECT_EQ( "this", toLower( splitinput[0] ) );
    EXPECT_EQ( "123", toString( 123 ) );
    EXPECT_EQ( "53.45", toString( 53.45f ) );
}

