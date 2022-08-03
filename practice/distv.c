#include<stdio.h>
struct 
{
   unsigned dist[20];
   unsigned from[20];
}rt[10];

int main(){
    int n=0;
    int dmat[20][20];
    printf("\nenter the number of nodes \n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].from[j]=j;
        }
    }
    printf("\nmatrix given\n");
     int count=0;

    do
    {
        count=0;
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
        {
        for(int k=0;k<n;k++)
        {
            if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
            {
                rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                rt[i].from[j]=k;
                count++;
            }
        }
        
        }
        }
     
    
    } while (count!=0);


    for(int i=0;i<n;i++)
    {
        printf("\n\nthe distance vector for node %d is\n",(i+1));
        printf("Node\t\tVia\t\tDistance\n");

        for(int j=0;j<n;j++)
        {
            printf("\n%d\t\t%d\t\t%d\n",(j+1),rt[i].from[j]+1,rt[i].dist[j]);
        }
       
    }

     printf("\n\n");

}
