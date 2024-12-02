#include <cstdio>
// need to rearrange to make compatabile with word size of cpu
// 64 bits = 8 bytes cpu breaks into word size therefore giving us hole of 4

struct hole
{
    int a;
    double b[6];
    short c;
    short d;
    int e;
    int f;
};

struct noHole
{
    int a;
    short b;
    short c;
    double d[6];
    int e;
    int f;
};

int main()
{
    printf("CHAR: %ld\n", sizeof(char));
    printf("INT: %ld\n", sizeof(int));
    printf("DOUBLE: %ld\n", sizeof(double));
    printf("SHORT: %ld\n", sizeof(short));
    hole gumgum;
    noHole meramera;
}