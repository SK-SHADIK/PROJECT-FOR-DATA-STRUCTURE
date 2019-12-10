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


class LinkedListQUEUE{
private:
    node * rear;
    node * font;

public:
    LinkedListQUEUE(){
        rear = NULL;
        font = NULL;
    }
    node * createNode(int);
    node * ENQUEUE(node*);
    void show();
    void DEQUEUE();

};

node* LinkedListQUEUE::createNode(int value){
    node *newNode = new node;
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}
//Defining a function to add a node after a previous node
node* LinkedListQUEUE::ENQUEUE(node * newNode)
{
    if (rear==NULL){

        font=rear= newNode;
    return NULL;

    }

        rear->next = newNode;
        rear = newNode;
    }





void LinkedListQUEUE::show()
{
    node * curr = font;
    while(curr != NULL)
    {
        cout<<"["<<curr->data<<","<<(int)curr->next<<"]";
        if(curr->next)cout<<"-->";
        curr = curr->next;
    }
    cout<<"\n\n";
}

void LinkedListQUEUE::DEQUEUE (){
    node * curr;

    if  (font==NULL){
        cout<<"\n THE QUEUE IS EMPTY \n"<<endl;
    }
    else{
        curr=font;
        font=font->next;
        delete(curr);
    }

}
int main()
{

    int n,elem,i;
    LinkedListQUEUE myList;
    node * myNode;

    cout<<"How many elements? ";
    cin>>n;
    node *p=NULL,*tmp;
    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        myNode = myList.createNode(elem);
        p = myList.ENQUEUE(myNode);
    }
    myList.show();

    int choice;
    while(true)
    {
        cout<<"\n1) ENQUEUE\n2) DEQUEUE \n3) show List\n0) Exit\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:

            cout<<"Which element to ENQUEUE? ";
            cin>>elem;
            myNode = myList.createNode(elem);
            myList.ENQUEUE(myNode);
            myList.show();
            break;
        case 2:

            myList.DEQUEUE();
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
