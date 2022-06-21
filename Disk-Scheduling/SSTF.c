#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("-----SSTF Scheduling-----\n");
    
	//scanning the request
	int n;
	printf("Enter the No.of Requests: "); scanf("%d",&n);
	int q[n];
	for(int i=0; i<n; i++){
		printf("Request %d: ",i+1); scanf("%d",&q[i]);
	}

	//reading current head position
	int head;
	printf("Enter current position of head: "); scanf("%d",&head);

	//calculation of total seek time
    printf("Head Movement: ");
	int seek = 0,dif,index,count=0;
    
    while (count != n){
        int min=1000;
        for (int i = 0; i < n; i++)
        {
            dif = abs(q[i]-head);
            if(min > dif){
                min = dif;
                index = i;
            }
        }
        seek+=min;
        printf("%d ",head);
        head = q[index];
        q[index] = 1000; 
        count++;
    }
    
    printf("%d ",head);
    printf("\nTotal seek: %d",seek);
	
	return 0;
}