# 🛣️ Path Optimizer Using Dijkstra's Algorithm (C++)

A simple C++ project that finds the cheapest route between two cities using **Dijkstra's Shortest Path Algorithm**. The road network is loaded from a text file, and the program outputs the minimum-cost path along with its total travel cost.

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

## 📂 Project Structure

```
.
├── main.cpp        # Source code
├── roads.txt       # Road network data
└── README.md
```

---

## 📖 Input File Format

The road network should be stored in a file named **roads.txt**.

Each line should contain:

```
City1 City2 Distance
```

### Example

```
Delhi Mumbai 1400
Mumbai Pune 150
Pune Bangalore 840
Delhi Jaipur 280
Jaipur Ahmedabad 670
Ahmedabad Mumbai 530
```

The graph is considered **undirected**, so every road can be travelled in both directions.

---

## ▶️ How to Run

### Compile

```bash
g++ main.cpp -o RouteFinder
```

### Run

```bash
./RouteFinder
```

On Windows (MinGW)

```bash
g++ main.cpp -o RouteFinder.exe
RouteFinder.exe
```

---

## 💻 Example

### roads.txt

```
Delhi Mumbai 1400
Mumbai Pune 150
Pune Bangalore 840
Delhi Jaipur 280
Jaipur Ahmedabad 670
Ahmedabad Mumbai 530
```

### Input

```
Enter the city from to

Delhi Bangalore
```

### Output

```
Best route among all routes possible is:

Delhi->Mumbai->Pune->Bangalore->

Total Cost:2390
```

---

## ⚙️ Algorithm Used

The project uses **Dijkstra's Shortest Path Algorithm**.

### Time Complexity

Using a priority queue:

- **O((V + E) log V)**

where

- **V** = Number of cities
- **E** = Number of roads

### Space Complexity

```
O(V + E)
```

---

## 🏗️ Code Structure

### `graph`

Responsible for:

- Reading `roads.txt`
- Assigning IDs to cities
- Building the adjacency list

### `routeFinder`

Responsible for:

- Running Dijkstra's Algorithm
- Finding the shortest path
- Printing the final route

### `input`

Responsible for:

- Taking source and destination cities from the user

---

## 📚 Data Structures Used

- `unordered_map`
- `vector`
- `priority_queue`
- `pair`
- `fstream`

---

## 🚀 Future Improvements

- Directed road support
- Add/remove cities dynamically
- Save updated graph back to file
- Display multiple shortest paths
- GUI using Qt or SFML
- Interactive map visualization
- Road distance and travel time support
- A* Search Algorithm for faster routing
- Case-insensitive city search
- Better input validation

---

## 📝 Notes

- City names should not contain spaces in the current implementation.
- The file **roads.txt** must exist in the same directory as the executable.
- If no path exists, the program displays an appropriate message.

---

## 👨‍💻 Author

**Dip Rajhans Jadhav**

B.Tech Mechanical Engineering  
IIT Madras

Interested in:
- C++
- Data Structures & Algorithms
- Machine Learning
- Defence Engineering
