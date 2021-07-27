int n=times.size();
priority_queue<int,vector<int>,greater<int>> pq;
for(int i=0;i<n;i++)
{
    pq.push(i);
}
int ft=times[tf][0];
sort(times.begin(),times.end());
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ed;
for(int i=0;i<n;i++)
{
    if(times[i][0]==ft)
    {
        while(ed.size()>=1 and ed.top().first<=times[i][0])
        {
            pq.push(ed.top().second);
            ed.pop();
        }
        int temp=pq.top();
        return temp;
        ed.push({times[i][1],temp});
        pq.pop();
    }
    else
    {
        while(ed.size()>=1 and ed.top().first<=times[i][0])
        {
            pq.push(ed.top().second);
            ed.pop();
        }
        int temp=pq.top();
        ed.push({times[i][1],temp});
        pq.pop();

    }
}
