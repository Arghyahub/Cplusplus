/*
https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h> 
#define ll long long

bool solve(vector<int> &time, ll maxDays, ll maxHours) {
	ll hours = 0, day=1;
	for (int i=0; i<time.size(); i++){
		if (hours + (ll)time[i] > maxHours){
			day++;
			hours=time[i];
			if (day > maxDays) return false;
		}
		else {
			hours+=time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> &time) 
{	
	ll s=0, e=0, ans=-1;
	for (ll t : time){
		s=max(s,t);
		e+=t;
	} 
	while (s<=e){
		ll mid = s + (e-s)/2;
		bool isPossible = solve(time,n,mid);
		// cout<<mid<<" "<<isPossible<<endl;
		if (isPossible){
			ans=mid;
			e=mid-1;
		}
		else {
			s=mid+1;
		}
	}

	return ans;
}