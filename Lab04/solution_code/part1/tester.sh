#! /bin/sh
echo "Test 1..."
./part1 < tests/input/test-01.in > tests/output/test-01.out
diff tests/expected/test-01.expected tests/output/test-01.out
echo "Test 2..."
./part1 < tests/input/test-02.in > tests/output/test-02.out 
diff tests/expected/test-02.expected tests/output/test-02.out
echo "Test 3..."
./part1 < tests/input/test-03.in > tests/output/test-03.out
diff tests/expected/test-03.expected tests/output/test-03.out
