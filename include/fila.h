#ifndef FILA_H
#define FILA_H





#include <stdlib.h>
#include <stdbool.h>





/**
 * Estrutura que armazena os detalhes de um item da fila.
 * 
 * \param proximo: Ponteiro para o próximo item da fila.
 * \param dado: Ponteiro para onde a informação será realmente armazenada.
 */
typedef struct ItemF
{
	struct ItemF *proximo;
	void *dado;
} itemF_t;



/**
 * Estrutura que armazena os detalhes de uma fila.
 * 
 * \param primeiro: Ponteiro para o primeiro item da fila.
 * \param ultimo: Ponteiro para o último item da fila.
 * \param quantidade: Guarda a quantidade de itens na fila.
 * \param tamanho_dado: Tamanho em bytes da informação que é armazenada em cada item da fila.
 */
typedef struct Fila
{
	itemF_t *primeiro;
	itemF_t *ultimo;
	size_t quantidade;
	size_t tamanho_dado;
} fila_t;










/**
 * Criar e retorna uma fila. 
 * 
 * \param tamanho_dado Representa o tamanho em bytes do tipo de dados que será usado por essa fila. 
 * O comportamento é indefinido para tamanhos menores ou iguais a zero. 
 * Esse tamanho é único para cada fila e não deve alterado. 
 * 
 * \returns Uma estrutura de uma fila. 
 */
fila_t CriarFila(size_t tamanho_dado);



/**
 * \param fila Ponteiro para a fila em questão.
 * 
 * \returns A quantidade de itens atualmente presentes na fila.
 */
size_t QuantidadeItensFila(fila_t *fila);



/**
 * \param fila Ponteiro para a fila em questão. 
 * 
 * \returns Ponteiro para o dado do próximo item da fila (primeiro).
 */
itemF_t *ProximoItemFila(fila_t *fila);



/**
 * Libera todos os itens da memória e os apaga da fila. 
 * O resultado será uma fila vazia que ainda pode ser reusada. 
 * 
 * \param fila Ponteiro para a fila em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool LimparFila(fila_t *fila);










/**
 * Insere um novo elemento no final da fila. 
 * A informação salva é uma cópia da infomação passada na função. 
 * O tamanho da cópia é determinado pelo tamanho do dado especificado na hora da criação da função. 
 * 
 * \param fila Ponteiro para a fila em questão. 
 * \param dado Ponteiro para o local em que a informação está localizada. 
 * 
 * \returns ponteiro para o item inserido. 
 */
itemF_t *InserirItemFila(fila_t *fila, void *dado);










/**
 * Libera a memória do primeiro item e o remove da fila. 
 * 
 * \param fila Ponteiro para a fila em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool RemoverItemFila(fila_t *fila);










/**
 * Executa a função especificada para todos os itens da fila. Vai do primeiro item ao último. 
 * 
 * \param fila Ponteiro para a fila em questão. 
 * \param func Função que será executada para cada item da fila. 
 * Essa função recebe o dado de um item e a numeração daquele item (começando por zero). 
 * A função deve retornar true se deseja que a travessia continue, ou false se deseja que ela pare. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool AtravessarFila(fila_t *fila, bool (*func)(void *dado, size_t index));





#endif /* FILA_H */