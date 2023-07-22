#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;

vector<int> kano(vector<vector<int>>& dep, vector<int>& dependenceCount) {
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 1; i < dependenceCount.size(); i++)
        if (dependenceCount[i] == 0) queue.push(i);

    vector<int> result;
    while (!queue.empty()) {
        int i = queue.top();
        queue.pop();
        result.push_back(i);
        for (auto j : dep[i]) {
            dependenceCount[j]--;
            if (dependenceCount[j] == 0)
                queue.push(j);
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;


    vector<int> dependenceCount(n + 1, 0);
    vector<vector<int>> dep(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dep[a].push_back(b);
        dependenceCount[b]++;
    }

    vector<int> resIndex = kano(dep, dependenceCount);

    if (resIndex.size() == n) {
        vector<int> resValue(n);
        for (int i = 0; i < n; i++)
            resValue[resIndex[i] - 1] = i + 1;
        cout << "YES" << endl;
        for (auto i : resValue) cout << i << ' ';
    }
    else cout << "NO";
}