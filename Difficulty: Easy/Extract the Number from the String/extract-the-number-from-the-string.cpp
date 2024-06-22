//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
               string temp;
        vector<long long> ans;
        int n = sentence.size();

        for (int i = 0; i < n; i++) {
            if (isdigit(sentence[i])) {
                temp += sentence[i];
            } 
            else {
                
                if (!temp.empty()) {
                    if (temp.find('9') == string::npos) {
                        ans.push_back(stoll(temp));
                    }
                    temp.clear();
                }
            }
        }
        if (!temp.empty() && temp.find('9') == string::npos) {
            ans.push_back(stoll(temp));
        }

        if (ans.empty()) {
            return -1;
        }

        return *max_element(ans.begin(), ans.end());
        
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends