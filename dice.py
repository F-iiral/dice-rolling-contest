# Optimized Python code
#
# Run time for 1'000'000:
#    97 seconds
#
# Run time for 1'000'000'000:
#    1 day, 3 hours (estimate)


import random
import time

N = 1000000000

def rollDice():
    maxCount = 0

    for i in range(N):
        result = 0
        count = 0

        for j in range(231):
            result = random.randint(0, 4)

            if result == 0:
                count += 1

        if count > maxCount:
            maxCount = count
    
    return maxCount

def main():
    start = time.time()
    maxRoll = rollDice()
    end = time.time()
    time_spent = end - start

    print(f"Sessions: {N}")
    print(f"Longest streak was: {maxRoll}")
    print(f"Operation took: {time_spent}sec")

if __name__ == "__main__":
    main()