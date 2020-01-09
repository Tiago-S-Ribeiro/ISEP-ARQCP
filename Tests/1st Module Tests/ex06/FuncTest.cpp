#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 
} 

//START: testGroup
TEST_GROUP(power_ref)
{
      
    int  expected; 
    void setup()
    {
        expected = -1;
    }
    void teardown()
    {
    }
    void expect(int res)
    {
        expected = res; 		

	}
    void given(int x, int y )
    { 
	int pot=x;   
    	power_ref(&pot,y); 	
	LONGS_EQUAL(expected,pot); 
    }
};
//END: testGroup


TEST(power_ref, Zero)
{
    expect(1);
    given(3,0);
}

TEST(power_ref, Minus)
{
    expect(0);
    given(3,-3);
}

TEST(power_ref, One)
{
    expect(2);
    given(2,1);
}



TEST(power_ref, Minus3)
{
    expect(-27);
    given(-3,3);
}

TEST(power_ref, Plus3)
{
    expect(27);
    given(3,3); 
}





//END: RefactoredTests


