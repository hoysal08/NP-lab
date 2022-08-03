#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define N strlen(g)
char t[100],g[]="1101",cs[20];
int a,e,c;
void xor()
{
    for( c=1;c<N;c++)
    {
        cs[c]=((cs[c]==g[c])?'0':'1');
    }
}

void crc()
{  
    for( e=0;e<N;e++)
     cs[e]=t[e];


    do{ 

    if(cs[0]=='1')
    xor();
  
    for(c=0;c<N-1;c++)
    {
        cs[c]=cs[c+1];
    }
    cs[c]=t[e++];

    }while(e<=a+N-1);

}

int main(){

printf("\nenter the polynimial\n");
scanf("%s",t);
printf("\nThe generating polynimial is  %s\n",g);
a=strlen(t);
for( e=a;e<a+N-1;e++)
{
    t[e]='0';
}
printf("\nThe modified polynimial is  %s\n",t);

crc();

printf("The generated CRC is %s",cs);



}