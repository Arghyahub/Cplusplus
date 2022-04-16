#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    } ;

    vector<int> ans;
    int row = matrix.size() ;
    int col=matrix[0].size() ;
    
    int startingRow=0, endingRow=row-1 ; // indexes
    int startingCol=0, endingCol=col-1 ;
    int counter=0;
    int volume=col*row ;
    
    while (counter<volume)
    {
        // startingRow , traverse from startingCol to endingCol
        for (int index=startingCol ;counter<volume && index<=endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]) ;
            counter++ ;
        }
        startingRow++ ;
        
        // endingCol , traverse from starting row to ending row
        for (int index=startingRow ;counter<volume && index<=endingRow; index++)
        {
            ans.push_back(matrix[index][endingCol]) ;
            counter++ ;
        }
        endingCol-- ;
        
        // endingRow , traverse from endingCol to startingCol
        for (int index=endingCol;counter<volume && index>=startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]) ;
            counter++ ;
        }
        endingRow-- ;
        
        // startingCol , traverse from endingRow to startingRow
        for (int index=endingRow;counter<volume && index>=startingRow; index--)
        {
            ans.push_back(matrix[index][startingCol]) ;
            counter++ ;
        }
        startingCol++ ;
    }
    
    for (int i=0; i<ans.size(); i++) {cout<<ans[i]<<" " ;}
       
    return 0 ;
}