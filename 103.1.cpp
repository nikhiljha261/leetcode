class Solution {
public:
    bool canBeIncreasing(vector<int>& a) {
        int n=a.size();
        vector<int> lcs;
        lcs.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>lcs.back())
            {
                lcs.push_back(a[i]);
            }
            else
            {
                int ind=lower_bound(lcs.begin(),lcs.end(),a[i])-lcs.begin();
                lcs[ind]=a[i];
            }

        }
        int x=lcs.size();
        if(x<n-1) return false;
        return true;
    }
};
