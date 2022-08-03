#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) x>y?y:x

int main()
{    int cap,ouprat,ip[20]={0};
    printf("\nenter the bucket size\n");
    scanf("%d",&cap);
    printf("\nenter the output rate\n");
    scanf("%d",&ouprat);
    int ch,i=0;
    do{
       printf("enter number of packets coming at second %d :\n",(i+1));
       scanf("%d",&ip[i]);

       if(ip[i]>cap)
       {
        printf("\n bucket overflow \n");
        printf("Packet discarded\n");
        exit(0);
       }
       i++;
       printf("\nenter 1 to receive packets and 0 to exit\n");
       scanf("%d",&ch);
    }while(ch);

    int nsec=i;
    int count=0;
    int x,drop=0;
  

    printf("\n Second \t Recieved \t Sent \t Dropped \tRemained \n");
    for(i=0; count || i<nsec;i++)
    {   
        printf(" %d\t",(i+1));
        printf("\t%d\t",ip[i]);
        printf("\t%d\t",MIN((ip[i]+count),ouprat));

        if(( x = ip[i]+count-ouprat)>0)
        {  
            if(x>cap)
            {    
               count=cap;
               drop=x-count;
            }
            else
            {    
                drop=0;
                count=x;
            }
        }
        else
        {
            drop=0;
            count=0;
        }
        printf("\t%d\t%d\n",drop,count);
        printf("\n");
    }

}