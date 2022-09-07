#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time_t(NULL));
    for(int i=0; i<5; i++)
        printf("Random number #%d: %d\n", i, rand()%100);
    return 0;
}
