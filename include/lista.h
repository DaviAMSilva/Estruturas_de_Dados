#ifndef LISTA_H
#define LISTA_H





#include <stdlib.h>
#include <stdbool.h>




/**
 * Tipos de lista que podem existir
 * 
 * \param LISTA_SIMPLES: Lista duplamente encadeada
 * \param LISTA_CIRCULAR: Lista duplamente encadeada circular
 */
typedef enum TipoLista
{
	LISTA_SIMPLES,
	LISTA_CIRCULAR,
} tipoLista_t;





/**
 * Estrutura que armazena os detalhes de um item da lista.
 * 
 * \param proximo: Ponteiro para o próximo item da lista.
 * \param anterior: Ponteiro para o item anterior da lista.
 * \param dado: Ponteiro para onde a informação será realmente armazenada.
 */
typedef struct ItemL
{
	struct ItemL *proximo;
	struct ItemL *anterior;
	void *dado;
} itemL_t;



/**
 * Estrutura que armazena os detalhes de uma lista.
 * 
 * \param primeiro: Ponteiro para o primeiro item da lista.
 * \param ultimo: Ponteiro para o último item da lista.
 * \param quantidade: Guarda a quantidade de itens na lista.
 * \param tamanho_dado: Tamanho em bytes da informação que é armazenada em cada item da lista.
 * \param tipo_lista: Define se a lista é simples ou circular. 
 */
typedef struct Lista
{
	itemL_t *primeiro;
	itemL_t *ultimo;
	size_t quantidade;
	size_t tamanho_dado;
	tipoLista_t tipo_lista;
} lista_t;










/**
 * Criar e retorna uma lista, podendo ser duplamente encadeada simples ou circular. 
 * 
 * \param tamanho_dado Representa o tamanho em bytes do tipo de dados que será usado por essa lista. 
 * Esse tamanho é único para cada lista e não deve alterado. 
 * O comportamento é indefinido para tamanhos menores ou iguais a zero. 
 * \param tipo_lista Define se a lista será simples ou circular. 
 * Esse tipo é único para cada lista e não deve alterado. 
 * O comportamento é indefinido para tipos diferentes dos esperados. 
 * 
 * \returns Uma estrutura de uma lista. 
 */
lista_t CriarLista(size_t tamanho_dado, tipoLista_t tipo_lista);



/**
 * \param lista Ponteiro para a lista em questão.
 * 
 * \returns A quantidade de itens atualmente presentes na lista.
 */
size_t QuantidadeItensLista(lista_t *lista);



/**
 * Libera todos os itens da memória e os apaga da lista. 
 * O resultado será uma lista vazia que ainda pode ser reusada. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool LimparLista(lista_t *lista);










/**
 * Insere um novo elemento no início da lista. 
 * A informação salva é uma cópia da infomação passada na função. 
 * O tamanho da cópia é determinado pelo tamanho do dado especificado na hora da criação da função. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * \param dado Ponteiro para o local em que a informação está localizada. 
 * 
 * \returns ponteiro para o item inserido. 
 */
itemL_t *InserirInicioLista(lista_t *lista, void *dado);



/**
 * Insere um novo elemento no final da lista. 
 * A informação salva é uma cópia da infomação passada na função. 
 * O tamanho da cópia é determinado pelo tamanho do dado especificado na hora da criação da função. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * \param dado Ponteiro para o local em que a informação está localizada. 
 * 
 * \returns ponteiro para o item inserido. 
 */
itemL_t *InserirFinalLista(lista_t *lista, void *dado);










/**
 * Libera a memória do primeiro item e o remove da lista. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool RemoverPrimeiroLista(lista_t *lista);



/**
 * Libera a memória do último item e o remove da lista. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * 
 * \returns true se houve sucesso, false senão.
 */
bool RemoverUltimoLista(lista_t *lista);



/**
 * Libera a memória do item especificado e o remove da lista. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * \param item Ponteiro para o item em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool RemoverItemLista(lista_t *lista, itemL_t *item);










/**
 * Executa a função especificada para todos os itens da lista. Vai do primeiro item ao último. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * \param func Função que será executada para cada item da lista. 
 * Essa função recebe o dado de um item e a numeração daquele item (começando por zero). 
 * A função deve retornar true se deseja que a travessia continue, ou false se deseja que ela pare. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool AtravessarListaNormal(lista_t *lista, bool (*func)(void *dado, size_t index));



/**
 * Executa a função especificada para todos os itens da lista. Vai do último item ao primeiro. 
 * 
 * \param lista Ponteiro para a lista em questão. 
 * \param func Função que será executada para cada item da lista. 
 * Essa função recebe o dado de um item e a numeração daquele item (começando por zero). 
 * A função deve retornar true se deseja que a travessia continue, ou false se deseja que ela pare. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool AtravessarListaContrario(lista_t *lista, bool (*func)(void *dado, size_t index));





#endif /* LISTA_H */