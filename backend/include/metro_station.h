#ifndef METRO_STATION_H
#define METRO_STATION_H

#include <string>
#include <vector>
using namespace std;

// Represents a connection between two stations
struct Connection {
    int destinationId;
    int travelTime;  // in minutes

    Connection(int dest, int time) : destinationId(dest), travelTime(time) {}
};

// Represents a metro station
class MetroStation {
private:
    int id;
    string name;
    vector<Connection> connections;

public:
    MetroStation();
    MetroStation(int stationId, string stationName);

    // Getters
    int getId() const;
    string getName() const;
    vector<Connection> getConnections() const;

    // Add connection to another station
    void addConnection(int destinationId, int travelTime);

    // Display station info
    void display() const;
};

#endif
