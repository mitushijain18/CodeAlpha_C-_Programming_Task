# Sudoku Solver Using C++ Programming

## Project Overview

This project is developed as part of the CodeAlpha C Programming Internship. The project focuses on creating a Sudoku Solver that automatically solves a given Sudoku puzzle using algorithmic problem-solving techniques.

The main objective of this project is to implement the backtracking algorithm in C programming to solve Sudoku puzzles efficiently while applying concepts such as arrays, functions, recursion, and logical reasoning.

## About Sudoku Solver

A Sudoku Solver is a program that finds the correct solution for a Sudoku puzzle by filling empty cells while following Sudoku rules.

The puzzle consists of a 9×9 grid where each row, column, and 3×3 sub-grid must contain numbers from 1 to 9 without repetition.

## Project Objectives

The main objectives of this project are:

- Develop a Sudoku solving program using C
- Implement backtracking algorithm
- Understand recursion and logical problem solving
- Work with two-dimensional arrays
- Create an efficient puzzle-solving application

## Technologies Used

- C Programming Language
- GCC Compiler
- VS Code / Code::Blocks

## Concepts Used

- Arrays
- Two-Dimensional Arrays
- Functions
- Recursion
- Conditional Statements
- Loops
- Backtracking Algorithm

## Features

The Sudoku Solver includes:

- Accepts a Sudoku puzzle as input
- Automatically finds the solution
- Checks Sudoku rules
- Handles empty cells
- Displays solved Sudoku grid
- Efficient backtracking approach

## Working of the Program

The Sudoku Solver works using the backtracking technique.

### Working Steps:

1. The program takes a partially filled Sudoku grid as input.
2. It searches for an empty cell in the grid.
3. It tries possible numbers from 1 to 9.
4. The program checks whether the number is valid according to Sudoku rules.
5. If the number is valid, it is placed in the cell.
6. The algorithm recursively solves the remaining puzzle.
7. If a solution path fails, the program backtracks and tries another number.
8. The final solved Sudoku grid is displayed.

## Algorithm Used

### Backtracking Algorithm

Backtracking is a recursive algorithm that tries different possibilities and removes incorrect choices when a solution cannot be achieved.

It is commonly used in:

- Puzzle solving
- Path finding
- Constraint satisfaction problems
- Combinatorial problems

## Sudoku Rules Followed

The solution ensures that:

- Each row contains numbers 1–9 without repetition.
- Each column contains numbers 1–9 without repetition.
- Each 3×3 box contains numbers 1–9 without repetition.

## Project Structure

Sudoku-Solver

- sudoku_solver.cpp
- Input_Output
- Output_Screenshots
- Documentation
- README.md

## How to Run the Project

1. Install a C++ compiler such as GCC.

2. Compile the program:

```bash
gcc sudoku_solver.cpp -o sudoku
