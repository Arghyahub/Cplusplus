#include<iostream>
#include<string>
using namespace std;

void shiftstr(string &str, string space ,int shift, int start) // start is the next index to space
{
    int l= str.length() - 1 ;
    for (int i=0; i<shift; i++) // padding with '0' to shift numbers
        str.push_back('0') ;

    for (int i=l ; i>=start ; i--)
        swap(str[i],str[i+shift]) ;    // shifting n-1 to newLength -1 ; or n-1 +(shift)
    
    int spindex = start -1 ;
    
    for (int j=0; j<space.length(); j++)
    {
        str[spindex] = space[j] ;
        spindex++ ;
    }
}

void delspace(string &str,int spindex)
{
    for (int i=spindex+1; i<str.length(); i++)
    {
        swap(str[i-1],str[i]) ;
    }
    str.pop_back() ;
}

int main(){
    string str , space;
    cout<<"Enter string : " ;
    getline(cin,str) ;

    // to be replaced with
    cout<<"\nEnter string to replace space with : ";
    getline(cin,space) ;

    for (int i=0; i<str.length(); i++)
    {
        if (str[i]==' ' && space.length()!=0) // say we need to replace ' ' with '@@' ,we can put one @ in place of space and
            shiftstr(str,space,space.length()-1,i+1) ; //shift string 1index (len('@@')-len(' ')) to enter other @ 

        else if (str[i]==' ' && space.length()==0)
            delspace(str,i) ;
    }

    cout<<str ;

    return 0 ;
}