#include <stdio.h>

struct structJob 
{
	char name[32];
	float salary;
	int workerNo;
}sJob;

union unionJob 
{
	char name[32];
	float salary;
	int workNo;
}uJob;

union Job
{
	float salary;
	int workerNo;
}job;


int main()
{
	printf("\n\n\n\n");
	printf("Size of Union = %d bytes", sizeof(uJob));
	printf("\nYou can access all members of a structure at once as sufficient memory.");
	printf("\nSize of Struct = %d bytes", sizeof(sJob));

	printf("\n---------------------------");
	sJob.salary = 14.3;
	printf("%2.1f\n", sJob.salary);
	job.salary = 12.3;  //this variable is not accessed
	// job.workerNo = 100; //but this is accessed
	printf("\nSalary = %2.1f", job.salary);
	// printf("\nNumber of workers = %d", job.workerNo);
	printf("\nMemory Allocated: %d bytes", sizeof(job));	
	printf("\n-----------------------------");
	printf("\nHowever, it's not the case in unions.");
	printf("\nYou can only access a single member of a union at on time.");	
	printf("\n\n");
	
	return 0;	
}
