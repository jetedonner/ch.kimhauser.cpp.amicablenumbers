#include <math.h>
#include <stdio.h>
#include <time.h>

int getSum(int i){
     int tsum = 1;
     for(int y = 2; y <= sqrt(i); y++){
         if(i % y == 0){
             tsum += i/ y + y;
         }
     }
     return tsum;
}

int main() {
    printf ("Please enter End num (220) : ");
    int numUser = 0;
    scanf("%d", &numUser);
    int idx = 0;
    printf ("end num is %d\n", numUser);
    const clock_t begin_time = clock();
    for(int i = 1; i <= numUser; i++){
        int tsum  = getSum(i);
        int tsum2 = getSum(tsum);
        if(i == tsum2 && i != tsum && tsum > i){
            idx++;
            printf("Found (#%d): %d => %d\n", idx,  i,  tsum);
        }
    }
    float time_diff = float(clock() - begin_time );
    float sec = time_diff / 1000000;
    printf ("Found %d amicable number pairs between 1 and %d in %.0f ns (%.3f sec)\n", idx, numUser,  time_diff, sec);
    return 0;
}