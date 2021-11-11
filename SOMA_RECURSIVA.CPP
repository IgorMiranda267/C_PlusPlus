#include <iostream>

using namespace std;

//PROTOTIPO DA FUNCÃO
int Soma_vet(int tam, int vet[]);

int main()
{
    int n = 0, vet[n];

    cout << " DIGITE QUANTOS NUMERO DESEJA SOMAR, EM SEGUIDA DIGIT-OS: " << endl;
    cin >> n;

    //RECEBENDOS OS VALORES DO VETOR
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    // IMPRESSÃO DA SOMA DOS RESULTADOS
    cout << "o valor da some " << Soma_vet(n, vet) << endl;
    
    system ("pause");
    return 0;
}

// FUNÇÕES
int Soma_vet(int tam, int vet[])
{
    if (tam == 0) // CONDIÇÃO DE PARADA
    {
        return 0;
    }
    else //SOMA DOS VALORES DO VETOR
    {
        return vet[tam - 1] + Soma_vet(tam - 1, vet);
    }
}
