#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* potato;
    potato = (char*)malloc(100);
    potato = "123";
    int num = atoi(potato);
    printf("d: %d\n", num);
}
