//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution { 
public:

int findMidSum(int ar1[], int ar2[], int n) {
    int low = 0;
    int high = n;
    
    if (n == 1) {
        return ar1[0] + ar2[0];
    }
    
    int total =( 2 * n)/2;
    
    while (low <= high) {
        int mid1 = (high + low) / 2;
        int mid2 = total - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 - 1 >= 0) {
            l1 = ar1[mid1 - 1];
        }

        if (mid2 - 1 >= 0) {
            l2 = ar2[mid2 - 1];
        }

        if (mid1 < n) {
            r1 = ar1[mid1];
        }

        if (mid2 < n) {
            r2 = ar2[mid2];
        }

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2) + min(r1, r2);
        }

        if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return -1;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends