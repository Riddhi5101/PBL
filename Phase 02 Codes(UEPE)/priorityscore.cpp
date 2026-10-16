#include <iostream>
using namespace std;

int main()
{
    int vehicleType, urgency;

    cout << "Vehicle type (1-Ambulance, 2-Fire brigade, 3-Police): ";
    cin >> vehicleType;

    cout << "Enter urgency from 1 to 5: ";
    cin >> urgency;

    if (vehicleType < 1 || vehicleType > 3 ||
        urgency < 1 || urgency > 5)
    {
        cout << "Please enter valid values.\n";
        return 0;
    }

    // These numbers are only example values for our project demo.
    int extra = 10;
    if (vehicleType == 1)
        extra = 30;
    else if (vehicleType == 2)
        extra = 20;

    int score = urgency * 10 + extra;

    cout << "Priority score for this request: " << score << '\n';
    cout << "This is a sample scoring rule for simulation only.\n";

    return 0;
}
