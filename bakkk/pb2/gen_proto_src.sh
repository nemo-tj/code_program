
protoc --proto_path=proto --cpp_out=. proto/*.proto

protoc --grpc_out=./ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` rpc/*.proto
