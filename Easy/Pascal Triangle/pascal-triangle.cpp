//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    #define mod 1000000007
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        
        vector<vector<long long>>ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==i || j==0)ans[i].push_back(1);
                else{
                    int temp=(ans[i-1][j-1]+ans[i-1][j])%mod;
                    ans[i].push_back(temp);
                }
            }
        }
        return ans[n-1];
        
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends