/*
https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM
*/

int search(vector<int>& arr, int n, int k)
{
    int s=0, e=n-1;
    while (s<=e){
        int mid = s + (e-s)/2;
        if (k==arr[mid]) return mid;
        // sorted plane
        if (arr[s]<=arr[mid]){
            if (k>=arr[s] && k<arr[mid]) e=mid-1;
            else s = mid+1;
        }
        // Two different planes
        else {
            if (k>arr[mid] && k<=arr[e]) s=mid+1;
            else e = mid-1;
        }
    }
    return -1;
}
