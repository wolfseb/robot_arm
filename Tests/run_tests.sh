mkdir -p "build"
cd build
cmake ..
cmake --build .
./servo_tests
cd ..