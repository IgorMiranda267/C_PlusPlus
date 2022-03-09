#include <iostream>
#include <stack>

/* <stack> ( pilha ) é uma biblioteca ultilizada para implementarmos uma pilha
    last-in first-out, ou ultimo a entrar será o primeiro a sair!

    FUNÇÕES:
    .push()   Permite empilhar valores na pilha
    .top()    Retorna o elemento no topo da pilha sem exclui-lo
    .pop()    Remove o elemento mas nao retorna
    .empty()  Retorna true caso a pilha esteja vazia
*/
using namespace std;

int main()
{
    stack<int> pilha;

    //Preenche a pilha com 10 elementos.
    for (int i = 0; i < 10; i++)
    {
        pilha.push(i);
    }


    for (int i = 0; i < 10; i++)
    {
        cout << pilha.top() << endl; // Retira 1 elemento a cada laço
        pilha.pop();

        if (pilha.empty()) // Quando a pilha estiver vazia retorna a condição.
        {
            cout << "Pilha Vazia" << endl;
        }
    }

    return 0;
}