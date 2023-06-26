//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H


#include <boost/lockfree/queue.hpp>

#include <common/thread.h>

namespace poker::server::database {

	/**
	 * @brief
	 */
	class Thread: public poker::common::Thread {
	public:
		//	boost::lockfree::queue<>

	public:
		Thread();

	};

}	//	namespace poker::server::database


#endif //POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H_D
