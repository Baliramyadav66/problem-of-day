//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#define vi std::vector<int>
#define vvi std::vector<vi>
#define ppi std::pair<int, std::pair<int, int>>

class Solution {
public:
    int MinimumEffort(int r, int c, std::vector<std::vector<int>> &heights) {
        // Priority queue to store cells with their current effort; min-heap based on effort
        std::priority_queue<ppi, std::vector<ppi>, std::greater<ppi>> pq;
        // Distance vector to store the minimum effort required to reach each cell
        std::vector<std::vector<int>> distance(r, std::vector<int>(c, 1e9));
        distance[0][0] = 0; // Starting point effort is 0
        pq.push({0, {0, 0}}); // Push the starting cell into the priority queue
        
        // Direction vectors for moving up, down, left, and right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        // Process the priority queue until empty
        while (!pq.empty()) {
            auto top = pq.top();
            int dist = top.first;
            int x = top.second.first;
            int y = top.second.second;
            pq.pop();
            
            // Traverse through all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                // Check if the new position is within bounds
                if (newX >= 0 && newY >= 0 && newX < r && newY < c) {
                    // Calculate the effort to move to the new cell
                    int newDist = std::abs(heights[newX][newY] - heights[x][y]);
                    newDist = std::max(newDist, dist); // Update effort to the maximum encountered
                    
                    // If this new effort is smaller, update the distance and push to the queue
                    if (newDist < distance[newX][newY]) {
                        distance[newX][newY] = newDist;
                        pq.push({newDist, {newX, newY}});
                    }
                }
            }
        }
        
        // Return the minimum effort required to reach the bottom-right corner
        return distance[r-1][c-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends