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

int count(struct Node* head)
{
    struct Node* curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }

    //std::cout << "Count is " << count << "  ";
    return count;
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

struct Node* maxNode(struct Node* head)
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

bool search(struct Node* head, int key)
{
    struct Node* curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

void insert(struct Node* head, int pos, int data)
{
    struct Node* t, * p, *curr = head;
    if (pos < 0 || pos > count(head)) return;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (pos == 0)
    {
    
        t->next = head;
        head = t;
        curr = t;
    }
    else 
    {
        int i = 1;
        while (i != pos)
        {
            head = head->next;
            i++;
            //t = t->next;
        }

        t->next = head->next;
        head->next = t;
        head = t;
    }

    display(curr);
}

void createInsert(int a[], int count)
{
    struct Node* t, * p=head;
    int pos = 0;

    while (pos < count)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        //t->next = NULL;
        if (pos == 0)
        {
            t->data = a[pos];
            t->next = head;
            head = t;
            p = head;
        }
        else 
        {

            t->data = a[pos];
            t->next = NULL;
            p->next = t;
            p = t;
        }

        pos++;
    }
   
}

void insertingInSortedLL(struct Node* p, int ele)
{
    if (count(head) == 0) insert(head, 0, ele);
    else 
    {
        struct Node* curr = head, *prev=head;

       while (curr != NULL)
       {
           if (curr->data > ele) break;

           prev = curr;
           curr = curr->next;
      }
       
       struct Node* t;

       t = (struct Node*)malloc(sizeof(struct Node));
       t->data = ele;
       t->next = NULL;

       if (curr == head)
       {
           t->next = head;
           head = t;
       }

       else 
       {

           t->next = curr;
           prev->next = t;
       }
      



        //display(head);
    }
}

void deleteNode(struct Node* head, int ele)
{
    if (head == NULL) return;

    struct Node* curr = head, *prev = head;
    
    while (curr != NULL)
    {
        if (curr->data == ele) break;

        prev = curr;
        curr = curr->next;
    }

    if (curr == head)
    {
        head = curr->next;
        curr->next = NULL;
    }
    else 
    {
        prev->next = curr->next;
        curr->next = NULL;
    }
    

    display(head);

}

int main()
{
    int a[] = { 3,5,7,10,15 };

    createInsert(a, 5);
    insertingInSortedLL(head, 4);
    deleteNode(head,4);
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
