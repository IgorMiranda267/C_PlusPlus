#include <iostream>
#include <chrono> // Manipulação de tempo

using namespace std;

//Prototipo da Função
void tempLeitura ();

int main()
{
    //captura o tempo inical e final após a chamada da função.
    auto tempoInicial = chrono::high_resolution_clock::now();
    tempLeitura();
    auto tempoFinal = chrono::high_resolution_clock::now();

    //Calcula o tempo e converte para horas, minutos e segundos
    auto int_h = chrono::duration_cast <chrono::hours> (tempoFinal - tempoInicial);
    auto int_m = chrono::duration_cast <chrono::minutes> (tempoFinal - tempoInicial);
    auto int_s = chrono::duration_cast <chrono::seconds> (tempoFinal - tempoInicial);
 
    cout << " O formato e hh:mm:ss " << endl;
    cout << " O tempo de execucao foi " << int_h.count() << ":"<< int_m.count() << ":" << int_s.count() << endl;
    return 0;

}

void tempLeitura (){
    int numUsuario = 0;

    cout << "Digite um numero interiro" << endl;
    cin >> numUsuario;
}
