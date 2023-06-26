//
// Created by Dominik on 26.06.2023.
//

#ifndef POKER_ONLINE_COMMON_COMMON_THREAD_H
#define POKER_ONLINE_COMMON_COMMON_THREAD_H


#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace poker::common {

	class Thread {
	private:
		boost::uuids::uuid signature;

	public:
		Thread();
		virtual ~Thread() = default;

	public:
		boost::uuids::uuid getUuid();

	};

}	//	namespace poker::common


#endif	//	POKER_ONLINE_COMMON_COMMON_THREAD_H
