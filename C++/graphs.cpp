// basic graph implementation with bfs and dfs traversal
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> adjlist[], int startnode, vector<bool> &visited)
{
    queue<int> q;
    visited[startnode] = true;
    q.push(startnode);

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        cout << cur_node << " ";

        for (int neigh: adjlist[cur_node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}

void dfs(vector<int> adjlist[], int startnode, vector<bool> &visited)
{
    visited[startnode] = true;
    cout << startnode << " ";
    for (auto it: adjlist[startnode]) {
        if (!visited[it]) {
            dfs(adjlist, it, visited);
        }
    }
}

int main()
{
    // create graph
    int n, m;   // vertices, edges
    cout << "Enter number of vertices and egdes: ";
    cin >> n >> m;

    // get vertices and implement adjacency matrix
    vector<int> adj[n+1];
    cout << "Input vertices values" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // for directed graph comment out one of the lines below
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    cout << endl;

    vector<bool> visited(n, false);
    cout << "BFS traversal of the input graph: ";
    bfs(adj, 1, visited);
    cout << endl;

    for (int i = 0; i <=n; i++) {
        visited[i] = false;
    }
    cout << "DFS traversal of the input graph: ";
    dfs(adj, 1, visited);
    cout << endl;

    return 0;
}
