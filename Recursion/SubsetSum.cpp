// Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether 
//if the sum of any of the non-empty subsets of the set A is zero.

// Input Format
// The first line contains an integer T, which is the total number of test cases.
// T test cases follow.
// Each test case consists of two lines.
// The first line consists of a single integer N, which is the number of elements present in the set A.
// The second line contains N space separated integers denoting the elements of the set A.

// Constraints
// 1 ≤ T ≤10
// 1 ≤ N ≤ 4
// -10^5 ≤ A[i] ≤ 10^5

// Output Format
// Print the answer for each testcase in a new line.
// If the sum of any of the subset is zero, then print “Yes” (without quotes) else print “No”(without quotes).

// Sample Input
// 1
// 4
// 1 3 2 -3
// Sample Output
// Yes
// Explanation
// The sum of the subset {3,-3} is zero.

#include<bits/stdc++.h>
using namespace std;

bool res=false;

void SubsetSum(vector<int> &v,vector<int> ans,int i,int j,int n,int sum){
    if(v.size()<1){
        res=true;
        return;
    }
    if(i==n){
        for(auto it:ans){
            sum+=it;
        }
        if(ans.size()>1 && sum==0){
            res = true;
        }
        return;
    }
    //Not including the number
    SubsetSum(v,ans,i+1,j,n,sum);
    //Including the number
    ans.push_back(v[i]);
    SubsetSum(v,ans,i+1,j+1,n,sum);
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        res = false;
        vector<int> v(n),ans;
        for(int i=0;i<n;i++)
            cin>>v[i];
        SubsetSum(v,ans,0,0,n,0);
        if(res){
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}