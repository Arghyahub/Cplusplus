int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    queue<pair<int,int>> week; //first = day, second = ticket cost
    queue<pair<int,int>> month;
    int ans = 0 ;
    for (auto d : days)
    {
        while(!week.empty() && week.front().first + 7 <= d )
            week.pop() ;
        while(!month.empty() && month.front().first + 30 <= d )
            month.pop() ;
        
        week.push({d,ans+cost[1]}) ;
        month.push({d,ans+cost[2]}) ;
        
        ans = min(ans+cost[0],min(week.front().second,month.front().second)) ;
    }
    return ans;
}
