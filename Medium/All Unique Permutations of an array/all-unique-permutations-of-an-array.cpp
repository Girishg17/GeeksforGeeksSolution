//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int n, vector<int> arr, vector<int> &ds, set<vector<int>> &ans, vector<bool> &vis) {
        // base case
        if (ds.size() == n) {
            ans.insert(ds);
            return ;
        }
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                ds.push_back(arr[i]);
                solve(n, arr, ds, ans, vis);
                ds.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<bool> vis(n, false);
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n, arr, ds, res, vis);
        
        for (auto it = res.begin(); it != res.end(); it++) {
            ans.push_back(*it);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends