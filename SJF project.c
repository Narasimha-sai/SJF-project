#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bursttime[10],temp,j,arivaltime[10],wt[10],turnaroundtime[10],ta=1,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("Enter the No. of processes :\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Arrival time of p%d process :\n",i+1);
scanf("%d",&arivaltime[i]);
//printf("Brust time of p%d process :\n",i+1);
bursttime[i]=2*arivaltime[i];
//printf("%d\n",bt[i]);
}
/*Sorting According to Arrival Time*/
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(arivaltime[i]<arivaltime[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=arivaltime[j];
arivaltime[j]=arivaltime[i];
arivaltime[i]=temp;
temp=bursttime[j];
bursttime[j]=bursttime[i];
bursttime[i]=temp;
}
}
}
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
for(j=0;j<n;j++)
{
btime=btime+bursttime[j];
min=bursttime[k];
for(i=k;i<n;i++)
{
if (btime>=arivaltime[i] && bursttime[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=arivaltime[k];
arivaltime[k]=arivaltime[i];
arivaltime[i]=temp;
temp=bursttime[k];
bursttime[k]=bursttime[i];
bursttime[i]=temp;
}
}
k++;
}
wt[0]=0;
sum=1;
for(i=1;i<n;i++)
{
sum=sum+bursttime[i-1];
wt[i]=sum-arivaltime[i];
wsum=wsum+wt[i];
}
 
wavg=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+bursttime[i];
turnaroundtime[i]=ta-arivaltime[i];
tsum=tsum+turnaroundtime[i];
}
 
tavg=(tsum/n);
 
printf("******************************************************************************");
printf("\n RESULT:-");
printf("\n--------------------------------------------------------------------");
printf("\nPROCESS\t| BURST\t| ARRIVAL\t| WAITING\t| TURN-AROUND-TIME |" );
printf("\n--------------------------------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n| p%d\t|  %d\t|  %d\t\t|  %d\t\t|\t%d\t   |",p[i],bursttime[i],arivaltime[i],wt[i],turnaroundtime[i]);
}
printf("\n--------------------------------------------------------------------\n");
for(i=0;i<n;i++)
{
printf(" p%d,",p[i]);
}
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f\n",tavg);
return 0;
}
