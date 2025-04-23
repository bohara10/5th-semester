#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& arr, int index, int target_sum) {
    // Base case: if sum becomes 0, subset is found
    if (target_sum == 0) {
        return true;
    }
    
    // If index reaches the end of the array, return false
    if (index == arr.size()) {
        return false;
    }
    
    // If the current element is greater than the remaining sum, skip it
    if (arr[index] > target_sum) {
        return isSubsetSum(arr, index + 1, target_sum);
    }
    
    // Recursive case: include or exclude the current element
    bool include = isSubsetSum(arr, index + 1, target_sum - arr[index]);
    bool exclude = isSubsetSum(arr, index + 1, target_sum);
    
    return include || exclude;
}

int main() {
    int n, target_sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> target_sum;
    
    if (isSubsetSum(arr, 0, target_sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "No subset with the given sum." << endl;
    }
    
    return 0;
}
