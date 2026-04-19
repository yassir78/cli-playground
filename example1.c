#include <stdio.h>
#include <string.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}


void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int fun1(unsigned word) {
return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
return ((int) word << 24) >> 24;
}

int uadd_ok(unsigned x, unsigned y){
    int sum = x + y;
    return sum >= x;
}

int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x > 0 && y > 0 && sum < 0) return 0;
    if (x < 0 && y < 0 && sum >= 0) return 0;
    return 1;
}

int main()
{
    int x = 53191;
    short sx = (short) x;
    printf("x = %d\n", x);
    printf("sx = %u\n", sx);
    return 0;
}