/*
https://leetcode.com/problems/online-stock-span/
In a stack keep track of previously occuring elements in the stream and find a precompute condition
by which you don't have to parse entire array.
*/
class StockSpanner {
    stack<pair<int,int> > s;
public:
    StockSpanner() {

    }

    int next(int price) {
        int ans = 1;
        while (!s.empty() && s.top().first <= price){
            ans+=s.top().second;
            s.pop();
        }

        s.push({price,ans});
        return ans;
    }
};
