#include <bits/stdc++.h>
using namespace std;
void dfsTopo(int  u , vector<vector<int>>& adj , vector<bool> &visited , stack<int> &st  ){
	    visited[u] = 1 ; 
	    
	    for(auto it : adj[u])
	        if(!visited[it])
	         dfsTopo(it , adj , visited,st);
	    
	    st.push(u);
	}
	
	void dfs(int  u , vector<vector<int>>& adjReversed , vector<bool> &visited){
	    visited[u] = 1 ; 
	   // cout << u << " ";
	    for(auto it : adjReversed[u])
	        if(!visited[it])
	         dfs(it , adjReversed , visited);
	}
	
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        vector<bool> visited(v,false) ;
        stack<int> st ; 
        
        // get toposorted order in the  stack 
        for(int  i = 0 ; i < v ; i++)
          if(!visited[i])
           dfsTopo(i,adj,visited,st);
        
        
        // reverse all edgess !!  
        vector<vector<int>>  adjReversed (v) ;
        
        for(int  src  = 0 ; src< v ; src++)
            for(auto dest : adj[src])
                adjReversed[dest].push_back(src) ; 
            
        // call dfs for scc 
        
        int sccCount = 0 ;
        fill(visited.begin(), visited.end(), false);
        
        while(!st.empty()){
            
            int curr = st.top();
            st.pop();
            if(!visited[curr]){
                sccCount++;
                dfs(curr ,adjReversed , visited ) ; 
                // cout <<endl;
            }
        }
        
        return sccCount;
        
    }

int main()
{
    return 0;
}