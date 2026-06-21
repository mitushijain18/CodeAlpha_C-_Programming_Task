# Login and Registration System Using C++ Programming

## Project Overview

This project is developed as part of the CodeAlpha C Programming Internship. The project focuses on creating a Login and Registration System that allows users to create accounts and securely access the system using their registered credentials.

The main objective of this project is to implement user authentication concepts using C programming, file handling, and basic data management techniques.

## About Login and Registration System

A Login and Registration System is an application that manages user accounts by allowing new users to register and existing users to log in using their username and password.

The system stores user information and verifies credentials during login to provide controlled access.

## Project Objectives

The main objectives of this project are:

- Develop a user authentication system using C
- Implement registration and login functionality
- Store user information securely
- Apply file handling concepts
- Understand basic security and validation techniques

## Technologies Used

- C Programming Language
- GCC Compiler
- VS Code / Code::Blocks
- File Handling in C++

## Concepts Used

- Variables and Data Types
- Functions
- Conditional Statements
- Loops
- Strings
- Structures
- File Handling
- User Input Handling

## Features

The Login and Registration System includes:

- New user registration
- User login authentication
- Username and password verification
- User data storage
- Invalid login handling
- Simple menu-driven interface

## Working of the System

The system works through the following steps:

### Registration Process

1. User selects the registration option.
2. User enters username and password.
3. User details are stored in a file.
4. Account creation is completed successfully.

### Login Process

1. User enters registered username and password.
2. System reads stored user information.
3. Entered credentials are compared with stored data.
4. Access is granted if credentials match.
5. Error message is displayed for incorrect details.

## System Modules

### 1. Registration Module

Handles:

- New user account creation
- User information input
- Saving credentials

### 2. Login Module

Handles:

- User authentication
- Credential verification
- Access control

### 3. File Management Module

Handles:

- Storing user details
- Reading user records
- Managing user data

## Project Structure

Login-Registration-System

- login_registration.cpp
- users.txt
- Output_Screenshots
- Documentation
- README.md

## How to Run the Project

1. Install a C compiler such as GCC.

2. Compile the program:

```bash
gcc login_registration.cpp -o login
