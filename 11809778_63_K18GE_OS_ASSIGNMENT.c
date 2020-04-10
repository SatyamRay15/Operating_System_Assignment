#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int function(int a)
{
	printf("Process with %d burst time is under execution. \n", a);
	sleep(a);
	printf("The execution of the process with %d burst time is completed.\n",a);
	printf("\n");
}

int main()
{
	int j;
	float Tat=0,Wat=0,sjf_Tat=0,sjf_Wat=0,awt,ata;
        printf("Enter the number of processes to be executed: \n");
        scanf("%d",&j); 
	int burst_time[j], arrival_time[j], complete_time[j], turnaround_time[j], waiting_time[j],sjf_at[j],sjf_bt[j];
	int process_id[j],sjf_process_id[j];

	printf("Enter the values of arrival time: \n");
	for(int i=1;i<=j;i++)
	{
		scanf("%d",&arrival_time[i]);
		sjf_at[i]=arrival_time[i];
	}
	for(int i=1;i<=j;i++)
	{
		burst_time[i] = arrival_time[i] * 2;
		sjf_bt[i]=burst_time[i];
	}

	printf("The table is as follows:\n");
	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME \n");
	for(int i=1;i<=j;i++)
	{
		process_id[i]=i;
		printf("  P%d\t\t   %d\t\t   %d \n",process_id[i],arrival_time[i],burst_time[i]);
	}
	printf("The value with the largest burst time will be selected: \n");
	for(int k=1;k<=j;k++)
	{
		for(int i=1;i<j;i++)
		{
			if(burst_time[i]<=burst_time[i+1])
			{
			int temp,temp1;
			temp=burst_time[i+1];
			burst_time[i+1]=burst_time[i];
			burst_time[i]=temp;
		
			temp=arrival_time[i+1];
			arrival_time[i+1]=arrival_time[i];
			arrival_time[i]=temp;

			temp1=process_id[i+1];
			process_id[i+1]=process_id[i];
			process_id[i]=temp1;
			}
		}
	}
	printf("The sequence of the execution after selecting the largest BT is given below Table: \n");
	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME    \n"); 
	for(int i=1;i<=j;i++)
	{
	printf("   P%d\t\t    %d\t\t    %d     \n",process_id[i],arrival_time[i],burst_time[i]);
	}

	for(int i=1;i<=j;i++)
	{
	int number;
	number=function(burst_time[i]);
	}
	printf("Now all the process have been executed. \n");
	printf("\n");

	printf("The final table is as follows: \n");
	int sum=arrival_time[1];
	for(int i=1;i<=j;i++)
	{
	sum=sum+burst_time[i];
	complete_time[i]=sum;
	}

	for(int i=1;i<=j;i++)
	{
	turnaround_time[i]=complete_time[i]-arrival_time[i];
	Tat=Tat+turnaround_time[i];
	}

	for(int i=1;i<=j;i++)
	{
 	waiting_time[i]=turnaround_time[i]-burst_time[i];
	Wat=Wat+waiting_time[i];
	}

	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME\t COMPLETE TIME\t TURNAROUND TIME\t WAITING TIME \n");
	for(int i=1;i<=j;i++)
	{
	printf("   P%d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t\t   %d \n",process_id[i],arrival_time[i],burst_time[i],complete_time[i],turnaround_time[i],waiting_time[i]);
	}
		
	Tat=Tat/j;
	printf("The average Turn Around Time of the overall process is: %f \n",Tat);
	
	Wat=Wat/j;
	printf("The average Waiting Time of the overall process is: %f \n", Wat);

	//Shortest Job First
	printf("\n");
	 printf("The table for SHORTEST JOB FIRST is as follows:\n");
        printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME \n");
        for(int i=1;i<=j;i++)
        {
                sjf_process_id[i]=i;
                printf("  P%d\t\t   %d\t\t   %d \n",sjf_process_id[i],sjf_at[i],sjf_bt[i]);
        }
	
	for(int l=1;l<=j;l++)
	{
		for(int i=1;i<j;i++)
		{
			if(sjf_bt[i]<sjf_bt[l])
			{
			int temporary;
			temporary=sjf_at[i];
			sjf_at[i]=sjf_bt[l];
			sjf_bt[l]=temporary;

			temporary=sjf_bt[i];
			sjf_bt[i]=sjf_bt[l];
			sjf_bt[l]=temporary;

			temporary=sjf_process_id[i];
			sjf_process_id[i]=sjf_process_id[l];
			sjf_process_id[l]=temporary;
			}
		}
	}
int st[j],ft[j],wt[j],sjf_ta[j];
for(int i=1;i<=j;i++)
{
	if(i==1)
	{
		st[i]=sjf_at[i];
	}
	else
	{
	st[i]=ft[i-1];
	wt[i]=st[i]-sjf_at[i];
	ft[i]=st[i]+sjf_bt[i];
	sjf_ta[i]=ft[i]-sjf_at[i];
	sjf_Wat=sjf_Wat+wt[i];
	sjf_Tat=sjf_Tat+sjf_ta[i];
	}

}

awt=(float)sjf_Wat/j;
ata=(float)sjf_Tat/j;

printf("\nPROCESS ID\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME \n");
for(int i=1;i<=j;i++)
{
	printf("\n P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t \n",sjf_process_id[i],sjf_at[i],sjf_bt[i],wt[i],sjf_ta[i]);	
}
printf("\n Average Waiting Time is: %f",awt);
printf("\n Average Turnaround Time is: %f",ata);

	return 0;
}
