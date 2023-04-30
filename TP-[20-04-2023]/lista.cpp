#include <iostream>
using namespace std;

struct Lista
{
    int dado;
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

Lista *insert(Lista *lista, int i)
{
    Lista *novo = new Lista();
    novo->dado = i;
    novo->prox = lista;
    return novo;
}

void print(Lista *lista)
{
    Lista *aux = lista;

    while (aux != NULL)
    {
        cout << "Dado: " << aux->dado << endl;
        aux = aux->prox;
    }
}

Lista *find(Lista *lista, int i)
{
    Lista *aux = lista;

    while (aux != NULL && aux->dado != i)
    {
        aux = aux->prox;
    }
    return aux;
}

Lista *remove(Lista *lista, int i)
{
    Lista *ant = NULL;
    Lista *aux = lista;

    while (aux != NULL && aux->dado != i)
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

int main(int argc, char **argv)
{
    Lista *minhaLista;
    minhaLista = init();
    minhaLista = insert(minhaLista, 5);
    minhaLista = insert(minhaLista, 7);
    minhaLista = insert(minhaLista, 10);
    print(minhaLista);

    Lista *procurado;
    procurado = find(minhaLista, 7);
    if (procurado != NULL)
    {
        cout << "Achou" << endl;
        cout << procurado->dado << endl;
    }
    else
    {
        cout << "Năo achou" << endl;
    }

    minhaLista = remove(minhaLista, 160);
    print(minhaLista);

    return 0;
}
