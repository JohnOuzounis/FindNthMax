#include "std_lib_facilities.h"
#define count 9
#define size 9

using namespace std;

void PrintArray(int* val_list)
{
    for (int i=0; i<size; i++)
        cout << val_list[i] << " ";
    cout << endl;
}


// This function takes as arguements an integer array
// and an integer that indicates the number of iterations (how many times we'll swap)
// This function swaps the elements of the array starting from the end and reaching the size-n element
void MultiSwap(int* val_list, int n)
{ 
    for (int i=n, index=size; i>=1; i--)
    {
        swap(val_list[index-1],val_list[index-2]);
        index--;
    } 
}


// This function takes as agruements an integer array containing the values
// and an integer indicating the nth max that we want to find
int FindNthMax(int* val_list, int n)
{
    // allocate enough memory to store all maxes
    if (n < 1)
        return NULL;
    int* max = new int[n];

    // initialise all maxes (assume that the first element is the largest)
    for (int i=0; i<n; i++)
        max[i] = val_list[0];


    // traverse the value list once
    for (int i=1; i<count; i++)
    {
        // check for every max if it is smaller than the current element
        // if so swap all previous maxes and assign the new value to this max
        // then exit the loop to repeat this process with the next element
        for (int j=0; j<size; j++)
        {
            if (val_list[i] > max[j])
            {
                MultiSwap(max,size-1-j);
                max[j] = val_list[i];
                break;
            }
        }
    }
    return max[n-1];
}

int main()
{
    int val[] = {1, 2, 3, 4, 30, 50, 69, 72, 98};
    
    int max = FindNthMax(val,3);
    
    cout << max;
}