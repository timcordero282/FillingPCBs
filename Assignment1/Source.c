#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

//Tim Cordero
// Working alone, not with partner
// Assignment 1
//Due: 9/17/20

	
	// create struct for State
	struct State {
		char processState[10];
	};

	// create struct for PCB
	struct PCB {
		int processId;
		int userId;
		int arrivalTime;   // time units in simulation, not actual time
		int priority;      // base priority						   
		int expectedTimeRemaining;
		int expectedMemoryNeed;
		int expectedPctCPU; // to get an idea of whether CPU bound or IO bound    						   
		int realTime;  // 0 or 1 - whether a real-time process or not (real-time processes may need immediate attention)
		struct State processState; // Not input - initially NEW
		int currentPriority;   // can be increased or lowered based on what has happened with the process - not input - initially same as base priority
		int timeWaitingSoFar;   // Not input - initially zero
		int timeProcessingLastRun; // Not input - initially zero
		int timeProcessingSoFar; // Not input - initially zero
		struct processblock* nextPtr;  // not used in this program
	};
	// create tempPCB
	struct PCB tempPCB;
	// array for PCBs, no more that 600
	struct PCB pcbs[600];
	// counter to load pcbs
	int counter = 0;

	int read() {
		FILE *file = fopen("E:\\OS\\Assignment1\\Assignment1\\Assignment1\\processes.txt", "r");
		do {
			// if no file print an error
			if (file == NULL) {
				printf("FILE ERROR");
			}

			
			else if (counter >= 40) {
				break;
			}
			else {
				
				// read from file and create a temporary PCB to put in array of PCBS
				fscanf_s(file, "%i", &tempPCB.processId);
				fscanf_s(file, "%i", &tempPCB.userId);
				fscanf_s(file, "%i", &tempPCB.arrivalTime);
				fscanf_s(file, "%i", &tempPCB.priority);
				fscanf_s(file, "%i", &tempPCB.expectedTimeRemaining);
				fscanf_s(file, "%i", &tempPCB.expectedMemoryNeed);
				fscanf_s(file, "%i", &tempPCB.expectedPctCPU);
				fscanf_s(file, "%i", &tempPCB.realTime);
				// &tempPCB.processState = "NEW"; // should State be a struct?
				tempPCB.currentPriority = &tempPCB.priority;
				tempPCB.timeWaitingSoFar = 0;
				tempPCB.timeProcessingLastRun = 0;
				tempPCB.timeProcessingSoFar = 0;

				// put temporary PCB into array
				pcbs[counter] = tempPCB;
				counter++;
			}
		} while (fgets != NULL);
		fclose(file);

		for (int i = 0; i <= 39; i++) {
			// print out all process created
			printf("Process ID: %d \n", pcbs[i].processId);
		}

	};
	int findPriority() {
		// find and display all PCBs with given priority
		int cnt = 0;
		int priorityLevel = 0;
		printf("Enter a priority level: ");
		scanf("%d", &priorityLevel);
		for (int i = 0; i < 600; i++) {
			if (pcbs[i].priority == priorityLevel) {
				printf("Process ID:  %d, Priority level:  %d \n" , pcbs[i].processId ,pcbs[i].priority);
				cnt++;
			}
		}
		printf("\n Amount of process with that priority level: %d \n", cnt);
	};

	int display() {
		// display given PCB by finding PCB process ID
		int pcbNumber = 0;
		printf("\nEnter a PCB process ID number to display between 1 and 40: ");
		scanf("%d", &pcbNumber);
		for (int i = 0; i < 600; i++) {
			if (pcbs[i].processId == pcbNumber) {
				printf("\nID: %d , Usr: %d , Arr: %d , Pri: %d , Remain: %d , Mem: %d , CPU: %d \n", pcbs[i].processId, pcbs[i].userId, pcbs[i].arrivalTime, pcbs[i].priority, pcbs[i].expectedTimeRemaining, pcbs[i].expectedMemoryNeed, pcbs[i].expectedPctCPU);
			}
		}
	};

int main() {

	// read function
	read();

	printf("\n");

	//priority function
	findPriority(1);

	//display function
	display(10);

	//Pause to see results
	getchar();
}


