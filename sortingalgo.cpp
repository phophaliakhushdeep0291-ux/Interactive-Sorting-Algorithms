#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    cout << "\nBubble Sort Steps:\n";
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
        printArray(arr); // show intermediate steps
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    cout << "\nInsertion Sort Steps:\n";
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printArray(arr);
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    cout << "\nSelection Sort Steps:\n";
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
        printArray(arr);
    }
}

// Merge Sort helper
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(n1), R(n2);
    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

// Merge Sort
void mergeSort(vector<int>& arr, int l, int r) {
    if(l<r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort helper
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if(low<high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Main Program
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    srand(time(0));
    cout << "Original Array: ";
    for(int i=0;i<n;i++) {
        arr[i] = rand()%100; // random numbers 0-99
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n";
    cout << "4. Merge Sort\n5. Quick Sort\nEnter choice: ";
    int choice; cin >> choice;

    vector<int> arrCopy = arr; // copy original array

    switch(choice) {
        case 1: bubbleSort(arrCopy); break;
        case 2: insertionSort(arrCopy); break;
        case 3: selectionSort(arrCopy); break;
        case 4: 
            mergeSort(arrCopy,0,n-1);
            cout << "\nMerge Sorted Array: ";
            printArray(arrCopy);
            break;
        case 5: 
            quickSort(arrCopy,0,n-1);
            cout << "\nQuick Sorted Array: ";
            printArray(arrCopy);
            break;
        default: cout << "Invalid choice!"; return 0;
    }

    cout << "\nFinal Sorted Array: ";
    printArray(arrCopy);
    return 0;
}
