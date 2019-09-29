#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define drawLine for(int i=0;i<60;i++) printf("*");printf("\n");

struct JOB {
	int id;
	int priority;
	int arrival;
	int cpuBust[101];
	int ioBust[100];
	int bustCount;
	int bustSum;
	int remaining;
	int entry;
	int reentry;
	int end;
} typedef JOB; 

void sort(JOB * jobs, int parameter){
	
   JOB valueToInsert;
   int holePosition;
   int i;
  
   for(i = 1; i < 20; i++) { 	 
      valueToInsert = jobs[i];		 
      holePosition = i;		
	switch(parameter){
		case 0:
			// Sort by arrival time	
		      while (holePosition > 0 && jobs[holePosition-1].arrival > valueToInsert.arrival) {
			 jobs[holePosition] = jobs[holePosition-1];
			 holePosition--;
		      }		
			break;
		case 1:
			// Sort by priority 
		      while (holePosition > 0 && jobs[holePosition-1].priority > valueToInsert.priority) {
			 jobs[holePosition] = jobs[holePosition-1];
			 holePosition--;
		      }
			break;
		case 2:
			// Sort by JobID
		      while (holePosition > 0 && jobs[holePosition-1].id > valueToInsert.id) {
			 jobs[holePosition] = jobs[holePosition-1];
			 holePosition--;
		      }
			break;
		case 3:
			// Sort by Exit time
		      while (holePosition > 0 && jobs[holePosition-1].end > valueToInsert.end) {
			 jobs[holePosition] = jobs[holePosition-1];
			 holePosition--;
		      }
			break;
	}
      if(holePosition != i) {
         jobs[holePosition] = valueToInsert;
      }		
   } 
}

void doFCFS(JOB * jobs){	
	int jobRemainingCount = 20;
	JOB pipeline[20];
	int jobCurIdx = 0;
	int pipeIdx = 0;
	sort(jobs,0);	// sorting jobs by arrival time	
	int jobCount = 0;
	long long int timer = 0;
	printf("Gantt Chart: ");
	while(jobRemainingCount>0 && timer < 10000000){	
		if(jobs[jobCurIdx].arrival <= timer){
			printf("P%d ",jobs[jobCurIdx].id);
			pipeline[pipeIdx] = jobs[jobCurIdx++];
			pipeline[pipeIdx].entry = timer;
			pipeline[pipeIdx].end = timer + pipeline[pipeIdx].bustSum;
			timer = pipeline[pipeIdx].end;
			jobCount++;
			jobRemainingCount--;
			pipeIdx++;
		} 
		else{
			timer++;
		}
	}
	printf("\nJOBID\tArrival\tEntry\tExit\tTurnaround\n");
	int waitTime = 0;
	for(int i = 0; i < 20; i++){
		JOB j = pipeline[i];
		printf("%d\t%d\t%d\t%d\t%d\n",j.id,j.arrival,j.entry,j.end,j.end-j.entry);
		waitTime += j.entry - j.arrival;
	}
	printf("\nTotal Time: %lld units",timer);
	printf("\nAverage Waiting Time: %f units\n",waitTime/20.0);
}

void doPriority(JOB * jobs){	
	int jobRemainingCount = 20;
	JOB pipeline[20];
	int jobCurIdx = 0;
	int pipeIdx = 0;
	sort(jobs,1);	// sorting jobs by arrival time	
	int jobCount = 0;
	long long int timer = 0;
	int jobIDtrack[21] = {0};
	printf("Gantt Chart: ");
	while(jobRemainingCount>0 && timer < 10000000){	
		int min = 21;
		for(int i = 0; i < 20; i++){
			if(jobs[i].arrival <= timer && min > jobs[i].priority && jobIDtrack[jobs[i].id]==0){
				jobCurIdx = i;
				min = jobs[i].priority;
			}
		}
		if(jobs[jobCurIdx].arrival <= timer){
			printf("P%d ",jobs[jobCurIdx].id);
			pipeline[pipeIdx] = jobs[jobCurIdx];
			jobIDtrack[jobs[jobCurIdx].id] = 1;
			pipeline[pipeIdx].entry = timer;
			pipeline[pipeIdx].end = timer + pipeline[pipeIdx].bustSum;
			timer = pipeline[pipeIdx].end;
			jobCount++;
			jobRemainingCount--;
			pipeIdx++;
		} 
		else{
			timer++;
		}
	}
	printf("\nJOBID\tPriority\tArrival\tEntry\tExit\tTurnaround\n");
	int waitTime = 0;
	for(int i = 0; i < 20; i++){
		JOB j = pipeline[i];
		printf("%d\t%d\t\t%d\t%d\t%d\t%d\n",j.id,j.priority,j.arrival,j.entry,j.end,j.end-j.entry);
		waitTime += j.entry - j.arrival;
	}
	printf("\nTotal Time: %lld units",timer);
	printf("\nAverage Waiting Time: %f units\n",waitTime/20.0);
}

void doRR(JOB * jobs, int q){	
	long long int timer = 0;
	int jobCount = 0;
	int jobPtr = 0;
	sort(jobs,0);	// sorting jobs by arrival time	
	int jobBustStatus[21] = {0};
	int jobStart[21] = {0};
	printf("Gantt Chart: ");
	while (jobCount != 20)
	{
		if(jobs[jobPtr].reentry <= timer && jobBustStatus[jobs[jobPtr].id] != -1){
			
			if(jobStart[jobPtr]==0) {
				jobs[jobPtr].entry = timer;
				jobStart[jobPtr] = timer;
			}
			int i = jobBustStatus[jobs[jobPtr].id];
			int chunk = jobs[jobPtr].cpuBust[i];
			printf("P%d",jobs[jobPtr].id);
			if( chunk > q){
				jobs[jobPtr].cpuBust[i] -= q;
				jobs[jobPtr].remaining -= q;
				timer += q;	
			}
			else {
				jobs[jobPtr].cpuBust[i] = 0;
				timer += chunk;
				jobs[jobPtr].reentry = timer + jobs[jobPtr].ioBust[i];
				jobs[jobPtr].ioBust[i] = 0;
				jobBustStatus[jobs[jobPtr].id]++;
				if(jobs[jobPtr].cpuBust[jobBustStatus[jobs[jobPtr].id]] == 0){
					jobs[jobPtr].end = jobs[jobPtr].reentry;
					jobBustStatus[jobs[jobPtr].id] = -1;
					printf("*");
					jobCount++;
				}
			}
			printf(" ");				
		} 
		else{
			timer++;
		}
		if(jobPtr==19) printf(" | ");
		jobPtr = (jobPtr+1)%20;
	}	
	sort(jobs,3);
	printf("\nJOBID\tPriority\tArrival\tEntry\tExit\tTurnaround\n");
	int waitTime = 0;
	for(int i = 0; i < 20; i++){
		JOB j = jobs[i];
		printf("%d\t%d\t\t%d\t%d\t%d\t%d\t\n",j.id,j.priority,j.arrival,j.entry,j.end,j.end-j.entry);
		waitTime += j.entry - j.arrival;
	}
	printf("\nTotal Time: %lld units",timer);
	printf("\nAverage Waiting Time: %f units\n",waitTime/20.0);
}

void printJob(JOB j){
	printf("%d\t",j.id);
	printf("%d\t",j.priority);
	printf("%d\t\t",j.arrival);
	int t = 0;
	while(t < j.bustCount ){
		if(t%2==0)
			printf("%d ",j.cpuBust[t/2]);
		else
			printf("%d ",j.cpuBust[(t-1)/2]);
		t++;
	}
	printf("\n");
}

int main(int argc, char *argv[] ){
	FILE * jobsFile;
	jobsFile = fopen(argv[1],"r");
	if(jobsFile == NULL){
		printf("Error opening file.\n");
		exit(0);
	}
	JOB jobs[20];
	int jobIndex = 0;
	int jobIndexJ = 0;
	int temp,sum;
	do
	{
		sum = 0;
		JOB tempjob;
		fscanf(jobsFile,"%d", &tempjob.id);
		fscanf(jobsFile,"%d", &tempjob.priority);
		fscanf(jobsFile,"%d", &tempjob.arrival);
		tempjob.reentry = tempjob.arrival;
		int t = 0;
		fscanf(jobsFile,"%d", &temp);
		while(temp != -1 ){
			sum += temp;
			if(t==201){
				printf("BUST LIMIT EXCEED");
				exit(0);
			}
			if(t%2==0){
				tempjob.cpuBust[t/2] = temp;
			}
			else{
				tempjob.cpuBust[(t-1)/2] = temp;
			}
			fscanf(jobsFile,"%d", &temp);
			t++;
		}
		tempjob.bustSum = sum;
		tempjob.bustCount = t;
		tempjob.remaining = sum;
		jobs[jobIndex++] = tempjob;
	}
	while(!feof(jobsFile) && jobIndex < 20);
	fclose(jobsFile);

	printf("\nOS Schedulling Simulation\n\nJob Sheet\n");
	printf("\nJOBID\tPrior\tArrival\t\tBust Time\n");
	for (int i = 0; i < 20 ; i++) {
		printJob(jobs[i]);	
	}

	printf("\nFirst Come First Serve\n\n");
	doFCFS(jobs);
	drawLine	

	printf("\nNon Preemptive Priority\n\n");
	doPriority(jobs);
	drawLine

	printf("\nRound Robin\n\n");
	doRR(jobs,20);
	drawLine

/*
	printf("\nSorted by Priority\n");
	sort(jobs,1);
	for (int i = 0; i < 20 ; i++) {
		printJob(jobs[i]);	
	}
	printf("\nSorted by JOBID\n");
	sort(jobs,2);
	for (int i = 0; i < 20 ; i++) {
		printJob(jobs[i]);	
	}
*/
}
