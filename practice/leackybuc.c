#include<stdio.h>
#define MIN(x,y) (x>y)?y:x
int main(){
    int cap;
    printf("\nenter the bucket size\n");
    scanf("%d",&cap);
    printf("\nEnter the output rate\n");
    int outtate;
    scanf("%d",&outtate);
    int ip[20]={0};
    int i=0;
    int ch;
    do{
        printf("\nenter the no of packets coming at second %d\n",(i+1));
        scanf("%d",&ip[i++]);
        printf("Enter 1 to continue receving and 0 to exit\n");
        scanf("%d",&ch);        
    }while(ch);

    int nsec=i;
    int count=0;
    int drop=0;
    printf("\tSecond\t\tRecived\t\tSent\t\tDropped\t\tRemaining\n");
    for(int j=0;j<nsec ||count ;j++)
    {
      printf("\t%d\t\t",(j+1));
      printf("%d\t\t",ip[j]);
      printf("%d\t\t",MIN(outtate,(ip[j]+count)));
      int x=0;
      if((x=ip[j]+count-outtate)>0)
      {
        if(x>cap)
        {
            count=cap;
            drop=x-cap;
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

 printf("%d\t\t%d\n",drop,count);

    }

}