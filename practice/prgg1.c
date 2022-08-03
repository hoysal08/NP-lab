#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
char frames[1025];
void recieve();
int main()
{
printf("\nenter the number of bits you wnt to insert\n");
int n;
scanf("%d", &n);
char buffer[256],temp[10];

for(int i = 0; i < n; i++)
{
    bzero(buffer,256);
    printf("enter the frame no %d",(i+1));
    scanf("%s",buffer);
   
    int len=strlen(buffer);
     printf("\n the length of the input is %d\n",len);
    sprintf(temp,"%d",len);
    strcat(frames,temp);
    strcat(frames,buffer);
}

printf("\nthe frames being sent is %s\n",frames);

recieve();
}
void recieve()
{
    int framelen=strlen(frames);
    printf("the length of the frames is %d",framelen);
    printf("\nframes....\n");
    int i=0;
    while(i<framelen)
    {
        char leninchar=frames[i++];
        int len=(int)leninchar-(int)'0';
 printf("\n");
        while(len>0)
        {
            printf("%c",frames[i++]);
            len--;
        }
    }
}