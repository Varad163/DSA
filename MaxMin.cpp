#include <iostream>
#include <climits>   // for INT_MAX and INT_MIN
using namespace std;

int getMin(int num[], int n) {
    int mini = INT_MAX;   // start with biggest possible value

    for (int i = 0; i < n; i++) {
        if (num[i] < mini) {   // update if smaller element found
            mini = num[i];
        }
    }
    return mini;
}

int getMax(int num[], int n) {
    int maxi = INT_MIN;   // start with smallest possible value

    for (int i = 0; i < n; i++) {
        if (num[i] > maxi) {   // update if larger element found
            maxi = num[i];
        }
    }
    return maxi;
}

int main() {
    int size;
    cin >> size;

    int num[100];

    // taking input in array
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << "Maximum value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;

    return 0;
}
