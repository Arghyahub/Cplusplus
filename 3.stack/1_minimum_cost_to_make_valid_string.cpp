/*
https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h> 
using namespace std;
int findMinimumCost(string &str) {
    stack<char> st;
    st.push('*');
    int left = 0, ans = 0;
    for (char c : str){
        if (c=='}'){
            if (left==0){
                st.push('{');
                ans++;
                left++;
            }
            else {
                st.pop();
                left--;
            }
        }
        else {
            st.push('{');
            left++;
        }
    }

    if (st.size()%2==0) return -1;
    return ans + (st.size()/2);
}