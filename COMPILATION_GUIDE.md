# How to Compile and Run MetroRoute

## Windows (MinGW/G++)

### Step 1: Open Command Prompt
Press `Win + R`, type `cmd`, press Enter

### Step 2: Navigate to project folder
```bash
cd C:\Users\asus\AppData\Local\Claude-3p\local-agent-mode-sessions\375b585d\00000000\436c9b76\outputs\MetroRoute\backend\CLI
```

### Step 3: Compile the program
```bash
g++ -o metroroute.exe main.cpp ../src/metro_graph.cpp ../src/metro_station.cpp -I../include
```

### Step 4: Run the program
```bash
metroroute.exe
```

---

## Linux/macOS

### Step 1: Open Terminal

### Step 2: Navigate to project folder
```bash
cd /path/to/MetroRoute/backend/CLI
```

### Step 3: Compile the program
```bash
g++ -o metroroute main.cpp ../src/metro_graph.cpp ../src/metro_station.cpp -I../include
```

### Step 4: Run the program
```bash
./metroroute
```

---

## Troubleshooting

### Error: "g++ is not recognized"
**Solution:** Install MinGW from https://www.mingw-w64.org/ and add it to PATH

### Error: "No such file or directory"
**Solution:** Make sure you're in the `backend/CLI` directory before compiling

### Error: Compilation warnings
**Solution:** These are usually safe to ignore for this project

---

## What to Say During Compilation Demo

"I'll now compile and run the program. I'm using g++ compiler with three source files - main.cpp, metro_graph.cpp, and metro_station.cpp. The -I flag tells the compiler where to find the header files."

[Run compilation command]

"The program compiled successfully. Now I'll run it."

[Run the executable]

"As you can see, the menu appears. Let me demonstrate finding a route..."

[Type 3, then enter source and destination]
