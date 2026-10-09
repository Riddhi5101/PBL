#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct EmergencyVehicle
{
    string name;
    string type;
    int priority;
    bool operator<(const EmergencyVehicle &e) const
    {
        return priority > e.priority;
    }
};
int main()
{
    priority_queue<EmergencyVehicle> pq;
    int n;
    cout << "URBAN EMERGENCY PRE-EMPTION ENGINE\n";
    cout << "\nEnter number of emergency vehicles: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        EmergencyVehicle e;
        cout << "\nEmergency Vehicle " << i + 1 << endl;
        cout << "Enter vehicle name: ";
        cin >> e.name;
        cout << "Enter vehicle type: ";
        cin >> e.type;
        cout << "Enter priority (1 = highest): ";
        cin >> e.priority;
        pq.push(e);
    }
    cout << "\nEmergency vehicles will be handled in this order:\n";
    while (!pq.empty())
    {
        EmergencyVehicle e = pq.top();
        pq.pop();
        cout << "\nVehicle: " << e.name;
        cout << "\nType: " << e.type;
        cout << "\nPriority: " << e.priority << endl;
        cout << "Status: Emergency request processed\n";
    }
    return 0;
}