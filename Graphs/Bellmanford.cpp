#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // unordered_map<int, list<pair<int, int>>> adjList;
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        if (direction == 0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else
        {
            adjList[u].push_back(v);
        }
    }

    // void addEdge(int u, int v, int wt, bool direction)
    // {
    //     if (direction == 0)
    //     {
    //         adjList[u].push_back({v, wt});
    //         adjList[v].push_back({u, wt});
    //     }
    //     else
    //     {
    //         adjList[u].push_back({v, wt});
    //     }
    // }

    // void printAdjList()
    // {
    //     for (auto i : adjList)
    //     {
    //         cout << i.first << "->";
    //         for (auto j : i.second)
    //         {
    //             cout << "{" << j.first << "," << j.second << "},";
    //         }
    //         cout << endl;
    //     }
    // }

    // void bellman(int n, int src)
    // {
    //     vector<int> dist(n, INT_MAX);
    //     dist[src - 'A'] = 0;
    //     // N-1 Times Relaxation karna hai
    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         for (auto a : adjList)
    //         {
    //             for (auto b : a.second)
    //             {
    //                 char u = a.first;
    //                 char v = b.first;
    //                 int wt = b.second;
    //                 if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
    //                 {
    //                     dist[v - 'A'] = dist[u - 'A'] + wt;
    //                 }
    //             }
    //         }
    //     }
    // checking the cyclic or not - ak baar aur relaxation karke dekhenge.
    //     bool anyUpdate = false;
    //     for (auto a : adjList)
    //     {
    //         for (auto b : a.second)
    //         {
    //             char u = a.first;
    //             char v = b.first;
    //             int wt = b.second;
    //             if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
    //             {
    //                 anyUpdate = true;
    //                 break;
    //                 dist[v - 'A'] = dist[u - 'A'] + wt;
    //             }
    //         }
    //     }
    // agar ak relaxation extra chalane ke baad kuch changes hua hai means anyupdate true ho jyga hence
    // hum check kar lenge and ans accordingly return karenge.
    //     if (anyUpdate == true)
    //     {
    //         cout << "negative cycle is present" << endl;
    //     }
    //     else
    //     {
    //         cout << "no negative cycle is present" << endl;
    //         cout << "printing shortest path :" << endl;
    //         for (int i = 0; i < n; i++)
    //         {
    //             cout << dist[i] << " ";
    //         }
    //     }
    // }

    // void floydWarshal(int n)
    // {
    //     // initial state - ak distance array create kar lenge.
    //     vector<vector<int>> dist(n, vector<int>(n, 1e9));

    //     // diagonal par zero daalo
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (i == j)
    //             {
    //                 dist[i][j] = 0;
    //             }
    //         }
    //     }
    //     // kuch weights graphs ke andar given hai so hum update karenge accordingly.
    //     for (auto a : adjList)
    //     {
    //         for (auto b : a.second)
    //         {
    //             int u = a.first;
    //             int v = b.first;
    //             int wt = b.second;
    //             dist[u][v] = wt;
    //         }
    //     }
    //     // main logic or helper logic.
    //     for (int helper = 0; helper < n; helper++)
    //     {
    //         for (int src = 0; src < n; src++)
    //         {
    //             for (int dest = 0; dest < n; dest++)
    //             {
    //                 dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
    //             }
    //         }
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             cout << dist[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        for (auto nbr : adjList[node])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, ordering, vis);
            }
        }
        // Push the node into the stack after all its neighbors are visited
        ordering.push(node);
    }

    void dfs2(int src, unordered_map<int, bool> &vis2, unordered_map<int, list<int>> &adjNew)
    {
        vis2[src] = true;

        cout << src << " ";

        for (auto nbr : adjNew[src])
        {
            if (!vis2[nbr])
            {
                dfs2(nbr, vis2, adjNew);
            }
        }
    }

    int getStrongComponents(int n)
    {
        // step 01 : get the ordering
        stack<int> ordering;  
        unordered_map<int, bool> vis;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs1(i, ordering, vis);
            }
        }
        // step 02 : reverse edges
        unordered_map<int, list<int>> adjNew;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                int u = a.first;
                int v = b;

                // reverse karna hai , v to u entry create karni hai.
                // so humne new adjList create kar li and vha v to u entry create kar li.
                adjNew[v].push_back(u);
            }
        }

        // step 03 : traverse using ordering and count components
        int count = 0;
        unordered_map<int, bool> vis2;

        while (!ordering.empty())
        {
            int topNode = ordering.top();
            ordering.pop();
            if (!vis2[topNode])
            {
                cout << "SSC #" << count + 1 << ": ";
                dfs2(topNode, vis2, adjNew);
                count++;
                cout << endl;
            }
        }

        return count;
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);

    g.addEdge(2, 4, 1);

    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);

    g.addEdge(6, 7, 1);

    // g.addEdge('A', 'B', -1, 1);
    // g.addEdge('B', 'E', 2, 1);
    // g.addEdge('E', 'D', -3, 1);
    // g.addEdge('D', 'C', 5, 1);
    // g.addEdge('A', 'C', 4, 1);
    // g.addEdge('B', 'C', 3, 1);
    // g.addEdge('B', 'D', 2, 1);
    // g.addEdge('D', 'B', 1, 1);

    // g.printAdjList();
    // g.bellman(5, 'A');

    // g.addEdge(0, 1, 3, 1);
    // g.addEdge(1, 0, 2, 1);
    // g.addEdge(0, 3, 5, 1);
    // g.addEdge(1, 3, 4, 1);
    // g.addEdge(3, 2, 2, 1);
    // g.addEdge(2, 1, 1, 1);

    // g.floydWarshal(4);

    int n = 8;
    int ans = g.getStrongComponents(n);
    cout << "the count of ssc is :" << ans << endl;

    return 0;
}