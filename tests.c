#include "unity/unity.h"

void setUp()
{
}
void tearDown()
{
}

extern void test_obj();

int main()
{
        UNITY_BEGIN();

        test_obj();

        return UNITY_END();
}
