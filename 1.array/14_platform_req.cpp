/*
Similar to sorting by early finish
https://takeuforward.org/plus/dsa/problems/minimum-number-of-platforms-required-for-a-railway
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Comp {
    public:
    bool operator()(pair<int,int> &a, pair<int,int> &b) const {
        return a.second<b.second;
    }
};

class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int N = Arrival.size() ;
        vector<pair<int,int> > arr(N);
        for (int i=0; i<N; i++){
            arr[i].first = Arrival[i];
            arr[i].second = Departure[i];
        }

        sort(arr.begin(),arr.end(),Comp());

        for (auto [x,y] : arr)
        printf("[%d,%d] ",x,y);

        int count = 1, r=arr[0].second;
        for (int i=1; i<N; i++){
            if (arr[i].first > r){
                count++;
                r=arr[i].second;
            }
        }
        return count;
    }
};

int main() {
    Solution x;
    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};
    int res = x.findPlatform(Arrival, Departure);
    cout << res << endl;
    return 0;
}
