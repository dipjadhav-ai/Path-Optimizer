# 🛣️ Path Optimizer Using Dijkstra's Algorithm (C++)

A C++ project that finds the cheapest route between two cities using **Dijkstra's Shortest Path Algorithm**. The road network is loaded from a text file, and the program outputs the minimum-cost path along with its total travel cost.

---

## 📌 Features

- Reads road network from a file (`roads.txt`)
- Represents the map using an adjacency list
- Uses Dijkstra's Algorithm for shortest path
- Displays:
  - Best route
  - Total travel cost
- Supports adding new cities automatically while reading the file

---

# 🛣️ Route Finder

A C++ application that finds the shortest path between two cities using **Dijkstra's Algorithm**. The road network is loaded from a `roads.txt` file, and the project is deployed through a **Node.js** server for easy access.

## 🚀 Features

- Finds the minimum-cost route between two cities
- Uses Dijkstra's Algorithm
- Reads road data from `roads.txt`
- Fast adjacency-list implementation
- Node.js deployment support

## 📂 Project Structure

```
.
├── logic/
│   ├── graph.cpp
│   ├── graph.h
│   ├── routeFinder.cpp
│   ├── routeFinder.h
│   ├── main2.cpp
│   ├── roads.txt
│   └── app.exe
│
├── web/
│   ├── public/
│   ├── node_modules/
│   ├── server.js
│   ├── package.json
│   └── package-lock.json
│
└── raw code/
```

## 📄 Input Format

Each line in `roads.txt`:

```
City1 City2 Distance
```

Example:

```
Delhi Mumbai 1400
Mumbai Pune 150
Pune Bangalore 840
```

## ▶️ Run Locally

### C++ Version

```bash
g++ logic/main2.cpp logic/graph.cpp logic/routeFinder.cpp -o RouteFinder
./RouteFinder
```

### Node.js Version

```bash
cd web
npm install
npm start
```

## ⚙️ Algorithm

- **Algorithm:** Dijkstra's Shortest Path
- **Time Complexity:** `O((V + E) log V)`
- **Space Complexity:** `O(V + E)`

## 🛠️ Tech Stack

- C++
- STL
- Node.js
- File Handling (`fstream`)

## 📌 Future Improvements

- Interactive map visualization
- Dynamic road updates
- Multiple shortest paths
- Case-insensitive city names

---


**Dip Rajhans Jadhav**

B.Tech Mechanical Engineering  
IIT Madras

Interested in:
- C++
- Data Structures & Algorithms
- Machine Learning
- Defence Engineering
