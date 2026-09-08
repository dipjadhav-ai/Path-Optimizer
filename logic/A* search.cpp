#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n, m;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool valid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < n &&
               y >= 0 && y < m &&
               grid[x][y] == 0;
    }

    int heuristic(int x, int y, int gx, int gy) {
        return abs(x - gx) + abs(y - gy);
    }

    vector<pair<int,int>> AStar(
        vector<vector<int>>& grid,
        pair<int,int> start,
        pair<int,int> goal
    ) {

        n = grid.size();
        m = grid[0].size();

        // {f, g, x, y}
        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<tuple<int,int,int,int>>
        > pq;

        vector<vector<int>> g(
            n, vector<int>(m, INT_MAX)
        );

        vector<vector<pair<int,int>>> parent(
            n, vector<pair<int,int>>(m, {-1, -1})
        );

        int sx = start.first;
        int sy = start.second;

        int gx = goal.first;
        int gy = goal.second;

        g[sx][sy] = 0;

        int h = heuristic(sx, sy, gx, gy);

        pq.push({h, 0, sx, sy});

        while (!pq.empty()) {

            auto [f, currG, x, y] = pq.top();
            pq.pop();

            // Ignore outdated state
            if (currG != g[x][y])
                continue;

            // Goal reached
            if (x == gx && y == gy)
                break;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!valid(nx, ny, grid))
                    continue;

                int newG = g[x][y] + 1;

                if (newG < g[nx][ny]) {

                    g[nx][ny] = newG;

                    parent[nx][ny] = {x, y};

                    int h = heuristic(
                        nx, ny,
                        gx, gy
                    );

                    int newF = newG + h;

                    pq.push({
                        newF,
                        newG,
                        nx,
                        ny
                    });
                }
            }
        }

        // No path
        if (g[gx][gy] == INT_MAX)
            return {};

        // Reconstruct path
        vector<pair<int,int>> path;

        int x = gx;
        int y = gy;

        while (x != -1 && y != -1) {

            path.push_back({x, y});

            auto p = parent[x][y];

            x = p.first;
            y = p.second;
        }

        reverse(path.begin(), path.end());

        return path;
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

    Solution obj;

    pair<int,int> start = {0, 0};
    pair<int,int> goal = {6, 6};

    vector<pair<int,int>> path =
        obj.AStar(grid, start, goal);

    cout << "Path:\n";

    for (auto p : path) {
        cout << "(" << p.first
             << ", " << p.second << ") ";
    }

    cout << "\n";

    return 0;
}
