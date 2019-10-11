/*
 * Program description: A program to impliment a simple alphabet linked list
 * Author: Mikael Escolin
 * Date started: 11/10/19
 */

#include <stdio.h>

typedef struct AlphaNode
{
    char data;
    struct AlphaNode **next_node;
} Alpha;

void insert_node(Alpha **, char data);
void delete_node(Alpha **, char data);
void print_list(Alpha *);
void print_node(Alpha *, char data);

int main()
{
    printf("Hello World");

    return 0;
}//END main()
