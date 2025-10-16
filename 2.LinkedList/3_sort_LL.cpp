#include <bits/stdc++.h> 
using namespace std;

void insertInPos(stack<int> &st, int x){
    if (st.empty()){
        st.push(x);
        return;
    }
    if (st.top() <= x){
        st.push(x);
        return;
    }
    int y = st.top(); st.pop();
    insertInPos(st,x);
    st.push(y);
}

void sortStack(stack<int> &st)
{
    if (st.empty()) return;
    int x = st.top(); st.pop();
    sortStack(st);
    insertInPos(st,x);
}
