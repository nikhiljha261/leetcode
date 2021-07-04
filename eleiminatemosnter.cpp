class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> time(n);
        for(int i=0;i<n;i++)
        {
            time[i]=dist[i]/(double)speed[i];
        }
        sort(time.begin(),time.end());
        int ans=1;
        int ind=1;
        for(int i=1;i<n;i++)
        {
            int shotime=(double)i;
            if(time[ind]<=shotime)
            {
                break;
            }else
            {
                ind++;
                ans++;
            }
        }
        return ans;
    }
};
