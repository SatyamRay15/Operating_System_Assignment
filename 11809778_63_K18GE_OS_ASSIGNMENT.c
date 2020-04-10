//Qusetion Number 17  Project done by:Satyam Kumar Ray  Registration No.:11809778  Roll No.:B63
//Header Files
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int function(int a)        //Function to execute the process
{
	printf("Process with %d burst time is under execution. \n", a);
	sleep(a);
	printf("The execution of the process with %d burst time is completed.\n",a);
	printf("\n");
}

int main()                              //Main process
{
	//Declaration of variables
	int j;
	float Tat=0, Wat=0, sjf_Tat=0, sjf_Wat=0;

	//The number of processes taken from user
        printf("Enter the number of processes to be executed: \n");
        scanf("%d",&j);

	//Declaration of variables
	int burst_time[j], arrival_time[j], complete_time[j], turnaround_time[j], waiting_time[j];
	int sjf_at[j], sjf_bt[j], sjf_complete_time[j], sjf_turnaround_time[j],sjf_waiting_time[j];
	int process_id[j], sjf_process_id[j];

	//Arrival time taken from the user
	printf("Enter the values of arrival time: \n");
	for(int i=1;i<=j;i++)
	{
		scanf("%d",&arrival_time[i]);
		sjf_at[i]=arrival_time[i];
	}

	//Burst Time is doubled here by multiplying by two
	for(int i=1;i<=j;i++)
	{
		burst_time[i] = arrival_time[i] * 2;
		sjf_bt[i]=burst_time[i];
	}

	//Printing the initial Table
	printf("The table is as follows:\n");
	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME \n");
	for(int i=1;i<=j;i++)
	{
		process_id[i]=i;                 //As this process array is empty, we are allocating the values to it.
		printf("  P%d\t\t   %d\t\t   %d \n",process_id[i],arrival_time[i],burst_time[i]);
	}

	//Here we are using the sorting method to sort the processes and select the largest from it
	printf("The value with the largest burst time will be selected: \n");
	for(int k=1;k<=j;k++)
	{
		for(int i=1;i<j;i++)
		{
			if(burst_time[i]<=burst_time[i+1])
			{
			//Swapping is done here if the above if condition is true
			int temp;                                  //Swapping of Burst Time
			temp=burst_time[i+1];
			burst_time[i+1]=burst_time[i];
			burst_time[i]=temp;

			temp=arrival_time[i+1];                    //Swapping of Arrival Time
			arrival_time[i+1]=arrival_time[i];
			arrival_time[i]=temp;

			temp=process_id[i+1];                     //Swapping of Process Id
			process_id[i+1]=process_id[i];
			process_id[i]=temp;
			}
		}
	}

	//The Table which is displayed after the sorting is done
	printf("The sequence of the execution after selecting the largest BT is given below Table: \n");
	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME    \n"); 
	for(int i=1;i<=j;i++)
	{
	printf("   P%d\t\t    %d\t\t    %d     \n",process_id[i],arrival_time[i],burst_time[i]);
	}

	//Here the processes will be executed using function which is on the top (Function Call)
	for(int i=1;i<=j;i++)
	{
	int number;
	number=function(burst_time[i]);
	}
	printf("Now all the process have been executed. \n");
	printf("\n");


	//Here complete time is calculated. As the arrival time of the largest process is taken first, the first
	//arrival time is added in order to keep the consistency and to find out the accurate Wating time and TAT
	int sum=arrival_time[1];
	for(int i=1;i<=j;i++)
	{
	sum=sum+burst_time[i];
	complete_time[i]=sum;
	}

	//Here the Turnaround Time is calculated using the formula TAT=Complete Time-Arrival Time
	for(int i=1;i<=j;i++)
	{
	turnaround_time[i]=complete_time[i]-arrival_time[i];
	Tat=Tat+turnaround_time[i];
	}

	//Here the Waiting Time is calculated using the formulae Waiting=TAT-Burst Time
	for(int i=1;i<=j;i++)
	{
 	waiting_time[i]=turnaround_time[i]-burst_time[i];
	Wat=Wat+waiting_time[i];
	}

	//Here the final Table is displayed. All the values are displayed
        printf("The final table is as follows: \n");

	printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME\t COMPLETE TIME\t TURNAROUND TIME\t WAITING TIME \n");
	for(int i=1;i<=j;i++)
	{
	printf("   P%d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t\t   %d \n",process_id[i],arrival_time[i],burst_time[i],complete_time[i],turnaround_time[i],waiting_time[i]);
	}

	//Here the average Turnaround Time is calculated and displayed	
	Tat=Tat/j;
	printf("The average Turn Around Time of the overall process is: %f \n",Tat);

	//Here the Average Waiting Time is calculated and displayed
	Wat=Wat/j;
	printf("The average Waiting Time of the overall process is: %f \n", Wat);

	//Shortest Job First
	//Table of the SJF is displayed using the same same attribute values
	printf("\n");
	printf("The table for SHORTEST JOB FIRST is as follows:\n");
        printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME \n");
        for(int i=1;i<=j;i++)
        {
		sjf_process_id[i]=i;            //As this process array is empty, we are allocating the values to it.
                printf("  P%d\t\t   %d\t\t   %d \n",sjf_process_id[i],sjf_at[i],sjf_bt[i]);
        }

	//Here we are sorting the processes into acending order. If we want to execute the processes having lowest burst
	//time which will be automatically having the lowest arrival time.
	for(int l=1;l<=j;l++)
	{
		for(int i=1;i<j;i++)
		{
			if(sjf_bt[i]>=sjf_bt[i+1])
			{
			//Swapping is done if the above if condition is true
			int temporary;
			temporary=sjf_at[i+1];            //Swapping of arrival time
			sjf_at[i+1]=sjf_bt[i];
			sjf_bt[i]=temporary;

			temporary=sjf_bt[i+1];           //Swapping of burst time
			sjf_bt[i+1]=sjf_bt[i];
			sjf_bt[i]=temporary;

			temporary=sjf_process_id[i+1];     //Swapping of process id
			sjf_process_id[i+1]=sjf_process_id[i];
			sjf_process_id[i]=temporary;
			}
		}
	}

	//Here we will be printing the Table after sorting is done
        printf("The sequence of the execution after selecting the largest BT is given below Table: \n");
        printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME    \n"); 
        for(int i=1;i<=j;i++)
        {
        printf("   P%d\t\t    %d\t\t    %d     \n",sjf_process_id[i],sjf_at[i],sjf_bt[i]);
        }

	//Here we are calculating the Complete Time using SJF (Non-Preemption)
	int sum1=0;
        for(int i=1;i<=j;i++)
        {
        sum1=sum1+sjf_bt[i];
        sjf_complete_time[i]=sum1;
        }

	//Here the Turnaround Time using SJF(Non-preemption) is calculated using the formula TAT=Complete Time-Arrival Time
        for(int i=1;i<=j;i++)
        {
        sjf_turnaround_time[i]=sjf_complete_time[i]-sjf_at[i];
        sjf_Tat=sjf_Tat+sjf_turnaround_time[i];
        }

        //Here the Waiting Time using SJF(Non-preemption) is calculated using the formulae Waiting=TAT-Burst Time
        for(int i=1;i<=j;i++)
        {
        sjf_waiting_time[i]=sjf_turnaround_time[i]-sjf_bt[i];
        sjf_Wat=sjf_Wat+sjf_waiting_time[i];
        }

//Here the final table is being printed
printf("This is the final table using Shortest Job First \n");
printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME\t COMPLETE TIME\t TURNAROUND TIME\t WAITING TIME\t \n");
for(int i=1;i<=j;i++)
{
	printf("  P%d\t\t   %d\t\t   %d\t\t   %d\t\t   %d\t\t\t   %d \n",sjf_process_id[i],sjf_at[i],sjf_bt[i],sjf_complete_time[i],sjf_turnaround_time[i],sjf_waiting_time[i]);
}

//Here the Average Turnaround Time is being calculated and printed in SJF
sjf_Tat=sjf_Tat/j;
printf("\n Average Turnaround Time using SJF (Non-Preemption) is: %f",sjf_Tat);

//Here the Average Waiting Time is being calculated and printed in SJF
sjf_Wat=sjf_Wat/j;
printf("\n Average Waiting Time using SJF (Non-Preemption) is: %f",sjf_Wat);

return 0;
} 
