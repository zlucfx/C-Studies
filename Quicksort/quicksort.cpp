#include <iostream>
#include <vector>

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);

        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Digite o número de elementos: ";
    std::cin >> n;

    std::cout << "Digite os elementos: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    quicksort(arr, 0, n - 1);

    std::cout << "Array ordenado: \n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
