set -x
sh grpctool.sh
echo "end generate proto src............"
echo "---------------------------------"
mkdir -p build
cd build
cmake ..
rm -rf ./server/main_server
make -j 4

echo "running ............................"
echo ""

./server/main_server

echo ""
echo "done    ............................"
cd -

