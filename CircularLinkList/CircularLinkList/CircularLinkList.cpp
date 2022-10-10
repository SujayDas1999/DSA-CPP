// CircularLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int data;
    struct Node* next;
}*head = NULL;

void create(int a[], int count)
{
    int i;
    struct Node* temp, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (i = 1; i < count; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

}

void display(struct Node* he)
{
    
    //struct Node* curr = head;
    int flag = 0;
    do
    {
        std::cout << he->data << " ";
        flag = 1;
        he = he->next;
    } while (he != head && flag == 1);
}

int Length()
{
    struct Node* p = head;
    int count = 0;
    while (p->next != head)
    {
        p = p->next;
        count++;
    }

    return count;
}

void insert(struct Node* p, int number, int position)
{
    struct Node* temp; 
    int i;

    if (position < 0 || position > Length()) return;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = number;

    if (head == NULL)
    {
        head = temp;
        head->next = head;
    }

    if (position == 0)
    {
        while (p->next != head) p = p->next;
        p->next = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        for (i = 0; i < position - 1; i++)
        {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
        p = temp;
    }
}

void Delete(struct Node* p, int pos)
{
    if (pos < 0 || pos > Length()) return;
    struct Node* t = head;
    int i;
    if (pos == 0)
    {
        while (p->next != head) p = p->next;
        p->next = head->next;
        free(head);
        head = p->next;
        //delete(t);
    }
    else
    {
        for (i = 0; i < pos ; i++)
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
        p->next = NULL;
        p = t;
    }
}

int main()
{
    int a[] = { 1,2,3,4,5 };
    create(a, 5);
    insert(head,10, 0);
    Delete(head, 5);
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
