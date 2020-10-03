#! /bin/sh
echo "Test 1..."
./part2 < tests/input/test-01.in > tests/output/test-01.out
diff tests/expected/test-01.expected tests/output/test-01.out
echo "Test 2..."
./part2 < tests/input/test-02.in > tests/output/test-02.out
diff tests/expected/test-02.expected tests/output/test-02.out
echo "Test 3..."
./part2 < tests/input/test-03.in > tests/output/test-03.out
diff tests/expected/test-03.expected tests/output/test-03.out
echo "Test 4..."
./part2 < tests/input/test-04.in > tests/output/test-04.out
diff tests/expected/test-04.expected tests/output/test-04.out
