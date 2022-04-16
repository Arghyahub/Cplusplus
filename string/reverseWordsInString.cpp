#include<iostream>
#include<string>
using namespace std;

void reverseStr(string &str , int start, int end)
{
    while (start<end)
    {
        swap(str[start],str[end]) ;
        start++ ;
        end-- ;
    }
}

int main(){
    // so if a "space" is seen the word end | in the end '\0' is seen the word ends
    string str = "this is the string" ; //you can access '\0' in character array so add last word yourself
    int start=0 ;
    for (int i=0; i<str.length(); i++)
    {
        if (str[i]==' ')
        {
            reverseStr(str,start,i-1) ;
            start=i+1 ;
        }
    }
    reverseStr(str,start,str.length()-1) ;

    cout<<str;

    return 0 ;
}