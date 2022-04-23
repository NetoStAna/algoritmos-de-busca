#include "03_lista_estatica.h"

#include <iostream>

using namespace std;

int main()
{
    int menu, busca, id, idade, quantidade_max;
    float peso, altura;
    string nome;

    cout << "Algoritmos de busca!\n";

    cout << "Digite a quantidade máxima de indivíduos a serem inseridos na lista!\n";
    cin >> quantidade_max;

    Lista lista_individuos(quantidade_max);

    do
    {
        cout << "Digite 1 para inserir um indivíduo na lista!\n";
        cout << "Digite qualquer outro número inteiro para encerrar a inserção e realizar a busca na lista!\n";
        cin >> menu;

        if (menu == 1)
        {
            cout << "Digite o id do indivíduo: ";
            cin >> id;

            cout << "Digite o nome do individuo: ";
            cin >> nome;

            cout << "Digite a idade do indivíduo: ";
            cin >> idade;

            cout << "Digite o peso do indivíduo: ";
            cin >> peso;

            cout << "Digite a altura do indivíduo: ";
            cin >> altura;

            Individuo inserido(id, idade, peso, altura, nome);
            bool resultado = lista_individuos.inserir(inserido);

            if (resultado)
            {
                cout << "Indivíduo id: " << id << " inserido com sucesso!\n";
            }
            else
            {
                cout << "Indivíduo id: " << id << " não inserido, pois a lista está cheia!\n";
            }
        }
    } while (menu == 1);

    cout << "Digite 1 para realizar uma busca linear!\n";
    cout << "Digite 2 para realizar uma busca ordenada!\n";
    cout << "Digite qualquer outro número inteiro para realizar uma busca binária!\n";
    cin >> busca;

    cout << "Digite o id do indivíduo a ser buscado: ";
    cin >> id;

    Individuo buscado;

    if (busca == 1)
    {
        buscado = lista_individuos.busca_linear(id);
    }
    else
    {
        lista_individuos.merge_sort();

        if (busca == 2)
        {
            buscado = lista_individuos.busca_ordenada(id);
        }
        else
        {
            buscado = lista_individuos.busca_binaria(id);
        }
    }

    if (buscado.get_id() == -1)
    {
        cout << "Indivíduo id: " << id << " não se encontra na lista!\n";
    }
    else
    {
        cout << "Indivíduo id: " << id << endl;
        cout << "\tNome: " << buscado.get_nome() << endl;
        cout << "\tIdade: " << buscado.get_idade() << " anos\n";
        cout << "\tPeso: " << buscado.get_peso() << " kg\n";
        cout << "\tAltura: " << buscado.get_altura() << " m\n";
    }
    cout << "Fim do algoritmo!\n";

    return 0;
}
