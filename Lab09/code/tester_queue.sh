#!/bin/sh
echo "Running Test Queue.."
echo "1" | ../cmake-build-debug/queue_main > tests/queue.out
diff tests/expected/queue.expected tests/queue.out
