# A basic cpp logger

# Build scripts
```
conan install . -s compiler=clang -s compiler.version=3.7 -s compiler.libcxx=libstdc++11 --build googletest
conan install . -s compiler='Visual Studio' -s compiler.version=14 --build googletest
```
