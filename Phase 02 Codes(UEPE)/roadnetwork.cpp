#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nodes, roads;

    cout << "How many intersections are there? ";
    cin >> nodes;

    if (nodes < 1 || nodes > 100)
    {
        cout << "Please enter between 1 and 100 intersections.\n";
        return 0;
    }

    vector<vector<pair<int, int>>> city(nodes);

    cout << "How many roads connect them? ";
    cin >> roads;

    for (int i = 0; i < roads; i++)
    {
        int from, to, distance;

        cout << "Enter road (start end distance): ";
        cin >> from >> to >> distance;

        if (from < 0 || from >= nodes || to < 0 ||
            to >= nodes || from == to || distance <= 0)
        {
            cout << "That road entry is not valid. Try again.\n";
            i--;
            continue;
        }

        city[from].push_back({to, distance});
        city[to].push_back({from, distance});
    }

    cout << "\nRoads in the network:\n";
    for (int i = 0; i < nodes; i++)
    {
        cout << "Intersection " << i << ": ";
        for (auto road : city[i])
            cout << road.first << " (distance " << road.second << ")  ";
        cout << '\n';
    }

    return 0;
}
