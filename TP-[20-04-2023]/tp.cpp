#include <iostream>
using namespace std;

struct Funcionario
{
    int prontuario;
    string nome;
    double salario;
};

struct Lista
{
    Funcionario *funcionario;
    struct Lista *prox;
};

Lista *init()
{
    return NULL;
}

int isEmpty(Lista *lista)
{
    return (lista == NULL);
}

Lista *insert(Lista *lista, Funcionario *funcionario)
{
    Lista *novo = new Lista();
    novo->funcionario = funcionario;
    novo->prox = lista;
    return novo;
}

void print(Lista *lista)
{
    Lista *aux = lista;
    int salarioSum = 0;
    while (aux != NULL)
    {
        cout << "Prontuario: " << aux->funcionario->prontuario << endl;
        cout << "Nome: " << aux->funcionario->nome << endl;
        cout << "Salario: " << aux->funcionario->salario << endl;
        cout << endl;
        salarioSum += aux->funcionario->salario;
        aux = aux->prox;
    }
    cout << "Soma dos salarios: " << salarioSum << endl;
}

Lista *find(Lista *lista, int prontuario)
{
    Lista *aux = lista;

    while (aux != NULL && aux->funcionario->prontuario != prontuario)
    {
        aux = aux->prox;
    }
    return aux;
}

Lista *remove(Lista *lista, int prontuario)
{
    Lista *ant = NULL;
    Lista *aux = lista;

    while (aux != NULL && aux->funcionario->prontuario != prontuario)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return lista;
    }
    if (ant == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }
    free(aux);
    return lista;
}

Lista *insertOption(Lista *lista)
{
    Funcionario *funcionario = new Funcionario();
    cout << "Digite o prontuario: ";
    int prontuario;
    cin >> prontuario;
    bool prontuarioExiste = find(lista, prontuario) != NULL;
    while (prontuarioExiste)
    {
        cout << "Prontuario ja existe!" << endl;
        cout << "Digite o prontuario: ";
        cin >> prontuario;
        prontuarioExiste = find(lista, prontuario) != NULL;
    }
    funcionario->prontuario = prontuario;
    cout << "Digite o nome: ";
    cin >> funcionario->nome;
    cout << "Digite o salario: ";
    cin >> funcionario->salario;
    cout << endl;
    lista = insert(lista, funcionario);
    cout << endl;
    return lista;
}

int optionsMessage()
{
    cout << "0. Sair" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Pesquisar" << endl;
    cout << "4. Listar" << endl;
    cout << endl;
    cout << "Digite a opcao: ";
    cout << endl;
    int opcao;
    cin >> opcao;
    return opcao;
}

Lista *options(int opcao, Lista *lista)
{
    Lista *funcionario = nullptr;
    switch (opcao)
    {
    case 0:
        cout << "Saindo..." << endl;
        break;
    case 1:
        cout << "Incluindo..." << endl;
        lista = insertOption(lista);
        cout << endl;
        break;
    case 2:
        cout << "Excluindo..." << endl;
        cout << "Digite o prontuário do funcionário: ";
        int prontuario;
        cin >> prontuario;
        cout << endl;
        lista = remove(lista, prontuario);
        cout << endl;
        break;
    case 3:
        cout << "Pesquisando..." << endl;
        cout << "Digite o prontuário do funcionário: ";
        int prontuarioPesquisa;
        cin >> prontuarioPesquisa;
        cout << endl;
        funcionario = find(lista, prontuarioPesquisa);
        if (funcionario != NULL)
        {
            cout << "Prontuario: " << funcionario->funcionario->prontuario << endl;
            cout << "Nome: " << funcionario->funcionario->nome << endl;
            cout << "Salario: " << funcionario->funcionario->salario << endl;
            cout << endl;
        }
        else
        {
            cout << "Funcionario nao encontrado!" << endl;
            cout << endl;
        }
        break;
    case 4:
        cout << "Listando..." << endl;
        cout << endl;
        print(lista);
        cout << endl;
        break;
    }

    return lista;
}

int main(int argc, char **argv)
{

    Funcionario *funcionario1 = new Funcionario();
    funcionario1->prontuario = 1;
    funcionario1->nome = "Joao";
    funcionario1->salario = 1000.0;

    Funcionario *funcionario2 = new Funcionario();
    funcionario2->prontuario = 2;
    funcionario2->nome = "Maria";
    funcionario2->salario = 2000.0;

    Funcionario *funcionario3 = new Funcionario();
    funcionario3->prontuario = 3;
    funcionario3->nome = "Jose";
    funcionario3->salario = 3000.0;

    Lista *minhaLista;
    int opcao = -1;
    minhaLista = init();
    do
    {
        opcao = optionsMessage();
        minhaLista = options(opcao, minhaLista);
    } while (opcao != 0);
    // minhaLista = options(minhaLista);
    // print(minhaLista);
    // minhaLista = insert(minhaLista, funcionario1);
    // minhaLista = insert(minhaLista, funcionario2);
    // minhaLista = insert(minhaLista, funcionario3);
    // print(minhaLista);

    // Lista *procurado;
    // procurado = find(minhaLista, funcionario1);
    // if (procurado != NULL)
    // {
    //     cout << "Achou" << endl;
    //     cout << procurado->funcionario->nome << endl;
    //     cout << endl;
    // }
    // else
    // {
    //     cout << "Năo achou" << endl;
    //     cout << endl;
    // }

    // minhaLista = remove(minhaLista, funcionario2);
    // print(minhaLista);

    return 0;
}
