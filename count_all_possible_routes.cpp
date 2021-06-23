class Solution {
public:
    int f;
    int dp[105][105][205];
    int mod = 1e9 + 7;
    int find(int ind,int tp,vector<int>& a)
    {
        if(tp==0 and ind==f)
        {
            return 1;
        }
        else if(tp<0)
        {
            return 0;
        }
        if(dp[ind][f][tp]!=-1)
        {
            return dp[ind][f][tp];
        }
        int ans=0;
        if(ind==f)
        {
            ans=1;
        }
        for(int i=0;i<a.size();i++)
        {
            if(i!=ind)
            {
                ans=(ans%mod+find(i,tp-abs(a[i]-a[ind]),a)%mod)%mod;
            }
        }
        return dp[ind][f][tp]=ans%mod;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        f=finish;
        return find(start,fuel,locations);
    }
};
