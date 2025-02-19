//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
    
    stack<char>st;
    for(int i=0;i<S.size();i++){
        while(!st.empty() &&K>0 && st.top()>S[i] ){
            st.pop();
            K--;
        }
        st.push(S[i]);
        
    }
     if(st.empty())
            return "0";
        while(K--)
            st.pop();
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int i=0;
    while(ans[i]=='0')
            i++;
        if(i==ans.size())
            return "0";
    return ans.substr(i);
      
   
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends