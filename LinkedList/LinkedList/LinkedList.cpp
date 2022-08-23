// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*head = NULL;

void create(int a[], int n)
{
    int i; 
    struct Node *t, *last; 

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = a[0];
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }


}

void display(struct Node *p)
{
    struct Node* t = p;

    while (t != NULL)
    {
        std::cout << t->data << "  ";
        t = t->next;
    }
}

void recdisplay(struct Node* p)
{
    if (p != NULL)
    {
        
        std::cout << p->data << "  ";
        recdisplay(p->next);
    }
}

void count(struct Node* head)
{
    struct Node* curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }

    std::cout << "Count is " << count << "  ";
}

int sum(struct Node* head)
{
    struct Node* curr = head;
    
    int sum = 0;
    
    while (curr != NULL)
    {
        sum += curr->data;
        curr = curr->next;
    }

    return sum;
}

Node* maxNode(struct Node* head)
{
    struct Node* curr = head, * ele = head;
    
    int max = curr->data;
    
    while (curr != NULL)
    {
        if (max < curr->data)
        {
            max = curr->data;
            ele = curr;
        }

        curr = curr->next;
    }

    return ele;
}

int main()
{
    int a[] = { 3,5,7,10,15 };

    create(a, 5);
   // display(first);
    recdisplay(head);
    count(head);

    std::cout << "Sum is " << sum(head) << "\n";

    std::cout << "Max is " << maxNode(head)->data << " ";
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
