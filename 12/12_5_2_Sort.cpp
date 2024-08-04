#include <iostream>

void FillArray (float arr[], int sizeArr) {

    for (int i = 0; i < sizeArr; ++i) {
        std::cout << "Enter number: ";
        float n;
        std::cin>>n;
        arr[i] = n;
    }

    std::cout<<"\nThe array is full.\n";

}

void PrintArray(float arr[], int sizeArr) {
   
    for(int i = 0; i < sizeArr; ++i)
        std::cout<<arr[i]<<" ";

    std::cout<<"\n";     

}


void heapify(float arr[], int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main() {

    int numDig = 15; 
    float nums[numDig];
    FillArray(nums, numDig);
    int n = sizeof(nums)/sizeof(nums[0]);
    
    std::cout<<"\nArray before sorting:\n";
    PrintArray(nums, n);

    heapSort(nums, n);

    std::cout<<"\nArray after sorting:\n";
    PrintArray(nums, n); 
  
    return 0;
    
}
