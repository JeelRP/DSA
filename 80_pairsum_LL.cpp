#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int val)
{
    
    node* n=new node(val);
    n->next=head;
    if (head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}
void insertAtTail(node* &head,int val)
{
    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    
    node* n=new node(val);
    node* temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void PairSum(node* head, int x)
{
    node* first=head;
    node* second=head;

    while (second->next!=NULL)
    {
        second=second->next;
    }
    bool found=false;
    while (first!=second && second->next!=first)
    {
        if (first->data + second->data == x)
        {
            found=true;
            cout<<"("<<first->data<<","<< second->data<<")"<<endl;
        
            first=first->next;
            second=second->prev;
        }

        else
        {
            if (first->data + second->data < x)
            {
                first=first->next;
            }

            else
            {
                second=second->prev;
            }
            
        }
    }
    if (found==false)
    {
        cout<<"No pair found"<<endl;
    }
    
}

void display(node* head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;   
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    PairSum(head,17);
     
    return 0;
}