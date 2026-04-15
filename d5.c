#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void delete_begin() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    if(head == NULL) return;

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


void delete_value(int key) {
    struct Node *temp = head, *prev = NULL;

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Not found\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void display() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(30);
    insert(20);
    insert(10);

    delete_begin();
    delete_end();
    delete_value(20);

    display();
    return 0;
}