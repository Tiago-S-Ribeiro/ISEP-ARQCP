#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "asm.h"
long long  * ptrvec;
int num;

 int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(vec_greater20)
{
    long long test_vec[100];
    int  expected;
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = 0;
	ptrvec=test_vec;
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(long long * vec, int num_elem)
    {
	int result;
	memcpy(test_vec,vec,num_elem*sizeof(long long ));
	num=num_elem;
	result=call_func(vec_greater20);
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_greater20, NullVector)
{
    expect(0);
    long long v[]={0};
    given(v,0);
}

TEST(vec_greater20, One)
{
    expect(1);
    long long v[]={21};
    given(v,1);
}


TEST(vec_greater20,Zero)
{
    expect(0);
    long long v[]={1,0,-1};
    given(v,3);
}


TEST(vec_greater20,Three)
{
    expect(3);
    long long v[]={100,1001,0x1000000001};
    given(v,3);
}

TEST(vec_greater20,Ten)
{
    expect(0);
    long  long v[]={1,1,1,1,1,1,1,1,20,1};
    given(v,10);
}
