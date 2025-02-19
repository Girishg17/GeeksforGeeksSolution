//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n==1)return 1;
        long long prefix_sum=0;
        long long total_sum=0;
        for(long long i=0;i<n;i++){
            total_sum+=a[i];
        }
    
        for(long long i=0;i<n;i++){
        
            if((total_sum-a[i]-prefix_sum)==prefix_sum)return i+1;
            prefix_sum+=a[i];
        }
        return -1;
        
        
        
    
        // Your code here
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends