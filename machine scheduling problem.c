#include<stdio.h>
#include<stdlib.h>
typedef struct MacSch{
	int task;
	int start;
	int finish;
} ms;
typedef struct Macs{
	int macn;
	int task;
	int start;
	int finish;
} mc;

int main(){
	int s,n,i,j,k;
	printf("Enter the number of tasks: ");
	scanf("%d",&s);
	ms arr[s];
	for (i=0;i<s;i++){
		printf("Enter task ID start time and finish time: ");
		scanf("%d%d%d",&arr[i].task,&arr[i].start,&arr[i].finish);
	}

	for(i=0;i<s;i++){
		for(j=0;j<s-i-1;j++){
			if (arr[j].start>arr[j+1].start){
				ms t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	printf("Task ID: ");
	for(i=0;i<s;i++){
		printf("T%d	",arr[i].task);
	}
	printf("\nStart Time: ");
	for(i=0;i<s;i++){
		printf("%d	",arr[i].start);
	}
	printf("\nEnd Time: ");
	for(i=0;i<s;i++){
		printf("%d	",arr[i].finish);
	}
	int nm=3;
	ms m[nm][s];
	ms raw;
	raw.task=-1;
	raw.start=-1;
	raw.finish=-1;
	for(i=0;i<nm;i++){
		for(j=0;j<s;j++){
		m[i][j]=raw;
		}
	}
	for(i=0;i<s;i++){
			int f=0;
			for(j=0;j<nm;j++){
				for(k=0;k<i+1;k++){
					if(m[j][k].finish<=arr[i].start){
						m[j][k]=arr[i];
						f=1;
						break;
					}
					else if(m[j][k].start==-1){
						break;
					}
				}
				if(f==1){
					break;
				}
			}
		}

	
	printf("\n");
	printf("T%d",m[0][0].task);
	printf("T%d\n",m[1][0].task);
	for(i=0;i<nm;i++){
		j=0;
		printf("Machine %d:",i+1);
		while (m[i][j].finish!=-1){
			printf("T%d",m[i][j].task);
			j++;
		}
		printf("\n");
	}
	
}