#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int source){

    vector<int> order;
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        order.push_back(u);

        for(int v : adj[u]){

            if(!visited[v]){

                visited[v] = true;
                q.push(v);

            }

        }

    }

    return order;
}