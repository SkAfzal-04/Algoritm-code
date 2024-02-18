#include<stdio.h>
#include<stdlib.h>
typedef struct jobs{
	int job;
	int deadl;
	int prof;
}jo;
int main(){
	int size,i,j;
	printf("How many jobs you want to insert: ");
	scanf("%d",&size);
	jo arr[size];
	for (i=0;i<size;i++){
		printf("Job ID: ");
		scanf("%d",&arr[i].job);
		printf("Deadline: ");
		scanf("%d",&arr[i].deadl);
		printf("Profit: ");
		scanf("%d",&arr[i].prof);
	}

	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j+1].prof>arr[j].prof){
				jo t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
	}

	int max=arr[0].deadl;
	for(i=0;i<size;i++){
		if (arr[i].deadl>max)
			max=arr[i].deadl;
	}
	int res[max],rec[max];
	int r=0,maxprof=0;
	for(i=0;i<size;i++){
		if (r==max)
			break;
		else{
			int f=0;
			for(int c=0;c<max;c++){
				if(arr[i].deadl==rec[c]){
					f=1;
					break;
				}
			}
			if (f==0){
			maxprof+=arr[i].prof;
			res[arr[i].deadl-1]=arr[i].job;
			rec[r]=arr[i].deadl;
			r++;
			}
		
	}
	}
	printf("Maximum profit=%d\n",maxprof);
	for(i=0;i<max;i++)
		if (i==max-1){
			printf("J%d",res[i]);
		}
		else{
		printf("J%d-->",res[i]);
		}
	
}