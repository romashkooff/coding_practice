#include <iostream>
#include <cstdlib>

using namespace std;

void fillArray(int *arr, unsigned int N)
{
    cout << "Enter array elements" << endl;
    for (unsigned int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}
void printArray(int *arr, unsigned int N)
{
    for (unsigned int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int findMinimumInArray(int* arr, unsigned int N) {
    int min = arr[0];
    for (unsigned int i = 1; i < N; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    unsigned int size;
    int* ptr;
    cout << "Hello, how many numbers between 1 and 100 do you need?";
    cin >> size;
    ptr = new int[size];
    fillArray(ptr, size);
    printArray(ptr, size);
    cout << "Minimal element has value of " << findMinimumInArray(ptr, size) << endl;
    cout << RAND_MAX << endl;
    
}