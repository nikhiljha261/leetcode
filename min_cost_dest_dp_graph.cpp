class Solution {
public:
    int minCost(int mt, vector<vector<int>>& a, vector<int>& b) {
        int n=b.size();
        vector<pair<int,int>> adj[100005];
        for(int i=0;i<a.size();i++)
        {
            int x=a[i][0];
            int y=a[i][1];
            int z=a[i][2];
            adj[x].push_back({y,z});
            adj[y].push_back({x,z});
        }
        // int dp[mt+1][n];
        vector<vector<int>> dp(mt+1,vector<int>(n,INT_MAX));
        dp[0][0]=b[0];
        for(int i=0;i<=mt;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=dp[i][j];
                if(x>=INT_MAX)
                {
                    continue;
                }
                for(auto child : adj[j])
                {
                    int time=child.second+i;
                    int node=child.first;
                    if(time<=mt) dp[time][node]=min(dp[time][node],b[node]+dp[i][j]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=mt;i++)
        {
            ans=min(ans,dp[i][n-1]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
        
    }
};
