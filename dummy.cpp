#include <stdio.h>
int main()
{
    unsigned int a = 0x12345678, b = 0x11223344, c = 0x11223344;
    b = (unsigned short int)a;
    c = (unsigned char)a;
    printf("a=%x, b = %x, c = %x\n", a, b, c);
}