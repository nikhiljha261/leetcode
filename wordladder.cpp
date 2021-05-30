class Solution {
public:
    bool check(string a,string b)
    {
        int n=a.length();
        int m=b.length();
        if(n!=m)
        {
            return false;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                c++;
            }
        }
        if(c>1) return false;
        return true;
    }
    int ladderLength(string s, string e, vector<string>& list) {
        // n=list.size();
        queue<string> q;
        q.push(s);
        unordered_map<string,int> m;
        m[s]=true;
        int level=1;
        while(!q.empty())
        {
            
            int sz=q.size();
            for(int j=0;j<sz;j++)
            {
                string temp=q.front();
                // cout<<temp<<endl;
                q.pop();
                m[temp]=true;
                if(temp==e)
                {
                    return level;
                }
                for(auto i : list)
                {
                    if(m[i]==false)
                    {
                        if(check(temp,i)==true)
                        {
                            q.push(i);
                            
                        }
                    }
                }
            }
            level++;
            
        }
        return 0;
        
    }
};
