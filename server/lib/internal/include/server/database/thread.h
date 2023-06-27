//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H


#include <boost/lockfree/queue.hpp>

#include <common/thread.h>
#include <server/database/controller.h>
#include <server/database/request.h>

namespace poker::server::database {

	/**
	 * @brief   Thread that manages work given to a database
	 */
	class Thread final: public poker::common::Thread {
	private:
		Controller database;
		boost::lockfree::queue<Request> workload();

	public:
		Thread(std::shared_ptr<bool>);

	public:
		void operator() ();

	};

}	//	namespace poker::server::database


#endif	//	POKER_ONLINE_SERVER_SERVER_DATABASE_THREAD_H
