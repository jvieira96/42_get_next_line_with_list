# Get Next Line (with linked lists) - 42 Project

This version of **Get Next Line** reads a file descriptor line by line, returning one line at a time.  
It uses **linked lists** internally to manage buffer storage dynamically, allowing handling of lines of any length efficiently.

---

## Features

- Reads from any file descriptor until a newline or EOF  
- Uses linked lists to store buffer chunks dynamically  
- Supports **bonus** functionality: manages multiple file descriptors simultaneously  
- Efficient memory handling by freeing nodes as lines are returned  
- Complies with 42 coding standards  

---

## Why linked lists?

Linked lists allow dynamic, flexible storage of data chunks without fixed-size buffers, enabling the program to process very long lines seamlessly.
