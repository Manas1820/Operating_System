//SCAN disk Schduling algorithm
#include <iostream>
#include <stdlib.h>
using namespace std;
class scan_disk
{
    int ref[100];
    int totalTracks, currentPos, size, prev;
    int sort();

public:
    void getdata();
    void total_move();
};
int scan_disk::sort()
{
    int temp;
    for (int i = 0; i < size - 1; i++)
        for (int y = 0; y < size - 1; y++)
            if (ref[y] > ref[y + 1])
            {
                temp = ref[y + 1];
                ref[y + 1] = ref[y];
                ref[y] = temp;
            }
    for (int i = 0; i < size; i++)
        if (ref[i] > currentPos)
            return i;
    return size;
}
void scan_disk::getdata()
{
    cout << "Enter total number of tracks : ";
    cin >> totalTracks;
    totalTracks--;
    cout << "Enter the current position of head : ";
    cin >> currentPos;
    cout << "Enter previous position of head : ";
    cin >> prev;
    cout << "Enter the size of queue : ";
    cin >> size;
    cout << "Enter the " << size << " request for tracks : ";
    for (int i = 0; i < size; i++)
        cin >> ref[i];
}
void scan_disk::total_move()
{
    int num = currentPos, move = 0, ind, dir = currentPos - prev;
    ind = sort();
    if (dir > 0)
    {
        for (int i = ind; i < size; i++)
        {
            move += ref[i] - num;
            num = ref[i];
        }
        if (ind != 0)
        {
            if (ind == size)
                move += totalTracks - currentPos;
            else
                move += totalTracks - ref[size - 1];
            move += totalTracks - ref[ind - 1];
            num = ref[ind - 1];
            for (int i = ind - 2; i >= 0; i--)
            {
                move += num - ref[i];
                num = ref[i];
            }
        }
    }
    else
    {
        for (int i = ind - 1; i >= 0; i--)
        {
            move += num - ref[i];
            num = ref[i];
        }
        if (ind == 0)
            move += currentPos + ref[0];
        else if (ind != size)
            move += ref[0] + ref[ind];
        num = ref[ind];
        for (int i = ind + 1; i < size; i++)
        {
            move += ref[i] - num;
            num = ref[i];
        }
    }
    cout << "Total head movements : " << move;
}
int main()
{
    scan_disk scan;
    scan.getdata();
    scan.total_move();
    return 0;
}