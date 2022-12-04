//      ol  => Open brackets Left
//      cl  => Closed brackets Left

class Solution {
    void solve(int ol, int cl,string &str, vector<string> &ans)
    {
        if (ol==0 && cl==0){
            ans.push_back(str) ;
            return ;
        }

        if (ol){
            str.push_back('(') ;
            solve(ol-1,cl,str,ans) ;
            str.pop_back() ;
        }
        
        if (cl && cl>ol){
            str.push_back(')') ;
            solve(ol,cl-1,str,ans) ;
            str.pop_back() ;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        solve(n,n,str,ans) ;
        return ans;
    }
};