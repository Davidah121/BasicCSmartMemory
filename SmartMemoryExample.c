#include <stdio.h>
#include <stdlib.h>
#include "SmartMemory.h"

int main()
{
    int* v = SmartMalloc(sizeof(int));
    *v = 32;
    if(SmartMemoryIsValid(v))
        printf("Pointer %p is valid with value = %d\n", v, *v);
    else
        printf("Pointer %p is INVALID\n", v);
    
    SmartFree(v);
    if(SmartMemoryIsValid(v))
        printf("Pointer %p is valid\n", v);
    else
        printf("Pointer %p is INVALID\n", v);
    
    return 0;
}