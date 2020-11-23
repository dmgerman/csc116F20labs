#!/bin/sh
echo "Test 1..."
./lab07 < tests_part2/test-01.in > tests_part2/output/test-01.out
diff tests_part2/expected/test-01.expected tests_part2/output/test-01.out
echo "Test 2..."
./lab07 < tests_part2/test-02.in > tests_part2/output/test-02.out
diff tests_part2/expected/test-02.expected tests_part2/output/test-02.out
echo "Test 3..."
./lab07 < tests_part2/test-03.in > tests_part2/output/test-03.out
diff tests_part2/expected/test-03.expected tests_part2/output/test-03.out
echo "Test 4..."
./lab07 < tests_part2/test-04.in > tests_part2/output/test-04.out
diff tests_part2/expected/test-04.expected tests_part2/output/test-04.out
