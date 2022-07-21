
// ESTRUTURA DE DADOS DA LISTA
 
typedef void *tdado;
typedef struct tnoh
{
    tdado dado;
    struct tnoh *proximo;
} tnode;

typedef tnode* pnoh;

typedef struct{
    pnoh primeiro;
    pnoh ultimo;
    int tamanho;
} tcabec;

typedef tcabec* lista;
 
// INTERFACE DO TAD LISTA


lista cria_lista();
lista append_lista(lista lst, tdado dado);
int len_lista(lista lst);
tdado prim_lista(lista lst);
tdado ult_lista(lista lst);
int index_lista(lista lst, tdado dado);
lista insert_lista(lista lst, int index, tdado dado);
lista remove_lista(lista lst, int index);
tdado dado_lista(lista lst, int index);
