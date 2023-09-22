//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int low=0;
        int high=n;
        int lowest=-1,highest=-1;
        while(low<=high){
           int mid=low+((high-low)/2);
           if(arr[mid]==x){
               if(mid==0||arr[mid-1]<x){
                   lowest=mid;
                   break;
               }
           }
          if(arr[mid]>=x){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
        }
         low=0;
         high=n;
          while(low<=high){
           int mid=low+((high-low)/2);
           if(arr[mid]==x){
               if(mid==n-1||arr[mid+1]>x){
                   highest=mid;
                   break;
               }
           }
          if(arr[mid]>x){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
        }
        
        
        
        return {lowest,highest};
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends