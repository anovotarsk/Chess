# Chess

### Must Have (dependencies)
- CMake 3.5 or above - https://cmake.org/download
- Qt 5.15 or above - https://www.qt.io/download

### Building
##### First step
If you do not have ```CMAKE_PREFIX_PATH```:
- go into ```CMakeLists.txt``` and ```src/CMakeLists.txt``` then add ```set(CMAKE_PREFIX_PATH "/your/path/to/qt")```

##### Second step
   Run CMake  
   Example - ```cmake . -Bbuild -Wdev -Werror=dev && cmake --build ./build```

##### Third step
   Move the directory ```resources``` to the directory with the created executable file.  
   If you are using Windows, extract everything from the directory ```libraries``` to directory with created executable file.
   
### Run
   Run the executable file ```Chess``` or ```Chess.exe```.

### P.S
   With the left mouse button, select the shape we want to resemble.  
   Move with the right button.
