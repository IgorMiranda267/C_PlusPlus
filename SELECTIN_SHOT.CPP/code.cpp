#include <iostream>
#include <algorithm> //biblioteca para swap.

#define TAM 5 //TAMANHO DO VETOR.

using namespace std;

//PROTOTIPOS DAS FUNÇÕES.
int Preencher(int vet[TAM]);
int Selectin_short(int vet[TAM]);
int verifica ( int vet[TAM], int ordenado);

int main()
{
    int vet[TAM], ordenado = 0;

    //CHAMADAS DAS FUNCÕES.
    Preencher(vet);
    verifica (vet, ordenado);
     Selectin_short(vet);
 

    return 0;
}

// FUNÇÕES.
int Preencher(int vet[TAM])
{
    cout << "Digite " << TAM << " valores inteiros: " << endl;

    for (int i = 0; i < TAM; i++) //PREENCHE O VETOR.
    {
        cin >> vet[i];
    }

    system("CLS"); //LIMPA A TELA.
    return (vet[TAM]);
}

int Selectin_short(int vet[TAM])
{
 
    for (int i = 0; i < TAM; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < TAM; j++)
        {
            if (vet[j] < vet[indice_menor])
            {
                indice_menor = j;
            }
        }

        swap(vet[i], vet[indice_menor]);
    }

    cout << "\n O vetor em ordem crescente  e:  ";

    for (int i = 0; i < TAM; i++)
    {
        cout << " " << vet[i];
    }
    system("pause");

    return 0;
}

//Esta função verifica se o vetor esta desordenado
int verifica ( int vet[TAM] , int ordenado)
{
    for (int i = 0; i < TAM; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < TAM; j++)
        {
            // Verifica se o primeiro vamor e menor que o segundo e assim por diante
            if (vet[j] < vet[indice_menor])
            {
                cout << " O vetor esta desordenado" << endl;
            }
        }break;
    }

}