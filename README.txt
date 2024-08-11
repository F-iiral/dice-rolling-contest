dice.py is the optimized version of your code, it takes around 97 seconds to run for 1 Million iterations (310% improvement)
dice.js is written in JS and run with a JIT compiler, it takes around 11.5 seconds to run for 1 Million iterations (2600% improvement)
dice.cs is written in C Sharp and pre-compiled, it takes around 5.6 seconds to run for 1 Million iterations (5400% improvement)
dice-slow.cpp is written in C++, it takes around 4.2 seconds to run for 1 Million iterations (7100% improvement)

At this point, we slowly reach the limits of my machine

dice-fast.cpp is written in C++ but is parallelized on 256 threads, it takes around 55ms to run for 1 Million iterations (545,000% improvement) and is the only one I ran 1 Billion iterations on, taking just about 50 seconds to complete. We can also see that it is not nearly as much as an improvement, as it, despite using 256 threads, is "only" 76x faster.

It is theoretically possible to get even faster by using the GPU instead of a CPU by using CUDA, but I am not experienced enough to do this, nor is my GPU powerful enough to overcome overhead from transferring a billion vector over to it.