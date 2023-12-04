//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0 || A[X][Y]==0)return -1;
        // code here
        int steps=0;
        queue<pair<int,int>>pq;
        vector<vector<int>>vis(N,vector<int>(M,0));
        int arr[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({0,0});
        vis[0][0]=1;
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                int row=pq.front().first;
                int col=pq.front().second;
                pq.pop();
                if(row==X && col==Y)return steps;
                for(auto &it:arr){
                    int newrow=row+it[0];
                    int newcol=col+it[1];
                    if(newrow>=0 && newcol>=0 && newrow<N && newcol<M &&A[newrow][newcol]==1 && vis[newrow][newcol]==0 )
                    {
                        pq.push({newrow,newcol});
                        vis[newrow][newcol]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends