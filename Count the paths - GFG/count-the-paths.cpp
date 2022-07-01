// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    list<int>* adj;
public:
    int helper(int src, int dest){
        if(src==dest){
            return 1;
        }
        int count=0;
        for(auto nei: adj[src]){
            count+=helper(nei,dest);
        }
        return count;
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    adj=new list<int>[n];
	    for(auto edge: edges){
	        adj[edge[0]].push_back(edge[1]);
	    }
	    return helper(s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends