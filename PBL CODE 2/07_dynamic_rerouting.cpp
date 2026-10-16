#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void findRoute(const vector<vector<pair<int, int>>>& city,
               const vector<vector<bool>>& closedRoad,
               int start, int destination)
{
    int nodes = static_cast<int>(city.size());
    vector<int> distance(nodes, INT_MAX);
    vector<int> previous(nodes, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> waiting;

    distance[start] = 0;
    waiting.push({0, start});

    while (!waiting.empty())
    {
        int cost = waiting.top().first;
        int current = waiting.top().second;
        waiting.pop();

        if (cost != distance[current])
            continue;

        for (auto road : city[current])
        {
            int next = road.first;
            int roadCost = road.second;

            if (closedRoad[current][next])
                continue;

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
        cout << "No route is available with the current road closure.\n";
        return;
    }

    vector<int> route;
    for (int point = destination; point != -1; point = previous[point])
        route.push_back(point);

    cout << "Route after checking road closures: ";
    for (int i = static_cast<int>(route.size()) - 1; i >= 0; i--)
    {
        cout << route[i];
        if (i > 0)
            cout << " -> ";
    }
    cout << "\nRoute cost: " << distance[destination] << '\n';
}

int main()
{
    int nodes, roads;

    cout << "Enter number of intersections (maximum 100): ";
    cin >> nodes;
    if (nodes < 1 || nodes > 100)
    {
        cout << "Invalid number of intersections.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> city(nodes);
    vector<vector<bool>> closedRoad(nodes, vector<bool>(nodes, false));

    cout << "Enter number of roads: ";
    cin >> roads;

    for (int i = 0; i < roads; i++)
    {
        int a, b, cost;
        cout << "Enter road (start end distance): ";
        cin >> a >> b >> cost;

        if (a < 0 || a >= nodes || b < 0 || b >= nodes ||
            a == b || cost <= 0)
        {
            cout << "Invalid road details. Please try again.\n";
            i--;
            continue;
        }

        city[a].push_back({b, cost});
        city[b].push_back({a, cost});
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

    cout << "\nBefore closing a road:\n";
    findRoute(city, closedRoad, start, destination);

    char answer;
    cout << "\nDo you want to close a road? (y/n): ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        int a, b;
        cout << "Enter the two ends of the road to close: ";
        cin >> a >> b;

        if (a < 0 || a >= nodes || b < 0 || b >= nodes || a == b)
        {
            cout << "Invalid road endpoints.\n";
            return 0;
        }

        closedRoad[a][b] = true;
        closedRoad[b][a] = true;

        cout << "\nAfter closing that road:\n";
        findRoute(city, closedRoad, start, destination);
    }

    return 0;
}
