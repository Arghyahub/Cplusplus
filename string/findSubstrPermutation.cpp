#include<iostream>
#include<string>
using namespace std;

bool checksame(int a[], int b[])
{
    for (int i=0; i<26; i++)
    {
        if (a[i]!=b[i]) {return 0 ;}
    }
    return 1 ;
}

int main(){
    string s1 = "ab" ;
    string s2 = "yooba" ;

    int windowsize = s1.length() ;
    int strsize = s2.length() ;
    
    int s1count[26] = {0} ;
    for (int i=0; i<windowsize; i++)
    {
        int temp = s1[i] - 'a' ;
        s1count[temp]++ ;
    }
    
    int s2count[26] = {0} ;
    int i=0 ;
    
    while (i<windowsize && i<strsize)
    {
        int temp = s2[i] - 'a' ;
        s2count[temp]++ ;
        i++ ;
    }
    
    if (checksame(s1count,s2count))
        cout<<"Exists"<<endl ;
        // return 1 ;
    
    while (i<strsize )
    {
        int newch = s2[i] - 'a' ;
        s2count[newch]++ ;
        
        int oldch = s2[i-windowsize] - 'a' ;
        s2count[oldch]-- ;
        i++ ;
        
        if (checksame(s1count,s2count))
            cout<<"Exists"<<endl ;
            // return 1 ;
    }
    
    return 0 ;
}