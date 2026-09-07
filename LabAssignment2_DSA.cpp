#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
    //QUESTION 1
    int binarySearch(int arr[], int target, int n) {
        int low = 0;
        int high = n - 1;
            
        while(low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
               low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int linearSearch(int arr[], int target, int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    //QUESTION 2
     void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }
    }
    
    void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    
    //QUESTION 3
    //PART A 
    int findLS(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                return i + 1;
            }
        }
        return -1;
    }
    
    //PART B
    int findBS(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == mid + 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + 1;
    }


   //QUESTION 4 
   //PART A 
    void concatenate(string s, string t) {
        cout << s + " " + t;
    }
    
    //PART B
    void reverse(string s) {
        char* left = 0;
        char* right = s.length() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        cout << s;
    }
    
    //PART C
    void deleteVowels(string s) {
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
    
            if(ch != 'a' && ch != 'e' && ch != 'i' &&
               ch != 'o' && ch != 'u' &&
               ch != 'A' && ch != 'E' && ch != 'I' &&
               ch != 'O' && ch != 'U') {
                cout << ch;
            }
        }
    }
    
    //PART D
    void sortString(string s) {
        for(int i = 0; i < s.length() - 1; i++) {
            for(int j = 0; j < s.length() - i - 1; j++) {
                if(s[j] > s[j + 1]) {
                    swap(s[j], s[j + 1]);
                }
            }
        }
        cout << s;
    }
    
    //PART E
    void toLower(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
        }
    
        cout << s;
    }
    
    //QUESTION 5
    //PART A
    void sparseMatrix(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (i == j) {
                   cout << arr[i] <<" ";
               } else {
                   cout << 0 << " ";
               }
            }
            cout << endl;
        }
    }
       
    //PART B
    void triDiagonal(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || (j - i) == 1 || (i - j) == 1) {
                    cout << arr[i];
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
     
    //PART C
    void triangle(int arr[], int n) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    cout << arr[k++] << " ";
                } else {
                    cout << 0 << " ";
                }
            } 
            cout << endl;
        }
    }
    
    //PART D
    void upperTriangle(int arr[], int n) {
        int k = 0;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i <= j)
                    cout << arr[k++] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
    
    //PART E
    void symmetric(int arr[], int n) {
        int k = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(i >= j)
                    cout << arr[i * (i + 1) / 2 + j] << " ";
            }
            cout << endl;
        }
    }
    
    
    //QUESTION 6
    //PART A
    void transpose(int a[][3], int b[][3]) {
        b[0][0] = a[0][1];
        b[0][1] = a[0][0];
        b[0][2] = a[0][2];
    
        int k = 1;
    
        for(int col = 0; col < a[0][1]; col++) {
            for(int i = 1; i <= a[0][2]; i++) {
                if(a[i][1] == col) {
                    b[k][0] = a[i][1];
                    b[k][1] = a[i][0];
                    b[k][2] = a[i][2];
                    k++;
                }
            }
        }
    }
    
    //PART B
    void add(int a[][3], int b[][3], int c[][3]) {
        int i = 1, j = 1, k = 1;
    
        c[0][0] = a[0][0];
        c[0][1] = a[0][1];
    
        while(i <= a[0][2] && j <= b[0][2]) {
            if(a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2] + b[j][2];
                i++;
                j++;
                k++;
            }
            else if(a[i][0] < b[j][0] ||
                   (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
                c[k++] = a[i++];
            }
            else {
                c[k++] = b[j++];
            }
        }
    
        while(i <= a[0][2])
            c[k++] = a[i++];
    
        while(j <= b[0][2])
            c[k++] = b[j++];
    
        c[0][2] = k - 1;
    }
      
    //PART C
    void multiplication(int a[][3], int b[][3], int c[][3]) {
        int k = 1;
    
        for(int i = 0; i < a[0][0]; i++) {
            for(int j = 0; j < b[0][1]; j++) {
                int sum = 0;
    
                for(int p = 0; p < a[0][1]; p++) {
                    int x = 0, y = 0;
    
                    for(int m = 1; m <= a[0][2]; m++)
                        if(a[m][0] == i && a[m][1] == p)
                            x = a[m][2];
    
                    for(int m = 1; m <= b[0][2]; m++)
                        if(b[m][0] == p && b[m][1] == j)
                            y = b[m][2];
    
                    sum += x * y;
                }
    
                if(sum != 0) {
                    c[k][0] = i;
                    c[k][1] = j;
                    c[k][2] = sum;
                    k++;
                }
            }
        }
    
        c[0][0] = a[0][0];
        c[0][1] = b[0][1];
        c[0][2] = k - 1;
    }
    
    //QUESTION 7 
    int inversion(int arr[], int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
    
    //QUESTION 8
    int distinctEl(vector<int> &arr, int n) {
        unordered_set<int> Set(arr.begin(), arr.end());
        return Set.size();
    }
};
int main()
{
    
    Solution s;
    // vector<int> arr = {5, 4, 3, 2, 1};
    // vector<int> ans = s.distinctEl(arr, 5);
    // for (int x: ans) {
    //     cout << x;
    // }
    int arr[] = {1, 2, 3, 4, 5,
        6, 7 , 8, 9 , 10
    };
    s.triangle(arr, 4);
    
}
