#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
struct stk {
char symbol[5];
int quantity;
float price;
struct stk *next;
};
struct stk *first;
struct stk *current;
/* allocate structre */
first=(struct stk *)malloc(sizeof(struct stk)*1);
if(first==NULL)
{
puts("Some kind of malloc() error");
exit(1);
}
/* set the base */
current=first;
/* assign structure data */
strcpy(current->symbol,"GOOG");
current->quantity=26;
current->price=1373.19;
/* allocate the next structure */
current->next=
(struct stk *)malloc(sizeof(struct stk)*1);
if(current->next==NULL)
{
puts("Another malloc() error");
exit(1);
}
/* reference the new structure */
current=current->next;
strcpy(current->symbol,"MSFT");
current->quantity=67;
current->price=183.16;
/* cap the end of the list */
current->next=NULL;
/* outupt database */
puts("Investment Portfolio");
printf("Symbol\tShares\tPrice\tValue\n");
current=first;
while( current )
{
printf("%-6s\t%5d\t%.2f\t%.2f\n",
current->symbol,
current->quantity,
current->price,
current->quantity*current->price);
current=current->next;
}
return(0);
}