#include<stdio.h>

int main(){
    int n, m, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter number of resources: ");
    scanf("%d", &m);
    
    int allocation[n][m], max[n][m], need[n][m];
    
    printf("Enter allocation matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &allocation[i][j]);
        }
    }
    
    printf("Enter max matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter available resources: ");
    int available[m];
    for(i=0; i<m; i++){
        scanf("%d", &available[i]);
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    int work[m];
    for(i=0; i<m; i++){
        work[i] = available[i];
    }
    
    int finish[n], safeSequence[n], count=0;
    for(i=0; i<n; i++){
        finish[i] = 0;
    }
    
    int needFlag;
    while(count < n){
        needFlag = 0;
        for(i=0; i<n; i++){
            if(finish[i] == 0){
                int j;
                for(j=0; j<m; j++){
                    if(need[i][j] > work[j]){
                        needFlag = 1;
                        break;
                    }
                }
                
                if(needFlag == 0){
                    for(j=0; j<m; j++){
                        work[j] += allocation[i][j];
                    }
                    
                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                }
            }
        }
        
        if(needFlag == 1){
            break;
        }
    }
    
    if(count < n){
        printf("System is in unsafe state");
    } else {
        printf("System is in safe state");
        printf("Safe sequence: ");
        for(i=0; i<n; i++){
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    }
    
    return 0;
}
