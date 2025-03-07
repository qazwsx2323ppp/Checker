#pragma once
#pragma once
#ifndef SIMHASH_H
#define SIMHASH_H

#include <string>
#include <vector>

// 计算文本的 SimHash 值
std::string compute_simhash(const std::string& text);

// 计算两个 SimHash 值的汉明距离
int calculate_hamming_distance(const std::string& hash1, const std::string& hash2);

// 读取文件内容
std::string read_file(const std::string& file_path);

// 计算相似度
double calculate_similarity(const std::string& original_hash, const std::string& plagiarized_hash);

#endif // SIMHASH_H
