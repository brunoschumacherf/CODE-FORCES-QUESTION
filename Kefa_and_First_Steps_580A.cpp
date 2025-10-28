//Bruno Schumacher Farias Souza 202121316
//Guilherme Sampaio Borges Santana 202220025
//Gabriel de Souza Matheus Oliveira 202121097

#include <iostream>
#include <vector>
using namespace std;

vector<long long> numeros;
vector<int> guardado;

// calcula o tamanho da sequencia nao decrescente ate a posicao atual
int conta(int pos) {
    if (pos == 0) return 1; // primeiro numero forma sequencia de tamanho 1
    if (guardado[pos] != -1) return guardado[pos]; // retorna o valor guardado

    if (numeros[pos] >= numeros[pos - 1]) {
        // se nao diminui, soma 1 ao tamanho anterior
        guardado[pos] = conta(pos - 1) + 1;
    } else {
        // começa nova sequeia
        guardado[pos] = 1;
    }

    return guardado[pos];
}

int main() {
    int n;
    cin >> n;

    numeros.resize(n);
    guardado.assign(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int maior = 1;

    for (int i = 0; i < n; i++) {
        int atual = conta(i);
        if (atual > maior) maior = atual;
    }

    cout << maior << endl;

    return 0;
}
