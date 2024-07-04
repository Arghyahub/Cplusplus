vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long N = A.size(), sum=0, sq=0;
    long long total = (N*(N+1))/2;
    long long sqTotal = (N*(N+1)*(2*N+1))/6 ;
    // cout<<total<<"t s"<<sqTotal<<endl;
    
    for (int i=0; i<N; i++){
        sum+=A[i];
        sq+=1LL*A[i] * 1LL * A[i];
    }
    
    // sum - x + y = total
    // y-x = total-sum
    long long ymx = total - sum;
    // cout<<ymx<<endl;
    
    // sq + y*y - x*x = sqTotal
    // (y+x)(y-x) = sqTotal - sq;
    // (y+x) = (sqTotal - sq)/(y-x)
    // cout<<sqTotal<<" "<<sq<<endl;
    long long ypx = (sqTotal-sq)/ymx;
    
    // cout<<ypx<<endl;
    
    return {(ypx-ymx)/2,(ymx+ypx)/2};
}
