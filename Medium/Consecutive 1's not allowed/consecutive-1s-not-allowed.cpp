//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    #define mod 1000000007
	// #define ll long long
	ll countStrings(int n) {
	    vector<long long>ans(n+1);
	    // code here
	    if(n==1)return 2;
	    if(n==2)return 3;
	    ans[0]=0;
	    ans[1]=2;
	    ans[2]=3;
	    for(int i=3;i<=n;i++){
	        ans[i]=(ans[i-1]+ans[i-2])%mod;
	    }
	    return ans[n];
	}
	
	
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends