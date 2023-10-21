
<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/get_next_linem.png alt=cado-car's 42Project Badge/>
<h2>Final score</h2>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/125Grade.png alt=Xanaco's 42Project Score/>
<h4>Completed + Bonus</h4>
</div>

## Overview

The "get_next_line" (often abbreviated as "GNL") project requires students to code a function that reads and returns the next line from a file descriptor. Unlike standard functions that might read an entire file or large chunks of data, "get_next_line" is designed to retrieve content line by line, which can be particularly useful in various programming scenarios, especially in parsers or interactive programs.

The primary challenge is managing buffers efficiently, ensuring that the function works seamlessly under varying conditions, and handling the complexities of file reading operations.

## Key Components

1. **File Reading**: Using system calls like `read` to fetch data from a given file descriptor.

2. **Buffer Management**: Efficiently handling a buffer to store data read from the file descriptor and using this buffer to return complete lines.

3. **Memory Allocation**: Dynamically allocating and freeing memory as required, ensuring no leaks and optimal memory usage.

4. **Return Values**: The function must be able to differentiate between a read line, end of file, or an error, typically using return values such as 1 (line read), 0 (EOF reached), or -1 (an error occurred).

5. **Static Variables**: Using static variables to retain values between function calls, ensuring continuity and efficiency in reading successive lines.

6. **Bonus Goals**: Handling multiple file descriptors simultaneously and ensuring that the function is not overly complicated are considered bonus objectives.

## Key Skills Developed

1. **File Operations**: Gaining a deeper understanding of file reading operations in C and managing file descriptors.

2. **Buffer Management**: Learning to efficiently handle buffers, essential for optimal performance and data retrieval.

3. **Memory Management**: Enhancing skills related to dynamic memory allocation, reallocation, and deallocation in C.

4. **Error Handling**: Implementing robust error checks and handling potential issues that may arise during file operations.

5. **Efficiency Optimization**: Crafting solutions that are not only functional but also optimized for performance.

6. **Data Parsing**: Indirectly, the project familiarizes students with the basics of parsing, as the function has to detect line breaks and manage partial data reads.

7. **Modular Programming**: Creating a utility function that can be reused in various projects, emphasizing the importance of modular and reusable code.
