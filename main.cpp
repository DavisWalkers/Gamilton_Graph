#include <iostream>
#include "is_gamilton.h"
#include "test.h"

using namespace std;

int main()
{
	srand(time(0));            
    /* Test for correctness */
    testCorrectness();

    /* Measuring time on arbitrary graphs */
	testTime();
	
    return 0;
}

