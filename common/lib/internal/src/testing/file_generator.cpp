//
// Created by Dominik on 08.06.2023.
//

#include "testing/file_generator.h"

namespace poker::testing {

	//	Template explicit instantiation
	template std::pair<DataGenerator::SizeType, DataGenerator::SizeType> calculate_number_of_continues_and_random_values<float>(float, DataGenerator::SizeType);
	template std::pair<DataGenerator::SizeType, DataGenerator::SizeType> calculate_number_of_continues_and_random_values<double>(double, DataGenerator::SizeType);
	template std::pair<DataGenerator::SizeType, DataGenerator::SizeType> calculate_number_of_continues_and_random_values<long double>(long double, DataGenerator::SizeType);

	//	Function definitions
	template<typename T>
	std::pair<DataGenerator::SizeType, DataGenerator::SizeType> calculate_number_of_continues_and_random_values(T ratio, DataGenerator::SizeType instances) {
		if (ratio < T(0) or ratio > T(1)) throw std::invalid_argument("Provided ratio must be between <0, 1>!");

		auto number_of_continues_values = static_cast<DataGenerator::SizeType>(ratio * T(instances));
		auto number_of_random_values = static_cast<DataGenerator::SizeType>((T(1) - ratio) * T(instances));

		const auto sum = number_of_continues_values + number_of_random_values;

		//	Adjust for inconsistencies.
		if (sum < instances) {
			number_of_continues_values += instances - sum;
		} else if (sum > instances) {
			number_of_continues_values -= sum - instances;
		}

		return std::make_pair(number_of_continues_values, number_of_random_values);
	}

	//	Template explicit instantiation
	template class FileGenerator<bool>;
	template class FileGenerator<char>;
	template class FileGenerator<signed char>;
	template class FileGenerator<unsigned char>;
	template class FileGenerator<short>;
	template class FileGenerator<unsigned short>;
	template class FileGenerator<int>;
	template class FileGenerator<unsigned int>;
	template class FileGenerator<long>;
	template class FileGenerator<unsigned long>;
	template class FileGenerator<long long>;
	template class FileGenerator<unsigned long long>;
	template class FileGenerator<float>;
	template class FileGenerator<double>;
	template class FileGenerator<long double>;

	//	Object methods definitions.
	template<typename T>
	void FileGenerator<T>::create_test_file(const std::filesystem::path& path, const std::list<T>& data) {
		if (!std::filesystem::is_regular_file(path)) throw std::runtime_error("Provided path:" + absolute(path).string() + " is not a file!");

		std::ofstream output_file = std::ofstream(path, std::ios_base::out | std::ios_base::trunc);

		if (!output_file.is_open()) throw std::runtime_error("File:" + absolute(path).string() + "could not be opened!");

		for (const auto & val : data)
			output_file.write(reinterpret_cast<const char*>(&val), sizeof(T));

		output_file.flush();
		output_file.close();
	}

	template<typename T>
	void FileGenerator<T>::create_test_data(const std::filesystem::path& path, const std::string& file_tag, SizeType continues, SizeType random) {
		std::list<T> output_data{};

		for (DataGenerator::SizeType continues_generated = 0; continues_generated < continues; continues_generated++) {

		}



//			for (int i = 0; i < sizeof(T) * FileGenerator::NUMBER_OF_BITS_IN_A_BYTE; ++i, range *= FileGenerator::RANGE_MULTIPLIER) {
//				DataGenerator::SizeType number_of_values_needed = range * (std::is_unsigned<T>::value ? 1 : 2) + 1;
//				if(number_of_values_needed <= instances) {
//					generator_function = FileGenerator::generate_continues_data;
//					number_of_generated_values = number_of_values_needed;
//				} else {
//					generator_function = FileGenerator::generate_random_data;
//					number_of_generated_values = instances;
//				}
//			}
		DataGenerator::SizeType number_of_values_needed;
		for (DataGenerator::SizeType random_generated = 0; ;) {

		}

		std::filesystem::path full_path = getFullPathFromDirectory(path, file_tag);
		create_test_file(full_path, output_data);
	}



//		template<typename T>
//		void FileGenerator<T>::create_test_data(const std::filesystem::path& path, const std::string& file_tag, DataGenerator::SizeType instances) {
//			T range(1);
//			std::list<T> (*generator_function)(T, T, DataGenerator::SizeType);
//			DataGenerator::SizeType number_of_generated_values;
//			const DataGenerator::SizeType number_of_continues_numbers = 0;
//
//
//
//			for (int i = 0; i < sizeof(T) * FileGenerator::NUMBER_OF_BITS_IN_A_BYTE; ++i, range *= FileGenerator::RANGE_MULTIPLIER) {
//				DataGenerator::SizeType number_of_values_needed = range * (std::is_unsigned<T>::value ? 1 : 2) + 1;
//				if (number_of_values_needed <= instances) {
//					generator_function = FileGenerator::generate_continues_data;
//					number_of_generated_values = number_of_values_needed;
//				} else {
//					generator_function = FileGenerator::generate_random_data;
//					number_of_generated_values = instances;
//				}
//
//				std::filesystem::path path_to_file = getFullPathFromDirectory(path, file_tag + "_" + std::to_string(i));
//				FileGenerator::create_test_file(path_to_file, (std::is_unsigned<T>::value ? T(0) : -range), range, number_of_generated_values, generator_function);
//			}
//		}

	template<typename T>
	std::list<T> FileGenerator<T>::read_test_file(const std::filesystem::path& path) {
		DataGenerator::SizeType number_of_instances;
		std::list<T> data{};

		std::ifstream input_file = std::ifstream(path, std::ios_base::in | std::ios_base::binary);
		if(!input_file.is_open())
			throw std::runtime_error("Unable to use input text file: " + path.string());
		else
			input_file.read(reinterpret_cast<char*>(&number_of_instances), sizeof(DataGenerator::SizeType));

		for(DataGenerator::SizeType i = 0; i < number_of_instances; ++i) {
			T temporary{};
			input_file.read(reinterpret_cast<char*>(&temporary), sizeof(T));
			data.push_back(temporary);
		}

		input_file.close();

		return data;
	}

	template<typename T>
	std::list<T> FileGenerator<T>::read_test_data(const std::filesystem::path& directoryPath) {
		if (!is_directory(directoryPath)) {
			throw std::filesystem::filesystem_error(
				"The provided path is not a directory.",
				directoryPath,
				std::error_code()
			);
		}

		std::list<T> output{};

		for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
			if (!entry.is_regular_file())
				continue;

			std::list<T> merge = read_test_file(entry.path());
			output.insert(output.end(), merge.begin(), merge.end());
		}

		return output;
	}

	template<typename T>
	std::list<T> read_test_data(const std::list<std::filesystem::path>& files) {
		std::list<T> output{};

		for (const auto& file : files) {
			std::list<T> merge = read_test_file<T>(file);
			output.insert(output.end(), merge.begin(), merge.end());
		}

		return output;
	}

	//	Static methods definitions
	template<typename T>
	std::filesystem::path FileGenerator<T>::getFullPathFromDirectory(std::filesystem::path directoryPath, const std::string& file_name) {
		if (!is_directory(directoryPath)) {
			throw std::filesystem::filesystem_error(
				"The provided path is not a directory.",
				directoryPath,
				std::error_code()
			);
		}
		if (file_name.ends_with(FileGenerator<T>::getFileExtension()))
			return directoryPath /= file_name;

		return directoryPath /= (file_name + FileGenerator<T>::getFileExtension());
	}

	template<typename T>
	void FileGenerator<T>::generate_random_data(std::list<T>& output, T min, T max, DataGenerator::SizeType instances) {
		std::random_device rd;
		std::mt19937 gen(rd());

		if constexpr (std::is_same<T, bool>::value) {
			output.push_back(min);
			output.push_back(max);
		} else if constexpr (std::is_floating_point<T>::value) {
			std::uniform_real_distribution<T> dist(min, max);
			for (DataGenerator::SizeType i = 0; i < instances; ++i)
				output.push_back(dist(gen));
		} else if constexpr (std::is_integral<T>::value) {
			std::uniform_int_distribution<T> dist(min, max);
			for(std::size_t i = 0; i < instances; ++i)
				output.push_back(dist(gen));
		}
	}

	template<typename T>
	void FileGenerator<T>::generate_continues_data(std::list<T>& output, T min, T max, DataGenerator::SizeType instances) {
		if constexpr (std::is_same<T, bool>::value) {
			output.push_back(min);
			output.push_back(max);
		} else if constexpr (std::is_floating_point<T>::value) {
			T step = std::nextafter(min, max);
			for (T value = min; value <= max; value = std::nextafter(value, max + step))
				output.push_back(value);
		} else if constexpr (std::is_integral<T>::value) {
			for (DataGenerator::SizeType i = 0; i < instances; ++i)
				output.push_back(i);
		}
	}

	template<typename T>
	constexpr std::string FileGenerator<T>::getFileExtension() {
		return ".bin";
	}
		
}	//	namespace poker::testing
