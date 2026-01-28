# Educational Programming Repository - GCE Advanced Level Computer Science

## Project Overview

This repository contains educational materials and programming exercises for GCE Advanced Level Computer Science students in Cameroon. It focuses on C programming, algorithms, and problem-solving techniques as taught by Mr. DCT. The repository includes implementations of classic computer science problems and exercises that align with the GCE Advanced Level Computer Science curriculum.

### Directory Structure

The repository consists of three main projects:

#### 1. AL-2025-CSC-3: Conway's Game of Life
- **Purpose**: Implementation of Conway's Game of Life cellular automaton in C
- **Content**: Complete solution to a Section B Programming Task from the GCE AL CSC-3 2025 syllabus
- **Key Features**:
  - 2D grid implementation using arrays
  - Functions for counting live neighbors
  - Generation of next generation based on Conway's rules
  - Random initialization with seed
  - Visual output formatting

#### 2. Algorithm-Mastery-Series-pseudocode-C-programs
- **Purpose**: Collection of algorithm exercises with both pseudocode and C implementations
- **Content**: Multiple exercises (Ex_1 through Ex_10) demonstrating fundamental programming concepts
- **Key Features**:
  - Side-by-side pseudocode and C code implementations
  - Progressive complexity from basic "Hello" program to more complex algorithms
  - Educational focus on algorithm design and implementation
  - Covers topics like input/output, arithmetic operations, conditionals, and loops

#### 3. CSC-P3-June-2021-Section-A-Programming-Solution
- **Purpose**: Solution to Section A Programming Task from June 2021 GCE exam
- **Content**: Implementation of Pascal's Triangle in C with detailed algorithm explanations
- **Key Features**:
  - Complete implementation of Pascal's Triangle generation
  - Step-by-step algorithm breakdown
  - Functions for filling diagonal, first column, and interior entries
  - Matrix printing functionality

## Building and Running

Since these are C programming exercises, they can be compiled and run using standard C compilers:

```bash
# For Conway's Game of Life
cd AL-2025-CSC-3
gcc AL-2025-CSC-3.cpp -o conway_game
./conway_game

# For Algorithm Mastery Series exercises
cd Algorithm-Mastery-Series-pseudocode-C-programs-/Ex_1
gcc Ex_1.c -o Ex_1
./Ex_1

# For Pascal's Triangle implementation
cd CSC-P3-June-2021-Section-A-Programming-Solution
gcc main.c -o pascal_triangle
./pascal_triangle
```

## Educational Content

### Key Programming Concepts Covered

1. **Basic Programming Constructs**:
   - Variables and data types
   - Input/output operations
   - Control structures (if/else, loops)
   - Functions and modularity

2. **Data Structures**:
   - Arrays (1D and 2D)
   - Matrices and grid manipulation

3. **Algorithms**:
   - Random number generation
   - Cellular automata (Conway's Game of Life)
   - Mathematical sequences (Pascal's Triangle)
   - Matrix operations

4. **Problem-Solving Techniques**:
   - Decomposition of complex problems
   - Step-by-step algorithm design
   - Translation from pseudocode to actual code

### Learning Objectives

Students using this repository will gain experience in:
- Writing clean, readable C code
- Understanding and implementing classic algorithms
- Translating mathematical concepts into code
- Working with 2D arrays and matrices
- Following systematic approaches to problem-solving
- Preparing for GCE Advanced Level Computer Science examinations

## Development Conventions

- Code follows standard C programming practices
- Clear variable names and consistent formatting
- Comprehensive comments explaining both the algorithm and implementation
- Modular design with separate functions for different tasks
- Error checking where appropriate

## Target Audience

This repository is specifically designed for:
- GCE Advanced Level Computer Science students in Cameroon
- Students preparing for Section A and B programming tasks
- Anyone interested in learning fundamental programming concepts in C
- Educators teaching computer science at the advanced level