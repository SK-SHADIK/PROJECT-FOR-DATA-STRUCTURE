//Heap
#include<iostream>
using namespace std;

const int MAX_SIZE=100;
int Heap[MAX_SIZE+1], N=0;

void heapifyDown(int p)
{
    int c;
    while(2*p <= N)
    {
        //find the smaller child's index
        c = 2*p;
        if(c+1 <= N && Heap[c+1] < Heap[c])c++;

        // swap
        if(Heap[p] > Heap[c])
            swap(Heap[p], Heap[c]);
        else break;

        //change parent
        p = c;
    }
}

void heapifyUp(int c)
{
    // Define the function
    int p;

    while (c > 1){

        p=c/2;

        if (Heap[p]>Heap[c])

            swap(Heap[p], Heap[c]);

        else break;

        c=p;
    }

}

void Heapify()
{
    for(int p=N/2; p>=1; p--)heapifyDown(p);
}

int insertData(int data)
{
    //implement this function
    N++;

    Heap[N]=data;

    heapifyUp(N);

}
int deleteRoot()
{
    //implement this function
    swap(Heap[1], Heap[N]);

    N--;

    heapifyDown(1);

}


void sortHeap()
{
    int tmp=N;
    for(int i=0; i<tmp; i++)deleteRoot();
    cout<<"Sorted List: ";
    for(int i=1; i<=tmp; i++)cout<<Heap[i]<<" ";
    cout<<"\n\n";
    N=tmp;
    Heapify();
}

void showHeap()
{
    if(N>0)
    {
        for(int i=1; i<=N; i++)cout<<Heap[i]<<" ";
        cout<<"\n\n";
    }
    else cout<<"Heap does not exist!\n\n";
}

void MODIFY(int i, int value){

    Heap[i]=value;


    if (Heap[i/2]>value){
        heapifyUp(i);
    }
    else{
        heapifyDown(i);
    }
    }

int main()
{
    //cout<<"Enter Number of elements? ";
    //cin>> N;
    //while(N<1 || N>100){
    //    cout<<"Enter a value less than 100\n\n";
    //    cin>> N;
    //}
    N=12;
    int a[13]= {0,45,38,30,32,40,15,5,43,20,10,35,25};
    for(int i=1; i<=N; i++)
    {
        //cout<<"Heap["<<i<<"]: ";
        //cin>>Heap[i];
        Heap[i]=a[i];
    }


    showHeap();
    cout<<"THE HEAPIFY VALUE IS :"<<endl;
    Heapify();
    showHeap();

    while(1)
    {
        int choice=-1;
        cout<<"0) Exit\n1) Insert\n2) Delete root\n3) sort \n4) MODIFY \nEnter Option: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            int value;
            cout<<"Enter a value to insert: ";
            cin>>value;
            insertData(value);
            showHeap();
            break;
        case 2:
            deleteRoot();
            showHeap();
            break;
        case 3:
            sortHeap();
            showHeap();
            break;
        case 4:
            int i,data;
            showHeap();
            cout<<"ENTER WHICH INDEX WANT TO MODIFY :";
            cin>>i;
            cout<<"ENTER MODIFY VALUE :";
            cin>>data;
            MODIFY(i,data);
            showHeap();
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
