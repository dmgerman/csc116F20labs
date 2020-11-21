#!/bin/sh
echo "Running Test 1A.."
echo "1" | ./part1 > tests/part1A.out
diff tests/expected/part1A.expected tests/part1A.out
echo "Running Test 1B.."
echo "2" | ./part1 > tests/part1B.out
diff tests/expected/part1B.expected tests/part1B.out
echo "Running Test 1C.."
echo "3" | ./part1 > tests/part1C.out
diff tests/expected/part1C.expected tests/part1C.out
