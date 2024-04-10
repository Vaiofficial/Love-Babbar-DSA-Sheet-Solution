#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<char, list<pair<char, int>>> adjList;

    void addEdge(char u, char v, int wt, bool direction)
    {
        if (direction == 0)
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else
        {
            adjList[u].push_back({v, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "},";
            }
            cout << endl;
        }
    }
    void bellman(int n, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;
        // N-1 Times Relaxation karna hai
        for (int i = 0; i < n - 1; i++)
        {
            for (auto a : adjList)
            {
                for (auto b : a.second)
                {
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;
                    if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                    {
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                    }
                }
            }
        }
        // checking the cyclic or not - ak baar aur relaxation karke dekhenge.
        bool anyUpdate = false;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                {
                    anyUpdate = true;
                    break;
                    dist[v - 'A'] = dist[u - 'A'] + wt;
                }
            }
        }
        if (anyUpdate == true)
        {
            cout << "negative cycle is present" << endl;
        }
        else
        {
            cout << "no negative cycle is present" << endl;
            cout << "printing shortest path :" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << dist[i] << " ";
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('B', 'E', 2, 1);
    g.addEdge('E', 'D', -3, 1);
    g.addEdge('D', 'C', 5, 1);
    g.addEdge('A', 'C', 4, 1);
    g.addEdge('B', 'C', 3, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('D', 'B', 1, 1);

    g.printAdjList();
    g.bellman(5, 'A');

    return 0;
}