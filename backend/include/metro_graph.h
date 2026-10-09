#ifndef METRO_GRAPH_H
#define METRO_GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include "metro_station.h"
using namespace std;

// Main Metro Network Graph class
class MetroGraph {
private:
    vector<MetroStation> stations;
    unordered_map<string, int> stationNameToId;
    int stationCount;

public:
    MetroGraph();

    // Add a new station
    void addStation(const string& stationName);

    // Add bidirectional connection between two stations
    void addConnection(const string& station1, const string& station2, int travelTime);

    // Display all stations
    void displayAllStations() const;

    // Display network structure
    void displayNetwork() const;

    // Find shortest route using Dijkstra's Algorithm
    void findShortestRoute(const string& source, const string& destination);

    // Check if station exists
    bool stationExists(const string& stationName) const;

    // Get station ID from name
    int getStationId(const string& stationName) const;

    // Get station name from ID
    string getStationName(int stationId) const;

private:
    // Helper: Reconstruct and display path
    void displayPath(const vector<int>& parent, int source, int destination, const vector<int>& dist);
};

#endif
