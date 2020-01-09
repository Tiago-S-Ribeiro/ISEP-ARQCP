#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
short  * ptrvec;  
int num;  
short x; 

int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(exists)
{
    short test_vec[100];
    int  expected; 
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = 0; 
	ptrvec=test_vec; 
	x=0; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(short * vec, int num_elem, short to_x)
    { 
	int result; 
	memcpy(test_vec,vec,num_elem*sizeof(short)); 
	num=num_elem; 
	x=to_x; 
	result=call_func(exists); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(exists, NullVector)
{
    expect(0); 
    short v[]={0}; 
    given(v,0,0);
}

TEST(exists, One)
{
    expect(0);
    short v[]={1}; 
    given(v,1,1);
}


TEST(exists,Zero)
{
    expect(0);
    short v[]={1,0,-1}; 
    given(v,3,2);
}


TEST(exists,Three)
{
    expect(1);
    short v[]={-1,-1,-1}; 
    given(v,3,-1);
}

TEST(exists,Nine)
{
    expect(1);
    short v[]={1,1,1,1,1,1,1,1,2}; 
    given(v,9,1);
}

TEST(exists,BIG)
{
    expect(1);
    short v[]={1,512,1,512,1,1,1,1,2}; 
    given(v,9,512);
}



//START: testGroup
TEST_GROUP(vec_diff)
{
    short test_vec[100];
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
    void given(short * vec, int num_elem)
    { 
	int result; 
	memcpy(test_vec,vec,num_elem*sizeof(short)); 
	num=num_elem; 
	result=call_func(vec_diff); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup


TEST(vec_diff, NullVector)
{
    expect(0); 
    short v[]={0}; 
    given(v,0);
}

TEST(vec_diff, One)
{
    expect(1);
    short v[]={1}; 
    given(v,1);
}


TEST(vec_diff,Zero)
{
    expect(1);
    short v[]={1,0,1}; 
    given(v,3);
}


TEST(vec_diff,MinusThree)
{
    expect(0);
    short v[]={-3,-3,-3}; 
    given(v,3);
}

TEST(vec_diff,Ten)
{
    expect(2);
    short v[]={120,10,10,10,10,10,10,10,10,110}; 
    given(v,10);
}




