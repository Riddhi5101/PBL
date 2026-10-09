#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Node
{
    int id;
    int cost;

    bool operator>(const Node &n) const
    {
        return cost > n.cost;
    }
};
vector<pair<int, int>> graph[20];
int heuristic(int node, int destination)
{
    return abs(destination - node);
}
void aStar(int start, int destination, int n)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> g(n, 9999);
    vector<int> parent(n, -1);
    g[start] = 0;
    pq.push({start, heuristic(start, destination)});
    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int u = current.id;
        if (u == destination)
            break;
        for (auto road : graph[u])
        {
            int v = road.first;
            int roadCost = road.second;
            int newCost = g[u] + roadCost;
            if (newCost < g[v])
            {
                g[v] = newCost;
                parent[v] = u;
                int f = newCost + heuristic(v, destination);
                pq.push({v, f});
            }
        }
    }
    if (g[destination] == 9999)
    {
        cout << "\nDestination cannot be reached.\n";
        return;
    }
    vector<int> path;
    int current = destination;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    cout << "\nBest route: ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }
    cout << "\nTotal cost: " << g[destination] << endl;
}
int main()
{
    int n, e;
    cout << "Enter number of intersections: ";
    cin >> n;
    cout << "Enter number of roads: ";
    cin >> e;
    cout << "\nEnter roads as: source destination cost\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        // For an undirected road
        graph[v].push_back({u, cost});
    }
    int start, destination;
    cout << "\nEnter emergency vehicle starting node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> destination;
    aStar(start, destination, n);
    return 0;
}

