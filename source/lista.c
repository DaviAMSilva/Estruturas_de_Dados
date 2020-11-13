#include <lista.h>
#include <string.h>





inline lista_t CriarLista(size_t tamanho_dado)
{
	return (lista_t) { NULL, NULL, 0, tamanho_dado };
}



inline size_t QuantidadeItensLista(lista_t *lista)
{
	return lista->quantidade;
}



bool LimparLista(lista_t *lista)
{
	itemL_t *ptr = lista->primeiro;
	itemL_t *proximo;



	if (lista->primeiro == NULL)
		return false;



	while (ptr)
	{
		proximo = ptr->proximo;
		free(ptr->dado);
		free(ptr);
		ptr = proximo;
	}



	lista->primeiro = lista->ultimo = NULL;
	lista->quantidade = 0;



	return true;
}










itemL_t *InserirInicioLista(lista_t *lista, void *dado)
{
	itemL_t *novo_item = calloc(1, sizeof(itemL_t));
	novo_item->dado = calloc(1, lista->tamanho_dado);



	if (dado == NULL || novo_item == NULL || novo_item->dado == NULL)
		return NULL;



	if (lista->primeiro == NULL)
	{
		novo_item->proximo = NULL;
		novo_item->anterior = NULL;
		lista->primeiro = lista->ultimo = novo_item;
	}
	else
	{
		novo_item->proximo = lista->primeiro;
		novo_item->anterior = NULL;
		lista->primeiro->anterior = novo_item;
		lista->primeiro = novo_item;
	}



	lista->quantidade++;



	return memcpy(novo_item->dado, dado, lista->tamanho_dado);
}



itemL_t *InserirFinalLista(lista_t *lista, void *dado)
{
	itemL_t *novo_item = calloc(1, sizeof(itemL_t));
	novo_item->dado = calloc(1, lista->tamanho_dado);



	if (dado == NULL || novo_item == NULL || novo_item->dado == NULL)
		return NULL;



	if (lista->primeiro == NULL)
	{
		novo_item->proximo = NULL;
		novo_item->anterior = NULL;
		lista->primeiro = lista->ultimo = novo_item;
	}
	else
	{
		novo_item->proximo = NULL;
		novo_item->anterior = lista->ultimo;
		lista->ultimo->proximo = novo_item;
		lista->ultimo = novo_item;
	}



	lista->quantidade++;



	return memcpy(novo_item->dado, dado, lista->tamanho_dado);	
}










bool RemoverPrimeiroLista(lista_t *lista)
{
	return RemoverItemLista(lista, lista->primeiro);
}



bool RemoverUltimoLista(lista_t *lista)
{
	return RemoverItemLista(lista, lista->ultimo);
}



/**
 * Essa função tem um problema que eu gostaria de resolver
 * mas que eu não consigo pensar em uma solução eficiente
 * 
 * Se alguém passar um ponteiro que não pertence à lista
 * problemas com certeza irão acontecer
 * 
 * Uma maneira de resolver seria manter um ponteiro para
 * a lista dentro de um item mas isso aumentaria a memória
 * e seria necessário mudar o metodo de criação de listas
 */
bool RemoverItemLista(lista_t *lista, itemL_t *item)
{
	if (item == NULL || lista->primeiro == NULL)
		return false;



	free(item->dado);



	// Estou muito orgulhoso disso :)
	if (item == lista->primeiro)	lista->primeiro	= item->proximo;
	if (item == lista->ultimo)		lista->ultimo	= item->anterior;

	if (item->proximo)	item->proximo->anterior = item->anterior;
	if (item->anterior)	item->anterior->proximo = item->proximo;



	free(item);



	lista->quantidade--;



	return true;
}










bool AtravessarListaNormal(lista_t *lista, bool (*func)(void *dado, size_t index))
{
	itemL_t *ptr = lista->primeiro;
	size_t index = 0;



	if (ptr == NULL)
		return false;



	while (ptr)
	{
		if (func(ptr->dado, index) == false)
			return false;

		ptr = ptr->proximo;
		index++;
	}



	return true;
}



bool AtravessarListaContrario(lista_t *lista, bool (*func)(void *dado, size_t index))
{
	itemL_t *ptr = lista->ultimo;
	size_t index = 0;



	if (ptr == NULL)
		return false;



	while (ptr)
	{
		if (func(ptr->dado, index) == false)
			return false;

		ptr = ptr->anterior;
		index++;
	}



	return true;
}