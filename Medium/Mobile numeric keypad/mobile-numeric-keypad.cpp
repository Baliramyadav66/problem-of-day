//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    ll fun(int i, int j, int n, vector<vector<vector<ll>>> &dp) {
        if(i<0 || j<0 || i>3 || j>2 || (i==3 && (j==0 || j==2))) return 0;
        if(n==0) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        return dp[i][j][n] = fun(i,j,n-1,dp)+ fun(i-1,j,n-1,dp)+ fun(i+1,j,n-1,dp)
                        + fun(i,j-1,n-1,dp)+ fun(i,j+1,n-1,dp);
    }
    
    ll getCount(int n) {
        ll ans=0;
        vector<vector<vector<ll>>> dp(4, vector<vector<ll>> (3, vector<ll> (n, -1)));
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) ans+=fun(i,j,n-1,dp);
        }
        ans+=fun(3,1,n-1,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends