#! /bin/sh
echo "Test 1..."
./word_stats < tests/input/zimmermann.in > tests/output/zimmermann.out
diff tests/expected/zimmermann.exp tests/output/zimmermann.out
echo "Test 2..."
./word_stats < tests/input/gettysburg.in > tests/output/gettysburg.out 
diff tests/expected/gettysburg.exp tests/output/gettysburg.out
echo "Test 3..."
./word_stats < tests/input/pearl-harbor.in > tests/output/pearl-harbor.out
diff tests/expected/pearl-harbor.exp tests/output/pearl-harbor.out
