/*
    Breadth First Search (BFS)

    Graph Type:
    - Directed / Undirected
    - Unweighted

    Time Complexity:
    - O(V + E)

    Space Complexity:
    - O(V)

    --------------------------------------------------------------------

    Adjacency List Representations

    1. Array of Vectors

        vector<int> adj[node];

        - 'adj' is an array, not a vector.
        - Arrays do NOT have .size().
        - Pass the number of nodes separately.

        Example:
        vector<int> bfs(vector<int> adj[], int node);

    --------------------------------------------------------------------

    2. Vector of Vectors (Recommended)

        vector<vector<int>> adj(node);

        - 'adj' is a vector.
        - adj.size() returns the number of nodes.
        - No need to pass the number of nodes separately.

        Example:
        vector<int> bfs(vector<vector<int>>& adj, int source);

    --------------------------------------------------------------------

    Input Format (Edge List)

        node edge
        u v
        u v
        ...

    Example

        5 5
        0 1
        0 2
        1 2
        2 3
        2 4
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int source){

    int node = adj.size();

    queue<int> q;
    vector<bool> visited(node, false);
    vector<int> order;

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

int main(){

    int node, edge;
    cin >> node >> edge;

    vector<vector<int>> adj(node);

    for(int i = 0; i < edge; i++){

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);     // Remove this line for a directed graph

    }

    int source = 0;

    vector<int> ans = bfs(adj, source);

    cout << "BFS Traversal: ";

    for(int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}