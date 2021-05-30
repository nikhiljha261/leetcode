class Solution {
public:
    int n;
    int m;
    vector<string> ans;
    int dx[2]={+1,0};
    int dy[2]={0,+1};
    map<string,bool> list;
    map<string,bool> seted;
    void dfs(vector<vector<char>>& board,int i,int j,string s,vector<vector<bool>> vis)
    {
        // cout<<s<<endl;
        if(list[s]==true)
        {
            if(seted[s]==false)
            {
                ans.push_back(s);
                seted[s]=true;
            }
        }
        reverse(s.begin(), s.end());
        if(list[s]==true)
        {
            if(seted[s]==false)
            {
                ans.push_back(s);
                seted[s]=true;
            }
        }
        reverse(s.begin(), s.end());
        if(i>=n or j>=m or vis[i][j]==true or i<0 or j<0)
        {
            return;
        }
        
        s+=board[i][j];
        vis[i][j]=true;
        for(int k=0;k<2;k++)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            dfs(board,ni,nj,s,vis);
        }
        vis[i][j]=false;
        s.pop_back();
        return ;
        
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        for(auto i : words)
        {
            list[i]=true;
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string s="";
                dfs(board,i,j,s,vis);
            }
        }
        return ans;
    }
};
