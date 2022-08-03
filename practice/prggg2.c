#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void recieve(int arr[], int len);
int main()
{
    printf("enter the number of bits you want to be sent");
    int n;
    scanf("%d", &n);
    int msg[120];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&msg[i]);
    }

    int result[120];

    result[0] = 0;
    result[1] = 1;
    result[2] = 1;
    result[3] = 1;
    result[4] = 1;
    result[5] = 1;
    result[6] = 1;
    result[7] = 0;

    int j = 8;
    int count1 = 0;
    int count0 = 0;
    int ins0 = 0;

    for (int i = 0; i < n; i++)
    {
        if (msg[i] == 0)
        {
            result[j++] = msg[i];
            count0 = 1;
            count1 = 0;
        }
        else
        {
            if (count1 == 5 && count0 == 1)
            {
                result[j++] = 0;
                ins0++;
                result[j++] = msg[i];
                count0 = 0;
                count1 = 0;
            }
            else
            {
                result[j++] = msg[i];
                count1++;
            }
        }
    }

    int len = 8 + n + ins0;

    printf(" The message being sent is \n");
  for(int i = 0; i < j; i++)
  {
    printf("%d",result[i]);
  }
    recieve(result,len);
}

void recieve(int msg[], int length)
{

    int result[120];
    int j = 0;

    int count1 = 0;

    for (int i = 8; i < length; i++)
    {
        if (msg[i] == 1)
        {
            result[j++] = msg[i];
            count1++;
        }
        else
        {
            if (count1 == 5)
            {
                i++;
                result[j++] = msg[i];
                count1 = 0;
            }
            else
            {
                result[j++] = msg[i];
                count1 = 0;
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