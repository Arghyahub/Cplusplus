bool isPossible(int row, int col, vector<vector<int>>& sudoku, int val )
{
    for (int i=0; i<9; i++)
    {
        if (sudoku[row][i]==val)
            return false ;
        if (sudoku[i][col]==val)
            return false ;
        
        if (sudoku[ 3*(row/3) + i/3 ][ 3*(col/3) + i%3 ] == val) // EXPLAINED LATER
            return false ;
    }
    return true ;
}

bool solve(vector<vector<int>>& sudoku)
{
    for (int row=0; row<9; row++)
    {
        for (int col=0; col<9; col++)
        {
            if (sudoku[row][col]==0)
            {
                for (int val = 1; val<=9; val++)
                {
                    if (isPossible(row,col,sudoku,val))
                    {
                        sudoku[row][col] = val ;
                        bool check = solve(sudoku) ;
                        if (check)
                            return true ;
                        else
                            sudoku[row][col] = 0 ;
                    }
                }
                return false ;  // IF AFTER INSERTING A NUMBER , NO OTHER NUMBER CAN BE FOUND FOR THE OTHER NUMBER
                // THEN THE WHOLE SET OF NUMBERS ARE WRONGLY PLACED, SO RETURN FALSE
            }
        }
    }
    return true ; // IF WE HAVE INSETED RIGHT NUMBERS IN RIGHT POSITION THEN THERE WILL BE NO POSITION LEFT
    // WITH ARR[I][J]==0 THUS BEING SOLVED THEREFORE RETURN TRUE
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku) ;
}