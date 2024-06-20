# SimplePairwiseAlignment

This repository contains a simple implementation of a pairwise alignment algorithm for FASTA files using the Needleman-Wunsch algorithm. It demonstrates basic proficiency in C++ and genetics.

## Features

- Reads sequences from FASTA files
- Aligns sequences using the Needleman-Wunsch algorithm
- Outputs aligned sequences to the console and a file

## Requirements

- CMake 3.10 or higher
- C++11 or higher

## Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/yourusername/SimplePairwiseAlignment.git
    cd SimplePairwiseAlignment
    ```

2. **Create a build directory and navigate to it:**
    ```bash
    mkdir build
    cd build
    ```

3. **Generate the build files using CMake:**
    ```bash
    cmake ..
    ```

4. **Build the project using make:**
    ```bash
    make
    ```

## Usage

1. **Run the executable:**
    ```bash
    ./PairwiseAlignment
    ```

2. **View the output:**
    - The aligned sequences will be printed to the console.
    - The aligned sequences will be saved in `aligned_sequences.txt` in the `build` directory.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


