#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./generateBest <N>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);

    for (int i = 1; i <= N; ++i) {
        int size = i * 10;
        std::cout << size << "\n";
        for (int j = 1; j <= size; ++j) {
            std::cout << j << (j == size ? '\n' : ' ');
        }
    }

    return 0;
}


