	vector<int> FactDigit(int N)
	{
	    vector<int> ans;
	    vector<long long> vec (10, 1);
	    for(int i = 2; i <= 9; i++){
	        vec[i] = vec[i - 1] * i;
	    }
	    int i = 9;
	    while(N > 0 && i >= 0){
	        if(N < vec[i]){
	            i--;
	            continue;
	        }
	        N -= vec[i];
	        ans.push_back(i);
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}