// wrong output

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(node *&head, int val)
{

    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

node *rotate_DLL_by_N(node *&head, int pos)
{
    if (head == NULL)
    {
        return NULL;
    }

    head->prev = NULL;
    node *temp = head;
    node *curr = head;
    node *newhead;

    int count = 0;
    while (curr != NULL && count < pos)
    {
        newhead = curr;

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->next;
        count++;
    }
    if (count >= pos)
    {
        node *rest = rotate_DLL_by_N(curr, pos);
        head->next = rest;
        if (rest != NULL)
        {
            rest->prev = head;
        }
    }

    return newhead;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head);
    node *newhead = rotate_DLL_by_N(head, 2);
    display(newhead);

    return 0;
}