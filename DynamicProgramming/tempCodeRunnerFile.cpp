int l1=s1.size();
    int l2=s2.size();
    vector<vector<int> > dp(l1+1,vector<int>(l2+1,0));
    for(int i=1;i<l1;i++){
        for(int j=1;j<l2;j++){
            if(dp[i-1][j]==dp[i][j-1]){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[l1-1][l2-1]<<endl;