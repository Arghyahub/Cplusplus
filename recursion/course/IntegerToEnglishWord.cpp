class Solution {
    unordered_map<int,string> mp {
        {1,"One "} , {2,"Two "}, {3, "Three "}, {4, "Four "}, {5, "Five "}, {6, "Six "},
        {7, "Seven "}, {8, "Eight "}, {9, "Nine "}, {10, "Ten "}, {11, "Eleven "},
        {12, "Twelve "}, {13, "Thirteen "}, {14, "Fourteen "}, {15, "Fifteen "},
        {16, "Sixteen "},{17, "Seventeen "},{18, "Eighteen "},{19, "Nineteen "},
        {20, "Twenty "},{30, "Thirty "},{40, "Forty "},{50, "Fifty "},{60, "Sixty "},
        {70, "Seventy "},{80, "Eighty "},{90, "Ninety "},{100, "Hundred "}, {1000,"Thousand "},
        {1000000, "Million "}, {1000000000,"Billion "} 
    };

    string forHun(int n){
        if (mp.find(n)!=mp.end())
            return mp[n] ;
        int last = n%10;
        int first = n - last;
        return mp[first] + mp[last] ;
    }

    string solve(int n)
    {
        if (n==0)
            return "" ;
        if (n<=20)
            return mp[n] ;
        if (n<100)
            return forHun(n) ;
        
        int pre10 = log10(n) ;
        if (pre10 > 3)
            pre10 -= pre10%3 ;
        int base = pow(10,pre10) ;

        int num = n/base;
        string first="";
        if (num<100)
            first = forHun(num) ;
        else
            first = mp[(num/100)] + "Hundred " + forHun(num%100) ;
        
        return first + mp[base] + solve(n%base) ;

    }

public:
    string numberToWords(int num) {
        if (num==0) return "Zero" ;
        string ans = solve(num);
        ans.pop_back() ;
        return ans;
    }
};