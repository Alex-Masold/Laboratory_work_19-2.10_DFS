#include <iostream> 
#include <unordered_map> 
#include <algorithm> 
#include <vector> 
#include <queue> 

using namespace std;

struct Definition {
    string name;
    int definitionsCount{};
    vector<string> definitions;
};

vector<int> kahn(vector<vector<int>>& graph, vector<int>& indegree) {
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<Definition> defs(n + 1);
    unordered_map<string, int> nameToIndex;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        if (nameToIndex.count(name) > 0) {
            cout << "multiple definition";
            return 0;
        }
        defs[i].name = name;
        nameToIndex[name] = i;

        cin >> defs[i].definitionsCount;
        for (int j = 0; j < defs[i].definitionsCount; j++) {
            string definition;
            cin >> definition;
            defs[i].definitions.push_back(definition);
        }
    }

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (string& definition : defs[i].definitions) {
            if (nameToIndex.count(definition) > 0) {
                int j = nameToIndex[definition];
                graph[i].push_back(j);
                indegree[j]++;
            }
        }
    }

    vector<int> result = kahn(graph, indegree);

    cout << (result.size() == n ? "correct" : "loop detected");

    return 0;
}