#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void delete_node(int data)
{
    struct node *temp = head;

    while(temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Data not found\n");
        return;
    }

    if(temp->prev == NULL)
    {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

void delete_the_end_node()
{
    if(head == NULL)
        return;

    struct node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    if(temp->prev == NULL)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }

    free(temp);
}

void delete_node_with_givenData(int key, int data)
{
    struct node *temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Key not found\n");
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

void traverse_backward()
{
    struct node *temp = head;

    if(temp == NULL)
        return;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *n1 = (struct node*)malloc(sizeof(struct node));
    struct node *n2 = (struct node*)malloc(sizeof(struct node));
    struct node *n3 = (struct node*)malloc(sizeof(struct node));

    n1->data = 10; n1->prev = NULL; n1->next = n2;
    n2->data = 20; n2->prev = n1; n2->next = n3;
    n3->data = 30; n3->prev = n2; n3->next = NULL;

    head = n1;

    delete_node(20);
    delete_the_end_node();
    delete_node_with_givenData(10, 25);

    traverse_backward();

    return 0;
}