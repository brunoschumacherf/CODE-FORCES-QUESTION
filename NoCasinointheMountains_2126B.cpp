// Bruno Schumacher Farias Souza - 202121316
// Gabriel de Souza Matheus Oliveira - 202121097
// Guilherme Sampaio Borges Santana - 202220025

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        int i = 0;
        while (i + k <= n) {
            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans++;
                i += k + 1;
            } else {
                i++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
