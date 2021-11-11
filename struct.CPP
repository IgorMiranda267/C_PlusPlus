#include <iostream>
#define TAMANHO 3

using namespace std;

//PROTOTIPOS DAS FUNÇÕES
void calculo( );

struct cadastro
{
    int codigo = 0;
    float salario = 0.0F;
    float porcentagem  = 0.0F;
};

int main()
{  
    calculo( ); // CHAMADA DA FUNÇÃO
    return 0;
}

//FUNÇÕES
void calculo( )
{
    cadastro funcionario [TAMANHO];
    int codigo  = 0;
    float salario = 0.0f;

    //GAURDA AS INFORMAÇÕES NO VETOR
    funcionario[0].codigo = 310;
    funcionario[0].porcentagem = 0.05;

    funcionario[1].codigo = 456;
    funcionario[1].porcentagem = 0.07;

    funcionario[2].codigo = 885;
    funcionario[2].porcentagem = 0.097;

    cout << "\n DIGITE SEU SALARIO SEGUIDO DO CODIGO DO CARGO: ...\n" ;
    cin >> salario >> codigo;

    for (int i = 0; i < TAMANHO; i++) // LAÇO PARA LEITURA DO VETOR
    {
        if ( codigo ==  funcionario[i].codigo) // VERIFICA A IGUALDADE DOS CODIGOS
        {
            float novo_salario = 0;

            novo_salario = salario * funcionario[i].porcentagem;

            cout << "\n O salario atual e: " << salario << endl;
            cout << " O salario atualizado e: " << novo_salario + salario << endl;
            cout << " O aumento foi de:  " <<  salario * funcionario[i].porcentagem << endl;

            system("pause");
            return;
        }
    }

    for (int i = 0; i < TAMANHO; i++) // VERIFICA A IGUALDADE DOS CODIGOS
    {
           if ( codigo !=  funcionario[i].codigo)
        {
            float novo_salario = 0;

            cout << "\n O salario atual e: " << salario << endl;
            cout << " O salario atualizado e: " << salario + ( novo_salario = (salario * 0.15 )) << endl;
            cout << " O aumento foi de:  " <<  salario * 0.15 << endl;

            system("pause");
            return;
        }
    }
    
   return;
}

