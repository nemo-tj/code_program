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

./server/main_server --log_dir=./log/

echo ""
echo "done    ............................"
cd -

