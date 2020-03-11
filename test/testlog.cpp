#include "Logging.hpp"
using namespace logging;
#include <iostream>
using namespace std;

class Printable {
public:
	friend ostream& operator<<(ostream& os, const Printable& p);
};

ostream& operator<<(ostream& os, const Printable& p) {
	os << "Printable@" << (&p);
	return os;
}


int main(int argc, char **argv) {
	logging::basicConfig(argc, argv, LogLevel::Trace).withUdp();
	
	LOG_TRACE("trace");
	LOG_DEBUG("debug");
	LOG_INFO("info");
	LOG_WARN("warning");
	LOG_ERROR("error");
	LOG_FATAL("fatal");
	
	LOG_INFO("multiple", "variables", '(', 3, " or more)");
	
	void *ptr = (void*)0xdeadbeef;
	LOG_INFO("works with pointers :", ptr);
	
	
	Printable printable;
	
	LOG_INFO("works with printable objs : ", printable); 
	
	LOG_DEBUG("Multiple\nlines\nare displayed\ndifferently");

	return 0;
}
