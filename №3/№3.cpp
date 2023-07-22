#include <iostream> 
#include <vector> 
using namespace std;

vector<int> graph[20001];
int components[20001] = {};
bool visited[20001] = {};

void dfs(int indV, int component) //component - так сказать, смежная пара, набор 
{
    visited[indV] = true;

    components[indV] = component;
    for (int u : graph[indV])
    {
        if (!visited[u])
            dfs(u, component);
    }
}

int main()
{
    int n, m, u, v;
    int cmp = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cmp++;
            dfs(i, cmp);
        }
    }

    cout << cmp << endl;
    for (int i = 1; i <= n; i++) {
        cout << components[i] << ' ';
    }

    return 0;
}