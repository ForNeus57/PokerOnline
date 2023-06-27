//
// Created by Dominik on 27.06.2023.
//

#ifndef POKER_ONLINE_COMMON_COMMON_THREAD_H
#define POKER_ONLINE_COMMON_COMMON_THREAD_H

#include <memory>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

namespace poker::common {

	class Thread {
	public:
		static boost::uuids::random_generator GENERATOR;

	protected:
		std::shared_ptr<bool> loop_control;

	private:
		boost::uuids::uuid signature;

	public:
		Thread();
		virtual ~Thread() = default;

	public:
		boost::uuids::uuid getSignature() const;

	};

}


#endif	//	POKER_ONLINE_COMMON_COMMON_THREAD_H
