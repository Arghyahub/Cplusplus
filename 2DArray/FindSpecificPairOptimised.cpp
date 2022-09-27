#include<iostream>
#include<climits>
using namespace std;
#define N 5

int getMaxPair(int mat[N][N])
{
    //1. Create another matrix
    int maxArr[N][N];
    // set lower corner element
    maxArr[N-1][N-1] = mat[N-1][N-1] ;

    //2. set last row and last column with respective greatest number starting from n-2 to 0
    for (int i=N-2; i>=0; i--)  // row
    {
        maxArr[N-1][i] = max( mat[N-1][i], maxArr[N-1][i+1] ) ;
    }

    for (int i=N-2; i>=0; i--)  // col
    {
        maxArr[i][N-1] = max( mat[i][N-1], maxArr[i+1][N-1] ) ;
    }

    int ans = INT_MIN ;

    for (int i=N-2; i>=0; i--)
    {
        for (int j=N-2; j>=0; j--)
        {
            // set ans
            if ( maxArr[i+1][j+1] - mat[i][j] > ans )
                ans = maxArr[i+1][j+1] - mat[i][j] ;
            
            // set point
            maxArr[i][j] = max( mat[i][j], max(maxArr[i+1][j],maxArr[i][j+1]) ) ;
        }
    }
    return ans;
}

int main(){
    int mat[N][N] = {
        {  1,  2, -1, -4, -20},
        { -8, -3,  4,  2,  1 },
        {  3,  8,  6,  1,  3 },
        { -4, -1,  1,  7, -6 },
        {  0, -4, 10, -5,  1 } };
    

    cout<< getMaxPair(mat) ;

    return 0 ;
}