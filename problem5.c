#include "stdio.h"
#include "stdlib.h"
#define N 6
#define M 5

int BinSearch(int *array[]);

int main(int argc, char *argv[]){
    int array[N][M]={{0}}, i,j;
    int top=0, bottom=N-1, mid, max=-1;
    int high=0, curr_high=0;

    //reads the array
    for(i=0; i<N; i++){
        for(j=0; j<M; j++)
            scanf("%d", &array[i][j]);
    }
    
    for(i=0; i<M; i++){
        top = 0;
        bottom = N-1;
        while(top<bottom){
            mid = top + (bottom - top)/2;

            if((array[mid][i] == 1) && (array[mid+1][i]==1))
                top = mid;
            else if((array[mid][i] == 1) && (array[mid+1][i]==0)){
                curr_high = N -1 - mid;
                break;
            }else if((array[mid][i] == 0) && (array[mid-1][i]==0))
                bottom = mid;
            else if((array[mid][i] == 0) && (array[mid-1][i]==1)){
                curr_high = N - mid;
                break;
            }

            if(bottom==top+1)
                break;
        }
        if(curr_high >= high){
            high = curr_high;
            max = i;
        }
    }
    printf("THE TALLEST BUILDING IS %d\n", max);
    return(0);
}
