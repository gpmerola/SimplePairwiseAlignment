#include "alignment.h"
#include <vector>
#include <algorithm>

int match_score(char a, char b) {
    return (a == b) ? 1 : -1;
}

std::pair<std::string, std::string> pairwise_alignment(const std::string& seq1, const std::string& seq2) {
    int gap_penalty = -1;
    int m = seq1.size();
    int n = seq2.size();
    
    std::vector<std::vector<int>> score(m+1, std::vector<int>(n+1, 0));
    std::vector<std::vector<int>> traceback(m+1, std::vector<int>(n+1, 0));
    
    for (int i = 1; i <= m; ++i) {
        score[i][0] = i * gap_penalty;
    }
    for (int j = 1; j <= n; ++j) {
        score[0][j] = j * gap_penalty;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match = score[i-1][j-1] + match_score(seq1[i-1], seq2[j-1]);
            int delete_score = score[i-1][j] + gap_penalty; // renamed from delete to delete_score
            int insert = score[i][j-1] + gap_penalty;
            score[i][j] = std::max({match, delete_score, insert});

            if (score[i][j] == match) {
                traceback[i][j] = 0; // 0 indicates match/mismatch
            } else if (score[i][j] == delete_score) {
                traceback[i][j] = 1; // 1 indicates gap in seq2
            } else {
                traceback[i][j] = 2; // 2 indicates gap in seq1
            }
        }
    }

    std::string aligned_seq1, aligned_seq2;
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (traceback[i][j] == 0) {
            aligned_seq1 += seq1[i-1];
            aligned_seq2 += seq2[j-1];
            i--; j--;
        } else if (traceback[i][j] == 1) {
            aligned_seq1 += seq1[i-1];
            aligned_seq2 += '-';
            i--;
        } else {
            aligned_seq1 += '-';
            aligned_seq2 += seq2[j-1];
            j--;
        }
    }
    
    std::reverse(aligned_seq1.begin(), aligned_seq1.end());
    std::reverse(aligned_seq2.begin(), aligned_seq2.end());
    
    return {aligned_seq1, aligned_seq2};
}
