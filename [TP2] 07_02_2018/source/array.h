#define MAXLEN 100000

typedef int Key;
typedef struct Item {
   Key id;
} Item;

typedef int Index; 
typedef Item ItemArray[(MAXLEN) + 1];

void printArray(ItemArray array, Index n); /*Este método imprime as chaves de um arranjo*/
void fillArray(ItemArray array, Index n, int option); /*Este método preenche um arranjo de acorco com a configuração passada por 'option'*/
void copyArray(ItemArray array, ItemArray copy, Index n); /*Este método copia um arranjo em outro*/