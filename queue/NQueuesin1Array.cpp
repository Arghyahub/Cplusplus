#include<iostream>
using namespace std ;
class specialQueue
{
    public:
    int n , k ;
    int freeSpot ;
    int *arr ;
    int *front;
    int *rear;
    int *next ;

    specialQueue(int n, int k)
    {
        this->n = n ;
        this->k = k ;
        arr = new int[n] ;
        next = new int[n] ;

        front = new int[k] ;
        rear = new int[k] ;

        for (int i=0; i<k; i++)
            front[i]=rear[i]=-1 ;

        for (int i=0; i<n; i++)
            next[i]=i+1 ;
        next[n-1] = -1 ;

        freeSpot = 0 ;
    }

    void enqueue(int data, int qn)
    {
        // check if queue is full
        if (freeSpot==-1)
        {
            cout<<"Stack overflow"<<"\n" ;
            return ;
        }

        // store the index of freeSpot
        int index = freeSpot ;
        freeSpot = next[index] ;
        

        if (front[qn-1]==-1) // first time
        {
            front[qn-1] = index;
        }
        else
        {
            next[rear[qn-1]] = index ;  // rear->last so next of the last will be associated
        }
        

        // put -1 at taken index of next
        next[index] = -1 ;

        // update rear
        rear[qn-1] = index ;

        // push element
        arr[index] = data ;

    }

    int dequeue(int qn)
    {
        // check if queue is empty
        if ( front[qn-1] == -1 )
        {
            cout<<"The queue is empty"<<endl ;
            return -1;
        }

        // take the index of the first element of qn queue
        int index = front[qn -1] ;

        // shift first to the next index which is the new front after deleting
        front[qn-1] = next[index] ;

        // link that free space to the the next freeSpot
        next[index] = freeSpot ;
        // pull freeSpot to the newly evacuated space
        freeSpot = index ;

        return arr[index] ;
    }
} ;



int main()
{
    specialQueue sq(10,2) ;

    sq.enqueue(7,1) ;
    sq.enqueue(9,1) ;
    sq.enqueue(2,1) ;
    sq.enqueue(11,1) ;
    sq.enqueue(90,1) ;

    sq.enqueue(8,2) ;
    sq.enqueue(66,2) ;

    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(1)<<endl ;

    cout<<"\n2nd queue"<<endl ;
    cout<<"Deleted element : "<<sq.dequeue(2)<<endl ;


    return 0 ;
}