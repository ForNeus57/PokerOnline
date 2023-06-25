//
// Created by Dominik on 13.06.2023.
//

#include <gtest/gtest.h>
#include <testing/file_generator.h>

namespace poker {

	/**
	 * @TODO: MAKE UNIT TESTS FOR THIS CLASS.
	 */
	class FileGeneratorTest : public ::testing::Test {
		protected:
			FileGeneratorTest() :
				bool_ptr(nullptr),
				char_ptr(nullptr),
				signed_char_ptr(nullptr),
				unsigned_char_ptr(nullptr),
				short_ptr(nullptr),
				unsigned_short_ptr(nullptr),
				int_ptr(nullptr),
				unsigned_int_ptr(nullptr),
				long_ptr(nullptr),
				unsigned_long_ptr(nullptr),
				long_long_ptr(nullptr),
				unsigned_long_long_ptr(nullptr),
				float_ptr(nullptr),
				double_ptr(nullptr),
				long_double_ptr(nullptr) {

			}

			~FileGeneratorTest() override = default;

			void SetUp() override {
				bool_ptr = std::make_unique<FileGenerator<bool>>();
				char_ptr = std::make_unique<FileGenerator<char>>();
				signed_char_ptr = std::make_unique<FileGenerator<signed char>>();
				unsigned_char_ptr = std::make_unique<FileGenerator<unsigned char>>();
				short_ptr = std::make_unique<FileGenerator<short>>();
				unsigned_short_ptr = std::make_unique<FileGenerator<unsigned short>>();
				int_ptr = std::make_unique<FileGenerator<int>>();
				unsigned_int_ptr = std::make_unique<FileGenerator<unsigned int>>();
				long_ptr = std::make_unique<FileGenerator<long>>();
				unsigned_long_ptr = std::make_unique<FileGenerator<unsigned long>>();
				long_long_ptr = std::make_unique<FileGenerator<long long>>();
				unsigned_long_long_ptr = std::make_unique<FileGenerator<unsigned long long>>();
				float_ptr = std::make_unique<FileGenerator<float>>();
				double_ptr = std::make_unique<FileGenerator<double>>();
				long_double_ptr = std::make_unique<FileGenerator<long double>>();
			}

			void TearDown() override {
				bool_ptr.reset();
				char_ptr.reset();
				signed_char_ptr.reset();
				unsigned_char_ptr.reset();
				short_ptr.reset();
				unsigned_short_ptr.reset();
				int_ptr.reset();
				unsigned_int_ptr.reset();
				long_ptr.reset();
				unsigned_long_ptr.reset();
				long_long_ptr.reset();
				unsigned_long_long_ptr.reset();
				float_ptr.reset();
				double_ptr.reset();
				long_double_ptr.reset();
			}
		protected:
			const std::filesystem::path example_file = std::filesystem::path("./data/file_generator/t1.bin");
		protected:
			std::unique_ptr<FileGenerator<bool>> bool_ptr;
			std::unique_ptr<FileGenerator<char>> char_ptr;
			std::unique_ptr<FileGenerator<signed char>> signed_char_ptr;
			std::unique_ptr<FileGenerator<unsigned char>> unsigned_char_ptr;
			std::unique_ptr<FileGenerator<short>> short_ptr;
			std::unique_ptr<FileGenerator<unsigned short>> unsigned_short_ptr;
			std::unique_ptr<FileGenerator<int>> int_ptr;
			std::unique_ptr<FileGenerator<unsigned int>> unsigned_int_ptr;
			std::unique_ptr<FileGenerator<long>> long_ptr;
			std::unique_ptr<FileGenerator<unsigned long>> unsigned_long_ptr;
			std::unique_ptr<FileGenerator<long long>> long_long_ptr;
			std::unique_ptr<FileGenerator<unsigned long long>> unsigned_long_long_ptr;
			std::unique_ptr<FileGenerator<float>> float_ptr;
			std::unique_ptr<FileGenerator<double>> double_ptr;
			std::unique_ptr<FileGenerator<long double>> long_double_ptr;
	};
	
	TEST_F(FileGeneratorTest, StaticAtributesTest) {

	}
	
	TEST_F(FileGeneratorTest, StaticMethodsTest) {
		//	Test of .generate_random_data(...) method



		//	Test of .generate_continues_data(...) method


	}


	
	
}	//	namespace poker