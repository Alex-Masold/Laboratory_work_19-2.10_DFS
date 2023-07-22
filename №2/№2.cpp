#include <iostream> 
#include <vector> 
#include <fstream> 

using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int main() {
    ifstream in("input.txt");
    int n, Arab, Brab;

    in >> n;
    vector<vector<int>> adj(n + 1);
    while (in >> Arab >> Brab) {
        adj[Arab].push_back(Brab);
        adj[Brab].push_back(Arab);
    }

    int k = 0;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            k++;
        }
    }

    cout << k + 1 << endl;

    return 0;
}