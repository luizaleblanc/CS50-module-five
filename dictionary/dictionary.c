// Implements a dictionary's functionality using a hash table

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// Um número grande (potência de 2) ajuda a espalhar as palavras
// e torna a tabela mais rápida.
const unsigned int N = 65536;

// Hash table
// 'table' é um array de ponteiros para 'node'.
// Cada índice do array é um "balde" que aponta para o início de uma lista ligada.
node *table[N];

// Variável global para contar o número de palavras
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
// Implementa a função check
bool check(const char *word)
{
    // 1. Calcula o hash da palavra para saber em qual balde procurar
    unsigned int index = hash(word);

    // 2. Acessa a lista ligada nesse balde
    node *cursor = table[index];

    // 3. Percorre a lista ligada, procurando pela palavra
    while (cursor != NULL)
    {
        // strcasecmp compara strings ignorando maiúsculas/minúsculas
        if (strcasecmp(word, cursor->word) == 0)
        {
            // Encontrou a palavra
            return true;
        }
        // Move para o próximo nó na lista
        cursor = cursor->next;
    }

    // 4. Se chegou ao fim da lista, a palavra não está no dicionário
    return false;
}

// Hashes word to a number
// Implementa a função hash
// Esta é uma função hash comum (djb2) encontrada online.
// O Pset permite o uso de hashes encontrados online, desde que citados.
// Fonte: http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash = 5381;
    int c;

    // Itera sobre cada caractere da palavra (convertido para minúsculo)
    while ((c = *word++))
    {
        // A fórmula do hash
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    }

    // Retorna o resultado do hash modulo N para caber na nossa tabela
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
// Implementa a função load
bool load(const char *dictionary)
{
    // 1. Abre o arquivo do dicionário
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // 2. Lê cada palavra do arquivo
    char word_buffer[LENGTH + 1];
    // fscanf retorna EOF (End Of File) quando não há mais o que ler
    while (fscanf(file, "%s", word_buffer) != EOF)
    {
        // 3. Para cada palavra, cria um novo nó
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            // Falha ao alocar memória
            fclose(file);
            return false;
        }

        // 4. Copia a palavra do buffer para o nó
        strcpy(new_node->word, word_buffer);
        new_node->next = NULL;

        // 5. Calcula o hash da palavra para saber onde guardá-la
        unsigned int index = hash(word_buffer);

        // 6. Insere o nó na tabela hash (no início da lista ligada)
        new_node->next = table[index];
        table[index] = new_node;

        // 7. Incrementa o contador de palavras
        word_count++;
    }

    // 8. Fecha o arquivo e retorna sucesso
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
// Implementa a função size
unsigned int size(void)
{
    // Simplesmente retorna a contagem global
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
// Implementa a função unload
bool unload(void)
{
    // 1. Itera sobre cada balde (índice) da tabela hash
    for (int i = 0; i < N; i++)
    {
        // 2. Define um cursor para o início da lista ligada desse balde
        node *cursor = table[i];

        // 3. Percorre a lista ligada, liberando cada nó
        while (cursor != NULL)
        {
            // Usa um ponteiro temporário para guardar o nó atual...
            node *tmp = cursor;
            // ...move o cursor para o próximo nó...
            cursor = cursor->next;
            // ...e libera o nó que o 'tmp' estava guardando.
            free(tmp);
        }
    }

    // Retorna sucesso
    return true;
}
