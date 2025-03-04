#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "simhash_utils.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    /* cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    
    int a;

    cin >> a; */

    if (argc != 4) 
    {
        cerr << "Usage: " << argv[0] << " <original_text_file> <plagiarized_text_file> <output_file>" << endl;
        return -1;
    }

    string original_file_path = argv[1];
    string plagiarized_file_path = argv[2];
    string output_file_path = argv[3];

    // 读取原文和抄袭版文件
    string original_text = read_file(original_file_path);
    string plagiarized_text = read_file(plagiarized_file_path);

    // 计算SimHash值
    string original_hash = compute_simhash(original_text);
    string plagiarized_hash = compute_simhash(plagiarized_text);

    // 计算汉明距离
    int hamming_distance = calculate_hamming_distance(original_hash, plagiarized_hash);

    // 计算相似度
    double similarity = 1.0 - static_cast<double>(hamming_distance) / original_hash.length();

    // 输出查重率到文件
    ofstream output_file(output_file_path);
    if (!output_file) {
        cerr << "Error opening output file!" << endl;
        return -1;
    }
    output_file.precision(2);
    output_file << fixed << similarity * 100 << "%" << endl;

    cout << "Similarity: " << similarity * 100 << "%" << endl;

    return 0;
}
