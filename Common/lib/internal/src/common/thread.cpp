//
// Created by Dominik on 26.06.2023.
//

#include "common/thread.h"

namespace poker::common {

	Thread::Thread(): signature() {
		boost::uuids::random_generator generator;
		this->signature = generator();
	}

	boost::uuids::uuid Thread::getUuid() {
		return this->signature;
	}

}
