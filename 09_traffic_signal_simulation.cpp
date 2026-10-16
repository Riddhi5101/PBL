#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "Which way is the emergency vehicle travelling?\n";
    cout << "1. North\n2. South\n3. East\n4. West\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice < 1 || choice > 4)
    {
        cout << "Please select a direction from 1 to 4.\n";
        return 0;
    }

    string direction;
    if (choice == 1) direction = "North";
    else if (choice == 2) direction = "South";
    else if (choice == 3) direction = "East";
    else direction = "West";

    cout << "\nEmergency vehicle direction: " << direction << '\n';
    cout << "Simulated signal for this direction: GREEN\n";
    cout << "Other directions: RED (for this demonstration only)\n";
    cout << "No real traffic signal is connected to this program.\n";

    return 0;
}
