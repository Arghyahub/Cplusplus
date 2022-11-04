class Solution {
  public:
    string baseEquiv(int n, int m){
        for (int i=2; i<=32; i++){
            if ( pow(i,m-1) > n ) continue;	// THE FIRST POWER CANNOT BE ZERO, SO WE HAVE TO CHECK IT
            int sum=0;
            for (int j=0; j<m; j++){
                sum+=pow(i,j)*(i-1) ;		// GET THE MAXIMUM NUMBER YOU CAN POSSIBLY MAKE,CUZ IF ITS A BIGGER NUMBER WE CAN POSSIBLY PUT 0'S IN THE END
                if (sum>=n) return "Yes";
            }
        }
        return "No" ;
    }
};
