// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

// Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, 
// and you can either start from the step with index 0, or the step with index 1.

// Example 1:
// Input: cost = [10, 15, 20]
// Output: 15
// Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
// Example 2:
// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// Output: 6
// Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
// Note:
// cost will have a length in the range [2, 1000].
// Every cost[i] will be an integer in the range [0, 999].

#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1);
    dp[0]=dp[1]=0;
    for(int i=2;i<=cost.size();i++){
        dp[i]=min((dp[i-2]+cost[i-2]),(dp[i-1]+cost[i-1]));
    }
    return dp[cost.size()];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        int result = minCostClimbingStairs(cost);
        cout<<result<<endl;
    }
    return 0;
}