#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    priority_queue<pair<int, string>> requests;
    int total;

    cout << "How many emergency requests do you want to enter? ";
    cin >> total;

    if (total < 0)
    {
        cout << "Please enter a valid number.\n";
        return 0;
    }

    for (int i = 0; i < total; i++)
    {
        string vehicle;
        int score;

        cout << "Enter vehicle name (one word) and priority score: ";
        cin >> vehicle >> score;

        requests.push({score, vehicle});
    }

    cout << "\nRequests will be handled in this order:\n";

    while (!requests.empty())
    {
        cout << requests.top().second
             << " - score " << requests.top().first << '\n';
        requests.pop();
    }

    return 0;
}
