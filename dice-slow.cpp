// C++ code
//
// Run time for 1'000'000:
//    4.2 seconds
//
// Run time for 1'000'000'000:
//    1 hour, 9 minutes (estimate)


#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 1000000

int rollDice() {
    int maxCount = 0;

    for (int i = 0; i < N; i++) {
        int result = 0;
        int count = 0;

        for (int j = 0; j < 231; j++) {
            result = std::rand() % 4;

            if (result == 0) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }
    
    return maxCount;
}

int main() {
    clock_t begin = clock();

    // Roll the dice
    srand(time(NULL));
    int maxRoll = rollDice();

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    std::cout << "Sessions: " << N << std::endl;
    std::cout << "Longest streak was: " << maxRoll << std::endl;
    std::cout << "Operation took: " << timeSpent << " sec" << std::endl;

    system("pause");
    return 0;
}