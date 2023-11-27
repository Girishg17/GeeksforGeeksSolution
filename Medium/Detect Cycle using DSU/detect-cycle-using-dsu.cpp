//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset{
public:
    vector<int> parent, rank;
    Disjointset(int node){
        parent.resize(node);
        rank.resize(node, 0);  // Corrected initialization to 0
        for(int i = 0; i < node; i++){
            parent[i] = i;
        }
    }

    int findparent(int a){
        if(a == parent[a]) return a;
        return parent[a] = findparent(parent[a]);
    }

    void insert(int u, int v){
        int u_parent = findparent(u);
        int v_parent = findparent(v);
        if(u_parent == v_parent) return;
        else {
            if(rank[u_parent] > rank[v_parent]){
                parent[v_parent] = u_parent;
            }
            else if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else {
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }
        }
    }
};

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        Disjointset temp(V);  // Corrected instantiation
        for(int i = 0; i < V; i++){
            for(auto &x : adj[i]){
                if(i < x){
                    int u_parent = temp.findparent(i);
                    int v_parent = temp.findparent(x);
                    if(u_parent == v_parent) return 1;
                    temp.insert(i, x);
                }
            }
        }
        return 0;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends