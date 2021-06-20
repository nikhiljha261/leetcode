class Solution {
public:
   
    bool ans;
    int dx[4]={0,0,+1,-1};
    int dy[4]={+1,-1,0,0};
    void dfs(vector<vector<int>>& a,vector<vector<int>>& b,int i,int j, vector<vector<int>>& vis)
    {
        if(b[i][j]!=a[i][j])
        {
            ans=true;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 and ni<a.size() and nj>=0 and nj<a[0].size() and vis[ni][nj]==-1 and a[ni][nj]==1)
            {
                dfs(a,b,ni,nj,vis);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ans=false;
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1)); 
        int c=0;
        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(vis[i][j]==-1 and grid2[i][j]==1)
                {
                    ans=false;
                    dfs(grid2,grid1,i,j,vis);
                    if(ans==false)
                    {
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
