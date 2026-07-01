/*
Platform   : LeetCode
Problem    : 1971. Find if Path Exists in Graph
Link       : https://leetcode.com/problems/find-if-path-exists-in-graph/
Topic      : Graph - BFS
Difficulty : Easy
Status     : Solved
Approach   : BFS (Adjacency List)
Time       : O(V + E)
Space      : O(V + E)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // Create adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Visited array
        vector<bool> visited(n, false);

        // BFS
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Destination found
            if (u == destination)
                return true;

            for (auto v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};