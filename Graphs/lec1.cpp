#include <bits/stdc++.h>
using namespace std;

// NON WEIGHTED GRAPH
class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction->0 = undirected graph
        // direction->1 = directed graph
        if (direction == 1)
        {
            // e.g  u se v ki taraf ak edge hai
            adjList[u].push_back(v);
        }
        else
        {
            // undirected means  u to v and v to u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        cout << "printing adj list" << endl;
        printAdj();
        cout << endl;
    }
    void printAdj()
    {
        for (auto it : adjList)
        {
            cout << it.first << "->{";
            for (auto neighbour : it.second)
            {
                cout << neighbour << " ";
            }
            cout << "}" << endl;
        }
    }

    void shortestPathBFS(int src, int dst)
    {
        queue<int> q;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;

        // initial state;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
            }
        }
        // parent array taiyar hai
        vector<int> ans;
        while (dst != -1)
        {
            // so humlog yha destination se -1 ki taraf jaa rhe hai.
            ans.push_back(dst);
            dst = parent[dst];
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
};

// WEIGHTED GRAPH

// template <typename T>
// class Graph
// {
//     unordered_map<T, list<pair<T, int>>> adjList;

// public:
//     void addEdge(T u, T v, int wt, int direction)
//     {
//         if (direction == 1)
//         {
//             adjList[u].push_back(make_pair(v, wt));
//         }
//         else
//         {
//             // we can use make_pair function or just use the curly braces.
//             adjList[u].push_back({v, wt});
//             adjList[v].push_back({u, wt});
//         }
//         cout << "Print adjList" << endl;
//         printAdj();
//         cout << endl;
//     }

//     // PRINT FUNCTION
//     void printAdj()
//     {
//         for (auto it : adjList)
//         {
//             cout << it.first << "->{";
//             for (pair<T, int> p : it.second)
//             {
//                 cout << "{" << p.first << "," << p.second << "},";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

int main()
{
    Graph g;
    // creating a graph
    g.addEdge(0, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);

    int n = 7;
    int src = 0;
    int dest = 3;

    g.shortestPathBFS(src, dest);

    return 0;
}