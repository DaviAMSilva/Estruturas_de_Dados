#include <fila.h>
#include <string.h>





inline fila_t CriarFila(size_t tamanho_dado)
{
	return (fila_t) { NULL, NULL, 0, tamanho_dado };
}



inline size_t QuantidadeItensFila(fila_t *fila)
{
	if (fila)
		return fila->quantidade;
	else
		return 0;
}



inline itemF_t *ProximoItemFila(fila_t *fila)
{
	if (fila)
		return fila->primeiro;
	else
		return NULL;
}



bool LimparFila(fila_t *fila)
{
	itemF_t *ptr = fila->primeiro;
	itemF_t *proximo;



	if (fila == NULL || ptr == NULL)
	{
		return false;
	}
	else
	{
		while (ptr)
		{
			proximo = ptr->proximo;
			free(ptr->dado);
			free(ptr);
			ptr = proximo;
		}
	}


	fila->primeiro = fila->ultimo = NULL;
	fila->quantidade = 0;



	return true;
}











itemF_t *InserirItemFila(fila_t *fila, void *dado)
{
	itemF_t *novo_item = calloc(1, sizeof(itemF_t));
	novo_item->dado = calloc(1, fila->tamanho_dado);

	if (fila == NULL || dado == NULL || novo_item == NULL || novo_item->dado == NULL)
		return NULL;



	if (fila->primeiro == NULL)
	{
		novo_item->proximo = NULL;
		fila->primeiro = fila->ultimo = novo_item;
	}
	else
	{
		novo_item->proximo = NULL;
		fila->ultimo->proximo = novo_item;
		fila->ultimo = novo_item;
	}



	fila->quantidade++;



	memcpy(novo_item->dado, dado, fila->tamanho_dado);



	return novo_item;	
}










bool RemoverItemFila(fila_t *fila)
{
	itemF_t *primeiro = fila->primeiro;

	if (fila == NULL || fila->primeiro == NULL)
		return false;



	free(fila->primeiro->dado);

	fila->primeiro = fila->primeiro->proximo;

	free(primeiro);


	fila->quantidade--;

	return true;
}










bool AtravessarFila(fila_t *fila, bool (*func)(void *dado, size_t index))
{
	itemF_t *ptr = fila->primeiro;
	size_t index = 0;



	if (fila == NULL || ptr == NULL || func == NULL)
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
