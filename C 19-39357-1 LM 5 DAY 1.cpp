#include<iostream>
using namespace std;

//Defining a BST node
struct node
{
    int data;
    node *left,*right;
};

node * root = NULL;

//declaration of all functions used in this code
node* insertData(int);
int deleteData(int);
node *searchData(int);
void visit(node*);
node * parent(int,node* &);
node * value(node*);

int main()
{
    // populate BST with some values
    int elem,i,o;

    int a[8]={66,32,89,23,45,78,98,67};
    for(i=0; i<8; i++)
    {
        //cout<<"Element "<<i+1<<": ";
        //cin>>elem;
        if(insertData(a[i])== NULL)
            cout<<"Duplicated!! Insertion unsuccessful."<<endl<<endl;
    }

    cout<< "in-order: ";
    visit(root);

    int choice;
    while(true)
    {
        cout<<"\n1) search data\n2) add data\n3) delete data\n4) show BST\n0) Exit\nEnter option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            //use searchData function here
            cout<<"Which element to search? ";
            cin>>elem;
            if(searchData(elem)==NULL)
                cout<<"Not found!\n";
            else
                cout<<"found!\n";
            break;
        case 2:
            //use insertData function here
            cout<<"Which element to insert? ";
            cin>>elem;
            if(insertData(elem))
                cout<<"Insertion successful."<<endl<<endl;
            else
                cout<<"Duplicated!! Insertion unsuccessful."<<endl<<endl;
            break;
        case 3:
            //use deleteData here
            cout<<"Which element to delete? ";
            cin>>elem;
            //call deleteData here
            o=deleteData(elem);
            if(o==1){
                cout<<"\nDELETE SUCCESSFUL\n"<<endl;
            }
            else {
                cout<<"\nDELETE UNSUCCESSFUL CAUSE THIS ELEM IS NOT ON THR TREE\n"<<endl;
            }
            visit(root); cout<<endl;;
            break;
        case 4:
            cout<< "in-order: ";
            visit(root);
            break;

        case 0:
            return 0;
        }
    }
    return 0;
}

//Defining a function to add a node in BST
node* insertData(int num)
{
    //create node
    node *nn=new node;
    nn->data=num;
    nn->left= nn->right = NULL;

    //traverse to the correct parent
    node *curr=root,*parent=NULL;
    while(curr!=NULL)
    {
        if(curr->data == num)
            return NULL;
        parent = curr;
        if(curr->data < num)
            curr=curr->right;
        else
            curr=curr->left;

    }

    // add the new node to parent
    if(root == NULL)
        root = nn;
    else if(parent->data < num)
        parent->right=nn;
    else
        parent->left=nn;

    return nn;
}

void visit(node *parent)//in-order traversal
{
    if(root == NULL)
        cout<<"Tree does not exist!\n\n";
    if(parent!=NULL)
    {
        visit(parent->left);
        cout<<parent->data<< " ";
        visit(parent->right);
    }
}

// Return the address of node where num is found
node *searchData(int num)
{
    if(root == NULL)
        cout<<"Tree does not exist!\n\n";
    else
    {
        //COMPLETE THE FUNCTION
        node * curr=root;

        while(curr!=NULL){

        if (curr->data>num){
            curr=curr->left;

        }
        else if (curr->data<num){
            curr=curr->right;
        }
        else {
            return curr;
        }
        }

    }
    return NULL;
}

//FOR GET PARENT AND CURR

node * parent (int num, node* & parent){
     node *curr=root;
     parent=NULL;
    while(curr!=NULL)
    {
        if(curr->data == num)
            return curr;
        parent = curr;
        if(curr->data < num)
            curr=curr->right;
        else
            curr=curr->left;

    }
    return NULL;
}

//FOR MAIN VALUE (FOR CASE 3)

node * value(node* node){
    while (node != NULL && node->left!=NULL)
        node=node->left;
    return node;
}

int deleteData(int num)
{
    //implement delete function, return 1 if deleted or 0 if not found

    // Step 1: find the current node where num found and its parent

    // Step 2: check whether current node is leaf node, with one child or both children

    // Step 3: Use proper rule for each case
    node * par;
    node * S;
    node * curr=parent(num,par);

    if (curr==NULL){
        return 0;
    }




    //CASE 1 DELETE VALUE FROM LEAFE NODE

    if (curr->left==NULL && curr->right==NULL){
        if (par->data>curr->data){
            par->left=NULL;
            delete(curr);
        }
        else {
            par->right=NULL;
            delete (curr);
        }
        return 1;
    }
    //CASE 2 DELETE VALUE FROM LEFT OR RIGHT WHICH HAS ONE CHILD

    else if (curr->left==NULL ){
        S=curr->right;
    delete (curr);

        if(par->data > S->data){
            par->left=S;
        }
        else {
            par->right=S;
        }
        return 1;
    }
    else if(curr->right==NULL){
        S=curr->left;
        delete (curr);

         if(par->data > S->data){
            par->left=S;
        }
        else {
            par->right=S;
        }
        return 1;
    }

// CASE 3 DELETE VALUE FROM LEFT OR RIGHT WHICH HAS TWO (BOTH) CHILD
else {
    node* S=value(curr->right);
    int O = S->data;
    deleteData(O);
    curr->data=O;

    return 1;
}

return 0;

}
