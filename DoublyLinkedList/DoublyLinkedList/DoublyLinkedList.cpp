// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} *head = NULL;

void create(int arr[], int n)
{
    struct Node* t, * p;
    int i;

    head = (struct Node*)malloc(sizeof(struct Node*));
    head->data = arr[0];
    head->prev = head->next = NULL;
    p = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node*));
        t->data = arr[i];
        t->next = p->next;
        t->prev = p;
        p->next = t;
        p = t;
    }
}

void display(struct Node* p)
{
    struct Node* k = p;
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    //while (p != NULL)
    //{
    //    std::cout << p->data << " ";
    //    p = p->prev;
    //}
}

int length(struct Node* p)
{
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }

    return count;
}

void Delete(struct Node* p, int pos)
{
    if (pos < 0 || pos > length(p)) return;

    struct Node* t;
    int x = -1, i;

    if (pos == 0)
    {
        head = head->next;
        if (head) head->prev = NULL;

        //x = p->data;
        //free(p);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        //free(p);
    }

}

void insert(struct Node* p, int value, int pos)
{
    if (pos < 0 || pos > length(p)) return;

    int i;

    struct Node* t = (struct Node*)malloc(sizeof(struct Node*));
    t->data = value;
    
    if (pos == 0)
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            p = p->next;
        }
        
        t->prev = p;
        t->next = p->next;
        if (p->next)p->next->prev = t;
        p->next = t;
    }
}


int main()
{
    int arr[5] = { 1,2,3,4,5 };
    create(arr, 5);
    std::cout << length(head)<<"\n\n";
    insert(head, 10, 2);
    Delete(head, 4);
    display(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
