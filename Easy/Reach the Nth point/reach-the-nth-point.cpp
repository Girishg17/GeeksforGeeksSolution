//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    #define mod 1000000007
		int nthPoint(int n){
		    vector<int>arr(n+1,0);
		    arr[1]=1;
		    arr[2]=2;
		    for(int i=3;i<=n;i++){
		        arr[i]=(arr[i-2]+arr[i-1])%mod;
		    }
		    return arr[n];
		    // Code here
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends