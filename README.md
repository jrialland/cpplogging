# cpplogging

A lean logging library for c++

[![Build Status](https://travis-ci.org/jrialland/cpplogging.svg?branch=master)](https://travis-ci.org/jrialland/cpplogging)

## Features
	
	* console logging, with terminal colors if using a tty
	* rolling file (creating one file per day up to 7 days)
	* udp using log4j:event xml format, so logs can be viewed using tools like [Logbert](https://github.com/couchcoding/Logbert)

## Dependencies:
	* depends on boost::regex

