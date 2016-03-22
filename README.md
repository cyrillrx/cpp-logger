# A basic cpp logger

# Build scripts
## Install the requirements
```
$ conan install . -s compiler=clang -s compiler.version=3.7 -s compiler.libcxx=libstdc++11 --build googletest
$ conan install . -s compiler="Visual Studio" -s compiler.version=14 -s compiler.runtime=MT --build googletest
```

## Compile and run the tests
```
$ mkdir build && cd build
$ cmake ../ -DBUILD_TEST=TRUE && cmake --build .
```

## Execute the test!
```
$ cd bin
$ test_looger.exe (WIN)
$ ./test_looger (UNIX)
```
