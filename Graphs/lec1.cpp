#include <bits/stdc++.h>
using namespace std;

// NON WEIGHTED GRAPH
// class Graph
// {
// public:
//     unordered_map<int, list<int>> adjList;

//     void addEdge(int u, int v, bool direction)
//     {
//         // direction->0 = undirected graph
//         // direction->1 = directed graph
//         if (direction == 1)
//         {
//             // e.g  u se v ki taraf ak edge hai
//             adjList[u].push_back(v);
//         }
//         else
//         {
//             // undirected means  u to v and v to u
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }

//         cout << "printing adj list" << endl;
//         printAdj();
//         cout << endl;
//     }
//     void printAdj()
//     {
//         for (auto it : adjList)
//         {
//             cout << it.first << "->{";
//             for (auto neighbour : it.second)
//             {
//                 cout << neighbour << " ";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

// WEIGHTED GRAPH

template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> adjList;

public:
    void addEdge(T u, T v, int wt, int direction)
    {
        if (direction == 1)
        {
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            // we can use make_pair function or just use the curly braces.
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        cout << "Print adjList" << endl;
        printAdj();
        cout << endl;
    }

    // PRINT FUNCTION
    void printAdj()
    {
        for (auto it : adjList)
        {
            cout << it.first << "->{";
            for (pair<T, int> p : it.second)
            {
                cout << "{" << p.first << "," << p.second << "},";
            }
            cout << "}" << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    // creating a graph
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1);

    return 0;
}