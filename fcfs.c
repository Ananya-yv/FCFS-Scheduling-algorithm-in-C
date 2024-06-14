/*

Name: FCFS CPU Scheduling algorithm using c
date: 14.06.2024
features:
--> perform FCFS scheduling algorithm.
--> sort processes based on arrival times.
--> if CPU is idle, move time to next jobs arrival.
--> print the Arrival time, Burst time, Completition time, Turn around time, Waiting time.
--> Calculate Avg tat, avg wt.
--> Show CPU idle time periods

*/



#include<stdio.h>

void swap(int *a,int *b){    //swap processes based on at
    int temp= *a;
    *a=*b;
    *b=temp;
}

int main(){
    int n,i,j;
    printf("enter number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n],p[n],tat[n],wt[n],ct[n];
    printf("enter arrival times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);   // input arrival times
    }
    printf("enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);   //input burst times
    }

    j=0,i=1;
    while(j<n){
        p[j]=i;    // assign process names
        i++;
        j++;
    }
    
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){      // sort processes according to arrival times
            if(at[j]<at[min])
            min=j;
        }
        swap(&at[i],&at[min]);
        swap(&p[i],&p[min]);
        swap(&bt[i],&bt[min]);
        
    }
    int st[n];
    int time = 0;   // current running time
    

    // Calculate times for each job
  
    for (i = 0; i < n; i++) {
         if (time < at[i]) {
            printf("CPU is idle from time %d to %d\n", time, at[i]);
            idle += at[i] - time;   // calculate and print CPU idle time
            time = at[i]; // If CPU is idle, move time to next job's arrival time
        }
        st[i] = time;
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];  
        
    }
    
    int tottat=0;
    int totwt=0;
  
    for(i=0;i<n;i++){
        tottat = tottat+tat[i];
        totwt = totwt+wt[i];
    }
    
    float avgtat=tottat/n;  // calculate average tat,wt
    float avgwt=totwt/n;
    
    printf("p\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average turn around time= %f\n",avgtat);
    printf("Average waiting time= %f",avgwt);
    return 0;
}
