#include "simhash.h"
#include <fstream>
#include <sstream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include "pch.h"


// ��ȡ�ļ�����
std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file: " + file_path);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// �����ı��� SimHash ֵ
std::string compute_simhash(const std::string& text) {
    std::vector<int> hash_bits(64, 0); // 64 λ�� SimHash

    // �����ı��е�ÿ���ַ�
    for (char ch : text) {
        std::hash<char> hasher;
        size_t hash_value = hasher(ch); // �����ַ��Ĺ�ϣֵ

        // ����ϣֵ��ÿһλ�ۼӵ� SimHash ��
        for (int i = 0; i < 64; ++i) {
            if (hash_value & (1 << i)) {
                hash_bits[i]++;
            }
            else {
                hash_bits[i]--;
            }
        }
    }

    // ���� SimHash ֵ
    std::string simhash;
    for (int i = 0; i < 64; ++i) {
        simhash += (hash_bits[i] > 0) ? '1' : '0';
    }
    return simhash;
}

// �������� SimHash ֵ�ĺ�������
int calculate_hamming_distance(const std::string& hash1, const std::string& hash2) {
    if (hash1.length() != hash2.length()) {
        throw std::runtime_error("Error: Hash lengths do not match!");
    }

    int distance = 0;
    for (size_t i = 0; i < hash1.length(); ++i) {
        if (hash1[i] != hash2[i]) {
            distance++;
        }
    }
    return distance;
}

// �������ƶ�
double calculate_similarity(const std::string& original_hash, const std::string& plagiarized_hash) {
    int hamming_distance = calculate_hamming_distance(original_hash, plagiarized_hash);
    return 1.0 - static_cast<double>(hamming_distance) / original_hash.length();
}