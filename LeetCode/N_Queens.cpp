#include<bits/stdc++.h>
using namespace std;
#define endl "\n" 

bool isSafe(vector<string> &row,int i,int j,int n){
    //left diagonal
    int k=i-1,l=j-1;
    while(k>=0 && l>=0){
        if(row[k][l]=='Q')
            return false;
        k--; l--;
    }
    //right diagonal
    k=i-1;l=j+1;
    while(k>=0 && l<n){
        if(row[k][l]=='Q')
            return false;
        k--; l++;
    }
    //upwards
    k=i-1;l=j;
    while(k>=0){
        if(row[k][l]=='Q')
            return false;
        k--;
    }
    return true;
}
void NQueens(vector<vector<string> > &queens,vector<string> &row,int i,int n){
    if(i==n){
        queens.push_back(row);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(row,i,j,n)){
            row[i][j]='Q';
            NQueens(queens,row,i+1,n);
            row[i][j]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string> > queens;
    vector<string> row(n,string(n,'.'));
    NQueens(queens,row,0,n);
    return queens;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int t,tc=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<string>> ans = solveNQueens(n);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                for(int k=0;k<ans[i][j].length();k++){
                    cout<<ans[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        cout<<ans.size();
    }
    return 0;
}