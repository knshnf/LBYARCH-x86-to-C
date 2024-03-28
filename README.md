# LBYARCH x86-to-C Interface Programming Project 2324T3-S11-G01

## Overview
This project compares the performance of calculating the dot product of two vectors using C programming language and x86-64 assembly language.

## Analysis of the Performance of the Kernels
### Table 1. Debug Mode - C and x86-64 Performance Analysis
| Vector Size | C Execution Time (seconds) | x86-64 Execution Time (seconds) |
|-------------|----------------------------|----------------------------------|
| 2^20        | 0.006067                   | 0.002367                         |
| 2^24        | 0.061733                   | 0.023000                         |
| 2^29        | 1.663033                   | 0.650200                         |

### Table 2. Release Mode - C and x86-64 Performance Analysis
| Vector Size | C Execution Time (seconds) | x86-64 Execution Time (seconds) |
|-------------|----------------------------|----------------------------------|
| 2^20        | 0.000800                   | 0.001100                         |
| 2^24        | 0.016167                   | 0.020833                         |
| 2^29        | 0.469600                   | 0.620600                         |


## Correctness Check
