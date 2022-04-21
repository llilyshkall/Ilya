#ifndef __two_three_tree_h
#define __two_three_tree_h

#define two_three_tree node*

int TTT_find(two_three_tree T);
// поиск
void TTT_push(two_three_tree T, int x);
// добавление с балансировкой
void TTT_pop(two_three_tree T, int x);
// удаление с балансировкой
#endif
