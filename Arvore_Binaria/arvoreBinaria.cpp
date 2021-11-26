#include <iostream>

using namespace std;

struct No
{
  int info;
  No *esquerdo, *direito;
};

struct arvoreBinaria
{
  No *raiz;
  No *inserir(int info, No *no_atual); // insere valores na arvore.
  No *remover(int info, No *no_atual);
  bool pesquisar(int info, No *no_atual);
  void criaArvoreBinaria(); // atribiu valor null ao nó raiz.
  void percorrerPreOrdem(No *no_atual);
  void percorrerEmOrdem(No *no_atual);
  void percorrerPosOrdem(No *no_atual);
};

void arvoreBinaria::criaArvoreBinaria()
{
  raiz = NULL; //Atribui um valor nulo ao nó raiz da arvore.
}

No *arvoreBinaria::inserir(int info, No *no_atual)
{
  //Nó atual é nulo.
  if (no_atual == NULL)
  {
    no_atual = new No;
    no_atual->info = info;
    no_atual->esquerdo = NULL;
    no_atual->direito = NULL;
    return no_atual;
  }
  //Aloca o valor no lado esqueso se for menor que no_atual
  else if (info < no_atual->info)
  {
    no_atual->esquerdo = inserir(info, no_atual->esquerdo);
    return no_atual;
  }
  //Aloca o valor > que o raiz no nó direito
  else if (info > no_atual->info)
  {
    no_atual->direito = inserir(info, no_atual->direito);
    return no_atual;
  }
}

No *arvoreBinaria::remover(int info, No *no_atual)
{
  No *no_temp;
  // Pesquisar

  // Não encontou o valor que queria remover
  if (no_atual == NULL)
  {
    return no_atual;
  }

  else if (info < no_atual->info)
  {
    no_atual->esquerdo = remover(info, no_atual->esquerdo);
  }

  else if (info > no_atual->info)
  {
    no_atual->direito = remover(info, no_atual->direito);
  }

  else
  { // no_atual tem o valor que estamos procurando

    // Caso 1: no_atual é folha
    if (no_atual->esquerdo == NULL && no_atual->direito == NULL)
    {
      delete no_atual;
      return NULL;
    }

    // Caso 2: no_atua é tem 1 filho
    else if (no_atual->esquerdo == NULL)
    {
      no_temp = no_atual->direito;
      delete no_atual;
      return no_temp;
    }
    else if (no_atual->direito == NULL)
    {
      no_temp = no_atual->esquerdo;
      delete no_atual;
      return no_temp;
    }

    // Caso 3: no_atua tem dois filhos
    else
    {
      no_temp = no_atual->direito;

      while (no_temp->esquerdo != NULL)
      {
        no_temp = no_temp->esquerdo;
      }

      no_atual->info = no_temp->info;

      no_atual->direito = remover(no_temp->info, no_atual->direito);
      return no_atual;
    }
  }
}

void arvoreBinaria::percorrerPreOrdem(No *no_atual)
{
  if (no_atual != NULL)
  {
    cout << no_atual->info << endl;
    percorrerEmOrdem(no_atual->esquerdo);
    percorrerEmOrdem(no_atual->direito);
  }
}

void arvoreBinaria::percorrerEmOrdem(No *no_atual)
{
  if (no_atual != NULL)
  {
    percorrerEmOrdem(no_atual->esquerdo);
    cout << no_atual->info << endl;
    percorrerEmOrdem(no_atual->direito);
  }
}

void arvoreBinaria::percorrerPosOrdem(No *no_atual)
{
  if (no_atual != NULL)
  {
    percorrerEmOrdem(no_atual->esquerdo);
    percorrerEmOrdem(no_atual->direito);
    cout << no_atual->info << endl;
  }
}

bool arvoreBinaria::pesquisar(int info, No *no_atual)
{

  if (no_atual == NULL)
  { //verifica se no atual e NULL
    return false;
  }
  else if (no_atual->info == info)
  {
    return true;
  }
  else
  {
    // Se o no_atual for menor que a info, atualiza o valor de info
    // como paramentro da função
    if (info < no_atual->info)
    {
      return pesquisar(info, no_atual->esquerdo);
    }
    else
    {
      return pesquisar(info, no_atual->direito);
    }
  }
}

int main()
{

  int info = 0, numLista = 0;
  char escolhaUsuario = 'S';

  arvoreBinaria arvore;
  arvore.criaArvoreBinaria();

  do {
    cout << "-------------------------------------------------" << endl;
    cout << "              Arvore Binaria" << endl;
    cout << "1 - Inserir:" << endl;
    cout << "2 - Remover:" << endl;
    cout << "3 - Pesquisar:" << endl;
    cout << "4 - Percorrer em Pre Ordem:" << endl;
    cout << "5 - Inserir em Ordem:" << endl;
    cout << "6 - Inserir em Pos Oedem:" << endl;
    cout << "-------------------------------------------------" << endl;

    cin >> numLista;
    

    switch (numLista)
    {
    case 1: //Inserir
      cout << "\nDigite o numero a Inserir:";
      cin >> info;
      arvore.raiz = arvore.inserir(info, arvore.raiz);
      break;

    case 2: //Remover
      cout << "\nDigite o numero a Remover:";
      cin >> info;
      arvore.raiz = arvore.remover(info, arvore.raiz);
      break;

    case 3: // Pesquisar
      cout << "\nDigite o numero a Pesquisar:";
      cin >> info;
      cout << arvore.pesquisar(info, arvore.raiz) << endl;
      break;

    case 4: // Pre ordem
      arvore.percorrerPreOrdem(arvore.raiz);
      break;

    case 5: // Em ordem
      arvore.percorrerEmOrdem(arvore.raiz);
      break;

    case 6: // Pos ordem
      arvore.percorrerPosOrdem(arvore.raiz);
      break;

    default:
      break;
    }

  cout << "\n(S) Para continar, ou (N) para sair:" << endl;
  cin >> escolhaUsuario;

  system("CLS");

  }while (escolhaUsuario == 's' || escolhaUsuario == 'S');

  return 0;
}