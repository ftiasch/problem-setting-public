#!/bin/sh

export PATH=`pwd`:$PATH
export CPLUS_INCLUDE_PATH=`pwd`:$CPLUS_INCLUDE_PATH

echo [INFO]: Building problem 'kd-tree-subroutine'.
cd problems/kd-tree-subroutine
./doall.sh
cd -

echo [INFO]: Building problem 'odd-discount'.
cd problems/odd-discount
./doall.sh
cd -

echo [INFO]: Building problem 'queen-dominating-set-count'.
cd problems/queen-dominating-set-count
./doall.sh
cd -

echo [INFO]: Building problem 'set-longest-common-subsequence'.
cd problems/set-longest-common-subsequence
./doall.sh
cd -

echo [INFO]: Building problem 'knapsack-123'.
cd problems/knapsack-123
./doall.sh
cd -

echo [INFO]: Building problem 'sparse-graph-shortest-path-query'.
cd problems/sparse-graph-shortest-path-query
./doall.sh
cd -

echo [INFO]: Building problem 'square-connectivity'.
cd problems/square-connectivity
./doall.sh
cd -

echo [INFO]: Building problem 'tree-eulerian-cycle-count'.
cd problems/tree-eulerian-cycle-count
./doall.sh
cd -

echo [INFO]: Building problem 'lis-5-count'.
cd problems/lis-5-count
./doall.sh
cd -

echo [INFO]: Building problem 'matrix-shift'.
cd problems/matrix-shift
./doall.sh
cd -

echo [INFO]: Building english contest statement.
cd statements/english
./doall.sh
cd -
