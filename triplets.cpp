#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findTriplets(vector<int> numbers, int target) {
    
    int n = numbers.size();
    vector<vector<int>> result;

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i <= n - 3; i++) {
        int j = i + 1;
        int k = n - 1;
        
        while (j < k) {
            int sum = numbers[i] + numbers[j] + numbers[k];
           
            if (sum == target) {
                result.push_back({numbers[i], numbers[j], numbers[k]});
                break;
            }
            else if (sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return result;
}

void showTriplets(vector<vector<int>> numbers) {
    
    for (auto row: numbers) {
        for (auto col: row) {
            cout << col << ", ";
        }
    cout << endl;
    }
}

int main(void) {
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,15};

    showTriplets(findTriplets(numbers, 18));

    return 0;
}