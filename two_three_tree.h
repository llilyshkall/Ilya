#ifndef __two_three_tree_h
#define __two_three_tree_h

#define two_three_tree struct node*

int TTT_find(two_three_tree T, int x);
// поиск
int TTT_push(two_three_tree T, int x);
// добавление с балансировкой
int TTT_pop(two_three_tree T, int x);
// удаление с балансировкой
void TTT_clear(two_tree_tree T);
// отчистка памяти

#endif
