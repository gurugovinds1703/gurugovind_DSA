#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insert_at_end(int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert_after_key(int key, int data) {
    struct Node *temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL) {
        printf("Key not found\n");
        return;
    }

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = temp->next;
    temp->next = newnode;
}

void traverse() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_end(20);
    insert_after_key(10, 15);

    traverse();
    return 0;
}