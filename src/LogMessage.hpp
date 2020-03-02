#ifndef LogMessage_HPP
#define LogMessage_HPP

#include "LogLevel.hpp"

#include <string>
#include <vector>

using namespace std;

namespace logging {

	struct LogMessage {
	  unsigned long tstamp;
	  const LogLevel &level;
	  string message;
	  string fnct;
	  string file;
	  int line;
	  vector<string> stackTrace;
	  LogMessage(const LogLevel &level);
	};
	
}
#endif
