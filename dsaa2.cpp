//Q1:
#include <iostream>
#include <vector>
using namespace std;


int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            left = mid + 1; 
        else
            right = mid - 1; 
    }
    return -1; 
}


int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right) 
        return -1; 

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}


int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1; 
}


int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    cout << "Iterative Binary Search: " 
         << binarySearchIterative(arr, target) << endl;

    cout << "Recursive Binary Search: " 
         << binarySearchRecursive(arr, 0, arr.size() - 1, target) << endl;

    cout << "Linear Search: " 
         << linearSearch(arr, target) << endl;

    return 0;
}

//Q2:
#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; 

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
              
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        
        if (!swapped)
            break;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

//Q3:
//(a)
int findMissingLinear(const vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1)
            return i + 1; 
    }
    return n; 
}

//(b)
int findMissingBinary(const vector<int>& arr, int n) {
    int left = 0, right = n - 2; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1) 
            left = mid + 1;   
        else 
            right = mid - 1;  
    }
    return left + 1; 
}

//Q4:

//(a):
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello ";
    string str2 = "World!";
    
   
    string result = str1 + str2;
    
    cout << "Concatenated String: " << result << endl;
    return 0;
}

//(b):
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str = "OpenAI";
    
    reverse(str.begin(), str.end());  
    
    cout << "Reversed String: " << str << endl;
    return 0;
}


//(c):
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    string str = "Artificial Intelligence";
    string result = "";

    for (char c : str) {
        if (!isVowel(c))
            result += c;
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}


//(d):
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> words = {"banana", "apple", "cherry", "date"};
    
    sort(words.begin(), words.end()); 
    
    cout << "Sorted Strings: ";
    for (string w : words)
        cout << w << " ";
    cout << endl;
    
    return 0;
}


//(e):
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch = 'G';
    
    char lower = tolower(ch); 
    
    cout << "Uppercase: " << ch << endl;
    cout << "Lowercase: " << lower << endl;
    return 0;
}


//Q5:

//(a):
#include <iostream>
using namespace std;

class Diagonal {
    int *A;
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        else return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

//(b):
class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i-j == 1) A[i-2] = x;           
        else if (i == j) A[n-1 + i-1] = x;   
        else if (j-i == 1) A[2*n-1 + i-1] = x; 
    }
    int get(int i, int j) {
        if (i-j == 1) return A[i-2];
        else if (i == j) return A[n-1 + i-1];
        else if (j-i == 1) return A[2*n-1 + i-1];
        else return 0;
    }
};


//(c):
class LowerTriangular {
    int *A;
    int n;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j)
            A[i*(i-1)/2 + j-1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + j-1];
        else return 0;
    }
};

//(d):
class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j)
            A[j*(j-1)/2 + i-1] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[j*(j-1)/2 + i-1];
        else return 0;
    }
};

//(e):
class Symmetric {
    int *A;
    int n;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + j-1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + j-1];
        else return A[j*(j-1)/2 + i-1]; 
    }
};

//Q6:

#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, numNonZero;
    vector<Element> data;

    // Constructor
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        numNonZero = n;
        data.resize(n);
    }

    // Display triplet
    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < numNonZero; i++) {
            cout << data[i].row << " "
                 << data[i].col << " "
                 << data[i].val << "\n";
        }
    }

  
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows, numNonZero);
        int k = 0;
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < numNonZero; i++) {
                if (data[i].col == c) {
                    result.data[k].row = data[i].col;
                    result.data[k].col = data[i].row;
                    result.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return result;
    }

    
    SparseMatrix add(SparseMatrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrix dimensions do not match!\n";
            return SparseMatrix(0, 0, 0);
        }

        vector<Element> resultData;
        int i = 0, j = 0;

        while (i < numNonZero && j < other.numNonZero) {
            if (data[i].row < other.data[j].row ||
               (data[i].row == other.data[j].row && data[i].col < other.data[j].col)) {
                resultData.push_back(data[i++]);
            } else if (other.data[j].row < data[i].row ||
                      (other.data[j].row == data[i].row && other.data[j].col < data[i].col)) {
                resultData.push_back(other.data[j++]);
            } else {
                // same position → add values
                int sum = data[i].val + other.data[j].val;
                if (sum != 0) {
                    resultData.push_back({data[i].row, data[i].col, sum});
                }
                i++; j++;
            }
        }
        while (i < numNonZero) resultData.push_back(data[i++]);
        while (j < other.numNonZero) resultData.push_back(other.data[j++]);

        SparseMatrix result(rows, cols, resultData.size());
        result.data = resultData;
        return result;
    }

  
    SparseMatrix multiply(SparseMatrix &other) {
        if (cols != other.rows) {
            cout << "Matrix dimensions do not allow multiplication!\n";
            return SparseMatrix(0, 0, 0);
        }

        vector<Element> resultData;

        
        for (int i = 0; i < numNonZero; i++) {
            for (int j = 0; j < other.numNonZero; j++) {
                if (data[i].col == other.data[j].row) {
                    int r = data[i].row;
                    int c = other.data[j].col;
                    int v = data[i].val * other.data[j].val;

                    // check if already exists
                    bool found = false;
                    for (auto &e : resultData) {
                        if (e.row == r && e.col == c) {
                            e.val += v;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        resultData.push_back({r, c, v});
                    }
                }
            }
        }

        SparseMatrix result(rows, other.cols, resultData.size());
        result.data = resultData;
        return result;
    }
};


int main() {
   
    SparseMatrix A(3, 3, 3);
    A.data[0] = {0, 2, 3};
    A.data[1] = {1, 0, 4};
    A.data[2] = {2, 1, 5};

    cout << "Matrix A in triplet form:\n";
    A.display();

 
    cout << "\nTranspose of A:\n";
    SparseMatrix T = A.transpose();
    T.display();

    
    SparseMatrix B(3, 3, 3);
    B.data[0] = {0, 0, 1};
    B.data[1] = {1, 2, 2};
    B.data[2] = {2, 1, 3};

    cout << "\nMatrix B in triplet form:\n";
    B.display();

    cout << "\nA + B:\n";
    SparseMatrix C = A.add(B);
    C.display();


    cout << "\nA * B:\n";
    SparseMatrix M = A.multiply(B);
    M.display();

    return 0;
}

//Q7:

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    int count = 0;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
                cout << "Inversion: (" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    cout << "Total Inversions: " << count << endl;
    return 0;
}


//Q8:

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

       
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements: " << distinctCount << endl;
    return 0;
}

