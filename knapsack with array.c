#include<stdio.h>
#include<stdlib.h>
int main(){
	int size,i,j;
	float cap,maxw=0.0,maxp=0.0;
	printf("Enter the number of items: ");
	scanf("%d",&size);
	float prof[size],weig[size];
	for (i=0;i<size;i++){
		printf("Weight and profit of item %d: ",i+1);
		scanf("%f%f",&weig[i],&prof[i]);
	}
	printf("Enter the capacity of knapsack: ");
	scanf("%f",&cap);
	
	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(prof[j+1]/weig[j+1]>prof[j]/weig[j]){
				float tr=prof[j+1];
				prof[j+1]=prof[j];
				prof[j]=tr;
				float tw=weig[j+1];
				weig[j+1]=weig[j];
				weig[j]=tw;
			}
		}
	}

	for(i=0;i<size;i++){
		if (maxw>=cap)
			break;
		else{
			if(maxw+weig[i]>cap){
				float rw=(cap-maxw)/weig[i];
				float rp=rw*prof[i];
				maxw+=rw*weig[i];
				maxp+=rp;
			}
			else{
				maxw+=weig[i];
				maxp+=prof[i];
			}
		}
	}
	printf("Maximum Profit = %0.2f",maxp);
}