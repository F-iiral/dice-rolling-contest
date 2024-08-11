// JavaScript code
//
// Run time for 1'000'000:
//    11.5 seconds
//
// Run time for 1'000'000'000:
//    3 hours, 11 minutes (estimate)


function rollDice(N) {
    let maxCount = 0;

    for (let i = 0; i < N; i++) {
        let count = 0;

        for (let j = 0; j < 231; j++) {
            const result = Math.floor(Math.random() * 5);

            if (result === 0) {
                count += 1;
            }
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

function main(N) {
    const start = Date.now();
    const maxRoll = rollDice(N);
    const end = Date.now();
    const timeSpent = (end - start) / 1000;

    console.log(`Sessions: ${N}`);
    console.log(`Longest streak was: ${maxRoll}`);
    console.log(`Operation took: ${timeSpent}sec`);
}

main(10000000);