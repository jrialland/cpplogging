# cpplogging

A lean logging library for c++

[![Build Status](https://travis-ci.org/jrialland/cpplogging.svg?branch=master)](https://travis-ci.org/jrialland/cpplogging)

## Features
Logger types:
* console logging, with terminal colors if using a tty (StreamAppender)
* rolling file (creating one file per day up to 7 days) (FileAppender)
* udp using log4j:event xml format, so logs can be viewed using tools like [Logbert](https://github.com/couchcoding/Logbert) (UdpAppender)

## Dependencies:
Project dependencies
	* depends on boost::regex

```c++
#include "Logging.hpp"

int main(int argc, char **argv) {
	logging::basicConfig(argc, argv, LogLevel::Trace).withUdp();
	LOG_TRACE("trace");
	LOG_DEBUG("debug");
	LOG_INFO("info");
	LOG_WARN("warning");
	LOG_ERROR("error");
	LOG_FATAL("fatal");
	LOG_INFO("multiple", "variables", '(', 3, " or more)");
	return 0;
}
```

[![Logbert screenshot](https://i.imgur.com/RWjPk4g.gif)]