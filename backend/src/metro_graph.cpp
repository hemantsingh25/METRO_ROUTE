#include "../include/metro_graph.h"
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Constructor
MetroGraph::MetroGraph() : stationCount(0) {}

// Add a new station
void MetroGraph::addStation(const string& stationName) {
    // Check if station already exists
    if (stationNameToId.find(stationName) != stationNameToId.end()) {
        cout << "Station '" << stationName << "' already exists!" << endl;
        return;
    }

    int newId = stationCount;
    stations.push_back(MetroStation(newId, stationName));
    stationNameToId[stationName] = newId;
    stationCount++;
}

// Add bidirectional connection between two stations
void MetroGraph::addConnection(const string& station1, const string& station2, int travelTime) {
    if (!stationExists(station1) || !stationExists(station2)) {
        cout << "Error: One or both stations don't exist!" << endl;
        return;
    }

    int id1 = stationNameToId[station1];
    int id2 = stationNameToId[station2];

    // Bidirectional connection
    stations[id1].addConnection(id2, travelTime);
    stations[id2].addConnection(id1, travelTime);
}

// Display all stations
void MetroGraph::displayAllStations() const {
    cout << "\n========== ALL METRO STATIONS ==========\n";
    for (int i = 0; i < stationCount; i++) {
        cout << (i + 1) << ". " << stations[i].getName() << endl;
    }
    cout << "========================================\n";
}

// Display network structure
void MetroGraph::displayNetwork() const {
    cout << "\n========== METRO NETWORK ==========\n";
    for (int i = 0; i < stationCount; i++) {
        cout << "\n" << stations[i].getName() << " connects to:\n";
        vector<Connection> connections = stations[i].getConnections();

        if (connections.empty()) {
            cout << "  (No connections)\n";
        } else {
            for (const auto& conn : connections) {
                cout << "  -> " << stations[conn.destinationId].getName()
                     << " (" << conn.travelTime << " min)\n";
            }
        }
    }
    cout << "===================================\n";
}

// Check if station exists
bool MetroGraph::stationExists(const string& stationName) const {
    return stationNameToId.find(stationName) != stationNameToId.end();
}

// Get station ID from name
int MetroGraph::getStationId(const string& stationName) const {
    if (stationExists(stationName)) {
        return stationNameToId.at(stationName);
    }
    return -1;
}

// Get station name from ID
string MetroGraph::getStationName(int stationId) const {
    if (stationId >= 0 && stationId < stationCount) {
        return stations[stationId].getName();
    }
    return "";
}

// Find shortest route using Dijkstra's Algorithm
void MetroGraph::findShortestRoute(const string& source, const string& destination) {
    // Validate input
    if (!stationExists(source)) {
        cout << "\nError: Source station '" << source << "' not found!\n";
        return;
    }
    if (!stationExists(destination)) {
        cout << "\nError: Destination station '" << destination << "' not found!\n";
        return;
    }

    int sourceId = stationNameToId.at(source);
    int destId = stationNameToId.at(destination);

    // Special case: source == destination
    if (sourceId == destId) {
        cout << "\nYou are already at the destination!\n";
        return;
    }

    // Dijkstra's Algorithm
    vector<int> dist(stationCount, INT_MAX);
    vector<int> parent(stationCount, -1);
    vector<bool> visited(stationCount, false);

    // Priority queue: {distance, stationId}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[sourceId] = 0;
    pq.push({0, sourceId});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if already visited
        if (visited[u]) continue;
        visited[u] = true;

        // If we reached destination, we can stop
        if (u == destId) break;

        // Relax edges
        vector<Connection> connections = stations[u].getConnections();
        for (const auto& conn : connections) {
            int v = conn.destinationId;
            int weight = conn.travelTime;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Check if destination is reachable
    if (dist[destId] == INT_MAX) {
        cout << "\nNo route found between " << source << " and " << destination << "!\n";
        return;
    }

    // Display the path
    displayPath(parent, sourceId, destId, dist);
}

// Helper: Reconstruct and display path
void MetroGraph::displayPath(const vector<int>& parent, int source, int destination, const vector<int>& dist) {
    // Reconstruct path
    vector<int> path;
    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    // Display route
    cout << "\n========== SHORTEST ROUTE ==========\n";
    for (size_t i = 0; i < path.size(); i++) {
        cout << "  " << getStationName(path[i]) << endl;
        if (i < path.size() - 1) {
            cout << "      ↓" << endl;
        }
    }

    cout << "\n====================================\n";
    cout << "Total Stops: " << (path.size() - 1) << endl;
    cout << "Estimated Travel Time: " << dist[destination] << " minutes\n";
    cout << "Algorithm Used: Dijkstra's Algorithm\n";
    cout << "====================================\n";
}
