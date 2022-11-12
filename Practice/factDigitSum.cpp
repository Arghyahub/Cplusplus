#include<bits/stdc++.h>
using namespace std;

vector<int> FactDigit(int N)
{
	//  A(154) = 1! + 5! + 4!= 145.
	// Given a number N, find the minimum number X such that A(X) = N
	vector<int> ans;
	vector<long long> vec (10, 1);
	for(int i = 2; i <= 9; i++){
		vec[i] = vec[i - 1] * i;
	}
	int i = 9;					// START FROM THE LARGEST NUM
	while(N > 0 && i >= 0){
		if(N < vec[i]){
			i--;
			continue;
		}
		N -= vec[i];			// SUBTRACT THE NUMBER
		ans.push_back(i);		// PUSH IT INTO LIST AGAIN
	}
	reverse(ans.begin(), ans.end());		// OBVIOUSLY LARGEST NUMBER WILL BE AT THE END
	return ans;
}