/*Seleção*/
void Select(Item *item, Index n);
/*Inserção*/
void Insert(Item *item, Index n);
/*Bolha*/
void Bubble(Item *item, Index n);
/*Quick Sort*/
void Partition(Index Left, Index Right, Index *i, Index *j, Item *item);
void Sort(Index Left, Index Right, Item *item);
void Quick(Item *item, Index n);
/*Shell Sort*/
void Shell(Item *item, Index n);
/*Heap Sort*/
void Remake(Index Left, Index Right, Item *item);
void Build(Item *item, Index n);
void Heap(Item *item, Index n);