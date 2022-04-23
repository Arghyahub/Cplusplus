// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(string digits,vector<string> mapped,vector<string> &ans,string output,int index) 
    {
        if (index>=digits.length()) // we see when given an input of 2 digits, ans is also of 2 digits
        {
            ans.push_back(output) ;
            return ;
        }
        
        // The digits are given in string , conver them to int and find mappings
        int n = digits[index] - '0' ;
        string str = mapped[n] ;
        
        for (int i=0; i<str.length(); i++)
        {
            output.push_back(str[i]) ;
            solve(digits,mapped,ans,output,index+1) ;
            
            // remove the previous entered character
            output.pop_back() ;
        }
    }

int main()
{
    string digits ;
    cin>>digits ; // like 23
    vector<string> ans ;
    if (digits.length()==0)
        cout<<"" ;
        // return ans ; 
    vector<string> mapped = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
    string output ;
    int index=0 ;
    solve(digits,mapped,ans,output,index) ;
    // return ans ; 

    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" " ;

    return 0 ;
}