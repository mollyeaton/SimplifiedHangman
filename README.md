# ME-Project1

###Examples of Errors Found:

####Compiler Errors:

CMake Error at CMakeLists.txt:6 (add_executable):
  Cannot find source file:

    debugging.h
    
    -- issue was that I had copied the CMakeLists and had forgotten
    to delete an unused header file
    
    Solution: Deleted the unused header file that was not part of the project
    
 
error: no type named 'vector' in namespace 'std'; did you mean 'hecto'?
     std::vector wordVec;    std::vector wordVec;
     
     -- The type used for the vector must be declared 
     
     Solution: I simply declared the vector as : std:: vector <string> wordVec instead
     
     
clang: error: linker command failed with exit code 1
 
    -- I had run the file without putting a return line in a function
    
    Solution: while testing the program I returned a test string

ld: 11 duplicate symbols for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
    
    -- Because I had used #include "HangmanGame.cpp" instead of #include "HangmanGame.h"
    the functions I was using were compiling twice and did not allow the program to run.
    
    Solution: once I included the header file versus the .cpp file the issue was resolved

####Runtime Errors:

I ran into a few runtime issues with this block of code:

if (word[i] == tolower(guess[i])) //character is equal
   tempHidden += guess[i]; //add character to string
else if (hiddenWord[i] != ('*')) //letter was already guessed
   tempHidden += hiddenWord[i]; //add previously guessed character to string
else //guess was not correct
   tempHidden += "*"; //keep character hidden
   
    -- The program would not allow any extra characters to be guessed or would replace the characters in the
    word with blank boxes. The issue was that all the calls to guess[i] were messing up the program.
    
    Solution: the call really had to be guess[0], because otherwise it was moving through empty characters
    and thus would never return as equal

Another error I experienced was the random number generator continued to output the same value and 
produced the same word to guess every time.

    --The issue turned out to be that the random function needed to be seeded before it could be properly
    called based on the current time of the run.
    
    Solution: By seeding the random number generator with: srand((unsigned) time(0)); within the pickWord() 
    function, it finally produced different numbers
    
The final error I will discuss caused the program to instantly jump outside of the guessing loop. The output would 
instantly say that you lost the game and display the word without allowing any guesses. 

    --I used the debugger mode to disect this issue. I placed stop points on line 16, 19 (main.cpp) and from there 
    narrowed down where the issue was. The variabled displayed showed that the wordVec was not getting any
    words added to it. By redoing the debugger within the pickWord() function within HangmanGame.cpp file the problem
    turned out to be that the words were'nt being read in correctly from the file. The file was not opening correctly.
    
    Solution: All the function needed to open the file properly was to add: (string("../")) before the file name
    within the call. 
    
###Style Choice

This project has two branches to represent the two groupings of style choices.

Style 1: 
- Hanging braces
- Camel case
- Top of file documentation
- Conventional variable naming

Style 2:
- Egyptian style braces
- Snake case
- RME documentation
- Prefixed variable naming

Personal preference:
    I prefer Style 1 over Style 2. I tend to go back and forth with curly braces
    style. Sometimes I prefer hanging braces because it is easier to tell the blocks
    of code apart, yet it takes up more line space. I exclusively use camel casing 
    for coding. I think that it looks much nicer and doesn't clog up the line with excessive
    underscores. I typically use the conventional variable naming, because there's only two 
    prefixes that would come into play (field and parameter), so I don't personally see 
    the need to make the change. For function documentation I tend to go for my own version of
    RME. This is the first time I've seen that style of comments, but will most likely 
    adopt it as time goes on. So, my opinions seem to jump between the two style partitions
    in this project, but I definitely have my preferences. 