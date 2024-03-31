# LBYARCH x86-to-C Interface Programming Project 2324T3-S11-G01
This project compares the performance of calculating the dot product of two vectors using C programming language and x86-64 assembly language.

## Analysis of the Performance of the Kernels
For each kernel, the process of calculating the dot product is measured for both implementations in debug and release modes.  Randomly generated vectors are used for testing and the same vectors are utilized for both the C and x86-64 implementations. Each kernel is executed 30 times to obtain reliable performance metrics.

The average execution times of the C and x86-64 assembly implementations in debug mode are as follows:
### Table 1. Debug Mode - C and x86-64 Performance Analysis
| Vector Size | C Execution Time (seconds) | x86-64 Execution Time (seconds) |
|-------------|----------------------------|----------------------------------|
| 2^20        | 0.006067                   | 0.002367                         |
| 2^24        | 0.061733                   | 0.023000                         |
| 2^29        | 1.663033                   | 0.650200                         |

The x86-64 assembly implementation consistently outperforms the C implementation across all vector sizes in debug mode. As expected, the execution times increase with larger vector sizes due to the increased computations.

Release mode led to improved performance for both the C and x86-64 assembly implementations:
### Table 2. Release Mode - C and x86-64 Performance Analysis
| Vector Size | C Execution Time (seconds) | x86-64 Execution Time (seconds) |
|-------------|----------------------------|----------------------------------|
| 2^20        | 0.000800                   | 0.001100                         |
| 2^24        | 0.016167                   | 0.020833                         |
| 2^29        | 0.469600                   | 0.620600                         |

Unexpectedly, the C implementation demonstrated slightly faster execution times compared to the x86-64 implementation in release mode. The performance of C significantly improved while the x84-64 implementation remained relatively consistent with its performance in debug mode. This may be attributed to the x86-64 kernel using NASM for both modes.

## Correctness Check
To ensure the correctness of the implementations, the following vectors were used to verify the dot product calculations:
| Vector A                                  | Vector B                                  | Expected Dot Product |
|-------------------------------------------|-------------------------------------------|----------------------|
| [0.532, 0.231, 0.856, 0.412, 0.624]       | [0.719, 0.831, 0.248, 0.956, 0.143]       | ~1.269861            |
| [1.5, 2.7, 3.8, 4.2, 5.1]                 | [0.9, 1.2, 2.5, 3.6, 4.8]                 | ~53.69               |
| [10.6, 15.2, 20.9, 25.3, 30.8]            | [5.4, 10.1, 15.9, 20.7, 25.6]             | ~1855.26             |

### Screenshots
![WindowsTerminal_9vifg35VGe](https://github.com/knshnf/LBYARCH-x86-to-C/assets/97265370/9e9cf872-88a8-4e56-bd16-121371ab34b5)
![0aGRldO3DN](https://github.com/knshnf/LBYARCH-x86-to-C/assets/97265370/6a61bc46-f829-4508-912b-88026d1b9547)
![9HLeiuS19f](https://github.com/knshnf/LBYARCH-x86-to-C/assets/97265370/d8fc7796-f5f5-4a2c-b9ef-4727f19b0119)


The screenshots above display the output of the implementations alongside the expected dot product values. The matching results show the correctness of both implementations.

