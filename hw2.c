#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*declar the process struc*/
struct Process {
int processName;
float arrivalTime;
float expectedTotalRunTime;
int priority;
int timeRemaining;
};
/* compare methond for quicksort based on arrival time*/
int ATcompare(const void * a, const void * b)
{
const struct Process *elem1 = a;
const struct Process *elem2 = b;
if ( elem1->arrivalTime < elem2->arrivalTime)
return -1;
else if (elem1->arrivalTime > elem2->arrivalTime)
return 1;
else
return 0;
}



int ATcompare1(const void * a, const void * b)
{
const struct Process *elem1 = a;
const struct Process *elem2 = b;
if ( elem1->expectedTotalRunTime < elem2-> expectedTotalRunTime)
return -1;
else if (elem1->expectedTotalRunTime > elem2->expectedTotalRunTime)
return 1;
else
return 0;
}



/*Assigning Process factory*/
struct Process processFactory(int pName, float arrivalT, float expectedTotalrt, int priority, int tRemain)
{
struct Process p;
p = *(struct Process *) malloc (sizeof(struct Process));
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
/*for (i = 0; i < 50; i++)
{
float runTime = ((float)rand() / (float)(RAND_MAX / 9.9)) + 0.1;
processes[i] = processFactory(i, (float)rand() / (float)(RAND_MAX / 100), runTime , rand() % 4 + 1, ceil(runTime));


}*/
qsort(processes, 50, sizeof(struct Process), ATcompare);
int c;
/*for(c = 0; c < 50; c++)
{
printf("P%i ", processes[c].processName);
printf("%f ", processes[c].arrivalTime);
printf("%f\n", processes[c].expectedTotalRunTime);
}*/
int j;
int k;
int processRunning = 0; float AverageWaitingTime;
struct Process * runnableProcesses = malloc(50 * sizeof(struct Process));
runnableProcesses = processes;
float timeSoFar = 0; int n =2;
float numerator; float Awt_numerator= 0.0;float avgwt= 0.0;
printf("Time \tProcessName \t ArrivalTime \t ExpectedTotalRunTime \t TimeRemaining\n\n");
for(j = 0; j < n; j++)
{

runnableProcesses[processRunning].timeRemaining--;
timeSoFar += runnableProcesses[processRunning].expectedTotalRunTime;


numerator += timeSoFar - runnableProcesses[processRunning].arrivalTime;

/*printf(" %s %.2f \n","expectedTotalRunTime:", runnableProcesses[processRunning].expectedTotalRunTime );
printf("%s %.2f\n", "avgwt: ", avgwt);
printf("%s %i\n", "processRunning", processRunning);*/

if(j <(n-1)){
avgwt += runnableProcesses[processRunning].expectedTotalRunTime;

/*printf(" %s %.2f\n", " Before Awt_numerator :",Awt_numerator);*/

Awt_numerator+=avgwt;
/*printf(" %s %.2f\n", " after add Awt_numerator: ", Awt_numerator );*/
}
processRunning++;
printf("%i \tP%i\t \t%.2f\t\t \t%.2f\t\t\t%i\n",j,runnableProcesses[processRunning].processName,processes[processRunning].arrivalTime,processes[processRunning].expectedTotalRunTime,runnableProcesses[processRunning].timeRemaining);


 


/*printf ("%s %i \n" ,"processRunning", processRunning);
		printf ("%s %f \n" ,"timeSoFar", timeSoFar);
printf(" %s %f\n", "avgwt: ", avgwt );
printf("\n\n\n%f", Awt_numerator);*/

}

float averageTurnAround = numerator/(processRunning);
printf("\n %s %.2f\n", "Average Turnaround Time: ", averageTurnAround);
 AverageWaitingTime = Awt_numerator/(processRunning);
printf("\n %s %.2f\n", "Average Wait Time: ", AverageWaitingTime);
/*printf(" %s %i\n ", "Throughput", processRunning);*/


/*/* SJF*/
/*qsort(processes, 50, sizeof(struct Process), ATcompare1);
float SJF_timeSoFar = 0;
float SJF_numerator; float SJF_awt_numerator= 0.0;
printf("%s \n", "SJF Start Here");
printf("\tTime \tProcessName \t ArrivalTime \t ExpectedTotalRunTime \t TimeRemaining\n\n");
for(j = 0; j < 5; j++)
{
printf("\t%i \tP%i\t \t%.2f\t\t \t%.2f\t\t\t%i\n",j,runnableProcesses[processRunning].processName,processes[processRunning].arrivalTime,processes[processRunning].expectedTotalRunTime,runnableProcesses[processRunning].timeRemaining);
runnableProcesses[processRunning].timeRemaining--;
if(runnableProcesses[processRunning].timeRemaining == 0)
{

SJF_timeSoFar += runnableProcesses[processRunning].expectedTotalRunTime;


SJF_numerator += SJF_timeSoFar - runnableProcesses[processRunning].arrivalTime;
if(j>=1){
SJF_awt_numerator+= processes[processRunning].expectedTotalRunTime;

}

processRunning++;

 
}

}
float SJF_AverageWaitingTime = SJF_awt_numerator/processRunning;
float SJF_averageTurnAround = SJF_numerator/(processRunning);
printf("\n %s %f\n", "Average Turnaround Time: ",SJF_averageTurnAround);
printf("\n %s %f\n", "Average Wait Time: ", SJF_AverageWaitingTime);
printf(" %s %i\n ", "Throughput", processRunning);*/







}