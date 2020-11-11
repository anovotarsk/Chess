# Chess

### Must Have (dependencies)
- CMake 3.5 or above - https://cmake.org/download
- Qt 5.15 or above - https://www.qt.io/download

### Building
##### First step
If you do not have ```CMAKE_PREFIX_PATH``` you can fix it in 2 ways:
- go into ```CMakeLists.txt``` and ```src/CMakeLists.txt``` then add ```set(CMAKE_PREFIX_PATH "/your/path/to/qt")```

##### Second step
   Run CMake

##### Third step
   Extract everything from the directory ```libraries``` to directory with created executable file.
   Move the directory ```resources``` to the directory with the created executable file.
   
### Run
Run the executable file ```Chess.exe```.

### P.S
The directory already contains an executable file ```Chess.exe```. If you don't want to compile the program yourself, use it.