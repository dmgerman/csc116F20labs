#!/bin/sh
echo "Running Test 2.."
echo "1" | ./part2 > tests/part2.out
diff tests/expected/part2.expected tests/part2.out
