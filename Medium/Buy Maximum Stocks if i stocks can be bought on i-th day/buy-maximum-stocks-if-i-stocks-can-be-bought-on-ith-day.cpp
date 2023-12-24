//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push_back({price[i],i+1});
        }
        sort(pq.begin(),pq.end());
        int c=0;
        int i=0;
        int sum=0;
        while(i<n && sum<=k){
            if(sum<=k){
                int j=0;
                while(sum+pq[i].first<=k && j<pq[i].second){
                    sum=sum+pq[i].first;
                    j++;
                    c++;
                }
            }
            else break;
            
           
            i++;
        }
        return c;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends