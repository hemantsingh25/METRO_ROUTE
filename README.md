# MetroRoute

**Smart Metro Navigation System**

MetroRoute is a console-based C++ application that finds the shortest route between metro stations using **Dijkstra's Algorithm**. Built as a B.Tech CSE PBL project to demonstrate practical applications of Data Structures and Algorithms.

---

## 📋 Project Overview

- **Project Type:** PBL (Project-Based Learning)
- **Language:** C++ (Standard C++11)
- **Core Algorithm:** Dijkstra's Algorithm
- **Network Size:** 20 stations across 4 metro lines
- **Platform:** Windows/Linux/macOS (Console-based)

---

## 🎯 Features

1. **View All Stations** — List all 20 metro stations
2. **View Metro Network** — Display complete network with connections and travel times
3. **Find Shortest Route** — Calculate fastest route between any two stations
4. **Journey Details** — Shows total stops, estimated time, and algorithm used
5. **Input Validation** — Handles invalid station names gracefully
6. **Multiple Searches** — Perform unlimited route searches without restarting

---

## 🗺️ Metro Network

The system models a fictional Dehradun metro network with **4 lines**:

- **Orange Line** (Main): Prem Nagar ↔ Mussoorie Diversion
- **Blue Line** (Southern): Rajpur Road ↔ Rajaji National Park
- **Green Line** (Western): Clock Tower ↔ Hathibarkala
- **Yellow Line** (Extended): ISBT ↔ Vikasnagar

**Total:** 20 stations, 24 connections

---

## 📚 DSA Concepts Demonstrated

| Concept | Implementation | Purpose |
|---------|---------------|---------|
| **Graph** | Metro network | Stations = vertices, tracks = edges |
| **Weighted Graph** | Edge weights | Travel time per connection |
| **Adjacency List** | `vector<Connection>` | Store neighbors for each station |
| **Dijkstra's Algorithm** | Shortest path | Finds time-optimal route |
| **Priority Queue** | Min-heap | Always picks closest unvisited station |
| **Vector** | Path storage | Stores reconstructed route |
| **unordered_map** | Name→ID lookup | O(1) station name search |
| **parent[] Array** | Path reconstruction | Traces back from destination to source |
| **OOP (Classes)** | MetroGraph, MetroStation | Encapsulates data and methods |

---

## 🛠️ Project Structure

```
MetroRoute/
├── backend/
│   ├── CLI/
│   │   └── main.cpp              # Main program with menu
│   ├── include/
│   │   ├── metro_graph.h         # Graph class header
│   │   └── metro_station.h       # Station class header
│   ├── src/
│   │   ├── metro_graph.cpp       # Graph implementation + Dijkstra
│   │   └── metro_station.cpp     # Station implementation
│   └── data/                     # (Reserved for data files)
├── docs/                         # Documentation
└── README.md
```

---

## ⚙️ Compilation & Execution

### **Windows (MinGW/G++)**

```bash
cd backend/CLI
g++ -o metroroute main.cpp ../src/metro_graph.cpp ../src/metro_station.cpp -I../include
metroroute.exe
```

### **Linux/macOS**

```bash
cd backend/CLI
g++ -o metroroute main.cpp ../src/metro_graph.cpp ../src/metro_station.cpp -I../include
./metroroute
```

### **Alternative (Compile from project root)**

```bash
g++ -o metroroute backend/CLI/main.cpp backend/src/metro_graph.cpp backend/src/metro_station.cpp -Ibackend/include
./metroroute
```

---

## 🖥️ Sample Output

```
====================================
       METROROUTE
  SMART METRO NAVIGATION SYSTEM
====================================
1. View All Stations
2. View Metro Network
3. Find Shortest Route
4. Exit
====================================
Enter your choice: 3

Enter source station: Prem Nagar
Enter destination station: Ballupur

========== SHORTEST ROUTE ==========
  Prem Nagar
      ↓
  ISBT
      ↓
  Clock Tower
      ↓
  Rajpur Road
      ↓
  EC Road
      ↓
  Race Course
      ↓
  Ballupur

====================================
Total Stops: 6
Estimated Travel Time: 27 minutes
Algorithm Used: Dijkstra's Algorithm
====================================
```

---

## 🧮 Algorithm Explanation

### **Why Dijkstra's Algorithm?**

- **BFS** finds route with fewest hops (ignores travel time)
- **Dijkstra** finds route with minimum total travel time ✅

Since metro connections have different travel times (weighted edges), Dijkstra is the correct choice.

### **Time Complexity**

- **O(E log V)** where E = edges (connections), V = vertices (stations)
- Efficient even for large metro networks

### **How It Works**

1. Start from source station
2. Use a **priority queue** (min-heap) to always pick the closest unvisited station
3. Update distances to neighboring stations
4. Repeat until destination is reached
5. Reconstruct path using **parent[] array**

---

## 📖 Viva Questions & Answers

### **Q: What is a graph?**
**A:** A data structure with nodes (stations) and edges (tracks). A weighted graph adds numbers (travel time) to edges.

### **Q: Why Dijkstra and not BFS?**
**A:** BFS treats all edges as equal. Our edges have different weights (travel times), so BFS gives wrong results. Dijkstra handles weights correctly.

### **Q: What is a priority queue?**
**A:** A min-heap that always returns the element with the smallest value. In Dijkstra, it always gives the closest unvisited station.

### **Q: Time complexity?**
**A:** O(E log V) — E = edges (connections), V = vertices (stations).

### **Q: What is OOP in your project?**
**A:** We created `MetroGraph` and `MetroStation` classes that bundle data (stations, connections) and methods (addStation, findRoute) together.

### **Q: What if source equals destination?**
**A:** We handle this as a special case: print "You are already at the destination" without running Dijkstra.

### **Q: What if station name is invalid?**
**A:** We validate using `unordered_map` lookup. If not found, display error message and return without crashing.

---

## ⚠️ Limitations

1. **Console-only** — No graphical interface
2. **Simulated network** — Not real GPS or live metro data
3. **No fare calculation** — Only shows travel time
4. **No interchange time** — Assumes instant line changes

---

## 🚀 Future Enhancements

1. Add GUI using Qt or web interface
2. Integrate real metro APIs for live delays
3. Calculate fare based on distance
4. Support multiple route options (fastest vs fewest stops)
5. Add real-time crowd density data
6. Mobile app version

---

## 🎓 Educational Value

This project demonstrates:
- Practical application of **graph algorithms**
- Real-world use of **Dijkstra's shortest path**
- **OOP principles** in C++
- **Data structure selection** (priority queue, adjacency list)
- **Input validation** and error handling
- Clean **code organization** and modularity

---

## 👥 Team

- **Project Type:** B.Tech CSE PBL Project
- **Language:** C++
- **Algorithm:** Dijkstra's Shortest Path
- **Compiler:** MinGW G++ / GCC

---

## 📄 License

This project is created for educational purposes as part of B.Tech CSE curriculum.

---

## 🙏 Acknowledgments

- Project structure inspired by CleanLink-PBL
- Metro network based on fictional Dehradun metro system
- Dijkstra's Algorithm implementation follows standard textbook approach

---

**Built with 💻 for PBL Project | C++ & Data Structures**
