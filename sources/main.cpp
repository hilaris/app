#include "Hilaris.h"
//#include "processors/EdgeProcessor.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(INFO);	

	Debug::log("foobar %d\n", 10);
	Debug::log(Debug::DEBUG, "meep - %s\n", "foo");
	
	return 0;
}
