# Linked List Implementation

This repository contains a **generic linked list implementation in C++**, developed with a strong focus on **data structures, templates, and exception handling**. The project is fully tested using **Google Test** and built with **CMake**, following modern C++ development practices.

---

## Overview

The project implements a **templated singly linked list**, supporting common operations such as insertion, removal, search, and position querying. The implementation is validated through an extensive test suite that checks correct behavior, edge cases, and exception handling.

The linked list supports different data types via templates, demonstrated with tests for `int` and `std::string`.

---

## Features

- Generic linked list using C++ templates  
- Abstract base class for list definition  
- Concrete linked list implementation  
- Robust exception handling for invalid operations  
- Comprehensive unit tests using Google Test  
- Build system managed with CMake  

---

## Supported Operations

- Insert at the beginning  
- Insert at the end  
- Insert at a specific position  
- Remove from the beginning  
- Remove from the end  
- Remove from a specific position  
- Remove by value  
- Check if the list is empty  
- Check list size  
- Search for elements and retrieve their position  

---

## Testing

The project uses **Google Test** to validate:

- Correct initialization  
- Insertions at different positions  
- Removals from beginning, middle, and end  
- Handling of invalid positions  
- Handling of operations on empty lists  
- Removal of duplicate values  
- Exception correctness  

---

## Technologies Used

- **Language:** C++  
- **Build System:** CMake  
- **Testing Framework:** Google Test  
- **Paradigm:** Object-Oriented Programming  
- **Concepts:** Templates, Abstraction, Exception Handling  

---

## Project Structure

- `ListaEncadeadaAbstrata.h` – Abstract linked list interface  
- `MinhaListaEncadeada.h` – Concrete linked list implementation  
- `excecoes.h` – Custom exception definitions  
- `main.cpp` – Google Test test suite and test runner  
- `CMakeLists.txt` – Build configuration  

---

## Build and Test Instructions (WSL Required)

This project is intended to be built and executed using **WSL (Windows Subsystem for Linux)**.

### Requirements

- Windows with WSL installed  
- Linux distribution (Ubuntu recommended)  
- C++ compiler (g++)  
- CMake  
- Google Test  

### Installing Dependencies (Ubuntu / WSL)

```bash
sudo apt update
sudo apt install build-essential cmake libgtest-dev
```

Google Test needs to be compiled after installation:

```bash
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
```

---

### Building the Project

From the project root directory:

```bash
mkdir build
cd build
cmake ..
make
```
---

## Running the Tests

```bash
./LinkedListTests
```
(The executable name may vary depending on your ```CMakeLists.txt``` configuration.)

---

## Educational Purpose

This project was created to practice and demonstrate:
- Implementation of classic data structures
- Use of templates for generic programming
- Proper exception handling
- Unit testing with Google Test
- CMake-based project organization
