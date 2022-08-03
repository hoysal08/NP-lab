#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define N strlen(g)
char t[120],g[]="1101",cs[120];
int e,a,c;

void xor()
{
    for(c=1;c<N;c++)
    {
        cs[c]=((cs[c]==g[c])?'0':'1');
    }
}

void crc(){
 
 for(e=0;e<N;e++)
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

int main()
{
    printf("enter the polynomial in binary format/n");
    scanf("%s",t);
    printf("\nthe generating polynomial is : %s \n",g);
     a=strlen(t);
   for (e = a; e < a +N -1 ;e++)
    {
        t[e]='0';
    }
    printf("\nthe modified polynomial is  : %s\n",t);

    crc();

    printf("\n the CRC is %s\n",cs);

    for(e=a;e<a+N-1;e++)
    {
        t[e]=cs[e-a];
    }

    printf("\nThe final code word is %s \n",t);
    
    printf("Do you want to generate error in the message:\t 1.Yes \t 2.No\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nEnter the index you want to insert error into:\n");
        int ind;
        scanf("%d",&ind);
        if(ind>a+N-1)
        {
            printf("Invalid index to enter the error: exit");
            return 0;
        }
        t[ind]=((t[ind]=='0')?'1':'0');
        printf("\nthe message after inserting error is : %s \n",t);
    }

    crc();
    
    for(int i=0;i<strlen(cs);i++)
    {
      if(cs[i]!='0')
      {
        printf("\nError detected the message: exit\n");
        return 0;
      }
    }
    printf("\n No error detected in the message");
}