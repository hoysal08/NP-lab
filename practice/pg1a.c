#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
void reciver();
char frames[1024];

int main()
{
    char buffer[256],temp[10];
    int n;
    printf("enter the number of frames you wanna send \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        bzero(buffer,256);
        printf("\nenter the frame %d\n", (i + 1));
        scanf("%s", buffer);
        int len=strlen(buffer);
        printf("\nThe length of the frame is %d",len);
        sprintf(temp,"%d",len);
        strcat(frames,temp);
        strcat(frames,buffer);
    }
    
    reciver();
}

void reciver(){
    printf("\nthe frame recived is %s\n",frames);
    int frameslen=strlen(frames);
    int i=0;
    printf("\nlength of the frame recived is : %d\n",frameslen);
    printf("\nframes....\n");
    while(i<frameslen)
    {
       char leninchar=frames[i++];
       int len=(int)leninchar-(int)'0';
       
       while(len>0)
       {
        printf("%c",frames[i++]);
        len--;
       }
       printf("\n");
    }
}