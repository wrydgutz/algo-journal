#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& nums) {

    for (int i = 1; i < nums.size(); i++) {

        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

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
