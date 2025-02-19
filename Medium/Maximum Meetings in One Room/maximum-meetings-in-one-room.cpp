//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            v.push_back({S[i],{F[i],i}});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        ans.push_back(0);
        int cnt=0;
        for(int i=1;i<n;i++)
        {   
            int j=ans.back();
            if(v[i].first>v[j].second.first){
                ans.push_back(i);
                cnt++;
            }
            else{
                if(v[i].second.first<v[j].second.first){
                    ans[cnt]=i;
                }
                else if(v[i].second.first==v[j].second.first){
                     if(v[i].second.second<v[j].second.second){
                       ans[cnt]=i;
                     }
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=v[ans[i]].second.second+1;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends