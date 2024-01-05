//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    #define mod 1000000007;
	    if(N==1)return 4;
	    if(N==2)return 9;
	    vector<long long>ans(N);
	    ans[0]=2;
	    ans[1]=3;
	    for(int i=2;i<N;i++){
	        ans[i]=(ans[i-1]+ans[i-2])%mod;
	    }
	    int x=(ans[N-1]*ans[N-1])%mod;
	    return x;
	}
// 	1-4        0 1 1 2 3 5 8 13
// 	2-9
// 	3-25;
// 	4-64
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends