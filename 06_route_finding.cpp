#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int nodes, roads;

    cout << "Enter number of intersections (maximum 100): ";
    cin >> nodes;

    if (nodes < 1 || nodes > 100)
    {
        cout << "Please enter between 1 and 100 intersections.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> city(nodes);

    cout << "Enter number of roads: ";
    cin >> roads;

    for (int i = 0; i < roads; i++)
    {
        int a, b, distance;
        cout << "Enter road (start end distance): ";
        cin >> a >> b >> distance;

        if (a < 0 || a >= nodes || b < 0 || b >= nodes ||
            a == b || distance <= 0)
        {
            cout << "Invalid road details. Please enter them again.\n";
            i--;
            continue;
        }

        city[a].push_back({b, distance});
        city[b].push_back({a, distance});
    }

    int start, destination;
    cout << "Enter start and destination: ";
    cin >> start >> destination;

    if (start < 0 || start >= nodes ||
        destination < 0 || destination >= nodes)
    {
        cout << "Invalid start or destination.\n";
        return 0;
    }

    vector<int> distance(nodes, INT_MAX);
    vector<int> previous(nodes, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> waiting;

    distance[start] = 0;
    waiting.push({0, start});

    while (!waiting.empty())
    {
        int currentCost = waiting.top().first;
        int current = waiting.top().second;
        waiting.pop();

        if (currentCost != distance[current])
            continue;

        for (auto road : city[current])
        {
            int next = road.first;
            int roadCost = road.second;

            if (distance[current] + roadCost < distance[next])
            {
                distance[next] = distance[current] + roadCost;
                previous[next] = current;
                waiting.push({distance[next], next});
            }
        }
    }

    if (distance[destination] == INT_MAX)
    {
        cout << "There is no route between these intersections.\n";
        return 0;
    }

    vector<int> route;
    for (int point = destination; point != -1; point = previous[point])
        route.push_back(point);

    cout << "\nMinimum-cost route: ";
    for (int i = static_cast<int>(route.size()) - 1; i >= 0; i--)
    {
        cout << route[i];
        if (i > 0)
            cout << " -> ";
    }

    cout << "\nTotal route cost: " << distance[destination] << '\n';
    cout << "This version uses a zero heuristic, so it is Dijkstra's algorithm.\n";

    return 0;
}
