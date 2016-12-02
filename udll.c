#include <stdio.h>
#include <stdlib.h>
#include "udll.h"

union Data {
int i;
int* ip;
float f;
float fp;
char c;
char cp;
};

struct Node {
int type;
union Data data;
struct Node *prev;
struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;
struct Node *current = NULL;

void insert(int index, union Data data, int type) {
struct Node *current = head;
struct Node *new = (struct Node*)malloc(sizeof(struct Node));
struct Node *length = (struct Node*)malloc(sizeof(struct Node));
new->data = data;
length->data = length();
if (head==NULL || index==0) {
new->next = NULL;
new->prev = length;
length->next = new;
length->prev = NULL;
last = new;
head = length;
} else if (index==1) {
head->next->prev = new;
new->next = head->next;
length->next = new;
length->prev = NULL;
head = length;
} else {
int i;
for (i=0; i<index-1; i++) {
if (current->next==NULL) {
printf("Index out of range.\n");
} else {
current = current->next;
}
}
if (current==last) {
new->next = NULL;
last = new;
} else {
new->next = current->next;
current->next->prev = new;
}
new->prev = current;
current->next = new;
}
}

void removeNode(int index) {
struct Node *current = head;
struct Node *length = (struct Node*)malloc(sizeof(struct Node));
length->data = length();
if (head==NULL) {
printf("List is empty.\n");
} else if (head->next->next==NULL) {
last = NULL;
head = NULL;
} else if (index==0) {
printf("Invalid index.");
} else if (index==1) {
head->next->next->prev = length;
length->next = head->next->next;
length->prev = NULL;
head = length;
} else {
int i;
for (i=0; i<index; i++) {
if (current->next==NULL) {
printf("Index out of range.\n");
} else {
current = current->next;
}
}
if (current==last) {
current->prev->next = current->next;
last = current->prev;
} else {
current->prev->next = current->next;
current->next->prev = current->prev;
}
}
}

union Data get(int index) {
struct Node *current = head;
int i;
for (i=0; i<index; i++) {
if (current->next==NULL) {
printf("Index out of range.\n");
} else {
current = current->next;
}
}
return current->data;
}

int length() {
struct Node *current;
int length = 0;
for (current=head; current!=NULL; current=current->next) {
length++;
}
return length;
}
