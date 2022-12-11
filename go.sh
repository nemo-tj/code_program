set -x
cd pb
sh gen_proto_src.sh
cd -
mkdir -p build
cd build
cmake ..
make -j 4

echo "running ............................"
echo ""

./server/main_server

echo ""
echo "done    ............................"
cd -

