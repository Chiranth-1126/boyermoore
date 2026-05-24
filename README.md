# Boyer-Moore String Matching Algorithm

A simple C implementation of the Boyer-Moore string matching algorithm.

## Overview

This project demonstrates how to search for a pattern inside a text using the Boyer-Moore algorithm. It includes:

- a C source file: `boyemoore.c`
- example input handling for text and pattern
- a clean command-line build and run workflow

## Files

- `boyemoore.c` — main implementation of the Boyer-Moore search algorithm
- `README.md` — project documentation
- `LICENSE` — project license
- `.gitignore` — ignored files for the repository

## Build and Run

Use a C compiler such as `gcc`:

```bash
gcc boyemoore.c -o boyemoore.exe
./boyemoore.exe
```

Then enter the text and the pattern when prompted.

## Example

Input:

- Text: `Hello world`
- Pattern: `world`

Output:

- `Pattern found at index 6`

## Notes

- The program removes newline characters from input before searching.
- This repository is intended as a small demonstration of string matching logic in C.

