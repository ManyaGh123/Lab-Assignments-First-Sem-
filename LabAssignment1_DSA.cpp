#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

class Solution {
    public:
    int n;
    int arr[100];
    int pos;
    int val;

    //1. CREATE
        void create() {
            cout << "Enter the number of elements:";
            cin >> n;
            
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            
            cout << "Array created successfully" << endl;
            display();
        }

    //2. DISPLAY
        void display() {
            cout << "The elements entered are:" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << endl;
            }
        }
        
    //3. INSERT
        void insertEl() {
            cout << "Enter the position: ";
            cin >> pos;
            
            cout<< "Enter the value: ";
            cin >> val;
            
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            
            arr[pos] = val;
            n++;
        }
        
    //4. DELETE
        void deleteEl() {
            cout << "Enter the position: ";
            cin >> pos;
            
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }
        
    //5. LINEAR SEARCH
        int linearSearch(int arr[], int target, int n) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    return i;
                    // cout << i;
                }
            }
            return -1;
        }
        
    //6. EXIT
        void exitProgram() {
            int choice;
            cout << "1. CREATE" << endl;
            cout << "2. DISPLAY" << endl;
            cout << "3. INSERT" << endl;
            cout << "4. DELETE" << endl;
            cout << "5. EXIT" << endl;
            
            cout << "Enter Choice:" << endl;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    create();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    insertEl();
                    break;
                case 4:
                    deleteEl();
                    break;
                case 5:
                    cout << "Exiting";  //exit
                    break;
                default:
                    cout << "Invalid";
            }
        }
        
    //7. REMOVE DUPLICATES
        //BRUTE FORCE SOLUTION
        void duplicates1() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i] == arr[j]) {
                        for (int k = j; k < n - 1; k++) {
                            arr[k] = arr[k + 1];
                        }
                        n--;
                        j--;
                    }
                }
            }
        }
        
        //OPTIMAL SOLUTION
        void duplicates2 () {
            unordered_set<int> seen;
            int new_size = 0;
            
            for(int i = 0; i < n; i++) {
                if (seen.find(arr[i]) == seen.end()) {
                    seen.insert(arr[i]);
                    arr[new_size] = arr[i]; //position where the array will be placed
                    new_size++;
                }
            }
            n = new_size;
        }
    
    // 8. REVERSE ARRAY
        void reverseArr(vector<int>& nums, int low, int high) {
            while (low <= high) {
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
                low++;
                high--;
            }
        }
       
    //9. ROTATE ARRAY
        void Rightrotate(vector<int>& nums, int k) {
            k = k % nums.size();
            reverseArr(nums, 0 , nums.size() - k - 1);
            reverseArr(nums,  nums.size() - k, nums.size() - 1);
            reverseArr(nums, 0 , nums.size() - 1);
        }
        
        void Leftrotate(vector<int>& nums, int k) {
            k = k % nums.size();
            reverseArr(nums, 0 , k - 1);
            reverseArr(nums, k, nums.size() - 1);
            reverseArr(nums, 0 , nums.size() - 1);
        }
        
    //10. MULTIPLY MATRICES
        void multiply() {
            int a[10][10], b[10][10], c[10][10];
            int r1, c1, r2, c2;
            
            cout << "Enter rows and columns of first matrix:";
            cin >> r1 >> c1;
            
            cout << "Enter rows and columns of second matrix:";
            cin >> r2 >> c2;
            
            if (c1 != r2) {
                cout << "Sorry cannot multiply";
                return;
            }
            
            cout << "Enter first matrix:";
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    cin >> a[i][j];
        
            cout << "Enter second matrix:";
            for (int i = 0; i < r2; i++)
                for (int j = 0; j < c2; j++)
                    cin >> b[i][j];
            
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < c1; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            
            cout << "Result:\n";
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++)
                    cout << c[i][j] << " ";
                cout << endl;
            }
    }
    
    //11. TRANSPOSE OF MATRIX
    void transpose() {
        int a[10][10], transpose[10][10];
        int rows, cols;
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transpose[j][i] = a[i][j];
            }
        }
    }
    
    //12. SUM OF EACH ROW AND COLUMN
    void sum() {
        int a[3][3] = {{10, 20, 30},
                    {40, 50, 60},
                    {70, 80, 90}};
                    
        int rows = 3, cols = 3;
        
        for (int i = 0; i < rows; i++) {
            int sumRows = 0;
            for (int j = 0; j < cols; j++) {
                sumRows += a[i][j];
            }
            cout << "Sum of Row" << i + 1 << "=" << sumRows << endl;
        }
        
        for (int i = 0; i < cols; i++) {
            int sumCols = 0;
            for (int j = 0; j < rows; j++) {
                sumCols += a[j][i];
            }
            cout << "Sum of Col" << i + 1 << "=" << sumCols << endl;
        }
    } 
};

int main() {
    Solution s;
    s.sum();
}