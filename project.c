#include<stdio.h>
#include<unistd.h>

int scheduling_process(int processing_no, int processing_no_2)
{
	printf("Process with %d burst time is under execution. \n", processing_no);
	sleep(processing_no);
	printf("The execution of the process with larger burst time is completed.\n");
	printf("Process with %d burst time is under execution \n", processing_no_2);
	sleep(processing_no_2);
	printf("The execution of the process with smaller burst time is completed.\n");
	printf("Now both the processes have completed executing.\n");
}

int main()
{
	int array_burst_time[2], array_arrival_time[2], array_final_burst_time[2], array_small_burst_time[2];
	char array_process_no[2] = {'a','b'};
	printf("Enter the values of arrival time: \n");
	for(int i=0;i<2;i++)
	{
		scanf("%d",&array_arrival_time[i]);
	}
	for(int i=0;i<2;i++)
	{
		array_burst_time[i] = array_arrival_time[i] * 2;
	}
	printf("The respective values of the arrival time and burst time is:\n");
		printf("PROCESS	BT	AT \n");
	for(int i=0;i<2;i++)
	{
		printf("%c 	%d	%d \n",array_process_no[i], array_burst_time[i], array_arrival_time[i]);
	}
	printf("The value with the largest burst time will be selected: \n");
	for(int i=0;i<2;i++)
	{
		if(array_burst_time[i] > array_burst_time[i+1])
		{
			int process_no;
			array_final_burst_time[i] = array_burst_time[i];
			array_final_burst_time[i+1] = array_burst_time[i+1];
			printf("Larger burst time= %d \n",array_final_burst_time[i]);
			printf("Smaller burst time= %d \n",array_final_burst_time[i+1]);
			process_no = scheduling_process(array_final_burst_time[i], array_final_burst_time[i+1]);
			break;
		}
		else if(array_burst_time[i] < array_burst_time[i+1])
		{
			int process_no;
			array_final_burst_time[i] = array_burst_time[i+1];
			array_final_burst_time[i+1] = array_burst_time[i];
			printf("Larger burst time= %d \n",array_final_burst_time[i]);
			printf("Smaller burst time= %d \n",array_final_burst_time[i+1]);
			process_no = scheduling_process(array_final_burst_time[i], array_final_burst_time[i+1]);
			break;
		}
		else if(array_burst_time[i] = array_burst_time[i+1])
		{
			printf("There will be context switching among the processes since they are arriving at the same time.\n");
			break;
		}
	
	}

	return 0;
}
