#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    // A small sample road map to check whether route finding works.
    vector<vector<pair<int, int>>> city(4);

    city[0].push_back({1, 2});
    city[1].push_back({0, 2});
    city[1].push_back({2, 3});
    city[2].push_back({1, 3});
    city[2].push_back({3, 4});
    city[3].push_back({2, 4});
    city[0].push_back({3, 20});
    city[3].push_back({0, 20});

    vector<int> distance(4, INT_MAX);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> waiting;

    distance[0] = 0;
    waiting.push({0, 0});

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

            if (distance[current] + roadCost < distance[next])
            {
                distance[next] = distance[current] + roadCost;
                waiting.push({distance[next], next});
            }
        }
    }

    cout << "Expected minimum cost from node 0 to node 3: 9\n";
    cout << "Calculated cost: " << distance[3] << '\n';

    if (distance[3] == 9)
        cout << "Route test passed.\n";
    else
        cout << "Route test failed.\n";

    return 0;
}
