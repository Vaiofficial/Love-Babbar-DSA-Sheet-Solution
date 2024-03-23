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

    void bfsTraversal(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        // inital state , means first element jo hai root usko push kardo queue mai.
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            // go for neighbours
            for (auto nbr : adjList[frontNode])
            {
                // jo neighbour node hai vo mil jyga.
                T nbrData = nbr.first;

                // check whether it is visited or not. If not visited then push it and mark it visited.
                if (!visited[nbrData])
                {
                    q.push(nbrData);
                    // yaha mistake ho skti hai so be careful mp[data] karna hai okkk.
                    visited[nbrData] = true;
                }
            }
        }
    }

    // DFS TRAVERSAL
    void dfsTraversal(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src])
        {
            // child utha liya
            T nbrData = nbr.first;
            // check karo already visited to nahi hai child
            if (!visited[nbrData])
            {
                dfsTraversal(nbrData, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    // creating a graph
    g.addEdge(0, 1, 5, 1);
    // g.addEdge(1, 2, 10, 1);
    g.addEdge(2, 3, 20, 1);
    g.addEdge(2, 4, 50, 1);
    g.addEdge(3, 4, 50, 1);
    g.addEdge(4, 5, 50, 1);

    // map to keep track of visited nodes of the graph.
    unordered_map<int, bool> visited;

    for (int node = 0; node <= 5; node++)
    {
        if (!visited[node])
        {
            // g.bfsTraversal(node, visited);

            g.dfsTraversal(0, visited);
        }
    }

    return 0;
}