# Algoritmos de Busca

Repositório contendo estudos de algoritmos de busca desenvolvidos na linguagem C++.



## Tipo de Dado

 Os algoritmos de busca presentes nesse repositório são aplicados sobre um vetor contendo elementos de uma classe denominada `Individuo`, contendo as variáveis `int`: id e idade; `float`: peso e altura; e `string`: nome.

```cpp
class Individuo
{
private:
    int id, idade;
    float peso, altura;
    string nome;
```

Para mais informações sobre a classe e a estrutura dos dados verifique a pasta sobre [Lista Sequencial Estática](https://github.com/NetoStAna/estruturas-de-dados/tree/main/01_lista_sequencial_estatica) em meu repositório sobre [Estruturas de Dados](https://github.com/NetoStAna/estruturas-de-dados).



## Tipos de Busca

Todos os algoritmos buscam um `Indivduo` no `vetor` através de seu `id`.



### Busca Linear

O método utiliza uma variável `int`: id como parâmetro, assim como, um laço `for` que pode percorrer todo o `vetor`.

```cpp
Individuo Lista::busca_linear(int id)
{
    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` do `Individuo` na posição `i` do `vetor` é comparado ao `id` recebido como parâmetro, assim que um `Individuo` com `id` idêntico ao recebido for encontrado o método é encerrado, retornando o mesmo.

```cpp
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
```

Caso o laço seja completado sem encontrar um `Individuo` com `id` idêntico ao recebido, o método é encerrado, retornando um `Individuo`: generico, inicializado pelo construtor padrão.

```cpp
    }
    Individuo generico;

    return generico;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(n)</sub>



### Busca Ordenada

O método utiliza uma variável `int`: id como parâmetro e uma variável `Individuo`: generico, inicializado pelo construtor padrão, assim como, um laço `for` que pode percorrer todo o `vetor`.

```cpp
Individuo Lista::busca_ordenada(int id)
{
    Individuo generico;

    for (int i = 0; i < this->quantidade_max; i++)
    {
```

A cada etapa do laço o `id` do `Individuo` na posição `i` do `vetor` é comparado ao `id` recebido como parâmetro, assim que um `Individuo` com `id` idêntico ao recebido for encontrado o método é encerrado, retornando o mesmo.

```cpp
        if (this->lista[i].get_id() == id)
        {
            return this->lista[i];
        }
```

Caso contrário, é verificado se o `id` do `Individuo` na posição `i` do `vetor` é maior que o `id` recebido e em caso positivo, o método é encerrado, retornando a variável `generico`.

```cpp
        else if (this->lista[i].get_id() > id)
        {
            return generico;
        }
```

Caso o laço seja completado sem encontrar um `Individuo` com `id` idêntico ao recebido, o método é encerrado, retornando a variável `generico`.

```cpp
    }

    return generico;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(n)</sub>



### Busca Binária

O método utiliza uma variável `int`: id como parâmetro, uma variável `int`: inicio, inicializada em `0`, uma variável `int`: meio e uma variável `int`: fim, inicializada com o valor da variável `quantidade_max` menos `1`, assim como um loop `while` que segue enquanto o valor da variável `inicio` for menor ou igual ao valor da variável `fim`.

```cpp
Individuo Lista::busca_binaria(int id)
{
    int inicio = 0;
    int meio;
    int fim = this->quantidade_max - 1;

    while (inicio <= fim)
    {
```

A cada etapa do loop `while` a variável `meio` recebe o valor da média aritmética entre os valores das variáveis `inicio` e `fim`. 

```cpp
        meio = (inicio + fim) / 2;
```

Em seguida, é comparado o `id` do `Individuo` na posição correspondente ao valor da variável `meio` e o `id` recebido como parâmetro. Se o primeiro for maior, a variável `fim` recebe o valor da variável `meio` menos `1`, limitando a pesquisa à primeira metade do `vetor`.

```cpp

        if (this->lista[meio].get_id() > id)
        {
            fim = meio - 1;
        }
```

Caso o primeiro seja menor, a variável `inicio` recebe o valor da variável `meio` mais `1`, limitando a pesquisa à segunda metade do `vetor`.

```cpp
	else if (this->lista[meio].get_id() < id)
        {
            inicio = meio + 1;
        }
```

Caso os valores sejam iguais, o método é encerrado, retornando o `Individuo` armazenado na posição correspondente ao valor da variável `meio`.

```cpp
	else
        {
            return this->lista[meio];
        }
```

Caso o loop seja encerrado sem encontrar um `Individuo` com `id` idêntico ao recebido, o método é encerrado, retornando um `Individuo`: generico, inicializado pelo construtor padrão.

```cpp
	}
	Individuo generico;

	return generico;
}
```

> Melhor Caso: O<sub>(1)</sub>
>
> Pior Caso: O<sub>(log<sub>n</sub>)</sub>



## Referência

Os algoritmos apresentados nesse repositório partem de estudos iniciados no vídeo de [busca em vetores](https://www.youtube.com/watch?v=ptvnLzqcJuA) do Dr. André Backes no canal [Programação Descomplicada Linguagem C](https://www.youtube.com/user/progdescomplicada) no YouTube.
