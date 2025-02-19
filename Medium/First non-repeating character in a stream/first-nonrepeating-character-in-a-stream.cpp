//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    string ans="";
		    map<char,int>mp;
		   
		 
		    queue<char>q;
		
		    for(int i=0;i<s.size();i++){
		        mp[s[i]]++;
		        q.push(s[i]);
		        
		        while(!q.empty()){
		            if(mp[q.front()]>1)q.pop();
		            else break;
		        }
		        if(q.empty())ans+="#";
		        else ans+=q.front();
		        
		        
		       
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends