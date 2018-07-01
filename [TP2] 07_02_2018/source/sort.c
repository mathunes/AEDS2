#include "array.h"
#include "sort.h"

void Select(Item *item, Index n){
   Index i, j, Min; 
   Item x; 
   for (i = 1; i <= n - 1; i++){
      Min = i; 
      for (j = i + 1; j <= n; j++)
         if (item[j].id < item[Min].id)   
            Min = j; 
      x = item[Min]; 
      item[Min] = item[i]; 
      item[i] = x;
   }
}

void Insert(Item *item, Index n){ 
   Index i, j; 
   Item x; 
   for (i = 2; i <= n; i++){
      x = item[i];
      j = i - 1; 
      item[0] = x;
      while (x.id < item[j].id){ 
         item[j+1] = item[j]; 
         j--; 
      } 
      item[j+1] = x; 
   } 
}

void Bubble(Item *item, Index n){ 
   Index i, j; 
   Item x; 
   for (i = 1; i <= n; i++){
      for (j = 1; j <= (n-i); j++){
         if (item[j].id > item[j+1].id){
            x = item[j];
            item[j] = item[j+1];
            item[j+1] = x;
         }
      }
   }
}

void Partition(Index Left, Index Right, Index *i, Index *j, Item *item){
   Item x, w; 
   *i = Left; *j = Right; 
   x = item[(*i + *j) / 2]; /* obtem o pivo x */ 
   do { 
      while (x.id > item[*i].id) (*i)++; 
      while (x.id < item[*j].id) (*j)--; 
      if (*i <= *j) { 
         w = item[*i]; item[*i] = item[*j]; item[*j] = w; 
         (*i)++; (*j)--; 
      } 
   } while (*i <= *j); 
}

void Sort(Index Left, Index Right, Item *item){ 
   Index i, j;
   Partition(Left, Right, &i, &j, item);
   if (Left < j) Sort(Left, j, item);
   if (i < Right) Sort(i, Right, item);
}

void Quick(Item *item, Index n){
   Sort(1, n, item);
}

void Shell(Item *item, Index n){ 
   int i, j; int h = 1;
   Item x;
   do h = h * 3 + 1; while (h < n);
   do {
      h /= 3;
      for (i = h + 1; i <= n; i++){ 
         x = item[i]; j = i;
         while (item[j - h].id > x.id){
            item[j] = item[j - h]; j -= h;
            if (j <= h) break;
         }
         item[j] = x;
      }
   } while (h != 1);
}

void Remake(Index Left, Index Right, Item *item) {
   Index i = Left;
   int j;
   Item x; j = i * 2;
   x = item[i];
   while (j <= Right) {
      if (j < Right) {
         if (item[j].id < item[j+1].id) j++;
      }
      if (x.id >= item[j].id) break;
         item[i] = item[j];
      i = j;
      j = i * 2;
   }
   item[i] = x;
}

void Build(Item *item, Index n) {
   Index Left;
   Left = n / 2 + 1;
   while (Left > 1) {
      Left--;
      Remake(Left, n, item);
   }
}

void Heap(Item *item, Index n) {
   Index Left, Right;
   Item x;
   Build(item, n);
   Left = 1;
   Right = n;
   while (Right > 1) {
      x = item[1];
      item[1] = item[Right];
      item[Right] = x;
      Right--;
      Remake(Left, Right, item);
   }
}