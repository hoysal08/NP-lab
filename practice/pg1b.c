#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void recieve(int msg[],int len);
void sender();

int main()
{
    sender();
}

void sender(){
    int result[150];
    printf("enter the number of bits you wanna send \n");
    int n;
    scanf("%d", &n);
    int message[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &message[i]);
    }
    
    
    result[0]=0;
    result[1]=1;
    result[2]=1;
    result[3]=1;
    result[4]=1;
    result[5]=1;
    result[6]=1;
    result[7]=0;

    int j=8;
    int count1=0;
    int count0=0;
    int ins0=0;

    for(int i = 0; i < n; i++)
    {   
        if(message[i]==0)
        {
            result[j++]=message[i];
            count0=1;
            count1=0;
        }
        else
        {
            if(count1==5 && count0==1)
            {
               result[j++]=0;
               ins0++;
               result[j++]=message[i];
               count0=0;
               count1=0;
            }
            else
            {
                result[j++]=message[i];
                count1++;
            }
        }
    }

  printf("\n");

  int len=8+n+ins0;
  printf("/n the length of the frame sent is  :%d",len);
  printf("Frame sent : ");
  for(int i = 0; i < len; i++)
  {
    printf("%d",result[i]);
  }
 recieve(result,len);
}



void recieve(int msg[],int len){

int result[150];
int j=0;
int count1=0;
 
 for(int i = 8; i < len; i++)
 {  
    if(msg[i]==1)
    {
       result[j++]=msg[i];
       count1++;
    }
    else
    {
        if(count1==5 )
        {    i++;
            result[j++]=msg[i];
            count1=0;
        }
        else
        {
            result[j++]=msg[i];
            count1=0;
        }
    }
     
 }
 
 printf("the length of the message is : %d",j);
  printf("message recevied is : ");
  for(int i = 0; i < j; i++)
  {
    printf("%d",result[i]);
  }
}