
#include "LogMessage.hpp"
#include "StackTrace.hpp"

#include <cmath>

namespace logging {
	
	LogMessage::LogMessage(const LogLevel& lvl) : level(lvl), message(""), fnct(""), file(""), line(0) {
		
		struct timespec spec;
		clock_gettime(CLOCK_REALTIME, &spec);
		time_t s  = spec.tv_sec;
		long ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
		if (ms > 999) {
			s++;
			ms = 0;
		}
		tstamp = s * 1000 + ms;
		
		stackTrace = getStackTrace();
		if(stackTrace.size()) {
			stackTrace.erase(stackTrace.begin());
		}
				
	}

}
