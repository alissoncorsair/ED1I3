/**
 * Alisson de Sousa 
 * Leonardo de Fontes
*/
#include <iostream>
using namespace std;

#define MAX 30

struct Pilha
{
	int qtde;
	float elementos[MAX];
};

Pilha *init()
{
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p)
{
	return (p->qtde == 0);
}

int count(Pilha *p)
{
	return (p->qtde);
}

void freePilha(Pilha *p)
{
	free(p);
}

int push(Pilha *p, float v)
{
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar)
	{
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p)
{
	float v;
	int podeDesempilhar = (!isEmpty(p));
	if (podeDesempilhar)
	{
		v = p->elementos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;
}

void print(Pilha *p)
{
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "-----------------------" << endl;
	for (int i = p->qtde - 1; i >= 0; --i)
	{
		cout << p->elementos[i] << endl;
	}
	cout << "-----------------------" << endl;
}

int main(int argc, char **argv)
{
	Pilha *pilhaPar = init();
	Pilha *pilhaImpar = init();
	Pilha *pilha = init();
	int numero;
	cout << "Digite 30 números inteiros em ordem crescente:" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "Digite o " << i + 1 << "º número: ";
		cin >> numero;

		while (numero <= pilha->elementos[pilha->qtde - 1])
		{
			cout << "O número digitado deve ser maior do que o anterior." << endl;
			cout << "Digite o " << i + 1 << "º número: ";
			cin >> numero;
		}
		push(pilha, numero);
		if (numero % 2 == 0)
		{
			push(pilhaPar, numero);
		}
		else
		{
			push(pilhaImpar, numero);
		}
	}
	cout << "Pilha de números pares:" << endl;
	print(pilhaPar);
	cout << "Pilha de números ímpares:" << endl;
	print(pilhaImpar);
	cout << "Desempilhando pilha de números pares..." << endl;
	while (!isEmpty(pilhaPar))
	{
		pop(pilhaPar);
	}
	cout << "Desempilhando pilha de números ímpares..." << endl;
	while (!isEmpty(pilhaImpar))
	{
		pop(pilhaImpar);
	}
	freePilha(pilhaPar);
	freePilha(pilhaImpar);
	while (!isEmpty(pilha))
	{
		cout << pop(pilha) << endl;
	}
	freePilha(pilha);

	return 0;
}