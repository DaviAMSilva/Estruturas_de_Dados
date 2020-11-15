#ifndef PILHA_H
#define PILHA_H





#include <stdlib.h>
#include <stdbool.h>










/**
 * Alguns defines com nomes mais convencionais paras essas funções
 */

#define PushPilha	InserirItemPilha
#define PopPilha	RemoverItemPilha
#define TopoPilha	ProximoItemPilha










typedef	void itemP_t;



/**
 * Estrutura que armazena os detalhes de uma pilha. 
 * 
 * \param itens: Ponteiro para os itens da pilha. 
 * \param tamanho_dado: Tamanho em bytes da informação que é armazenada em cada item da pilha. 
 * Esse tamanho não pode ser alterado após a pilha ser criada. 
 * \param quantidade_maxima: Quantidade máxima de elementos permitidos na pilha. 
 * Essa quantidade não pode ser alterado após a pilha ser criada. 
 * \param quantidade: Guarda a quantidade de itens na pilha. 
 * \param topo: Guarda a posição do item mais acima da pilha. 
 */
typedef struct Pilha
{
	itemP_t *itens;
	const size_t tamanho_dado;
	const size_t quantidade_maxima;
	size_t quantidade;
	long topo;
} pilha_t;










/**
 * Criar e retorna uma pilha. 
 * 
 * \param tamanho_dado Representa o tamanho em bytes do tipo de dados que será usado por essa pilha. 
 * O comportamento é indefinido para tamanhos menores ou iguais a zero. 
 * Esse tamanho é constante para cada pilha e não pode ser alterado. 
 * \param quantidade_maxima Quantidade máxima de itens que poderão ocupar a pilha ao mesmo tempo. 
 * Essa quantidade é constante para cada pilha e não pode ser alterado. 
 * 
 * \returns Uma estrutura de uma pilha. 
 */
pilha_t CriarPilha(size_t tamanho_dado, size_t quantidade_maxima);



/**
 * \param pilha Ponteiro para a pilha em questão. 
 * 
 * \returns A quantidade de itens atualmente presentes na pilha. 
 */
size_t QuantidadeItensPilha(pilha_t *pilha);



/**
 * \param pilha Ponteiro para a pilha em questão. 
 * 
 * \returns Ponteiro para o dado do próximo item da pilha (topo). 
 */
itemP_t *ProximoItemPilha(pilha_t *pilha);



/**
 * Zera a quantidade de itens da pilha sem liberar o espaço alocado. 
 * O resultado será uma pilha vazia que ainda pode ser reusada. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool LimparPilha(pilha_t *pilha);



/**
 * Libera o espaço de memória alocado para a pilha. 
 * AVISO: A pilha resultante não pode ser reusada ou reaproveitada. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool DestruirPilha(pilha_t *pilha);










/**
 * Insere um novo elemento no topo da pilha. 
 * A informação salva é uma cópia da infomação passada na função. 
 * O tamanho da cópia é determinado pelo tamanho do dado especificado na hora da criação da função. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * \param dado Ponteiro para o local em que a informação está localizada. 
 * 
 * \returns ponteiro para o item inserido. 
 */
itemP_t *InserirItemPilha(pilha_t *pilha, void *dado);










/**
 * Remove o item no topo da pilha. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool RemoverItemPilha(pilha_t *pilha);










/**
 * Executa a função especificada para todos os itens da pilha. Vai do primeiro item ao último. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * \param func Função que será executada para cada item da pilha. 
 * Essa função recebe o dado de um item e a numeração daquele item (começando por zero). 
 * A função deve retornar true se deseja que a travessia continue, ou false se deseja que ela pare. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool AtravessarPilhaNormal(pilha_t *pilha, bool (*func)(void *dado, size_t index));



/**
 * Executa a função especificada para todos os itens da pilha. Vai do último item ao primeiro. 
 * 
 * \param pilha Ponteiro para a pilha em questão. 
 * \param func Função que será executada para cada item da pilha. 
 * Essa função recebe o dado de um item e a numeração daquele item (começando por zero). 
 * A função deve retornar true se deseja que a travessia continue, ou false se deseja que ela pare. 
 * 
 * \returns true se houve sucesso, false senão. 
 */
bool AtravessarPilhaContrario(pilha_t *pilha, bool (*func)(void *dado, size_t index));





#endif /* PILHA_H */