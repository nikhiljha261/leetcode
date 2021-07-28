  int n=a.length();
  int m=b.length();
  int dp[m+1][n+1];//no of valid dp[i-1]
  memset(dp,0,sizeof(dp));
  dp[1][0]=0;
  for(int i=1;i<=n;i++)
  {
      if(a[i-1]==b[0])
      {
          dp[1][i]=1+dp[1][i-1];
      }
      else
      {
          dp[1][i]=dp[1][i-1];
      }
  }
  for(int i=2;i<=m;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(a[j-1]==b[i-1])
          {
              dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
          }
          else
          {
              dp[i][j]=dp[i][j-1];
          }
      }
  }
  return dp[m][n];
        
