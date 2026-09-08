#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    int x, y;

    bool operator==(const Node &other) const {
        return x == other.x && y == other.y;
    }
};

struct State {
    int k1, k2;
    Node u;

    bool operator>(const State &other) const {
        if (k1 != other.k1)
            return k1 > other.k1;
        return k2 > other.k2;
    }
};

class DStarLite {
public:
    int n, m;

    Node start, goal;
    Node last;

    vector<vector<int>> grid;
    vector<vector<int>> g, rhs;

    priority_queue<State, vector<State>, greater<State>> pq;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    DStarLite(vector<vector<int>> &grid, Node start, Node goal) {
        this->grid = grid;

        n = grid.size();
        m = grid[0].size();

        this->start = start;
        this->goal = goal;

        last = start;

        g.assign(n, vector<int>(m, INF));
        rhs.assign(n, vector<int>(m, INF));

        rhs[goal.x][goal.y] = 0;

        auto key = calculateKey(goal);

        pq.push({key.first, key.second, goal});
    }

    bool valid(Node u) {
        return u.x >= 0 && u.x < n &&
               u.y >= 0 && u.y < m &&
               grid[u.x][u.y] == 0;
    }

    int heuristic(Node a, Node b) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    int getG(Node u) {
        return g[u.x][u.y];
    }

    int getRHS(Node u) {
        return rhs[u.x][u.y];
    }

    pair<int, int> calculateKey(Node u) {

        int val = min(getG(u), getRHS(u));

        return {
            val + heuristic(start, u),
            val
        };
    }

    vector<Node> getNeighbors(Node u) {

        vector<Node> ans;

        for (int i = 0; i < 4; i++) {

            Node v = {
                u.x + dx[i],
                u.y + dy[i]
            };

            if (valid(v))
                ans.push_back(v);
        }

        return ans;
    }

    int cost(Node u, Node v) {

        if (!valid(u) || !valid(v))
            return INF;

        return 1;
    }

    void updateVertex(Node u) {

        if (!(u == goal)) {

            int mn = INF;

            for (Node v : getNeighbors(u)) {

                mn = min(
                    mn,
                    cost(u, v) + getG(v)
                );
            }

            rhs[u.x][u.y] = mn;
        }

        // Remove old copies lazily.
        // If g != rhs, insert the new key.
        if (getG(u) != getRHS(u)) {

            auto key = calculateKey(u);

            pq.push({
                key.first,
                key.second,
                u
            });
        }
    }

    bool smaller(pair<int, int> a, pair<int, int> b) {

        if (a.first != b.first)
            return a.first < b.first;

        return a.second < b.second;
    }

    void computeShortestPath() {

        while (!pq.empty()) {

            State top = pq.top();

            Node u = top.u;

            auto k_old = make_pair(
                top.k1,
                top.k2
            );

            auto k_new = calculateKey(start);

            if (!smaller(k_old, k_new) &&
                getRHS(start) == getG(start))
                break;

            pq.pop();

            auto k_current = calculateKey(u);

            // Stale entry
            if (smaller(k_old, k_current)) {

                pq.push({
                    k_current.first,
                    k_current.second,
                    u
                });

                continue;
            }

            if (getG(u) > getRHS(u)) {

                g[u.x][u.y] = rhs[u.x][u.y];

                for (Node p : getNeighbors(u))
                    updateVertex(p);

            }
            else {

                g[u.x][u.y] = INF;

                updateVertex(u);

                for (Node p : getNeighbors(u))
                    updateVertex(p);
            }
        }
    }

    vector<Node> getPath() {

        vector<Node> path;

        Node cur = start;

        if (getG(start) == INF)
            return path;

        path.push_back(cur);

        while (!(cur == goal)) {

            int best = INF;
            Node next = cur;

            for (Node v : getNeighbors(cur)) {

                int val =
                    cost(cur, v) + getG(v);

                if (val < best) {

                    best = val;
                    next = v;
                }
            }

            if (next == cur)
                break;

            cur = next;
            path.push_back(cur);
        }

        return path;
    }

    void changeEdge(Node u, Node v, bool blocked) {

        if (blocked) {
            grid[v.x][v.y] = 1;
        }
        else {
            grid[v.x][v.y] = 0;
        }

        updateVertex(v);

        for (Node p : getNeighbors(v))
            updateVertex(p);
    }

    void moveStart(Node newStart) {

        last = start;
        start = newStart;

        computeShortestPath();
    }
};

int main() {

    vector<vector<int>> grid = {

        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    Node start = {0, 0};
    Node goal = {6, 6};

    DStarLite dstar(grid, start, goal);

    // Initial planning
    dstar.computeShortestPath();

    vector<Node> path = dstar.getPath();

    cout << "Initial Path:\n";

    for (auto u : path) {
        cout << "(" << u.x << ", "
             << u.y << ") ";
    }

    cout << "\n";

    // Suppose an obstacle appears
    // on the current path.

    cout << "\nObstacle detected!\n";

    Node blocked = {4, 3};

    dstar.changeEdge(
        {4, 2},
        blocked,
        true
    );

    // Re-plan
    dstar.computeShortestPath();

    path = dstar.getPath();

    cout << "\nNew Path:\n";

    for (auto u : path) {
        cout << "(" << u.x << ", "
             << u.y << ") ";
    }

    cout << "\n";

    return 0;
}
