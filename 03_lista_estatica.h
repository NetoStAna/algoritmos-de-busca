#include "01_individuo.h"

using namespace std;

class Lista
{
private:
    int quantidade_max;
    Individuo *lista;
    
    void merge_recursion(Individuo *lista, int inicio, int fim);
    void merge(Individuo *lista, int inicio, int meio, int fim);
public:
    Lista(int quantidade_max);
    ~Lista();

    bool esta_vazia();
    bool esta_cheia();
    int quantidade_itens();

    bool inserir(Individuo individuo);
    Individuo remover(int id);

    Individuo busca_linear(int id);
    Individuo busca_ordenada(int id);
    Individuo busca_binaria(int id);

    void imprimir();

    void merge_sort();
};
