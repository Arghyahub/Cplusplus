class Solution{
  public:		
	int lps(string &s) {
	    vector<int> ps(s.size(),0) ;
	    
	    int prevlps=0 , i=1;
	    while (i<s.size()){
	        if (s[i]==s[prevlps]){  // If match then set them same
	            ps[i]=prevlps+1;
	            prevlps++;
	            i++;
	        }
	        else if (prevlps==0)
	            i++;
	        else
	            prevlps = ps[prevlps-1] ;	// go to lps of previous
	    }
	    return ps.back();
	}
};
