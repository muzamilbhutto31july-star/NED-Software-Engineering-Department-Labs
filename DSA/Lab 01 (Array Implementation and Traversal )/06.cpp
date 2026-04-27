#include <iostream>
using namespace std;

void frequencyOfElements(int arr[], int n) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    cout << "Element frequencies:\n";
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " -> " << count << endl;
    }
}

int main() {
    int arr[] = {10, 20, 10, 30, 20, 40, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequencyOfElements(arr, size);

}