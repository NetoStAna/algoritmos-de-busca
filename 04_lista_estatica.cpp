#include "03_lista_estatica.h"

#include <iostream>
#include <cstddef>
#include <math.h>

using namespace std;

Lista::Lista(int quantidade_max)
{
    this->quantidade_max = quantidade_max;
    this->lista = new Individuo[this->quantidade_max];
}
Lista::~Lista()
{
    delete [] this->lista;
}

bool Lista::esta_vazia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            return false;
        }
    }
    return true;
}
bool Lista::esta_cheia()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            return false;
        }
    }
    return true;
}
int Lista::quantidade_itens()
{
    int count = 0;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            count++;
        }
    }
    return count;
}

bool Lista::inserir(Individuo individuo)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == -1)
        {
            this->lista[i] = individuo;

            return true;
        }
    }
    return false;
}
Individuo Lista::remover(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            Individuo removido;

            removido = this->lista[i];
            this->lista[i] = generico;

            return removido;
        }
    }
    return generico;
}

Individuo Lista::busca_linear(int id)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
    }
    Individuo generico;

    return generico;
}
Individuo Lista::busca_ordenada(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
        else if (this->lista[i].get_id() > id)
        {
            return generico;
        }
    }

    return generico;
}
Individuo Lista::busca_binaria(int id)
{
    int inicio = 0;
    int meio;
    int fim = this->quantidade_max - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (this->lista[meio].get_id() > id)
        {
            fim = meio - 1;
        }
        else if (this->lista[meio].get_id() < id)
        {
            inicio = meio + 1;
        }
        else
        {
            return this->lista[meio];
        }
    }
    Individuo generico;

    return generico;
}

void Lista::imprimir()
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
        if (this->lista[i].get_id() != -1)
        {
            cout << "\tIndivíduo id: " << this->lista[i].get_id() << ", ";
            cout << "Nome: " << this->lista[i].get_nome() << endl;
        }
    }
}

void Lista::merge_sort()
{
    this->merge_recursion(this->lista, 0, this->quantidade_max - 1);
}

void Lista::merge_recursion(Individuo *lista, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);

        this->merge_recursion(lista, inicio, meio);
        this->merge_recursion(lista, meio + 1, fim);

        this->merge(lista, inicio, meio, fim);
    }
}
void Lista::merge(Individuo *lista, int inicio, int meio, int fim)
{
    int primeira_metade = inicio;
    int segunda_metade = meio + 1;
    int quantidade = fim - inicio + 1;
    bool fim_primeira_metade = false, fim_segunda_metade = false;
    Individuo *temporario = new Individuo[quantidade];

    if (temporario != NULL)
    {
        for (int i = 0; i < quantidade; i++)
        {
            if (!fim_primeira_metade && !fim_segunda_metade)
            {
                if (lista[primeira_metade].get_id() < lista[segunda_metade].get_id())
                {
                    temporario[i] = lista[primeira_metade++];
                }
                else
                {
                    temporario[i] = lista[segunda_metade++];
                }
                
                if (primeira_metade > meio)
                {
                    fim_primeira_metade = true;
                }

                if (segunda_metade > fim)
                {
                    fim_segunda_metade = true;
                }
            }
            else
            {
                if (!fim_primeira_metade)
                {
                    temporario[i] = lista[primeira_metade++];
                }
                else
                {
                    temporario[i] = lista[segunda_metade++];
                }
            }
        }
        
        for (int j = 0, k = inicio; j < quantidade; j++, k++)
        {
            lista[k] = temporario[j];
        }
    }
    delete [] temporario;
}
