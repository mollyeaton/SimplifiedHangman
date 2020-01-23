# ME-Project1

Errors found:

CMake Error at CMakeLists.txt:6 (add_executable):
  Cannot find source file:

    debugging.h
    
    -- issue was that I had copied the CMakeLists and had forgotten
    to delete an unused header file
    

 include <"1-1000.txt">  - "file not found"
 
 
 
 error: no type named 'vector' in namespace 'std'; did you mean 'hecto'?
     std::vector wordVec;    std::vector wordVec;
     
     
 clang: error: linker command failed with exit code 1
 
    had run the file without putting a return line in a function

clang: error: linker command failed with exit code 1
    had mistyped the project name in the CMAKE lists