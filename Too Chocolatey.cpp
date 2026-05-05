#include<bits/stdc++.h>
using namespace std;
string solve (int n, vector<int> arr) {
sort(arr.begin(), arr.end(), greater<int>());
    unordered_set<int> alex_used, bob_used;
    long long alex = 0, bob = 0;
    bool alex_turn = true;
    for (int i = 0; i < n; i++) {
        if (alex_turn) 
        {
            if (alex_used.find(arr[i]) == alex_used.end()) 
            {
                alex += arr[i];
                alex_used.insert(arr[i]);
                alex_turn = false;
            }
        } else 
        {
            if (bob_used.find(arr[i]) == bob_used.end()) 
            {
                bob += arr[i];
                bob_used.insert(arr[i]);
                alex_turn = true;
            }
        }
    }

    if (alex > bob)
        return "Alex";
    else
        return "Bob"; 
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i_arr = 0; i_arr < n; i_arr++)
        {
        	cin >> arr[i_arr];
        }
        string out_;
        out_ = solve(n, arr);
        cout << out_;
        cout << "\n";
    }
}
