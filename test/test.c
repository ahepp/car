#include "unity.h"

void setUp()
{
}
void tearDown()
{
}

extern void test_parse();
extern void test_eval();

int main()
{
        UNITY_BEGIN();

        test_parse();
        test_eval();

        return UNITY_END();
}
