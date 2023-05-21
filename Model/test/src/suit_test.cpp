/**
 * @file 	suit_test.cpp
 * @author 	Dominik Breksa
 * @date 	17.05.2023
 * @brief	Test source file relating to Suit class.
 * @see		suit.h file.
 * @see		suit.cpp file.
 * @version 0.1
**/

#include <Model/suit.h>

#include <cstdint>

#include <gtest/gtest.h>


namespace poker {
	
	class SuitTest : public ::testing::Test {
		protected:
			SuitTest() : suit(nullptr), TEST_ENUM_VALUES({Suit::Value::Heart, Suit::Value::Diamond, Suit::Value::Club, Suit::Value::Pick}) {}
			
			~SuitTest() {}
			
			void SetUp() override {
			
			}
			
			void TearDown() override {
			
			}
		
		protected:
			std::unique_ptr<Suit> suit;
			std::vector<Suit::Value> TEST_ENUM_VALUES;
	};
	
	TEST_F(SuitTest, StaticAtributesTest) {
		EXPECT_EQ(4, Suit::VALUE_RANGE);
		EXPECT_EQ(1, Suit::SHIFT_VALUE);
		EXPECT_EQ(1, Suit::SHIFT_VALUE_INDEX);
	}
	
	TEST_F(SuitTest, StaticMethodsTest) {
		for(uint8_t iterator_value = 0; iterator_value < INT8_MAX; ++iterator_value) {
			if(iterator_value == 0b1 || iterator_value == 0b10 || iterator_value == 0b100 || iterator_value == 0b1000) {
				EXPECT_TRUE(Suit::isValid(iterator_value));
			} else {
				EXPECT_FALSE(Suit::isValid(iterator_value));
			}
		}
		EXPECT_FALSE(Suit::isValid(INT8_MAX));
	}
	
	TEST_F(SuitTest, DefaultConstructorTest) {
		EXPECT_NO_THROW(suit = std::make_unique<Suit>());
		
		EXPECT_EQ(Suit::Value::Heart, suit->getValue());
		EXPECT_EQ(0b1, suit->getUnderlingValue());
	}
	
	TEST_F(SuitTest, CustomConstructorFormUnderlyingValueTest) {
		for(uint8_t iterator_value = 0; iterator_value < INT8_MAX; ++iterator_value) {
			if(iterator_value == 0b1 || iterator_value == 0b10 || iterator_value == 0b100 || iterator_value == 0b1000) {
				EXPECT_NO_THROW(suit = std::make_unique<Suit>(iterator_value));
				EXPECT_EQ(static_cast<Suit::Value>(iterator_value), suit->getValue());
				EXPECT_EQ(iterator_value, suit->getUnderlingValue());
			} else {
				EXPECT_THROW(suit = std::make_unique<Suit>(iterator_value), std::invalid_argument);
			}
		}
		EXPECT_THROW(suit = std::make_unique<Suit>(INT8_MAX), std::invalid_argument);
	}
	
	TEST_F(SuitTest, CustomConstructorFormValueTest) {
		for(const auto& value : TEST_ENUM_VALUES) {
			EXPECT_NO_THROW(suit = std::make_unique<Suit>(value));
			EXPECT_EQ(suit->getValue(), value);
			EXPECT_EQ(suit->getUnderlingValue(), static_cast<Suit::ValueUnderlingType>(value));
		}
	}
	
	TEST_F(SuitTest, CustomCopyConstructorTest) {
		for(const auto& outer : TEST_ENUM_VALUES) {
			Suit first(outer);
			Suit second(first);
			
			EXPECT_NE(&first, &second);
			EXPECT_EQ(first.getValue(), second.getValue());
			EXPECT_EQ(first.getUnderlingValue(), second.getUnderlingValue());
		}
	}
	
	TEST_F(SuitTest, ComparasonOperatorsTest) {
		for(std::size_t i = 0; i < TEST_ENUM_VALUES.size(); ++i) {
			Suit first(TEST_ENUM_VALUES[i]);
			for(std::size_t j = 0; j < TEST_ENUM_VALUES.size(); ++j) {
				Suit second(TEST_ENUM_VALUES[j]);
				if(i == j) EXPECT_TRUE(first == second);
				if(i != j) EXPECT_TRUE(first != second);
				if(i < j) EXPECT_TRUE(first < second);
				if(i <= j) EXPECT_TRUE(first <= second);
				if(i > j) EXPECT_TRUE(first > second);
				if(i >= j) EXPECT_TRUE(first >= second);
				EXPECT_EQ(i <=> j, first <=> second);
			}
		}
	}
	
	TEST_F(SuitTest, ToStringTest) {
		EXPECT_EQ();
		EXPECT_EQ();
		EXPECT_EQ();
		EXPECT_EQ();
	}
	
	TEST_F(SuitTest, InputOutputOperatorsTest) {
	
	}
	
	
}	//	namespace poker