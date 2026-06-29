#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int node){
    
    int source = 0;
    queue<int> q;

    vector<bool>visited(node,false);
    vector<int> order;
    visited[source] = true;
    q.push(source);


    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        order.push_back(u);

        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return order;
}
