# Available Languages: 
[English](README.eng.md) | [Türkçe](README.md)

# <center>Fixture Generation Assignment</center>

This is a C program that reads team names from a given `takimlar.txt` file, matches them weekly, simulates matches, and generates a points table based on the results. Match scores are determined randomly according to the power differences between teams.

## Table of Contents
- [Project Requirements](#project-requirements)  
- [Manual Execution](#manual-execution)  
- [Manual Compilation](#manual-compilation)  
- [Compiling the Code](#compiling-the-code)  
- [File Format](#file-format)  
- [Important Notes](#important-notes)  
- [Changelog](#changelog-29042024)

## Project Requirements

### Compilation Tools

```
gcc
```

## Supported Operating Systems

- Windows  
- Linux  

## Manual Execution

### Windows

```
./fikstur.exe
```

### Linux

```
./fikstur.o
```

## Manual Compilation

### Installing Requirements

#### Fedora

```
sudo dnf install gcc
```

#### Ubuntu

```
sudo apt-get install gcc
```

#### Windows

```
Mingw64-gcc
```

## Compiling the Code

#### Windows
```
gcc -o fikstur.exe fikstur.c
```

#### Linux
```
gcc -o fikstur.o fikstur.c
```

## File Format

### Teams File

Example format:

```
(Team Name)
(Team Name)
(Team Name)
(Team Name)
```

### Fixture Output File

- An example `fikstur.txt` file is included.

### Power File
```
(number)
(number)
(number)
```

### Points File

- An example `puanlar.txt` file is included.

## Important Notes

- The teams file must follow the example format; otherwise, the program may throw an error.
- The power range difference should not exceed 50, and power values should be multiples of 10. (90, 80, 70, 60, 50, 40 are used.)

## Changelog 06.05.2025

- A new `macSonuclari()` function was added, and goal-scoring probabilities based on the `Difference` variable were implemented using a switch-case structure
- The code has been further organized.
- The issue with teams having a bye week has been resolved.
- The matches in the first 19 weeks and the last 19 weeks are now mirrored, with home and away teams swapped (more realistic).
- Turkish and English ReadMEs have been separated.

