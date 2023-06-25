//
// Created by Dominik on 08.06.2023.
//

#ifndef POKER_ONLINE_FILE_GENERATOR_H
#define POKER_ONLINE_FILE_GENERATOR_H

#include <string>
#include <fstream>
#include <filesystem>
#include <list>
#include <random>
#include <limits>

#include <testing/data_generator.h>

namespace poker {
	
	inline namespace testing {
		
		/**
		 * @brief   Function that
		 * @tparam  T - type that must 
		 * @param   ratio - the percentage of constant values in a generated file in relation to
		 * @param   instances
		 * @return
		 */
		template<typename T>
		std::pair<DataGenerator::SizeType, DataGenerator::SizeType> calculate_number_of_continues_and_random_values(T ratio, DataGenerator::SizeType instances);
		
		/**
		 * @brief   Class that can generate a binary file with random provided T objects.
		 *
		 * @todo    Add unit tests.
		 *
		 * @tparam  T
		 */
		template<typename T>
		class FileGenerator : public DataGenerator {
				//	Constructors and destructors
			public:
				FileGenerator() = default;
				~FileGenerator() = default;
				
				//	Main user defined methods
			public:
				/**
				 * @brief
				 * @param   path
				 * @param   file_tag
				 * @param   continues
				 * @param   random
				 */
				void create_test_data(const std::filesystem::path& path, const std::string& file_tag, SizeType continues, SizeType random);
				void create_test_data(const std::filesystem::path& path, const std::string& file_tag, float fraction_of_constant_values, SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES);
				void create_test_data(const std::filesystem::path& path, const std::string& file_tag, double fraction_of_constant_values, SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES);
				void create_test_data(const std::filesystem::path& path, const std::string& file_tag, long double fraction_of_constant_values, SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES);
				std::list<T> read_test_file(const std::filesystem::path& path);
				std::list<T> read_test_data(const std::filesystem::path& directoryPath);
				std::list<T> read_test_data(const std::list<std::filesystem::path>& files);
				
				//	Static methods
			public:
				static std::filesystem::path getFullPathFromDirectory(std::filesystem::path directoryPath, const std::string& file_name = "input_values.bin");
				static void generate_random_data(std::list<T>& output, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max(), DataGenerator::SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES);
				static void generate_continues_data(std::list<T>& output, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max(), DataGenerator::SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES);
				constexpr static std::string getFileExtension();
			
			private:
				/**
				 * @brief   Method that writes all the contents of provided list to a binary file.
				 *
				 * @param   path - path to binary file.
				 * @param   data - list of values that will be put inside a file.
				 */
				void create_test_file(const std::filesystem::path& path, const std::list<T>& data);
		};
		
}	//	namespace testing
}	//	namespace poker


#endif //POKER_ONLINE_FILE_GENERATOR_H
