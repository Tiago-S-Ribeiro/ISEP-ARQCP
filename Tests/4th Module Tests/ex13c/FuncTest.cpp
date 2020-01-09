#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(int, int , int  ), int p_param, int , int , int); 
}

//START: testGroup
TEST_GROUP(activate_invert_bits)
{
    int  expected;
    void setup()
    {
        expected = 0; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(int x ,int y ,int z)
    { 
	int result; 
	result=call_func(activate_invert_bits,3,x,y,z); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(activate_invert_bits, Zero)
{
    expect(~0);
    given(0,31,0);
}

TEST(activate_invert_bits, One)
{
    expect(~0xfe00007f);
    given(0,24,7);
}


TEST(activate_invert_bits, Two)
{
    expect(~0x80000001);
    given(0,30,1);
}

TEST(activate_invert_bits, Three)
{
    expect(~0xc0000003);
    given(0,29,2);
}
TEST(activate_invert_bits,Four)
{
    expect(~0xffffffff);
    given(0,7,24);
}

TEST(activate_invert_bits, Five)
{
    expect(~0xffffffff);
    given(-1,31,0);
}

TEST(activate_invert_bits, Six)
{
    expect(~0xffffffff);
    given(-1,7,24);
}


TEST(activate_invert_bits, Seven)
{
    expect(~0xff55557f);
    given(0x55555555,24,7);
}


TEST(activate_invert_bits, Eight)
{
    expect(~0xd5555557);
    given(0x55555555,29,2);
}

