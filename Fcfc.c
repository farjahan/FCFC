#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Process {
	int processName;
	float arrivalTime;
	float expectedTotalRunTime;
	int priority;
	int timeRemaining;
};
int ATcompare(const void * a, const void * b)
{

	const struct Process *elem1 = a;
	const struct Process *elem2 = b;

	if (elem1->arrivalTime < elem2->arrivalTime)
		return -1;
	else if (elem1->arrivalTime > elem2->arrivalTime)
		return 1;
	else
		return 0;
}
	int ERTcompare(const void * a, const void * b)
	{
		const struct Process *elem1 = a;
		const struct Process *elem2 = b;

	    if (elem1->expectedTotalRunTime < elem2->expectedTotalRunTime)
		return -1;
     else if (elem1->expectedTotalRunTime > elem2->expectedTotalRunTime)
		return 1;
	 else
		return 0;
}
struct Process processFactory(int pName, float arrivalT, float expectedTotalrt, int priority, int tRemain)
{
	struct Process p;
	p = *(struct Process *) malloc(sizeof(struct Process));
	p.processName = pName;
	p.arrivalTime = arrivalT;
	p.expectedTotalRunTime = expectedTotalrt;
	p.priority = priority;
	p.timeRemaining = tRemain;
	return p;
}
int main(void) {

	int i;
	srand(time(NULL));
	struct Process * processes = malloc(50 * sizeof(struct Process));
	for (i = 0; i < 50; i++)
	{
		float runTime = ((float)rand() / (float)(RAND_MAX / 9.9)) + 0.1;
		processes[i] = processFactory(i, (float)rand() / (float)(RAND_MAX / 100), runTime, rand() % 4 + 1, ceil(runTime));
		
	}
	qsort(processes, 50, sizeof(struct Process), ERTcompare);
	int c;
	for (c = 0; c < 50; c++)
	{
		/*printf("P%i ", processes[c].processName);
		printf("%f ", processes[c].arrivalTime);
		printf("%f\n", processes[c].expectedTotalRunTime);*/
	}
	int j;float averageWaitTime ;
	int k;
	int processRunning = 0; float throughput = 0.0;
	struct Process * runnableProcesses = malloc(50 * sizeof(struct Process));
	runnableProcesses = processes;
	float timeSoFar = 0; int n = 3;
	float numerator;
	printf("\n\n\tTime \tProcessName \t ArrivalTime \t ExpectedTotalRunTime \t TimeRemaining\n");

	
	for (j = 0; j < n; j++)
	{
		printf("\t%i ", j);
		printf("\tP%i ", runnableProcesses[processRunning].processName);
		printf("\t\t%.2f\t", processes[processRunning].arrivalTime);
		printf("\t\t%.2f\t", processes[processRunning].expectedTotalRunTime);
		printf("\t\t%i\n", runnableProcesses[processRunning].timeRemaining);
		runnableProcesses[processRunning].timeRemaining--;
		
			/*printf("\n%s %.2f\n\n\n", "timeSoFar",timeSoFar);*/
			averageWaitTime =timeSoFar;
			timeSoFar += runnableProcesses[processRunning].expectedTotalRunTime;

			/*printf("\n%s %.2f\n\n\n", "Afteradd expecing time timeSoFar: ",timeSoFar);
			printf("%s %.2f\n","numerator",numerator);*/
			numerator += timeSoFar - runnableProcesses[processRunning].arrivalTime;
			/*printf("%s %.2f\n","after numerator",numerator);*/

			throughput+=processes[processRunning].expectedTotalRunTime;
			/*printf("%s %.2f\n","throughput:",throughput );*/


			processRunning++;
		
	
}
	float averageTurnAround = numerator /processRunning;
	averageWaitTime=averageWaitTime/processRunning;
	throughput=throughput/processRunning;
	printf("\n%s %.2f\n", "average Turnaround for FCFC:", averageTurnAround);
	printf ("%s %.2f\n ", "average Wait Time FCFC:",averageWaitTime);
	printf("%s %.2f\n", "Average response time", throughput);
	printf ("%s %.2f\n\n ", "Throughput :",throughput );



/*SJF*/


/*for (j = 0; j < n; j++)
	{
		printf("\t%i ", j);
		printf("\tP%i ", runnableProcesses[processRunning].processName);
		printf("\t\t%.2f\t", processes[processRunning].arrivalTime);
		printf("\t\t%.2f\t", processes[processRunning].expectedTotalRunTime);
		printf("\t\t%i\n", runnableProcesses[processRunning].timeRemaining);
		runnableProcesses[processRunning].timeRemaining--;
		*/
			/*printf("\n%s %.2f\n\n\n", "timeSoFar",timeSoFar);*/
			/*averageWaitTime =timeSoFar;
			timeSoFar += runnableProcesses[processRunning].expectedTotalRunTime;

			printf("\n%s %.2f\n\n\n", "Afteradd expecing time timeSoFar: ",timeSoFar);
			printf("%s %.2f\n","numerator",numerator);
			numerator += timeSoFar - runnableProcesses[processRunning].arrivalTime;
			/*printf("%s %.2f\n","after numerator",numerator);*/

			//throughput+=processes[processRunning].expectedTotalRunTime;
			//printf("%s %.2f\n","throughput:",throughput );


			//processRunning++;
		
	


/*printf("\n%s ", "average Turnaround for SJF:");
printf ("%s ", "average Wait Time SJF:");
printf("%s \n", "Average response time");
printf ("%s \n ", "Throughput " );
*/






/*Shortest Remaining Time First */


printf("%s\n", "Shortest Remaining Time First " );
float currentexpectedTotalRunTime =0, oldexpectedTotalRunTime =0.0;  int a[100],b[100]; int count =0;
printf("\n\n\tTime \tProcessName \t ArrivalTime \t ExpectedTotalRunTime \t TimeRemaining\n");
for (j = 0; j < n; j++)
	{
		/*printf("\t%i ", j);
		printf("\tP%i\t ", runnableProcesses[processRunning].processName);
		printf("\t\t%.2f", processes[processRunning].arrivalTime);
		printf("\t\t%.2f\t", processes[processRunning].expectedTotalRunTime);
		printf("\t\t%i\n", runnableProcesses[processRunning].timeRemaining);*/
		runnableProcesses[processRunning].timeRemaining--;
		a[j] =processes[processRunning].expectedTotalRunTime; b[count] =a[j];
		
		if( j>1 && a[j<b[count]]){

				printf("%s","Do nothing");

		}


		
count ++;
	printf("%.2f\n\n", currentexpectedTotalRunTime);
	printf("%.2f\n\n", oldexpectedTotalRunTime);

}
	// float averageTurnAround = numerator /processRunning;
	// averageWaitTime=averageWaitTime/processRunning;
	// throughput=throughput/processRunning;
	printf("\n%s %.2f\n", "average Turnaround for SRT:", averageTurnAround);
	printf ("%s %.2f\n ", "average Wait Time SRT:",averageWaitTime);
	printf("%s %.2f\n", "Average response time", throughput);
	printf ("%s %.2f\n\n ", "Throughput :",throughput );










}