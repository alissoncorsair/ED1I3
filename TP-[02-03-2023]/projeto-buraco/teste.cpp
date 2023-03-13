 #include <iostream>
using namespace std;

int Aux1 = 0;

const int MatrizY = 25;
const int MatrizX = 3;

int BaralhoOrg[MatrizX][MatrizY];
int BaralhoRan[MatrizX][MatrizY];

const int MaxNaipe = 4;
const int MaxCartas = 13;
const int MaxBaralho = 2;

int Naipe = 0;
int Carta = 0;
int Baralho = 0;

int main()
{
    cout << "oi" << endl;
    for (int i = 1; i <= MaxNaipe; i++)
    {
        Naipe += 1;
        for (int j = 0; j <= 25; j++)
        {
            for (int k = 10; k <= MaxCartas * 10; k += 10)
            {
                BaralhoOrg[Naipe][Carta + Aux1] = (Naipe * 1000) + k + Baralho;
                Carta = k / 10;
            }
            if (Baralho == 1)
            {
                Baralho = 2;
                Aux1 = 13;
            }
        }
    }

    for (int i = 0; i < MaxNaipe; i++)
    {
        for (int j = 0; j < MaxCartas * MaxBaralho; j++)
        {
            cout << BaralhoOrg[i][j] << "   ";
        }
        cout << endl;

        cout << "aaaaa";
    }

    return 0;
}