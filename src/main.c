// #include <iostream>
#include <stdio.h>

typedef struct person
{
    int id;
} person_t;

void main(int argc, char **argv)
{
    // printf("Hello, world!\n");
    ssize_t i;
    for (i = 0; i < 100000; i++)
    {
        person_t p;
        p.id = i;
        printf("person id %d\t", p.id);
    }
}
