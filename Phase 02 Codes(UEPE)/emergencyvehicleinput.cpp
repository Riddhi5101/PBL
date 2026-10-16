#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string vehicle;

    cout << "Choose the emergency vehicle:\n";
    cout << "1. Ambulance\n";
    cout << "2. Fire brigade\n";
    cout << "3. Police vehicle\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1)
        vehicle = "Ambulance";
    else if (choice == 2)
        vehicle = "Fire brigade";
    else if (choice == 3)
        vehicle = "Police vehicle";
    else
    {
        cout << "Please choose 1, 2 or 3.\n";
        return 0;
    }

    cout << vehicle << " has been added to the simulation.\n";
    cout << "This example uses keyboard input, not a real sensor.\n";

    return 0;
}
