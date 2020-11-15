#include <pilha.h>
#include <string.h>





pilha_t CriarPilha(size_t tamanho_dado, size_t quantidade_maxima)
{
	pilha_t pilha = { NULL, tamanho_dado, quantidade_maxima, 0, -1 };

	pilha.itens = calloc(quantidade_maxima, tamanho_dado);

	return pilha;
}



inline size_t QuantidadeItensPilha(pilha_t *pilha)
{
	if (pilha)
		return pilha->quantidade;
	else
		return 0;
}



itemP_t *ProximoItemPilha(pilha_t *pilha)
{
	if (pilha == NULL || pilha->itens == NULL || pilha->quantidade < 0)
		return NULL;
	else
		return pilha->itens + pilha->topo * pilha->tamanho_dado;
}



bool LimparPilha(pilha_t *pilha)
{
	if (pilha == NULL)
		return false;



	pilha->topo = -1;
	pilha->quantidade = 0;



	return true;
}



bool DestruirPilha(pilha_t *pilha)
{
	if (pilha == NULL || pilha->itens == NULL)
		return false;



	pilha->topo = -1;
	pilha->quantidade = 0;

	free(pilha->itens);

	pilha->itens = NULL;



	return true;
}










itemP_t *InserirItemPilha(pilha_t *pilha, void *dado)
{
	if (pilha == NULL || pilha->itens == NULL || dado == NULL || pilha->quantidade >= pilha->quantidade_maxima)
		return NULL;



	pilha->topo++;
	pilha->quantidade++;



	return memcpy(pilha->itens + pilha->topo * pilha->tamanho_dado, dado, pilha->tamanho_dado);
}










bool RemoverItemPilha(pilha_t *pilha)
{
	if (pilha == NULL || pilha->itens == NULL || pilha->topo < 0)
		return false;
	


	pilha->topo--;
	pilha->quantidade--;



	return true;
}










bool AtravessarPilhaNormal(pilha_t *pilha, bool (*func)(void *dado, size_t index))
{
	if (pilha == NULL || pilha->itens == NULL || func == NULL || pilha->topo < 0)
		return false;



	for (int i = 0; i <= pilha->topo; i++)
	{
		if (func(pilha->itens + i * pilha->tamanho_dado, i) == false)
			return false;
	}



	return true;
}



bool AtravessarPilhaContrario(pilha_t *pilha, bool (*func)(void *dado, size_t index))
{
	if (pilha == NULL || pilha->itens == NULL || func == NULL || pilha->topo < 0)
		return false;



	for (int i = pilha->topo; i >= 0; i--)
	{
		if (func(pilha->itens + i * pilha->tamanho_dado, i) == false)
			return false;
	}



	return true;
}