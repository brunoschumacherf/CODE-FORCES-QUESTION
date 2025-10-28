//Bruno Schumacher Farias Souza 202121316
//Guilherme Sampaio Borges Santana 202220025
//Gabriel de Souza Matheus Oliveira 202121097

#include <bits/stdc++.h>
using namespace std;

// verifica se 'prefixo' +'sufixo' = '2020'
bool verificaPrefixoSufixo(const string &s, int prefixo, int sufixo) {
    int n = s.size();
    string formado = s.substr(0, prefixo) + s.substr(n - sufixo);
    return formado == "2020";
}

// testa combinações de prefixo + sufixo para formar "2020"
bool verifica2020Recursivo(int k, const string &s, vector<int> &dp) {
    if (k > 4) return false;                        // Passou todos os casos possiveis
    if (dp[k] != -1) return dp[k];                  // Resultado memorizado
    if (verificaPrefixoSufixo(s, k, 4 - k))        // Prefixo k + sufixo 4-k
        return dp[k] = true;
    return dp[k] = verifica2020Recursivo(k + 1, s, dp);  // proximo k
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> dp(5, -1);  // dp[k] = -1 significa nao calculado
        cout << (verifica2020Recursivo(0, s, dp) ? "YES" : "NO") << "\n";
    }

    return 0;
}
