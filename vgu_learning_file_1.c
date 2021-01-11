#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fh;
int ch;
/* open the file */
fh=fopen("input.txt","r");
/* check for errors */
if(fh==NULL)
{
puts("Can't open that file!");
exit(1);
}
/* loop until the end-of-file */
while( !feof(fh) )
{
/* read one character */
ch=fgetc(fh);
/* end of file? */
if( ch==EOF )
break;
/* output character */
putchar(ch);
}
/* close the file */
fclose(fh);
return(0); 
}