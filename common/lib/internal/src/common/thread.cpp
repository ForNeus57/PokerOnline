//
// Created by Dominik on 27.06.2023.
//

#include "common/thread.h"

namespace poker::common {

	boost::uuids::random_generator Thread::GENERATOR = boost::uuids::random_generator();

	Thread::Thread(): loop_control(nullptr), signature(GENERATOR()) {}

	boost::uuids::uuid Thread::getSignature() const {
		return this->signature;
	}

}
