#include <iostream>
#include <string>
#include "../include/metro_graph.h"
using namespace std;

void showMenu() {
    cout << "\n====================================\n";
    cout << "       METROROUTE\n";
    cout << "  SMART METRO NAVIGATION SYSTEM\n";
    cout << "====================================\n";
    cout << "1. View All Stations\n";
    cout << "2. View Metro Network\n";
    cout << "3. Find Shortest Route\n";
    cout << "4. Exit\n";
    cout << "====================================\n";
    cout << "Enter your choice: ";
}

void initializeMetroNetwork(MetroGraph& metro) {
    // Add stations
    metro.addStation("Prem Nagar");
    metro.addStation("ISBT");
    metro.addStation("Clock Tower");
    metro.addStation("Rajpur Road");
    metro.addStation("EC Road");
    metro.addStation("Race Course");
    metro.addStation("Ballupur");
    metro.addStation("Patel Nagar");
    metro.addStation("Clement Town");
    metro.addStation("Sahastradhara");
    metro.addStation("Jogiwala");
    metro.addStation("Mussoorie Diversion");
    metro.addStation("Selaqui");
    metro.addStation("Herbertpur");
    metro.addStation("Vikasnagar");
    metro.addStation("Rajaji National Park");
    metro.addStation("Dehradun Railway Station");
    metro.addStation("Rispana");
    metro.addStation("Hathibarkala");
    metro.addStation("Premnagar Chowk");

    // Add connections (bidirectional with travel time in minutes)
    // Orange Line (Main Line)
    metro.addConnection("Prem Nagar", "ISBT", 5);
    metro.addConnection("ISBT", "Clock Tower", 4);
    metro.addConnection("Clock Tower", "Rajpur Road", 3);
    metro.addConnection("Rajpur Road", "EC Road", 6);
    metro.addConnection("EC Road", "Race Course", 4);
    metro.addConnection("Race Course", "Ballupur", 5);
    metro.addConnection("Ballupur", "Mussoorie Diversion", 7);

    // Blue Line (Southern Route)
    metro.addConnection("Rajpur Road", "Patel Nagar", 7);
    metro.addConnection("Patel Nagar", "Clement Town", 5);
    metro.addConnection("Clement Town", "Sahastradhara", 8);
    metro.addConnection("Sahastradhara", "Rajaji National Park", 10);

    // Green Line (Western Route)
    metro.addConnection("Clock Tower", "Jogiwala", 6);
    metro.addConnection("Jogiwala", "Rispana", 5);
    metro.addConnection("Rispana", "Hathibarkala", 4);

    // Yellow Line (Extended Route)
    metro.addConnection("ISBT", "Dehradun Railway Station", 3);
    metro.addConnection("Dehradun Railway Station", "Premnagar Chowk", 4);
    metro.addConnection("Premnagar Chowk", "Selaqui", 9);
    metro.addConnection("Selaqui", "Herbertpur", 12);
    metro.addConnection("Herbertpur", "Vikasnagar", 8);

    // Connector lines
    metro.addConnection("Prem Nagar", "Premnagar Chowk", 2);
    metro.addConnection("EC Road", "Clement Town", 9);
}

int main() {
    MetroGraph metro;

    cout << "\n========================================\n";
    cout << "  Initializing Metro Network...\n";
    cout << "========================================\n";

    initializeMetroNetwork(metro);

    cout << "Metro network loaded successfully!\n";
    cout << "Total Stations: 20\n";

    int choice;
    string source, destination;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        switch (choice) {
            case 1:
                metro.displayAllStations();
                break;

            case 2:
                metro.displayNetwork();
                break;

            case 3:
                cout << "\nEnter source station: ";
                getline(cin, source);
                cout << "Enter destination station: ";
                getline(cin, destination);
                metro.findShortestRoute(source, destination);
                break;

            case 4:
                cout << "\n========================================\n";
                cout << "  Thank you for using MetroRoute!\n";
                cout << "========================================\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}
