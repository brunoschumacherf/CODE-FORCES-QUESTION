// Bruno Schumacher Farias Souza - 202121316
// Gabriel de Souza Matheus Oliveira - 202121097
// Guilherme Sampaio Borges Santana - 202220025

#include <stdio.h>

int losango(int n)
{
    if (n == 1)
        return 1;
    else
        return losango(n - 1) + 4 * (n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", losango(n));
    return 0;
}