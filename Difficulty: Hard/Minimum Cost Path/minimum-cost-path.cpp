//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        int m = grid[0].size();
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        
        vector<int> delrow = {-1,1,0,0};
        vector<int> delcol = {0,0,1,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
           
            vis[r][c] =1;
 
            for(int i=0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
              
              if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] ==0) {
                  
                  vis[nr][nc] =1;
                  
                  if(nr==n-1 && nc==m-1){
                      return dis+grid[nr][nc];
                  }
                  
                  pq.push({dis+grid[nr][nc],{nr,nc}});
              }
            
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends