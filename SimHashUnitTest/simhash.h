#pragma once
#pragma once
#ifndef SIMHASH_H
#define SIMHASH_H

#include <string>
#include <vector>

// �����ı��� SimHash ֵ
std::string compute_simhash(const std::string& text);

// �������� SimHash ֵ�ĺ�������
int calculate_hamming_distance(const std::string& hash1, const std::string& hash2);

// ��ȡ�ļ�����
std::string read_file(const std::string& file_path);

// �������ƶ�
double calculate_similarity(const std::string& original_hash, const std::string& plagiarized_hash);

#endif // SIMHASH_H
