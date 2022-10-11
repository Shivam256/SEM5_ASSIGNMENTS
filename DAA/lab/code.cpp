#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int sumN(int n)
{
    int total = 0;
    while (n--)
    {
        int x;
        cin >> x;
        total += x;
    }

    return total;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

class Graph
{
public:
    map<int, int> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void dfs(int v)
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                dfs(*i);
            }
        }
    }
};

vector<vector<int>> addMatrix(vector<vector<int>> m1, vector<vector<int>> m2)
{
    int n = m1.size();
    int m = m1[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> m1, vector<vector<int>> m2)
{
    int r1 = m1[0].size();
    int r2 = m2[0].size();
    int c2 = m2.size();

    vector<vector<int>> result(c2, vector<int>(r1, 0));

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; i < c2; j++)
        {
            for (int k - 0; k < r2; k++)
            {
                result[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }

    return result;
}

int getResult()


int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.dfs(1);

    return 0;
}