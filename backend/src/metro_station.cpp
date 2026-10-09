#include "../include/metro_station.h"
#include <iostream>
using namespace std;

// Default constructor
MetroStation::MetroStation() : id(-1), name("") {}

// Parameterized constructor
MetroStation::MetroStation(int stationId, string stationName)
    : id(stationId), name(stationName) {}

// Getters
int MetroStation::getId() const {
    return id;
}

string MetroStation::getName() const {
    return name;
}

vector<Connection> MetroStation::getConnections() const {
    return connections;
}

// Add connection to another station
void MetroStation::addConnection(int destinationId, int travelTime) {
    connections.push_back(Connection(destinationId, travelTime));
}

// Display station information
void MetroStation::display() const {
    cout << "Station ID: " << id << " | Name: " << name << endl;
    if (connections.empty()) {
        cout << "  No connections" << endl;
    } else {
        cout << "  Connections: " << connections.size() << endl;
    }
}
