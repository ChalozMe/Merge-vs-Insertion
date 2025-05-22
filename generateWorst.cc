#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./generateWorst <N>\n";
        return 1;
    }

    int N = std::atoi(argv[1]);

    for (int i = 1; i <= N; ++i) {
        int size = i * 10;
        std::cout << size << "\n";
        for (int j = size; j >= 1; --j) {
            std::cout << j << (j == 1 ? '\n' : ' ');
        }
    }

    return 0;
}

