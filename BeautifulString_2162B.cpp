// Bruno Schumacher Farias Souza - 202121316
// Gabriel de Souza Matheus Oliveira - 202121097
// Guilherme Sampaio Borges Santana - 202220025

#include <bits/stdc++.h>
using namespace std;

string s;
int n;

unordered_map<string, bool> memo;
unordered_map<string, string> path;

string key(int l, int r, int p_state) {
    return to_string(l) + "," + to_string(r) + "," + to_string(p_state);
}

bool dp_solve(int l, int r, int p_state) {
    if (l > r) return true;

    string k = key(l, r, p_state);
    if (memo.count(k)) return memo[k];

    if (l == r) {
        if (!(s[l] == '0' && p_state == 1)) {
            path[k] = "add_l_to_p";
            return memo[k] = true;
        }
        path[k] = "add_x";
        return memo[k] = true;
    }


    if (s[l] == s[r]) {
        if (dp_solve(l + 1, r - 1, p_state)) {
            path[k] = "match_x";
            return memo[k] = true;
        }
    }

    int new_p_state_l = p_state;
    bool valid_p_l = true;
    if (s[l] == '1') new_p_state_l = 1;
    else if (s[l] == '0' && p_state == 1) valid_p_l = false;

    if (valid_p_l && dp_solve(l + 1, r, new_p_state_l)) {
        path[k] = "add_l_to_p";
        return memo[k] = true;
    }

    int new_p_state_r = p_state;
    bool valid_p_r = true;
    if (s[r] == '1') new_p_state_r = 1;
    else if (s[r] == '0' && p_state == 1) valid_p_r = false;

    if (valid_p_r && dp_solve(l, r - 1, new_p_state_r)) {
        path[k] = "add_r_to_p";
        return memo[k] = true;
    }

    return memo[k] = false;
}

void reconstruct_path(int l, int r, int p_state, vector<int>& p_indices) {
    if (l > r) return;

    string k = key(l, r, p_state);
    string choice = path[k];

    if (l == r) {
        if (choice == "add_l_to_p") p_indices.push_back(l + 1);
        return;
    }

    if (choice == "match_x") {
        reconstruct_path(l + 1, r - 1, p_state, p_indices);
    } else if (choice == "add_l_to_p") {
        p_indices.push_back(l + 1);
        int new_p_state = (p_state == 1 || s[l] == '1') ? 1 : 0;
        reconstruct_path(l + 1, r, new_p_state, p_indices);
    } else if (choice == "add_r_to_p") {
        p_indices.push_back(r + 1);
        int new_p_state = (p_state == 1 || s[r] == '1') ? 1 : 0;
        reconstruct_path(l, r - 1, new_p_state, p_indices);
    }
}

void solve() {
    cin >> n >> s;
    memo.clear();
    path.clear();

    if (dp_solve(0, n - 1, 0)) {
        vector<int> p_indices;
        reconstruct_path(0, n - 1, 0, p_indices);
        sort(p_indices.begin(), p_indices.end());

        cout << p_indices.size() << "\n";
        for (int i = 0; i < (int)p_indices.size(); i++) {
            cout << p_indices[i] << (i + 1 < (int)p_indices.size() ? " " : "");
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
