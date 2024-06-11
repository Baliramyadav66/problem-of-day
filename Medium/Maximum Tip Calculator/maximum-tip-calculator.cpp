//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#define mod 1000000007
#define ll long long

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        ll ans = 0;
        priority_queue<pair<ll, pair<ll, ll>>> pq;
        for(int i=0; i<n; i++){
            ll diff = abs(arr[i]-brr[i]);
            pq.push({diff, {(ll)arr[i], (ll)brr[i]}});
        }
        
        while(!pq.empty() && (x>0 || y>0)){
            ll a = pq.top().second.first;
            ll b = pq.top().second.second;
            pq.pop();
            
            if(a>b){
                if(x>0){
                    ans += a;
                    x--;
                }
                else{
                    ans += b;
                    y--;
                }
            }
            else{
                if(y>0){
                    ans += b;
                    y--;
                }
                else{
                    ans += a;
                    x--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends