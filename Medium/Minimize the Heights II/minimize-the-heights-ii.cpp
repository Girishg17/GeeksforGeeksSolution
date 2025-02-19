//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        int maxi = arr[n-1]; //store maximum element
        int mini = arr[0]; //store minimum element
        int ans = arr[n-1] - arr[0]; //initial ans will be (maxi - mini)
        
        //going through all the element and 
        //updating possible maximum and minimum hight after performing operation
        for(int i=1; i<n; i++) {
            if(arr[i]-k < 0) 
                continue;
                
            maxi = max(arr[i-1]+k, arr[n-1]-k);
            mini = min(arr[0]+k, arr[i]-k);
            
            ans = min(ans, maxi-mini);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends