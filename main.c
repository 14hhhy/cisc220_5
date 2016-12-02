#include <stdio.h>
#include"udll.h"

int main() {
union Data data;
data.i = 5;
insert(0,data.i,0);
data.i = 4;
insert(0,data.i,0);
data.i = 3;
insert(0,data.i,0);
data.i = 2;
insert(0,data.i,0);
data.i = 1;
insert(0,data.i,0);
removeNode(3);
//printf("Node 4: %u\n", get(4));
printf("List length: %d\n", length());
return 0;
}
