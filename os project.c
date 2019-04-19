#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bursttime[10],temp,j,arivaltime[10],wt[10],turnaroundtime[20],ta=1,sum=0,ct[10];
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("\nEnter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("\nArrival time of p%d process :",i+1);
	scanf("%d",&arivaltime[i]);}
	
printf("\n****BURSTTIME IS DOUBLE OF ARRIVAL TIME*****\n");
	for(i=0;i<n;i++){
	
	printf("\nBurst time of P%d process :",i+1);
	bursttime[i]=2*arivaltime[i];
	printf("%d\n",bursttime[i]);
}
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
wt[0]=0;
sum=1;
for(i=1;i<=n;i++)
{
	if(arivaltime[i-1]==0)
	  sum=sum+1;
sum=sum+bursttime[i-1];
ct[i-1]=sum;
turnaroundtime[i]=ct[i-1]-arivaltime[i-1];
tsum=tsum+turnaroundtime[i];
wt[i]=turnaroundtime[i]-bursttime[i-1];
wsum=wsum+wt[i];
}
 
wavg=(wsum/n);
tavg=(tsum/n);
printf("\n\t\t\t:-RESULT TABLE :-");
printf("\n-----------------------------------------------------------------------------------------------------");
printf("\nPROCESS\t| BURST\t| ARRIVAL\t| COMPLETION TIME\t| TURN-AROUND-TIME | \t WAITING TIME   \t|");
printf("\n-----------------------------------------------------------------------------------------------------");
for(i=0;i<n;i++)
{
	printf("\n| p%d\t|  %d\t|  %d\t\t|\t  %d\t\t|\t%d\t   | \t\t %d\t\t|",p[i],bursttime[i],arivaltime[i],ct[i],turnaroundtime[i+1],wt[i+1]);
}
printf("\n-----------------------------------------------------------------------------------------------------\n");
for(i=0;i<n;i++)
{
printf("\np%d",p[i]);
}
printf("\n\n AVERAGE TURNAROUND TIME: %f",wavg);
printf("\n AVERAGE TURN-AROUND-TIME : %f\n",tavg);
return 0;
}

