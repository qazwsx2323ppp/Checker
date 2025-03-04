#ifndef SIMHASH_UTILS_H
#define SIMHASH_UTILS_H

#include <string>

// 读取文件内容
std::string read_file(const std::string& file_path);

// 计算文本的SimHash值
std::string compute_simhash(const std::string& text);

// 计算汉明距离
int calculate_hamming_distance(const std::string& hash1, const std::string& hash2);

#endif // SIMHASH_UTILS_H
