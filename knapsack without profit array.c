#include<stdio.h>
#include<stdlib.h>
typedef struct jobs{
	float weig;
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
		float prof;
		printf("Weight and profit of item %d: ",i+1);
		scanf("%f%f",&arr[i].weig,&prof);
		arr[i].rat=prof/arr[i].weig;
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
				float rp=rw*arr[i].rat*arr[i].weig.0;
				maxw+=rw*arr[i].weig;
				maxp+=rp;
			}
			else{
				maxw+=arr[i].weig;
				maxp+=arr[i].rat*arr[i].weig;
			}
		}
	}
	printf("Maximum Profit = %0.2f",maxp);
}