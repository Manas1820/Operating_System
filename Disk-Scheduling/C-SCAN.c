#include <stdio.h>
#include <stdlib.h>

int main()
{
    int track1[30], track2[30], track3[30];
    int limit, disk_head, count = 0, j, seek_time = 0, range, diff;
    int t1, t2 = 0, t3 = 0;
    printf("Maximum Range of Disk:\t");
    scanf("%d", &range);
    printf("Initial Head Position:\t");
    scanf("%d", &disk_head);
    printf("track Request Size:\t");
    scanf("%d", &limit);
    printf("Disk track Element Positions:\n");
    while (count < limit)
    {
        scanf("%d", &t1);
        if (t1 >= disk_head)
        {
            track1[t2] = t1;
            t2++;
        }
        else
        {
            track2[t3] = t1;
            t3++;
        }
        count++;
    }
    count = 0;
    while (count < t2 - 1)
    {
        j = count + 1;
        while (j < t2)
        {
            if (track1[count] > track1[j])
            {
                t1 = track1[count];
                track1[count] = track1[j];
                track1[j] = t1;
            }
            j++;
        }
        count++;
    }
    count = 0;
    while (count < t3 - 1)
    {
        j = count + 1;
        while (j < t3)
        {
            if (track2[count] > track2[j])
            {
                t1 = track2[count];
                track2[count] = track2[j];
                track2[j] = t1;
            }
            j++;
        }
        count++;
    }
    count = 1;
    j = 0;
    while (j < t2)
    {
        track3[count] = track1[j];
        track3[count] = range;
        track3[count + 1] = 0;
        count++;
        j++;
    }
    count = t2 + 3;
    j = 0;
    while (j < t3)
    {
        track3[count] = track2[j];
        track3[0] = disk_head;
        count++;
        j++;
    }
    for (j = 0; j <= limit + 1; j++)
    {
        diff = abs(track3[j + 1] - track3[j]);
        seek_time = seek_time + diff;
        printf("\nDisk Head:\t%d -> %d [Seek Time: %d]\n", track3[j], track3[j + 1], diff);
    }
    printf("\nTotal Seek Time:\t%d\n", seek_time);
    return 0;
}