#include <iostream>
#include <fstream>
#include "alignment.h"

std::string read_fasta(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, sequence;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line[0] != '>') {
                sequence += line;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
    return sequence;
}

void write_alignment(const std::string& filename, const std::pair<std::string, std::string>& alignment) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Aligned Sequence 1: " << alignment.first << std::endl;
        file << "Aligned Sequence 2: " << alignment.second << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}

int main() {
    std::string seq1 = read_fasta("../data/sequence1.fasta");
    std::string seq2 = read_fasta("../data/sequence2.fasta");

    auto aligned = pairwise_alignment(seq1, seq2);

    std::cout << "Aligned Sequence 1: " << aligned.first << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned.second << std::endl;

    write_alignment("aligned_sequences.txt", aligned);

    return 0;
}
