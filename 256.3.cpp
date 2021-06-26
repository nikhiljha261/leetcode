class Solution {
public:
    long long dp[100005][2];
    long long count(int ind,int st,vector<int>& a)
    {
        if(ind==a.size())
        {
            return 0;
        }
        if(dp[ind][st]!=-1)
        {
            return dp[ind][st];
        }
        long long ans=INT_MIN;
        if(st==0)
        {
            ans=max({ans,a[ind]+count(ind+1,1,a),count(ind+1,0,a)});
            return dp[ind][st]=ans;
        }
        ans=max({ans,-a[ind]+count(ind+1,0,a),count(ind+1,1,a)});
        return dp[ind][st]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return count(0,0,nums);
    }
};
