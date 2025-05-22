#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./generateRng <N>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);
    std::srand(std::time(nullptr)); 

    for (int i = 1; i <= N; ++i) {
        int size = i * 10;
        std::vector<int> arr(size);
        for (int j = 0; j < size; ++j) {
            arr[j] = j + 1;
        }

        std::random_shuffle(arr.begin(), arr.end());

        std::cout << size << "\n";
        for (int j = 0; j < size; ++j) {
            std::cout << arr[j] << (j == size - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

