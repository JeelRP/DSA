#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev=NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n; 
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *reverse(node *head)
{
    node *prevptr = NULL;
    node *curptr = head;
    node *nextptr;

    while (curptr != NULL)
    {
        nextptr = curptr->next;
        curptr->next = prevptr;

        prevptr = curptr;
        curptr = nextptr;
    }
    return prevptr;
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node* reverseDLL(node * head)
{
    node *temp = NULL;
    node *current = head;
     
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }
     
    if(temp != NULL )
        head = temp->prev;
        
    return head;
}

int main()
{
    node *head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    node *newhead = reverseRecursive(head);
    display(newhead);

    // reverseDLL(head);
    // display(head);

    return 0;
}