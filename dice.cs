// C# code
//
// Run time for 1'000'000:
//    5.6 seconds
//
// Run time for 1'000'000'000:
//    1 hour, 33 minutes (estimate)


using System;
using System.Diagnostics;

namespace dice_roll
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            RollDice(1000000);
            stopwatch.Stop();
            Console.WriteLine(stopwatch.ElapsedMilliseconds + "ms");
            Console.ReadLine();
        }
        public static int RollDice(int N) {
            int maxCount = 0;

            var random = new Random();
            for (int i = 0; i < N; i++) {
                int count = 0;

                for (int j = 0; j < 231; j++) {
                    int result = random.Next(0, 4);

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

    }
}