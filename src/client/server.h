

#ifndef SERVER_H
#define SERVER_H
#include <json/json.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "engine.hpp"
#include "state.hpp"

#include <memory>
#include <unordered_map>
#include <stdexcept>
#include "ai.hpp"
using std::unique_ptr;
using std::string;

namespace server {
	class Server;
	class LocalServer;
	class Observable;
	class ServerObserver;
	class RemoteServer;
	enum ServerEvent : unsigned int;
}



namespace server {
template<class T,typename ... Args>
	std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}
}


#endif /* SERVER_H */

