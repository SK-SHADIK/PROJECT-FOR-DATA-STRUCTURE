/*
This code define four functions namely insertion, deletion, search and traverse
for linked list data structure.
*/
#include<iostream>
using namespace std;

//Defining the node
struct node
{
    int data;
    node * next;

};


class LinkedListSTACK{
private:
    node *top;

public:
    LinkedListSTACK(){
        top = NULL;
    }
    node * createNode(int);
    node * PUSH (node*);
    void show();
   void POP();
};

node* LinkedListSTACK::createNode(int value){
    node *newNode = new node;
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}
//Defining a function to add a node after a previous node
node * LinkedListSTACK::PUSH(node*newNode)
{
        newNode->next = top;
        top = newNode;
}


void LinkedListSTACK::POP()
{
    node * curr=top;

    if (curr!=NULL)
    {
        top=curr->next;
        delete (curr);
    }
    else
    {
        cout<<"\n THE LINKED LIST IS EMPTY \n"<<endl;
    }
}

// Now implement a function named deleteNode to delete a node (data)


void LinkedListSTACK::show()
{
    node * curr = top;
    while(curr != NULL)
    {
        cout<<"["<<curr->data<<","<<(int)curr->next<<"]";
        if(curr->next)cout<<"-->";
        curr = curr->next;
    }
    cout<<"\n\n";
}




int main()
{
    // populate linked list with some values
    int n,elem,i;
    LinkedListSTACK myList;
    node * myNode;
    node *p=NULL, *tmp;

    cout<<"How many elements? ";
    cin>>n;

    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        myNode = myList.createNode(elem);
        p=myList.PUSH(myNode);

    }
    myList.show();

    int choice;
    while(true)
    {
        cout<<"\n1) PUSH\n2) POP\n3) show List\n0) Exit\n Enter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:


           cout<<"Which element to PUSH? ";
            cin>>elem;
            myNode = myList.createNode(elem);
            myList.PUSH(myNode);
            myList.show();
            break;
        case 2:

            myList.POP();
            myList.show();
            break;

        case 3:
            myList.show();
            break;
        case 0:
            return 0;
        }
    }


    return 0;
}
