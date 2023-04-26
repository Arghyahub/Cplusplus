#include<map>
#include<queue>
// https://leetcode.com/problems/reorganize-string/
// THE MAIN ALGORITHM IS TO DISTRIBUTE THE CHARACTER HAVING MAXM OCCURRENCE
// AND THEN PLACE THE OTHER CHARACTERS
// EG: a=3 , b=2
// 1. MAXM FIRST =  ababa ✔
// 2. MINM FIRST =  babaa ❌

string reArrangeString(string &s)
{
    int n = s.size() ;
    map<char,int> mp ;
    for (auto x : s)
        mp[x]++ ;
    
    priority_queue<pair<int,char>> pq ;         // Distribute characters in terms of frequency
    
    for (auto it : mp)
        pq.push({it.second,it.first}) ;
    
    string ans = "" ;
    pair<int,char> prev = {-1,'$'} ;        // TO STORE THE PREVIOUS CHARACTER
    
    while(!pq.empty())
    {
        pair<int,char> temp = pq.top() ;
        pq.pop() ;                              // REMOVE THE ELEMENT ONCE SO THAT IT DOESN'T OCCUR TWICE
        ans.push_back(temp.second) ;        
        temp.first-- ;
        
        if (prev.first>0)                       // IF WE HAVE ATLEAST 1 ELEMENT THEN INSERT IT INTO THE PRIORITY QUEUE
            pq.push(prev) ;
        
        prev = temp ;                           //  STORE THE ELEMENT NOW SO THAT WE CAN INSERT IT THE NEXT TIME
    }
    
    // IF WE HAVE A CHAR MULTIPLE TIMES, SUCH THAT THE GAPS CAN'T BE FILLED AND THE THE CHARACTER GETS ADJACENT POSITIONS
    // THEN THE CHAR WOULD CLUTTER IN THE END, JUST BECAUSE WE REMOVE THE CHARACTER TEMPORARILY THE PRIORITY QUEUE BECOMES EMPTY
    // THE THE LOOP WILL STOP AND HENCE WE WILL GET A SHORTER STRING
    if (ans.size()!=n)                     
        return "not possible" ;
    return ans ;
}
