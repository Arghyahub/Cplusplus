#include<iostream>
#include<vector>
using namespace std;
int main(){// given the array is sorted use Binary Search
    vector<vector<int>> matrix ={           // ONLY APPLICABLE ON MATRIX WHICH IS SORTED IF WE COMBINE ALL THE ROWS TOGETHER
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    } ;

    int target=8 ;
    int row=matrix.size() ;
    int col=matrix[0].size() ;

    int start=0, end=row*col-1 ; // volume -1 is the last element

    bool check= 1;
    while (start<=end)
    {
        int mid=start+(end-start)/2 ;
        int element = matrix[mid/col][mid%col] ;
        // say volume=6 and total columns=2 then dividing volume/col = 6/2=3 the row number
        // and %col will give range from 0 to col-1 which we need

        if (element==target)
        {
            cout<<"RowIndex : "<<mid/col<<"\nColumnIndex : "<<mid%col ;
            check=0 ;
            break ;
        }
        else if (target>element)
            start=mid+1 ;
        else
            end=mid-1 ;
    }

    if (check)
        cout<<"Not found !" ;

    return 0 ;
}