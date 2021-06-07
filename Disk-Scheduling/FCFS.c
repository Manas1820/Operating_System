#include <stdio.h>
#include <stdlib.h>


int main()
{
    int size = 8;
    int arr[8] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
  
    int count = 0;
    int distance, cur_track;
  
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        count += distance;
        head = cur_track;
    }

    printf("Total number of seek operations = %d \n", count);

    printf("Sequence is\n");
  
    for (int i = 0; i < size; i++) {
        printf("%d -> ",arr[i]);
    }
    printf("completed\n");
  
    return 0;
}