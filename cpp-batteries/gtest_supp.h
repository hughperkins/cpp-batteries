#include "gtest/gtest.h"
#include "stringhelper.h"

//#define ASSERT_FLOAT_NEAR( val1, val2, tolerance_as_fraction_val1 ) \
//    ASSERT_NEAR( val1, val2, val1 * tolerance_as_fraction_val1 );

//#define EXPECT_FLOAT_NEAR( val1, val2, tolerance_as_fraction_val1 ) \
//    EXPECT_NEAR( val1, val2, val1 * tolerance_as_fraction_val1 );

//#define ASSERT_FLOAT_NEAR( val1, val2 ) \\
//    ASSERT_NEAR( val1, val2, 0.0001f );


inline ::testing::AssertionResult AssertFloatsNear( const char *expr_one, const char *expr_two,
    float one, float two ) {
    float diff = one - two;
    float absdiff = diff > 0 ? diff : - diff;
    float absone = one > 0 ? one : -one;
    if( absdiff <= absone * 0.0001f ) {
        return ::testing::AssertionSuccess();
    }
    std::string onestr = toString(one);
    std::string twostr = toString(two);
    return ::testing::AssertionFailure()
        << expr_one << " and " << expr_two << " differ: " << onestr << " vs " << twostr;
} 

inline bool floatsNear( float a, float b ) {
    float diff = a - b;
    float absdiff = diff > 0 ? diff : - diff;
    float absa = a > 0 ? a : - a;
//    std::cout << "absa " << absa << " absdiff " << absdiff << std::endl;
    return absdiff < absa * 0.0001f;
}

#define EXPECT_FLOAT_NEAR( one, two) EXPECT_PRED_FORMAT2( AssertFloatsNear, one, two )
#define ASSERT_FLOAT_NEAR( one, two) ASSERT_PRED_FORMAT2( AssertFloatsNear, one, two )


