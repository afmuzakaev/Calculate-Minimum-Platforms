#include <iostream>
#include <algorithm>
using namespace std;

int findMinPlatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int platforms = 1; // Minimum one platform required initially
    int maxPlatforms = 1;
    
    int i = 1; // Pointer for departure array
    int j = 0; // Pointer for arrival array
    
    while (i < n && j < n) {
        if (arr[j] <= dep[i]) {
            platforms++;
            j++;
            
            if (platforms > maxPlatforms) {
                maxPlatforms = platforms;
            }
        } else {
            platforms--;
            i++;
        }
    }
    
    return maxPlatforms;
}

int main() {
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;
    
    int arr[n], dep[n];
    
    cout << "Enter the arrival times:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the departure times:\n";
    for (int i = 0; i < n; i++) {
        cin >> dep[i];
    }
    
    int minPlatforms = findMinPlatforms(arr, dep, n);
    cout << "Minimum platforms required: " << minPlatforms << endl;
    
    return 0;
}
