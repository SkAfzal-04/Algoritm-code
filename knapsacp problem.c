#include<stdio.h>
#include<stdlib.h>
typedef struct jobs{
	float weig;
	float prof;
	float rat;
}jo;
int main(){
	int size,i,j;
	float cap,maxw=0.0,maxp=0.0;
	printf("Enter the number of items: ");
	scanf("%d",&size);
	jo arr[size];
	float rat[size];
	for (i=0;i<size;i++){
		printf("Weight and profit of item %d: ",i+1);
		scanf("%f%f",&arr[i].weig,&arr[i].prof);
		arr[i].rat=arr[i].prof/arr[i].weig;
	}
	printf("Enter the capacity of knapsack: ");
	scanf("%f",&cap);
	
	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j+1].rat>arr[j].rat){
				jo t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
	}

	for(i=0;i<size;i++){
		if (maxw>=cap)
			break;
		else{
			if(maxw+arr[i].weig>cap){
				float rw=(cap-maxw)/arr[i].weig;
				float rp=rw*arr[i].prof;
				maxw+=rw*arr[i].weig;
				maxp+=rp;
			}
			else{
				maxw+=arr[i].weig;
				maxp+=arr[i].prof;
			}
		}
	}
	printf("Maximum Profit = %0.2f",maxp);
}