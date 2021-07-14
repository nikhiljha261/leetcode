
int global_ans=INT_MIN;
int dx[3]={+1,+1,+1};
int dy[3]={+1,0,-1};
int dp[505][505];
int _maxpath(int i,int j,vector<vector<int>>& grid,int val)
{
    if(i==grid.size()-1)
    {
        return grid[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=INT_MIN;
    for(int k=0;k<3;k++)
    {
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 and ni<grid.size() and nj>=0 and nj<grid[0].size())
        {

            ans=max(ans,grid[i][j]+_maxpath(ni,nj,grid,val));
        }
    }
    return dp[i][j]=ans;
}
int maximumPath(int N, vector<vector<int>> Matrix)
{
    // code here
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<Matrix[0].size();i++) global_ans=max(global_ans,_maxpath(0,i,Matrix,0));
    return global_ans;
}

