// Paralized C++ code
//
// Run time for 1'000'000:
//    55ms
//
// Run time for 1'000'000'000:
//    50.4 seconds


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define N_TOTAL 1000000000
#define THREADS 256         // You might be able to go higher but my poor CPU :<
#define N N_TOTAL/THREADS

int rollDice() {
    int maxCount = 0;

#pragma omp parallel
    {
        int localMaxCount = 0;

#pragma omp for
        for (int i = 0; i < N; i++) {
            int result = 0;
            int count = 0;

            for (int j = 0; j < 231; j++) {
                result = std::rand() % 4;

                if (result == 0) {
                    count++;
                }
            }

            if (count > localMaxCount) {
                localMaxCount = count;
            }
        }

#pragma omp critical
        {
            if (localMaxCount > maxCount) {
                maxCount = localMaxCount;
            }
        }
    }

    return maxCount;
}

int main() {
    clock_t begin = clock();

    srand(time(NULL));
    omp_set_num_threads(256);
    int maxRoll = rollDice();

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

    std::cout << "Sessions: " << N_TOTAL << ", on " << THREADS << " threads (" << N << " per thread)" << std::endl;
    std::cout << "Longest streak was: " << maxRoll << std::endl;
    std::cout << "Operation took: " << timeSpent << " sec" << std::endl;

    system("pause");
    return 0;
}