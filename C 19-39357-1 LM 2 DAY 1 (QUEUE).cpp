/*
#### READ the instructions carefully. ######
1) First try to understand the given code in the program

2) The code is partially completed. Some queue operations are already implemented using functions in this program.

3) Your TASK is to define the remaining functions and complete the code.

4) ASK ME in case of any difficulties.
*/

#include<iostream>
using namespace std;

// Defining a class for stack properties and functions
class Q{
    int f;// index of front
    int r;// index of rear
    int *p; // Address of first element in Queue
    int capacity;

public:
    //constructor to initialize stack properties
    Q(int c=10){// default capacity is 10
        f = 0;
        r = 0;
        p = new int[c];
        capacity=c;
    }
    void traverse(); // it prints the elements in the stack

    void enqueue(int);// insert an element at rear
    bool dequeue();// delete element from front

    bool isEmpty();
    bool isFull();
};

int main(){
    // Declaring an stack object of type S
    Q a(5);//capacity is 5

    int option,item;

    // the while loop is used to do multiple operations in a single run
    while(1){
        cout<<"0)Exit\t1)Enqueue\t2)Dequeue\t3)Traverse\n";
        cout<<"Enter Option:";
        cin>>option;

        // to do selected operation from the above
        switch(option){
        case 0:
            return 0;
        case 1://Enqueue
            cout<<"Enter a value to push: ";
            cin>>item;
            a.enqueue(item);
            break;
        case 2://Dequeue
            /* COMPLETE IT YOURSELF*/
            a.dequeue();

            break;
        case 3:// traverse
            /* COMPLETE IT YOURSELF*/
            a.traverse();
            break;
        default:
            cout<<"\nWrong option!!!\n\n";
        }
    }
    return 0;
}

bool Q::isEmpty(){
  return f == r;
}

bool Q::isFull(){
  return r == capacity;
}

void Q::enqueue(int v){
    if(isFull()){
        cout<<"\nOverflow!!!\n";
        return;
    }

    //enqueue
    p[r] = v;

    //Increase rear by 1
    r++;
}
void Q:: traverse (){
    if(isEmpty())
        cout<<"\n THE QUEUL IS EMPTY !!! \n"<<endl;

    cout<<"THIS IS THE TRAVERSE :"<<endl;

    for(int i=f; i<r; i++){
      cout<<p[i]<<endl;

    }

}
bool Q::dequeue() {
    if(isEmpty()){
        cout<<"\n THE QUEUE IS EMPTY \n"<<endl;
    return false;
}
    f++;
    return true;
}


