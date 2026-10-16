#include <iostream>
using namespace std;

int main()
{
    int score;
    const int exampleLimit = 50;

    cout << "Enter the emergency priority score: ";
    cin >> score;

    if (score >= exampleLimit)
    {
        cout << "Pre-emption can be requested in the simulation.\n";
        cout << "The emergency direction receives simulated priority.\n";
    }
    else
    {
        cout << "Keep the normal signal sequence in the simulation.\n";
    }

    cout << "The score limit is only for demonstration.\n";
    cout << "This program does not control real traffic signals.\n";

    return 0;
}
