class Solution {
    string merge(string &a, string &b) {
        if (a.find(b)!=string::npos)
            return a;

        for (int i=a.size()-min(a.size()-1,b.size()-1); i<a.size(); i++){
            if (a.substr(i) == b.substr(0,a.size()-i) )
                return a.substr(0,i) + b;
        }
        return a + b;
    }
public:
    string minimumString(string a, string b, string c) {
        vector<string> vec = {a,b,c} ;
        // try all combinations
        string ans;

        for(int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i==j) continue;
                for (int k=0; k<3; k++) {
                    if (j==k || i==k) continue;
                    string mer = merge(vec[i],vec[j]) ;
                    string mer2 = merge(mer,vec[k]) ;

                    // cout<<i<<"i "<<j<<"j "<<k<<"k = "<<mer2<<endl;

                    if (ans.empty() || mer2.length() < ans.length() || 
                        (mer2.length()==ans.length() && mer2<ans) )
                        ans = mer2;
                }
            }
        }

        return ans;
    }
};

// abc dcb
