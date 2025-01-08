<h1 align="center">
  <samp>JOVO-LANG</samp>
</h1>

<p align="center">
  <samp>
    an experimental and fun project built on humor and curiosity, <br />
    initiated to gain deeper insights into compilers.
  </samp>
</p>

## Description

Jovo-lang is an experimental and fun project built on humor and curiosity, initiated to gain deeper insights into compilers. The project's motivation emerged in late 2022. Currently, the project is pursued solely for educational purposes.

## Prerequisites

Before building the project, ensure you have the following dependencies installed:

- CMake (minimum version 3.19)
- C++ Compiler (supporting C++20)
- Make
- Git

### Verify installation

```shell
g++ --version    # Should support C++20
cmake --version  # Should be 3.19 or higher
```

## Installation

```shell
# Clone the repository
git clone https://github.com/mtakhirov/jovo-lang.git
cd jovo-lang

# Create build directory
mkdir build
cd build

# Initialize CMake
cmake ..

# Build the project
cmake --build .

# Set PATH to use `jovo` command
export PATH="$PATH:$(pwd)/src/jovo"
```

## Usage

```shell
jovo [command] 
```

## License

This project is licensed under the [MIT License](./LICENCE).