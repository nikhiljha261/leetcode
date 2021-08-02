class Solution {
public:
    vector<vector<int>> ans;
    vector<int> adj[100005];
    map<int,bool> m;
    int tree;
    void dfs(int node,vector<int> v)
    {
         v.push_back(node);
        if(node==tree)
        {
            ans.push_back(v);
        }
        m[node]=true;
        // v.push_back(node);
        for(auto child : adj[node])
        {
            if(m[child]==false)
            {
                dfs(child,v);
            }
        }
        m[node]=false;
        v.pop_back();
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tree=graph.size()-1;
        for(int i=0;i<graph.size();i++)
        {
            int n=graph[i].size();
            for(int j=0;j<n;j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> v;
        dfs(0,v);
        return ans;
    }
};
