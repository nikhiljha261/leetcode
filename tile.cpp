class Solution {
public:
    int n;
    int ans;
    void count(map<int,int>& m,int ind)
    {
        if(ind==n)
        {
            return ;
        }
        for(int i=0;i<26;i++)
        {
            if(m[i]>0)
            {
                m[i]--;
                ans=ans+1;
                count(m,ind+1);
                m[i]++;
            }
        }
        
    }
    int numTilePossibilities(string tiles) {
        n=tiles.length();
        map<int,int> m;
        for(auto c : tiles)
        {
            m[c-'A']++;
        }
        ans=0;
        // int ans=0;÷
        count(m,0);
        return ans;
    }
};
