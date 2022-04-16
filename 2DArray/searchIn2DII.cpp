#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix = {// given the matrix is sorted in terms of colums
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
    };
    int target = 13 ;

    int rowsize = matrix.size(), colsize = matrix[0].size() ;
    /* Now we have two pointer one to move in row and the other in column to search the entire array
    take an element say  -> 16
    1<increase> if we go down the row the element>16 and if we go bigger column element>16
    2<decrease> now if we go to lower rows element decreases element<16 same for lower colums

    Now choose a task for row and a task for column
    say for increase I'm choosing row : to go to a bigger number row++
    for decrease I'm choosing column : to go to a smaller number col--

    Now choose a Number with opposite characteristics to sweep the entire matrix
    ie, lowest row(so that we can do row--)
    highest col(so that we can do col--)
    here : element 15
    now move to the prefered location
    */
    int row = 0, col = colsize - 1; // element 15

    while (row<rowsize && col>=0)  // we are incrementing row so keep upper bound and decrementing col so...
    {
        int element = matrix[row][col] ;
        if (target==element)
        {
            cout<<"Target found at Index : "<<endl;
            cout<<"Row : "<<row<<" Column : "<<col<<endl ;
            break ;
        }

        else if (target>element)
            row++ ;
        else
            col-- ;
    }
    return 0;
}