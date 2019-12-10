
/*
#### READ the instructions carefully. ######
1) First try to understand the given code in the program

2) The code is partially completed. Some array operations are already implemented using functions in this program.

3) Your TASK is to define the remaining functions and complete the code.

4) ASK ME in case of any difficulties.
*/

#include<iostream>
using namespace std;

// Defining a class for array properties and functions
class A
{
    int noOfElem;// Number of current elements in the array
    int capacity;// Maximum number of elements allowed
    int *p; // Address of first element in the array

public:
    //constructor to initialize array properties
    A(int c=10) // default capacity is 10
    {
        noOfElem = 0;
        capacity = c;
        p = new int[c];
    }
    void traverse(); // it prints the elements in the array
    void insertion(int,int);// inputs are value and position
    bool deleteByPosition(int);// input is position of the value
    int deleteByValue(int);// input is value itself
    int searching(int);// input is the item to search

    bool isEmpty();
    bool isFull();
};

int main()
{
    // Declaring an array object of type A
    A myArray(5);//capacity is 5

    int option,item,pos;

    // the while loop is used to do multiple operations in a single run
    while(1)
    {
        cout<<"0)Exit\t1)Insert\t2)Delete Position\t3) Delete Value\n";
        cout<<"4)Traverse\t5)Search\n";
        cout<<"Enter Option:";
        cin>>option;

        // to do selected operation from the above
        switch(option)
        {
        case 0:
            return 0;
        case 1://insertion
            cout<<"Enter value and position(index): ";
            cin>>item>>pos;
            myArray.insertion(item,pos);
            break;
        case 2://Delete by Position
            /* COMPLETE IT YOURSELF*/
            /*take input from user and call appropriate function*/
            cout<<"ENTER THE POSITION :"<<endl;
            cin>>pos;
            myArray.deleteByPosition(pos);
            break;
        case 3://Delete by Value
            /* COMPLETE IT YOURSELF*/
            /*take input from user and call appropriate function*/
            cout<<"ENTER THE VALUE :"<<endl;
            cin>>item;
            myArray.deleteByValue(item);
            break;
        case 4:
            myArray.traverse();
            break;
        case 5: // Searching
            /* COMPLETE IT YOURSELF*/
            /*take input from user and call appropriate function*/
            cout<<"ENTER THE SEARCHING VALUE :"<<endl;
            cin>>item;
            myArray.searching(item);
            break;
        default:
            cout<<"\nWrong option!!!\n\n";
        }
    }
    return 0;
}

bool A::isEmpty()
{
    return noOfElem == 0;
}

bool A::isFull()
{
    return noOfElem == capacity;
}

void A::insertion(int v, int position)
{
    if(isFull())
    {
        cout<<"\nArray is Full!!!\n";
        return;
    }
    //Check position
    if(position<0 || position > noOfElem)
    {
        cout<< "\nInvalid Position!!!\n";
        return;
    }
    //Shifting
    for(int i=noOfElem-1; i>= position; i--)
    {
        p[i+1]=p[i];
    }
    //Insertion
    p[position] = v;

    //Increase number of elements by 1
    noOfElem++;
}

void A::traverse()
{
    if(isEmpty())cout<<"\nArray is EMPTY!!!\n";
    for(int i=0; i< noOfElem; i++)
    {
        cout<<p[i] << " ";
    }
    cout<<endl;
}
bool A ::deleteByPosition (int pos)
{
    int i;

    for (i=pos; i<noOfElem; i++)

    {
        p[i]=p[i+1];

    }
    noOfElem--;
}
int A :: deleteByValue (int item)
{

    int i,j;

    for(i=0; i<noOfElem; i++)
    {

        if (p[i]==item)
        {

            for (int j=i; j<noOfElem; j++)
            {

                p[i]=p[i+1];

            }
            noOfElem--;
        }
    }
}
int A :: searching(int item)
{
    int S=0;
    int i;

    for(i=0; i<noOfElem; i++)
    {

        if (item==p[i])
        {
            cout<<i<<"FOUND"<<endl;
            S=1;

        }

    }
    if (S==0)
    {
        cout<<"NOT FOUND"<<endl;

    }
}
