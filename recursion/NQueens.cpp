bool isSafe(int row, int col, vector<vector<bool>> &queen , int n )
{
    // check right ;
    int x = row, y = col ;
    while(y>=0)
    {
        if (queen[x][y]==1)
            return false ;
        y-- ;
    }
    
    // check diagonal up right
    x = row, y = col ;
    
    while(x>=0 && y>=0)
    {
        if (queen[x][y]==1)
            return false ;
        x-- ;
        y-- ;
    }
    // check diagonal down left
    x = row, y = col ;
    
    while(x<n && y>=0)
    {
        if (queen[x][y]==1)
            return false ;
        x++ ;
        y-- ;
    }
    return true ;
}

void placeQueens(vector<vector<int>> &ans,int n, int col,
                 vector<vector<bool>> &queen)
{
    if (col==n)
    {
        vector<int> temp ;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                temp.push_back(queen[i][j]) ;
        ans.push_back(temp) ;
        return ;
    }

    
    for (int row = 0 ; row<n; row++ )
    {
        if (isSafe(row,col,queen,n))
        {
            queen[row][col] = 1 ;
            placeQueens(ans,n,col+1,queen) ;
            queen[row][col] = 0 ;
        }
    }
}


vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> ans ;
    vector<vector<bool>> queen(n,vector<bool>(n,0)) ;
    placeQueens(ans,n,0,queen) ;
    
    return ans ;
}