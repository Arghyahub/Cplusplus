/*
https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
*/
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
