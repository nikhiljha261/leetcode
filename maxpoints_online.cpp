class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int n=v.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            int x=v[i][0];
            int y=v[i][1];
            map<double,int> m;
            for(int j=i+1;j<n;j++)
            {
                int x1=v[j][0];
                int y1=v[j][1];
                if(x1-x==0) m[90]++;
                else
                { 
                    double slope=double((y1-y))/(x1-x);
                    m[slope]++;
                }
            }
            for(auto s : m)
            {
                ans=max(ans,s.second+1);
            }
        }
        return ans;
    }
};
