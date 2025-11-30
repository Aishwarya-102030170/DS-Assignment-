#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        int temp = a[start];
        a[start] = a[minIndex];
        a[minIndex] = temp;

        if (maxIndex == start)
            maxIndex = minIndex;

        temp = a[end];
        a[end] = a[maxIndex];
        a[maxIndex] = temp;

        start++;
        end--;
    }
}

int main() {
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
