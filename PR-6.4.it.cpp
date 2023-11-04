#include <iostream>
#include <iomanip>

using namespace std;

int* Create(int n) {
    int* arr = new int[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

void Print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int Sum(int n, int* arr) {
    int sum = 0;
    int firsti = -1;
    int lasti = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (firsti  == -1) {
                firsti = i;
            }
            else {
                lasti = i;
            }
        }
    }
    if (firsti != -1 && lasti != -1) {
        for (int i = firsti+ 1; i < lasti; i++) {
            sum += arr[i];
        }
    }
    return sum;
}

int Product(int n, int* arr) {
    int product = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            product *= arr[i];
        }
    }
    return product;
}

void Transform(int n, int* arr) {
    for(int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < 0 && arr[j + 1] >= 0) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = Create(n);

    cout << "Array elements: ";
    Print(arr, n);

    int product = Product(n, arr);
    int sum = Sum(n, arr);
   
    cout << "Product of elements with even indices: " << product << endl;
    cout << "Sum of elements between the first and last zero elements: " << sum << endl;

    Transform(n, arr);
    Print(arr, n);

    delete[] arr;

    return 0;
}
