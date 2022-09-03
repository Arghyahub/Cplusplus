#include<bits/stdc++.h>
using namespace std;

bool find(vector<string> &ans,string &temp)
{
    for (auto str : ans)
        if (str==temp)
            return true ;
    
    return false;
}

void powerset(vector<string> &ans, string s, string temp , int index)
{
    if (index>=s.length())
        return ;

    temp = temp + s[index] ; // include
    if (find(ans,temp)==false)  ans.push_back(temp) ;

    powerset(ans,s,temp,index+1) ;
    
    temp.pop_back() ;
    if (find(ans,temp)==false)  ans.push_back(temp) ;

    powerset(ans,s,temp,index+1) ;


}


void better(string &str , int index , string s , vector<string> &ans)
{
    if (index==str.length())
    {
        ans.push_back(s) ;
        return ;
    }

    // include
    better(str,index+1,s+str[index],ans ) ;

    // exclude
    better(str,index+1,s,ans) ;

}

int main(){
    
    string s = "abc" ;
    vector<string> ans ;

    powerset(ans,s,"",0) ;

    cout<<"Power set : " ;
    for (int i=0; i<ans.size(); i++){
        if (ans[i]=="")
            cout<<"\"\""<<" ";
        else
            cout<<ans[i]<<" " ;
    }

    ans.clear() ;

    better(s,0,"",ans) ;
    cout<<"\n\nPower set : " ;
    for (int i=0; i<ans.size(); i++){
        if (ans[i]=="")
            cout<<"\"\""<<" ";
        else
            cout<<ans[i]<<" " ;
    }

    return 0 ;
}