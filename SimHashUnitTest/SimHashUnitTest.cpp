#include "CppUnitTest.h"
#include "simhash.h"
#include "pch.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SimHashUnitTest
{
    TEST_CLASS(SimHashUtilsTest)
    {
    public:
        // ²âÊÔ compute_simhash º¯Êý
        TEST_METHOD(TestComputeSimHash_EmptyString)
        {
            std::string result = compute_simhash("");
            Assert::AreEqual(std::string(64, '0'), result);
        }

        TEST_METHOD(TestComputeSimHash_SingleChar)
        {
            std::string result = compute_simhash("a");
            Assert::AreEqual(64ull, result.length());
        }

        TEST_METHOD(TestComputeSimHash_SameString)
        {
            std::string text1 = "hello";
            std::string text2 = "hello";
            Assert::AreEqual(compute_simhash(text1), compute_simhash(text2));
        }

        TEST_METHOD(TestComputeSimHash_DifferentString)
        {
            std::string text1 = "hello";
            std::string text2 = "world";
            Assert::AreNotEqual(compute_simhash(text1), compute_simhash(text2));
        }

        TEST_METHOD(TestComputeSimHash_LongString)
        {
            std::string long_text(1000, 'a');
            std::string result = compute_simhash(long_text);
            Assert::AreEqual(64ull, result.length());
        }

        // ²âÊÔ calculate_hamming_distance º¯Êý
        TEST_METHOD(TestCalculateHammingDistance_SameHash)
        {
            std::string hash1 = "101010";
            std::string hash2 = "101010";
            Assert::AreEqual(0, calculate_hamming_distance(hash1, hash2));
        }

        TEST_METHOD(TestCalculateHammingDistance_DifferentHash)
        {
            std::string hash1 = "101010";
            std::string hash2 = "111111";
            Assert::AreEqual(3, calculate_hamming_distance(hash1, hash2));
        }

        TEST_METHOD(TestCalculateHammingDistance_AllZerosAndOnes)
        {
            std::string hash1 = "000000";
            std::string hash2 = "111111";
            Assert::AreEqual(6, calculate_hamming_distance(hash1, hash2));
        }

        TEST_METHOD(TestCalculateHammingDistance_LengthMismatch)
        {
            std::string hash1 = "1010";
            std::string hash2 = "101010";
            auto func = [hash1, hash2] { calculate_hamming_distance(hash1, hash2); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestCalculateHammingDistance_EmptyHash)
        {
            std::string hash1 = "";
            std::string hash2 = "";
            Assert::AreEqual(0, calculate_hamming_distance(hash1, hash2));
        }

        // ²âÊÔ calculate_similarity º¯Êý
        TEST_METHOD(TestCalculateSimilarity_SameHash)
        {
            std::string hash1 = "101010";
            std::string hash2 = "101010";
            Assert::AreEqual(1.0, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_DifferentHash)
        {
            std::string hash1 = "101010";
            std::string hash2 = "111111";
            Assert::AreEqual(0.5, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_AllZerosAndOnes)
        {
            std::string hash1 = "000000";
            std::string hash2 = "111111";
            Assert::AreEqual(0.0, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_LengthMismatch)
        {
            std::string hash1 = "1010";
            std::string hash2 = "101010";
            auto func = [hash1, hash2] { calculate_similarity(hash1, hash2); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestCalculateSimilarity_EmptyHash)
        {
            std::string hash1 = "";
            std::string hash2 = "";
            Assert::AreEqual(1.0, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_PartialMatch)
        {
            std::string hash1 = "101010";
            std::string hash2 = "101011";
            Assert::AreEqual(5.0 / 6.0, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_64BitHash)
        {
            std::string hash1(64, '0');
            std::string hash2(64, '1');
            Assert::AreEqual(0.0, calculate_similarity(hash1, hash2));
        }

        TEST_METHOD(TestCalculateSimilarity_64BitPartialMatch)
        {
            std::string hash1 = std::string(32, '0') + std::string(32, '1');
            std::string hash2 = std::string(32, '1') + std::string(32, '0');
            Assert::AreEqual(0.5, calculate_similarity(hash1, hash2));
        }
    };
}
