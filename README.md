# Estruturas de Dados

Conjunto simples de estruturas de dados que podem trabalhar com qualquer tipo de dados, usando ponteiros void e alocação dinâmica.

## Estruturas suportadas

- [x] `liblista` Listas duplamente encadeadas, simples ou circulares.
- [x] `libfila` Filas encadeadas.
- [x] `libpilha` Pilhas estáticas.

## Compilação

Use `make` para compilar as bibliotecas.

## Cabeçalhos

A documentação de cada função está presente em forma de comentários em cada cabeçalho.

### fila.h

```c
typedef struct ItemF itemF_t;
typedef struct Fila  fila_t;

fila_t   CriarFila          (size_t tamanho_dado);
size_t   QuantidadeItensFila(fila_t *fila);
itemF_t *ProximoItemFila    (fila_t *fila);
bool     LimparFila         (fila_t *fila);
itemF_t *InserirItemFila    (fila_t *fila, void *dado);
bool     RemoverItemFila    (fila_t *fila);
bool     AtravessarFila     (fila_t *fila, bool (*func)(void *dado, size_t index));
```

### lista.h

```c
typedef enum   TipoLista tipoLista_t;
typedef struct ItemL     itemL_t;
typedef struct Lista     lista_t;

lista_t  CriarLista              (size_t tamanho_dado, tipoLista_t tipo_lista);
size_t   QuantidadeItensLista    (lista_t *lista);
bool     LimparLista             (lista_t *lista);
itemL_t *InserirInicioLista      (lista_t *lista, void *dado);
itemL_t *InserirFinalLista       (lista_t *lista, void *dado);
bool     RemoverPrimeiroLista    (lista_t *lista);
bool     RemoverUltimoLista      (lista_t *lista);
bool     RemoverItemLista        (lista_t *lista, itemL_t *item);
bool     AtravessarListaNormal   (lista_t *lista, bool (*func)(void *dado, size_t index));
bool     AtravessarListaContrario(lista_t *lista, bool (*func)(void *dado, size_t index));
```

### pilha.h

```c
typedef void itemP_t;
typedef struct Pilha pilha_t;

pilha_t  CriarPilha              (size_t tamanho_dado, size_t quantidade_maxima);
size_t   QuantidadeItensPilha    (pilha_t *pilha);
itemP_t *ProximoItemPilha        (pilha_t *pilha);
itemP_t *TopoPilha               (pilha_t *pilha);
bool     LimparPilha             (pilha_t *pilha);
bool     DestruirPilha           (pilha_t *pilha);
itemP_t *InserirItemPilha        (pilha_t *pilha, void *dado);
itemP_t *PushPilha               (pilha_t *pilha, void *dado);
bool     RemoverItemPilha        (pilha_t *pilha);
bool     PopPilha                (pilha_t *pilha);
bool     AtravessarPilhaNormal   (pilha_t *pilha, bool (*func)(void *dado, size_t index));
bool     AtravessarPilhaContrario(pilha_t *pilha, bool (*func)(void *dado, size_t index));
```
