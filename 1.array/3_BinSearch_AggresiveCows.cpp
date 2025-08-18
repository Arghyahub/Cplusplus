/*
https://www.naukri.com/code360/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION
*/
bool solve(vector<int> &stalls,int minDist, int cows) {
    // book 0
    int lastCow = stalls[0], N=stalls.size();
    cows--;

    for (int i=1; i<N; i++){
        int currPos = stalls[i];
        if (currPos-lastCow < minDist) continue;
        else {
            lastCow = currPos;
            cows--;
            if (cows == 0) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int N = stalls.size();
    sort(stalls.begin(),stalls.end());
    int s=0,e=stalls[N-1]-stalls[0], ans = 0;
    
    while (s<=e){
        int mid = s + (e-s)/2;
        bool tryputting = solve(stalls,mid, k);
        if (tryputting){ 
            s = mid+1;
            ans = mid;
        }
        else e = mid-1;
    }

    return ans;
}