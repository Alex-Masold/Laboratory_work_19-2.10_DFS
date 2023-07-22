#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
using namespace std;

#include <iostream> 
#include <vector> 

using namespace std;

struct Glade
{
    int outcomeNumber = 0; // кол-во исходящих тропинок 
    vector<int> ways; // номера вершин, куда тропинки ведут 
    bool ShamanHere = false;
};

bool dfs(vector<Glade> glades, int ind, vector<bool>& visited, int& shamanLeft)
{
    if (glades[ind].ShamanHere) shamanLeft--;

    visited[ind] = true;

    if (!shamanLeft) return true;

    for (int i = 1; i <= glades[ind].outcomeNumber; i++)
    {
        if (!visited[glades[ind].ways[i - 1]]) // если поняна по этому пути еще не посещена 
            if (dfs(glades, glades[ind].ways[i - 1], visited, shamanLeft))
                return true;
    }
    return false;
}

int main() {
    int n, m, s;
    cin >> n >> m;
    int a, b, shaman;
    vector<Glade> glades(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        glades[a].ways.push_back(b);
        glades[a].outcomeNumber++;
        glades[b].ways.push_back(a);
        glades[b].outcomeNumber++;
    }

    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> shaman; // shaman - индекс поляны, на которой есть шаман 
        glades[shaman].ShamanHere = true;
    }

    vector<bool> visited(n + 1); // вектор посещенных полян 
    cout << (dfs(glades, 1, visited, s) ? "YES" : "NO");
}
