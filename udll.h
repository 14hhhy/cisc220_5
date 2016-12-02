#ifndef UDLL_H
#define UDLL_H

union Data;
struct Node;
void insert(int index, union Data data, int type);
void removeNode(int index);
union Data get(int index);
int length();

#endif
