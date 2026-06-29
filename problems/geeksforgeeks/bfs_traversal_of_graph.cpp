/*

Platform   : GeeksforGeeks
Problem    : BFS of graph
Link       : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Topic      : BFS, Graph
Difficulty : Easy
Status     : accepted

Approach
--------
- Standard BFS
- Queue
- Visited Array

Time  : O(V + E)
Space : O(V)

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<bool> visited(adj.size(),false);
        int node = adj.size();
        queue<int> q;
        vector<int> order;
        int source = 0;
        visited[source]=true;
        q.push(source);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }
};