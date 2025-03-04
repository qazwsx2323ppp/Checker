#include "simhash_utils.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <sstream>

using namespace std;

// 读取文件内容
string read_file(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_path << endl;
        exit(-1);
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// 计算文本的SimHash值
string compute_simhash(const string& text) {
    

    size_t hash_value = 0;
    for (char ch : text) {
        hash_value ^= hash<char>()(ch);
    }

    // 将hash值转换为二进制字符串表示
    bitset<64> hash_bits(hash_value);
    return hash_bits.to_string();
}

// 计算汉明距离
int calculate_hamming_distance(const string& hash1, const string& hash2) {
    if (hash1.length() != hash2.length()) {
        cerr << "Error: Hash lengths do not match!" << endl;
        exit(-1);
    }

    int distance = 0;
    for (size_t i = 0; i < hash1.length(); ++i) {
        if (hash1[i] != hash2[i]) {
            ++distance;
        }
    }

    return distance;
}
