# Integer Partitions Calculator

A command-line program written in C that calculates the number of integer
partitions of a positive integer.

An integer partition expresses a number as a sum of positive integers where
the order of the terms does not matter. For example, `4` has five partitions:

```text
4
3 + 1
2 + 2
2 + 1 + 1
1 + 1 + 1 + 1
```

Therefore, `p(4) = 5`.

## Requirements

- A C compiler that supports C11, such as GCC or Clang
- A terminal or command prompt

## Build

With GCC or Clang:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic partition_calculator.c -o partition_calculator
```

On Windows, the generated file will normally be named
`partition_calculator.exe`.

## Run

Linux and macOS:

```sh
./partition_calculator
```

Windows PowerShell:

```powershell
.\partition_calculator.exe
```

> **Supported input range:** Enter a positive integer from **1 to 31**. The
> maximum input that can be given is **31**.

The program currently prints a detailed recursion trace before displaying the
final result.

Example (trace shortened):

```text
Enter number: 5
...
The number of partitions of 5 is: 7
```

Some useful values for checking the output are:

| `n` | `p(n)` |
| ---: | -----: |
| 1 | 1 |
| 2 | 2 |
| 3 | 3 |
| 4 | 5 |
| 5 | 7 |
| 6 | 11 |
| 7 | 15 |
| 8 | 22 |
| 9 | 30 |
| 10 | 42 |

## How it works

The program calculates partition values from `p(1)` through `p(n)`. For each
new value, it recursively generates signed references to earlier partition
values, stores those references in a queue, and combines them to obtain the
next result.

## Limitations

- Input must be a positive integer between `1` and `31`; values greater than
  `31` are not supported.
- The program uses `int` for partition counts, so sufficiently large results
  will overflow.
- Its temporary queue grows exponentially and the recursion trace is very
  verbose, so the current implementation is intended for small inputs and
  educational use rather than large calculations.
- Executables are platform-specific. If an included executable does not run on
  your system, rebuild it locally with the command above.

## Project files

- `partition_calculator.c` — calculator source code
- `.gitignore` — excludes compiled object files and executables
