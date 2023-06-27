//
// Created by Dominik on 27.06.2023.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>
#include <common/thread.h>

namespace poker::common {

	class MockThread : public Thread {
	public:
		MOCK_CONST_METHOD0(getSignature, boost::uuids::uuid());
	};

	class ThreadTest : public ::testing::Test {
	protected:
		void SetUp() override {
			thread = std::make_unique<MockThread>();
		}

		void TearDown() override {
			thread.reset();
		}

		std::unique_ptr<MockThread> thread;
	};

	TEST_F(ThreadTest, GetSignature) {
		const boost::uuids::uuid mockSignature = boost::uuids::random_generator()();
		EXPECT_CALL(*thread, getSignature()).WillOnce(::testing::Return(mockSignature));

		const boost::uuids::uuid& signature = thread->getSignature();
		EXPECT_EQ(signature, mockSignature);
	}

}  // namespace poker::common