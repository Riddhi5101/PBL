#include <iostream>
using namespace std;

int main()
{
    int nodes, start, destination;

    cout << "Enter the total number of intersections: ";
    cin >> nodes;

    if (nodes <= 0)
    {
        cout << "The number of intersections must be positive.\n";
        return 0;
    }

    cout << "Enter the current intersection (0 to " << nodes - 1 << "): ";
    cin >> start;

    cout << "Enter the destination intersection: ";
    cin >> destination;

    if (start < 0 || start >= nodes ||
        destination < 0 || destination >= nodes)
    {
        cout << "One of the intersection numbers is invalid.\n";
        return 0;
    }

    cout << "\nEmergency vehicle starts at intersection " << start << ".\n";
    cout << "Its destination is intersection " << destination << ".\n";
    cout << "The route-finding program can now find a path.\n";

    return 0;
}
