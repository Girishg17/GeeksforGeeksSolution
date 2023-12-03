//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(vector<int>adj[],vector<int>&vis,vector<int>&path,int node){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(solve(adj,vis,path,it))return true;
               
            }
            else if(path[it]==1)return true;
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V+1,0);
        vector<int>pathvis(V+1,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(solve(adj,vis,pathvis,i))return true;
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends