# 🗂️ CLI Task Manager in C

A simple, lightweight command-line task manager written in **C (C11)** with persistent storage using a text file.

---

## 📌 Project Overview

This project is a console-based task management application that allows users to:

* Add new tasks
* View all tasks
* Mark tasks as completed
* Delete tasks
* Persist data between sessions using file storage

It was created to practice **C programming fundamentals**, including file handling, structures, arrays, and Makefile-based builds.

---

## ⚙️ Features

✔ Add tasks
✔ Display task list
✔ Mark tasks as completed
✔ Delete tasks
✔ Persistent storage (`tasks.txt`)
✔ Simple CLI interface
✔ Makefile build system

---

## 🧠 Technologies Used

* C (C11 standard)
* GCC Compiler
* File I/O (`fopen`, `fprintf`, `fscanf`)
* Structures (`struct`)
* Arrays
* Makefile
* Git & GitHub

---

## 📁 Project Structure

```
task-manager-c/
│
├── main.c          # Main application source code
├── Makefile        # Build automation
├── README.md       # Project documentation
├── .gitignore      # Ignored files for Git
└── tasks.txt       # Task storage file (runtime data)
```

---

## 🚀 How to Build

Compile the project using GCC:

```bash
gcc main.c -o taskmanager -Wall -Wextra -std=c11
```

OR using Makefile:

```bash
make
```

---

## ▶️ How to Run

```bash
./taskmanager
```

OR:

```bash
make run
```

---

## 🧪 Example Usage

```
===== TASK MANAGER =====
1. Add task
2. Show tasks
3. Complete task
4. Delete task
5. Exit
```

---

## 💾 Data Storage

Tasks are stored in a simple text file:

```
0|Learn C programming
1|Build CLI project
```

* `0` = not completed
* `1` = completed

---

## 🎯 Learning Goals

This project helped me practice:

* Low-level programming in C
* Working with files
* Data structures (structs)
* Memory and arrays
* Build automation with Makefile
* Git version control workflow

---

## 🔮 Possible Improvements

* Dynamic memory allocation (`malloc`, `realloc`)
* Task priorities (Low / Medium / High)
* Due dates (deadlines)
* Search and filter tasks
* Colored terminal output (ANSI escape codes)
* Multi-file architecture (`.h` / `.c` separation)
* JSON storage instead of text file

---

## 👨‍💻 Author

**Your Name**
  Rafal
---

## 📌 Status

✔ Working CLI application
✔ Stable file persistence
✔ Ready for portfolio use
✔ Beginner-friendly C project
