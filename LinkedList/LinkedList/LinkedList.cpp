// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <map>

struct Node
{
    int data;
    struct Node* next;
}*head = NULL,*head2 = NULL, *head3 = NULL;

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

void create2(int a[], int n)
{
    int i;
    struct Node* t, * last;

    head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = a[0];
    last = head2;

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
      



        display(head);
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

bool checkIfLinkedListIsSorted(struct Node* head) 
{
    struct Node *curr = head, *prev = head;
    while (curr != NULL) 
    {
        if (prev->data > curr->data) return false;
        
        prev = curr;
        curr = curr->next;
    }

    return true;
}

void removeDuplicate(struct Node* head)
{
    struct Node* curr = head->next, *prev = head;
    
    while (curr != NULL)
    {
        if (prev->data == curr->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    display(head);
}

void reverseLinkedList(struct Node** head)
{
    struct Node* current = *head, * prev = NULL, * next = NULL;
    while (current != NULL)
    {
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    *head = prev;
}

void concat(struct Node** head, struct Node** head2)
{
    struct Node* curr = *head, * curr2 = *head2;
    head3 = *head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = curr2;

        
}

void merge(struct Node** head, struct Node** head2)
{
    struct Node* last;
    struct Node* p = *head;
    struct Node* q = *head2;

    if (p->data < q->data)
    {
        head3 = last = p;
        p = p->next;
        head3->next = NULL;
    }
    else
    {
        head3 = last = q;
        q = q->next;
        head3->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }

    }

    if (p) last->next = p;
    if (q) last->next = q;
}

bool loop(struct Node** head) {
    struct Node* curr = *head, * curr2 = *head;

    while (curr && curr2)
    {
        curr = curr->next;
        curr2 = curr2->next->next;

        while (curr->next == curr2->next)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int a[] = { 10, 30, 50, 70, 90, 110 };
    int b[] = { 20, 40, 60, 80, 100, 120 };
    create(a, 6);
    create2(b, 6);
    //insertingInSortedLL(head, 20);
    //deleteNode(head,4);
    //bool isSorted = checkIfLinkedListIsSorted(head);
    //isSorted ? std::cout << "Sorted" : std::cout << "Not sorted";
    //removeDuplicate(head);
    //reverseLinkedList(&head);
    //concat(&head, &head2);
    //merge(&head, &head2);
    //display(head3);
    //display(head2);
    bool isLoop = loop(&head);
    if (isLoop) std::cout << "Is Looped";
    else std::cout << "Not Looped";
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
