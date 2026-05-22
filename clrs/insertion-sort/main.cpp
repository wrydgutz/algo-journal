#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& nums) {

    // Traverse nums but starting from the 2nd number.
    // The 1st element is already considered sorted by itself.
    for (size_t i = 1; i < nums.size(); i++) {

        // Keep track of the current number.
        const int key = nums[i];

        // Traverse backwards from the current element's previous index,
        // shifting larger elements one position to the right
        // until the correct insertion position for key is found.
        size_t j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        // Insert the key into its correct sorted position.
        nums[j + 1] = key;
    }
}

void print(vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
        if (i) cout << ' ';
        cout << nums[i];
    }
}

int main() {
    vector<int> a { 9, 34, 3, 2, 1, 6, 7 };

    cout << "Before sort: a = ";
    print(a);
    cout << endl;
    insertion_sort(a);

    cout << "After sort: a = ";
    print(a);
    cout << endl;

    return 0;
}
