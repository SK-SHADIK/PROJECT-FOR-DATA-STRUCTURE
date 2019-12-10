/*
#### READ the instructions carefully. ######
1) First try to understand the given code in the program

2) The code is partially completed. Some stack operations are already implemented using functions in this program.

3) Your TASK is to define the remaining functions and complete the code.

4) ASK ME in case of any difficulties.
*/

#include<iostream>
using namespace std;

// Defining a class for stack properties and functions
class S{
    int top;// Number of current elements in the stack
    int capacity;// Maximum number of elements allowed
    int *p; // Address of bottom element in the stack

public:
    //constructor to initialize stack properties
    S(int c=10){// default capacity is 10
        top = 0;
        capacity = c;
        p = new int[c];
    }
    void traverse(); // it prints the elements in the stack

    void push(int);// insert an element on top
    bool pop();// delete element from top

    bool isEmpty();
    bool isFull();
};

int main(){
    // Declaring an stack object of type S
    S myStack(5);//capacity is 5

    int option,item;

    // the while loop is used to do multiple operations in a single run
    while(1){
        cout<<"0)Exit\t1)Push\t2)Pop\t3)Traverse\n";
        cout<<"Enter Option:";
        cin>>option;

        // to do selected operation from the above
        switch(option){
        case 0:
            return 0;
        case 1://push
            cout<<"Enter a value to push: ";
            cin>>item;
            myStack.push(item);
            break;
        case 2://pop
            /* COMPLETE IT YOURSELF*/
            myStack.pop();
            break;
        case 3:// traverse
            /* COMPLETE IT YOURSELF*/
            myStack.traverse();

            break;
        default:
            cout<<"\nWrong option!!!\n\n";
        }
    }
    return 0;
}

bool S::isEmpty(){
  return top == 0;
}

bool S::isFull(){
  return top == capacity;
}

void S::push(int v){
    if(isFull()){
        cout<<"\nStack is Full!!!\n";
        return;
    }

    //push
    p[top] = v;

    //Increase top by 1
    top++;
}
void S::traverse()
{
    if(isEmpty())
        cout<<"\n THE STACK IS EMPTY!!! \n"<<endl;

    cout<< "THIS IS THE TRAVERSE :"<<endl;

    for(int i=0; i<top; i++)
    {
        cout<<p[i]<<endl;
    }
}
bool S::pop () {
    if(isEmpty()) {
     cout<<"\n THE STACK IS EMPTY !!! \n"<<endl;
     return false ;
    }

    top--;
    return true;


}
