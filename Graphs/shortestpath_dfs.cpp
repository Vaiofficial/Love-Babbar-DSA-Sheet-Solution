#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    // topological ordering is liye use kar rhe hai because start hum us node se
    // kar rhe hai jiski indegree zero hai, so topological ordering se humko
    // stack ke top mai vo element mil jyga jo ki sabse independent hoga means
    // vha pahuchne ka koi rasta nahi that is uski indegree zero hogi

    void addEdge(int u, int v, int w, int direction)
    {
        // if direction=0 undirected
        // if direction=1 directed
        if (direction == 1)
        {
            adj[u].push_back({v, w});
        }
        else
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << ":{";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << "}" << endl;
        }
    }

    void toporderDFS(int src, stack<int> &st, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        for (auto nbrPair : adj[src])
        {
            // first means adjacent node and second means vha jane tk ki distance.
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (!visited[nbrNode])
            {
                // recursive call
                toporderDFS(nbrNode, st, visited);
            }
        }

        // backtracking ke time stack mai push karo current node ko
        st.push(src);
    }

    void shortestDisDFS(stack<int> &st, int n)
    {
        vector<int> dist(n, INT_MAX);
        // intitially source vo lenge jo sabse independent hoga.
        int src = st.top();
        // use kar liye so pop kardo
        st.pop();
        // vector mai hum distance store kar rhe hai.
        dist[src] = 0;

        // update nbr distance for this src node
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            // har baar check kar rhe hai vector mai us nbrNode index par ki jo
            // distance vha hai vo minimum hai agar nahi so update karo.
            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // ab same upar ka concept sabhi element k liye lgao jo ki stack mai hai
        while (!st.empty())
        {
            int src = st.top();
            st.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        // ab mera distance array akdam ready hai.

        cout << "printing the distance array" << endl;
        for (auto it : dist)
        {
            cout << it << " ";
        }
    }

    void dijkastraShortestDistance(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // initial state
        st.insert({0, src});
        dist[src] = 0;

        // deletion updation logic
        while (!st.empty())
        {
            auto topElement = st.begin();
            // topElement ak pointer dega so usko dereference karna hoga to get
            // the actual value.
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            // remove top Node
            st.erase(st.begin());
            // ab neighbour find out karnege node ke
            for (pair<int, int> nbrPair : adj[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                // current node ka distance and neighbout edge ka sum karke check
                // kar rhe , kya vo kam hai distance array k andar jo value hai.
                // agar kam hai to update kardo.
                if (topDist + nbrDist < dist[nbrNode])
                {
                    //  found a new shorter distance
                    // now update
                    // 1.set ki entry
                    // set mai hum directly update nahi kar skte hai , phle vo element ko
                    // nikaalna hoga and then update karna hoga.

                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end())
                    {
                        // entry present in the set
                        st.erase(previousEntry);
                    }

                    // 2.dist ka array
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << "shortest distance from source" << src << "node to destination" << dest << "node is: " << dist[dest] << endl;
    }
};

int main()
{
    Graph g;

    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    // cout << "printing the adj list" << endl;
    // g.printadj();

    // int src = 0;
    // stack<int> st;
    // unordered_map<int, bool> vis;

    // g.toporderDFS(src, st, vis);

    // cout << "print topoorder" << endl;

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    int n = 6;
    int src = 6;
    int dest = 4;
    // g.shortestDisDFS(st, n);

    g.dijkastraShortestDistance(n, src, dest);

    return 0;
}