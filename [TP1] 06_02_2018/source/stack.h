typedef int Tray;
typedef struct sCell *sPointer;
typedef struct sCell {
	Tray trayNumber;
	sPointer next;
} sCell;

typedef struct Stack {
	sPointer top;
	sPointer bottom;
	int size;
	int max_size;
} Stack;

void clearStack(Stack *stack, int max_size);
int emptyStack(Stack stack);
int fullStack(Stack stack);
void push(Stack *stack, Tray trayNumber);
Tray pop(Stack *stack);
void fillStack(Stack *stack, int amount);