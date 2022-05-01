#include <stdio.h>
#include <stdlib.h>

struct node
{
    int size;      // количество занятых ключей
    int key[3];    
    node *first;   // *first <= key[0];
    node *second;  // key[0] <= *second < key[1];
    node *third;   // key[1] <= *third < key[2];
    node *fourth;  // kye[2] <= *fourth.
    node *parent;
}


int TTT_find(two_three_tree T)
{

}

void TTT_push(two_three_tree T, int x)
{
	printf("test\n");
}

void TTT_pop(two_three_tree T, int x)
{
  
}


void TTT_clear(two_three_tree T)
{
    if(first != NULL)
    {
        TTT_clear(T->first);
        free(T->first);
    }
    if(second != NULL)
    {
        TTT_clear(T->second);
        free(T->second);
    }
    if(third != NULL)
    {
        TTT_clear(T->third);
        free(T->third);
    }
    free(T);
}
