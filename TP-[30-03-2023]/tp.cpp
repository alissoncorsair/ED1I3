#include <iostream>
#include <locale.h>
using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    Data()
    {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
    void setCurrentDate()
    {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        this->dia = now->tm_mday;
        this->mes = now->tm_mon + 1;
        this->ano = now->tm_year + 1900;
    }
    void setDia(int dia)
    {
        this->dia = dia;
    }
    void setMes(int mes)
    {
        this->mes = mes;
    }
    void setAno(int ano)
    {
        this->ano = ano;
    }
    int getDia()
    {
        return this->dia;
    }
    int getMes()
    {
        return this->mes;
    }
    int getAno()
    {
        return this->ano;
    }
    string getData()
    {
        return to_string(this->dia) + "/" +
               to_string(this->mes) + "/" +
               to_string(this->ano);
    }

    Data *dia_seguinte()
    {
        Data *d1;
        int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        d1 = new Data(this->dia, this->mes, this->ano);
        if (d1->ano % 4 == 0)
        {
            diasNoMes[1]++;
        }
        d1->dia++;
        if (d1->dia > diasNoMes[d1->mes - 1])
        {
            d1->dia = 1;
            if (++d1->mes > 12)
            {
                d1->mes = 1;
                d1->ano++;
            }
        }
        return d1;
    }
};

class Contato
{
private:
    string nome;
    string telefone;
    string email;
    Data *dataNascimento;

public:
    Contato(string nome, string telefone, string email, Data *dataNascimento)
    {
        this->nome = nome;
        this->telefone = telefone;
        this->email = email;
        this->dataNascimento = dataNascimento;
    }
    Contato()
    {
        this->nome = "";
        this->telefone = "";
        this->email = "";
        this->dataNascimento = new Data();
    }
    void setNome(string nome)
    {
        this->nome = nome;
    }
    void setTelefone(string telefone)
    {
        this->telefone = telefone;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setDataNascimento(Data *dataNascimento)
    {
        this->dataNascimento = dataNascimento;
    }
    string getNome()
    {
        return this->nome;
    }
    string getTelefone()
    {
        return this->telefone;
    }
    string getEmail()
    {
        return this->email;
    }
    Data *getDataNascimento()
    {
        return this->dataNascimento;
    }
    int idade()
    {
        Data *hoje = new Data();
        hoje->setCurrentDate();
        int idade = hoje->getAno() - this->dataNascimento->getAno();
        if (hoje->getMes() < this->dataNascimento->getMes())
        {
            idade--;
        }
        else if (hoje->getMes() == this->dataNascimento->getMes())
        {
            if (hoje->getDia() < this->dataNascimento->getDia())
            {
                idade--;
            }
        }
        return idade;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Contato *contatos = new Contato[5];

    cout << "Cadastro de contatos (5)\n"
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Contato " << i + 1 << "\n";
        string nome, telefone, email;
        int dia, mes, ano;
        cout << "Digite o nome: ";
        cin >> nome;
        cout << "Digite o telefone: ";
        cin >> telefone;
        cout << "Digite o email: ";
        cin >> email;
        cout << "Digite o dia de nascimento: ";
        cin >> dia;
        cout << "Digite o mes de nascimento: ";
        cin >> mes;
        cout << "Digite o ano de nascimento: ";
        cin >> ano;
        Data *dataNascimento = new Data(dia, mes, ano);
        contatos[i] = Contato(nome, telefone, email, dataNascimento);
        cout << endl;
    }

    cout << "\nContatos salvos! Lista:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Idade: " << contatos[i].idade() << endl;
        cout << endl;
    }

    return 0;
}