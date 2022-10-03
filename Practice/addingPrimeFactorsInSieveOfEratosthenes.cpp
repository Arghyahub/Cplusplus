class Solution {
  public:
    int sumOfAll(int l, int r){
        vector<int> primesum(r+1,0);
        primesum[1]=1;
        for(int i=2;i<=r;i++){
            if(primesum[i]==0){
                primesum[i]=i;
                for(int j=i+i;j<=r;j+=i)
                    primesum[j] = primesum[j] + i;
            }
        }
        int sum=0;
        for(int i=l;i<=r;i++){
            sum+=primesum[i];
        }
        return sum;
    }
};