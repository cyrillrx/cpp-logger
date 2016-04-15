# Cpp logger
A basic logger for cpp

# Build scripts
## Install the requirements
```
$ conan install . -s compiler=clang -s compiler.version=3.7 -s compiler.libcxx=libstdc++11 --build googletest
$ conan install . -s compiler="Visual Studio" -s compiler.version=14 -s compiler.runtime=MT --build googletest
$ conan install . -s compiler=apple-clang -s compiler.version=7.3 -s compiler.libcxx=libstdc++ --build googletest
```

## Compile and run the tests
```
$ rm -rf build && mkdir build && cd build
$ cmake ../ -DBUILD_TEST=TRUE && cmake --build .
```

## Execute the test!
```
$ cd bin
$ test_logger.exe (WIN)
$ ./test_logger (UNIX)
```

# Reuse
## Export module
```
$ conan export cyrillrx/stable
```

## Check availability
```
$ conan search *Logger*
```

## Install the module
```
$ conan install Logger/0.1.0@cyrillrx/stable --build Logger
```