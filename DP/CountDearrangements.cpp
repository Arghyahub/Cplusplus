#include<vector>
int m = 1e9+7 ;
long long int solveRec(int n)
{
     if (n==1)
        return 0 ;
    if (n==2)
        return 1 ;
    
    return ( ((n-1)%m) *( ( (solveRec(n-1,dp))%m + (solveRec(n-2,dp))%m )%m ) )%m ;   
}
long long int countDerangements(int n) {
    return solveRec(n) ;
}

// WHEN YOU MOVE 0 TO ITH POSITION IT HAS TWO OPTIONS
/**
 * 1. TO MOVE TO 0TH POSITION GIVING N-1 OPTIONS
 * 2. TO MOVE TO ANY OTHER POSITON OTHER THAN 0TH POSITION (ith pos ❌, 0th pos❌) .:. N-2 options
 * Add them
 */