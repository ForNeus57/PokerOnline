//
// Created by Dominik on 08.06.2023.
//

#ifndef POKER_ONLINE_DATA_GENERATOR_H
#define POKER_ONLINE_DATA_GENERATOR_H

#include <string>
#include <fstream>
#include <filesystem>
#include <list>
#include <random>

namespace poker {
	
	inline namespace testing {
		
		/**
		 * @brief
		 *
		 * @todo    Transition this class to two separated files (.cpp and .h).
		 * @todo    Add unit tests.
		 *
		 * @tparam  T
		 */
		template<typename T>
		class DataGenerator {
			public:
				using SizeType = std::size_t;
				
			public:
				constexpr static SizeType DEFAULT_NUMBER_OF_INSTANCES = 1000000;
				constexpr static SizeType NUMBER_OF_BITS_IN_A_BYTE = 8;
			
			public:
				DataGenerator() = default;
				~DataGenerator() = default;
				
			public:
				
				/**
				 * @brief
				 * @param   min
				 * @param   max
				 * @param   instances
				 * @return
				 */
				static std::list<T> generate_random_data(T min, T max, SizeType instances) {
					std::list<T> output{};
					
					std::random_device rd;
					std::mt19937 gen(rd());
					
					if (!std::is_floating_point<T>::value) {
						std::uniform_int_distribution<T> dist(min, max);
						for (SizeType i = 0; i < instances; ++i)
							output.push_back(dist(gen));
					} else {
						std::uniform_real_distribution<T> dist(min, max);
						for (SizeType i = 0; i < instances; ++i)
							output.push_back(dist(gen));
					}
					
					return output;
				}
				
				/**
				 * @brief
				 * @param   min
				 * @param   max
				 * @param   instances
				 * @return
				 */
				static std::list<T> generate_continues_data(T min, T max, SizeType instances) {
					std::list<T> output{};
					
					if (!std::is_floating_point<T>::value) {
						for (SizeType i = 0; i < instances; ++i)
							output.push_back(instances++);
					} else {
						T step = std::nextafter(min, max);
						for (T value = min; value <= max; value = std::nextafter(value, max + step))
							output.push_back(value);
					}
					
					return output;
				}
				
				/**
				 * @brief
				 * @tparam  T
				 * @param   path
				 * @return
				 */
				void create_test_file(
						const std::filesystem::path& path,
						T min = std::numeric_limits<T>::min(),
						T max = std::numeric_limits<T>::max(),
						SizeType number_of_instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES,
						std::list<T> (*generator_function)(T, T, SizeType) = DataGenerator::generate_random_data
				) {
					std::ofstream output_file = std::ofstream(path, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
					if (!output_file.is_open())
						throw std::ifstream::failure("Failed to open file: " + path.string());
					
					output_file.write(reinterpret_cast<const char*>(&number_of_instances), sizeof(SizeType));
					
					for (const auto& val : generator_function(min, max, number_of_instances))
						output_file.write(reinterpret_cast<const char*>(&val), sizeof(T));
					
					output_file.close();
				}
				void create_test_data(const std::filesystem::path& path, const std::string& file_tag, SizeType instances = DataGenerator::DEFAULT_NUMBER_OF_INSTANCES) {
					T range = 1;
					for (int i = 0; i < sizeof(T) * DataGenerator::NUMBER_OF_BITS_IN_A_BYTE; ++i, range *= 2) {
						std::list<T> (*generator_function)(T, T, SizeType);
						SizeType number_of_generated_values;
						
						if (range <= instances) {
							generator_function = DataGenerator::generate_continues_data;
							number_of_generated_values = range;
						} else {
							generator_function = DataGenerator::generate_random_data;
							number_of_generated_values = instances;
						}
						
						std::filesystem::path path_to_file = getFullPathFromDirectory(path, file_tag);
						DataGenerator::create_test_file(path_to_file, -range, range, number_of_generated_values, generator_function);
					}
				}
				
				/**
				 * @brief
				 * @param   path
				 * @return
				 */
				std::list<T> read_test_file(const std::filesystem::path& path) {
					SizeType number_of_instances;
					std::list<T> data{};
					
					std::ifstream input_file = std::ifstream(path, std::ios_base::in | std::ios_base::binary);
					if(!input_file.is_open())
						throw std::runtime_error("Unable to use input text file: " + path.string());
					else
						input_file.read(reinterpret_cast<char*>(&number_of_instances), sizeof(SizeType));
					
					for(SizeType i = 0; i < number_of_instances; ++i) {
						T temporary{};
						input_file.read(reinterpret_cast<char*>(&temporary), sizeof(T));
						data.push_back(temporary);
					}
					
					input_file.close();
					
					return data;
				}
				
				
			public:
				static std::filesystem::path getFullPathFromDirectory(std::filesystem::path directoryPath, const std::string& file_name = "input_values.bin") {
					if (!is_directory(directoryPath)) {
						throw std::filesystem::filesystem_error(
								"The provided path is not a directory.",
								directoryPath,
								std::error_code()
						);
					}
					
					return directoryPath /= file_name;
				}
		};
	
}	//	namespace testing
}	//	namespace poker


#endif //POKER_ONLINE_DATA_GENERATOR_H
