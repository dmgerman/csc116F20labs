#!/bin/sh
echo "Running Queue Test.."
echo "1" | ./queue > tests/queue.out
diff tests/expected/queue.expected tests/queue.out
