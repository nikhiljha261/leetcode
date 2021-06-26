class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        int i=0;
        string ans;
        int m=s.length();
        string temp;
        while(i<m)
        {
            if(i+n<=m and s.substr(i,n)==part)
            {
                for(int j=i+n;j<m;j++)
                {
                    temp+=s[j];
                }
                s=temp;
                temp="";
                m=s.length();
                i=0;
            }
            else
            {
                // i++;
                temp=temp+s[i];
                i++;
            }
        }
        return temp;
        
    }
};
