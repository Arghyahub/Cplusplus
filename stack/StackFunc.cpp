#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s ;
    int option ;
    do
    {
        cout<<"\nEnter your choice\n 1. To PUSH element into stack \n 2. To POP element from back \n 3. To see TOP element \n 4. To exit \n : " ;
        cin>>option ;
        if (option==1){
            cout<<"Enter Data : ";
            int x ;
            cin>>x ;
            s.push(x) ;
        }
        else if (option==2){
            if (s.empty())
                cout<<"Stack is already Empty\n" ;
            else
                s.pop() ;
        }
        else if (option==3){
            if (s.empty())
                cout<<"Stack is empty\n" ;
            else
                cout<<s.top() ;
            }

    } while (option!=4);



    return 0 ;
}