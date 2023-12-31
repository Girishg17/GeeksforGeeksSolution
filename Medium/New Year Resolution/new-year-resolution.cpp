//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int solve(int N,int coins[],int i,int sum,vector<vector<int>>&dp){
        if(sum!=0 && (sum%20==0 || sum%24==0 ||sum==2024))return 1;
        if(i>=N)return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        return dp[i][sum]=(solve(N,coins,i+1,sum+coins[i],dp)||solve(N,coins,i+1,sum,dp));
        
        
        
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N,vector<int>(2025,-1));
        return solve(N,coins,0,0,dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends