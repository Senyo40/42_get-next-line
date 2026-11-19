_This project has been created as part of the 42 curriculum by ragliga_

## Description

`get_next_line` is a project that implements a function to read a file line by line.
The goal is to create a function that reads content from a file descriptor and returns one complete line at a time, including the newline character.

### Project Overview

The project provides implementation that:
- Reads from file descriptors using a customizable buffer size
- Maintains state between function calls to handle partial lines
- Returns complete lines (including the newline character `\n`) or the last line without one
- Properly manages memory allocation and deallocation
- Handles edge cases such as empty files, files without newlines, and read errors

### How It Works

The implementation uses three main helper functions:
- `read_join`: Reads from the file descriptor and joins data until a newline is found
- `extract_line`: Extracts the next complete line from the buffer
- `clean_rest`: Cleans up remaining data for the next call

### Bonus Features

The bonus version extends the basic implementation to handle multiple file descriptors simultaneously.
Instead of maintaining a single static buffer, the bonus version maintains an array of buffers (one for each file descriptor up to `MAX_FD`).
Allowing you to read from multiple files simultaneously without interfering with each other.

## Instructions

### Mandatory part

1. **Include the header file:**
   - #include "get_next_line.h"

2. **Compile with your main program:**
   - cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c
   
   Or with a custom buffer size:
   - cc -Wall -Werror -Wextra main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1024
   

3. **Use the function:**
   ```c
   int fd = open("file.txt", O_RDONLY);
   char *line;
   
   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
   close(fd);
   ```

### Bonus part

1. **Include the bonus header file:**
   - #include "get_next_line_bonus.h"

2. **Compile with bonus files:**
   - cc main.c -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_utils_bonus.c
   
   Or with a custom buffer size:
   - cc main.c -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=1024

3. **Use with multiple files:**
   ```c
   int fd1 = open("file1.txt", O_RDONLY);
   int fd2 = open("file2.txt", O_RDONLY);
   char *line;
   
   //First file
   while ((line = get_next_line(fd1)) != NULL)
   {
       printf("File1: %s", line);
       free(line);
   }
   
   //Second file
   while ((line = get_next_line(fd2)) != NULL)
   {
       printf("File2: %s", line);
       free(line);
   }
   
   close(fd1);
   close(fd2);
   ```

### Configuration

- `BUFFER_SIZE`: Define the buffer size at compile time (default: 1)
- `MAX_FD` (bonus only): Maximum number of file descriptors to handle simultaneously (default: 1024)

### Important Notes

- Always free the returned line after use
- Return value is `NULL` when EOF is reached or on error
- The function handles files with and without trailing newlines
- Invalid file descriptors (`fd < 0`) or zero `BUFFER_SIZE` return `NULL`

## Resources

To understand this project, i watched this video :
- https://www.youtube.com/watch?v=-Mt2FdJjVno

And documentation for `read()` and `open()` to understand how they work
- https://man7.org/linux/man-pages/man2/read.2.html
- https://man7.org/linux/man-pages/man2/open.2.html

## Usage of AI

I used `Claude` to help me understand the subject and as a tutor.