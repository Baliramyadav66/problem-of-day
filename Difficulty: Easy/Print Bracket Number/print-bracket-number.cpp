//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
vector<int> bracketNumbers(string str) {
        vector<int> res;
        stack<char> st;
        unordered_map<int, bool> mp1;
        int top = 0;
        int count_open = 0;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '(')
            {
                st.push(str[i]);
                count_open++;
                top = count_open;
                res.push_back(count_open);
            }
            else if(str[i] == ')')
            {
                mp1[top] = true;
                res.push_back(top);
                st.pop();
                while(mp1.find(top)!=mp1.end())
                {
                    top--;
                }
            }
            
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends