#include <iostream>
#include <locale.h>
using namespace std;
class Contato
{
private:
    string nome;
    string telefone;
    string email;
    int idade;

public:
    Contato(string nome, string telefone, string email, int idade)
    {
        this->nome = nome;
        this->telefone = telefone;
        this->email = email;
        this->idade = idade;
    }
    Contato()
    {
        this->nome = "";
        this->telefone = "";
        this->email = "";
        this->idade = 0;
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
    void setDataNascimento(int idade)
    {
        this->idade = idade;
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
    int getIdade()
    {
        return this->idade;
    }
};

int main()
{
    setlocale(LC_ALL, "");

    Contato *contatos = new Contato[10];
    int mediaIdade = 0;
    int maiorIdade = 0;
    int qtdMaiorIdade = 0;
    cout << "Cadastro de contatos (10)\n"
         << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Contato " << i + 1 << "\n";
        string nome, telefone, email;
        int idade;
        cout << "Digite o nome: ";
        cin >> nome;
        cout << "Digite o telefone: ";
        cin >> telefone;
        cout << "Digite o email: ";
        cin >> email;
        cout << "Digite a sua idade: ";
        cin >> idade;
        mediaIdade += idade;
        if (idade > maiorIdade)
        {
            maiorIdade = idade;
        }
        if (idade >= 18)
        {
            qtdMaiorIdade++;
        }
        contatos[i] = Contato(nome, telefone, email, idade);
        cout << endl;
    }
    mediaIdade /= 10;
    cout << "Média das idades: " << mediaIdade << endl;
    cout << "Contatos com idade maior que a média: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (contatos[i].getIdade() > mediaIdade)
        {
            cout << contatos[i].getNome() << endl;
        }
    }
    cout << "Quantidade de contatos maiores de idade: " << qtdMaiorIdade << endl;
    cout << "Contato(s) mais velho(s): " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (contatos[i].getIdade() == maiorIdade)
        {
            cout << "Nome: " << contatos[i].getNome() << endl;
            cout << "Telefone: " << contatos[i].getTelefone() << endl;
            cout << "Email: " << contatos[i].getEmail() << endl;
        }
    }

    return 0;
}