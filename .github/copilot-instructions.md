# Project Overview

This project is a fork of the GNU C Compiler (GCC) specifically tailored for the
Nanvix operating system. It provides a complete toolchain for compiling C, C++
and Fortran programs for Nanvix.

## Target Architecture Support

This fork introduces the following new target architectures and operating system support:
- `i686-nanvix` (32-bit x86 for Nanvix)
- `x86_64-nanvix` (64-bit x86 for Nanvix)

## Key Components

This repository contains the source code of the following development utilities:
- `gcc` - The GNU C Compiler
- `g++` - The GNU C++ Compiler
- `gfortran` - The GNU Fortran Compiler

## Building and Installation

This project uses a custom `z` utility script for streamlined building and installation.

### Quick Start

```bash
# See all available commands
./z help

# Complete build process
./z setup      # Install required system packages
./z configure  # Configure the build
./z build      # Compile the source code
./z install    # Install to default location
./z release    # Create a release zip file
```

## Contributing Guidelines

When making changes:
- **Target Compatibility**: Ensure all changes maintain compatibility with the `i686-nanvix` and `x86_64-nanvix` targets
- **Testing**: Test changes thoroughly using the build and install process
- **Code Style**: Follow the established GNU coding standards.
- **Documentation**: Update relevant documentation and comments
- **Upstream Compatibility**: Consider impact on future upstream merges from GCC

### Code Style and Standards

This project follows GNU coding standards and conventions.

