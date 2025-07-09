# 📄 Get Next Line - Using Linked Lists

## 📚 Project Overview

This project implements a **Get Next Line** function that reads from a file descriptor and returns one line at a time. Unlike a simple buffer-based approach, this version uses **linked lists** to manage the read data dynamically, allowing efficient handling of arbitrary line lengths and partial reads.

---

## 💡 What I Learned

- 🧩 How to manage dynamic input buffers using **linked lists** in C.
- 🔄 Handling partial reads and buffering data between function calls.
- 🗂 Memory management with dynamic allocation and freeing linked list nodes.
- ⚙️ Implementing line parsing logic that can handle newline characters spanning multiple buffers.
- 🧹 Writing clean, modular code adhering to 42 coding standards.
- 🛠 Using system calls like `read()` effectively in a loop.
- 📏 Handling edge cases like end-of-file, empty lines, and large inputs.

---

## 🛠 Technical Concepts Used

- **Linked list** data structure to store chunks of buffered data.
- Buffering partial reads and appending them to the linked list.
- Searching for newline characters across multiple nodes.
- Concatenating linked list content to assemble the returned line.
- Managing leftover data after extracting a line for the next call.
- Proper memory cleanup to avoid leaks.
- Using static variables to preserve state between calls.

---

## 🚀 Functionality

- Reads from any file descriptor, including files, stdin, or sockets.
- Returns one line per call, including the newline character.
- Handles lines of any length efficiently.
- Supports multiple calls until end-of-file.
- Returns `NULL` when no more lines are available or on error.

---

## ⚠️ Challenges Overcome

- Correctly splitting data across linked list nodes.
- Managing memory allocation and freeing without leaks or corruption.
- Handling different buffer sizes and partial reads.
- Ensuring function works reliably under all edge cases.

---

## 🧠 Key Takeaways

This project deepened my understanding of:

- Dynamic memory management and linked lists in C.
- Low-level file reading and buffering techniques.
- Writing robust code that handles real-world input scenarios.
- Debugging memory and pointer-related issues.
