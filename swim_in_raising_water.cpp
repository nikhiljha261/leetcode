
    void pathExist(int row, int col,vector<vector<int>>& a,int n , int t, vector<vector<bool>>& vis){
        if(row <0 || col < 0 || row>=n || col >=n || vis[row][col] || a[row][col]>t)return;
        vis[row][col] = 1;
        if(row==n-1 && col==n-1)return; 
        pathExist(row-1,col,a,n,t,vis);
        pathExist(row+1,col,a,n,t,vis);
        pathExist(row,col-1,a,n,t,vis);
        pathExist(row,col+1,a,n,t,vis);
    }
    int swimInWater(vector<vector<int>>& a) {
        int n  = a.size(),lo = 0 , hi = INT_MAX, ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            vector<vector<bool>> vis(n,vector<bool>(n));
            pathExist(0,0,a,n,mid,vis);
            if(vis[n-1][n-1]){
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        return ans;
    }
