#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

    void solve(int n, int m, int num,int &count)   // THE NUMBER WILL START FROM A LOWER RANGE AND GROW TO THE ACTUAL RANG
    {                               // SO DON'T KEEP A CHECK FOR IF num<n CUZ INTITIALLY num WILL WE SMALLER THAN n
                                    // IF NUMBER EXCEEDS THE UPPER BOUND , THEN WE DON'T NEED IT CUZ IT WILL ALWAYS PRODUCE NUMBERS GREATER THAN THE UPPER BOUND
        queue<int> q;
        q.push(num) ;
        
        while(!q.empty()){
            
            int element=q.front() ;
            q.pop() ;
            
            if (element>=n && element<=m)       // ONLY IF ELEMENT IS IN RANGE THEN INCREMENT COUNT
                count++ ;
                
            if (element>m )
                continue;
            
            int ldigit = element%10;
            
            int numberup = element*10 + (ldigit+1);
            int numberdown = element*10 + (ldigit-1);
            
            if (ldigit==0){
                q.push(numberup) ;
            }
            else if (ldigit==9){
                q.push(numberdown) ;
            }
            else{
                q.push(numberup) ;
                q.push(numberdown) ;
            }
        }
    }

    int steppingNumbers(int n, int m)
    {
        int count=0;

        if (0<=n && 0>=m) count++;          // IF 0 IS IN RANGE ADD THAT, CUZ IF WE TRY TO COMPUTE IT INSIDE THE FUNCTION IT WILL ADD UP AN EXTRA 1

        for (int i=1; i<10; i++)
            solve(n,m,i,count) ;
        return count;
    }
};


/**
 * WE WILL TAKE NUMBERS FROM 0 TO 9 AND KEEP INCREASING TO OUR DESIRED RANGE
 * LIKE 7 CAN BE TRANSFORMED TO 78 AND 76 BY
 * 7*10 + (LASTDIGIT+1)  |   7*10 + (LASTDIGIT -1)  => WE GET 78 AND 76
 * 
 * BUT THIS DOESN'T HOLDS TRUE FORM LASTDIGIT= 0 OR 9
 * 0*10+(0+1) IS 1 WHICH IS RIGHT BUT 0*10+(0-1) IS -1 WHICH IS NOT RIGHT
 * AND FOR 9
 * 9*10+(9+1) = 100 WHICH IS NOT RIGHT BUT 9*10+(9-1) = 98 WHICH IS RIGHT
 * SO WE HAVE TO KEEP TO IF CONDITIONS TO CHECK FOR LAST DIGIT =0 AND 9 
 * IF LASTDIGIT == 0 THEN INCREMENT CONDITION WILL BE TRUE
 * IF LASTDIGIT ==9 THEN DECREMENT CONDITION WILL BE TRUE
 * 
 * 
 * THERE IS STILL ANOTHER PROBLEM : IN IMPLEMENTING THE THE SOLUTION
 * 0 WILL ADD UP 1 TO THE QUEUE
 * BUT WE ARE GOING TO CHECK FOR 1'S CONDITION SEPERATELY SO WE HAVE TO CHECK FOR THAT TOO
 */