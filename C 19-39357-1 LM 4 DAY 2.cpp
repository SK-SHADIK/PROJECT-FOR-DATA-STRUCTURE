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
    node * prev;
};


class LinkedList{
private:
    node *head;

public:
    LinkedList(){
        head = NULL;

    }
    node * createNode(int);
    node * insertNode(node*,node*);
    void show();
    node* searchData(int);
    bool deleteData(int);

};

node* LinkedList::createNode(int value){
    node *newNode = new node;
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

}
//Defining a function to add a node after a previous node
node* LinkedList::insertNode(node * newNode, node * prev=NULL)
{
    //adding node at head (prev = null)

    if(prev==NULL){
        newNode->next = head;
        head=newNode;
        newNode->prev = NULL;


        /*if (head!=NULL){
            head->prev=newNode;
        }
        head = newNode;*/

    }

    //adding node after previous
    else
    {
        newNode->next = prev->next;
        prev->next =newNode;


        newNode->prev = prev;
        prev->next->prev=newNode;
    }
    return newNode;
}

// Now implement a function named deleteNode to delete a node (data)
bool LinkedList::deleteData(int K){
    node* curr = head;
    node* S = head;

    if (curr->data == K)
    {
        head = head->next;

    }
    else
    {
        while (curr->data != K)
        {
            curr = curr->next;


        }
        while (S->next->data != K)
        {
            S = S->next;

        }
        S->next=curr->next;

        delete (curr);
    }

}
void LinkedList::show()
{
    node * curr = head;



    while(curr != NULL)
    {
        cout<<"["<<curr->prev<<","<<curr->data<<","<<curr->next<<"]";
        if(curr->next)cout<<"<-->";
        curr = curr->next;


    }
    cout<<"\n\n";
}

/*
Now implement a function named searchData to search a particular value.
The function should return address of the node where the search element is found
otherwise return NULL.
*/
node* LinkedList::searchData(int key){
    //COMPLETE THE FUNCTION
    node * curr=head;

    while (curr!=NULL){

        if (curr->data==key){
            return curr;
        }

            curr=curr->next;
    }

    return NULL;

}


int main()
{
    // populate linked list with some values
    int n,elem,i;
    LinkedList myList;
    node * myNode;

    cout<<"How many elements? ";
    cin>>n;
    node *p=NULL,*tmp;
    for(i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>elem;
        myNode = myList.createNode(elem);
        p = myList.insertNode(myNode,p);
    }
    myList.show();

    int choice;
    while(true)
    {
        cout<<"\n1) search data\n2) add data\n3) add data at head\n4) delete data\n5) show List \n0) Exit\n Enter Option :  ";
        //cout<<"\n 6) PUSH \n 7) POP \n 8) ENQUEUE \n 9) DEQUEUE \nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            //use searchData function here
            cout<<"PLEASE ENTER DATA FOR SEARCH :"<<endl;
            cin>>elem;

            tmp = myList.searchData (elem);
            if(tmp==NULL)
                cout<<"\n THE DATA IS NOT MATCH \n"<<endl;
            else
                cout<<"\n THE DATA IS MATCH WITH : \n"<<tmp<<endl;

            break;
        case 2:
            //use addData function here
            myList.show();
            cout<<"After which element to insert? ";
            cin>>elem;
            tmp = myList.searchData(elem);
            if(tmp == NULL)
                cout<<elem <<" does not exist in the linked list!\n";
            else
            {
                cout<<"Which element to insert? ";
                cin>>elem;
                myNode = myList.createNode(elem);
                myList.insertNode(myNode,tmp);
            }
            myList.show();
            break;
        case 3:
            cout<<"Which element to insert? ";
            cin>>elem;
            myNode = myList.createNode(elem);
            myList.insertNode(myNode);
            myList.show();
            break;
        case 4:
            //use deleteData here
            myList.show();
            cout<<"PLEASE ENTER DATA WHICH DELETE :"<<endl;
            cin>>elem;
            myList.deleteData(elem);
            myList.show();

            break;
        case 5:
            myList.show();
            break;

        case 0:
            return 0;
        }
    }


    return 0;
}
