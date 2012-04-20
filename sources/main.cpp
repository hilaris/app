#include "Hilaris.h"

#include "processors/RegionProcessors.h"

int main(){
	
	Hilaris hilaris;
	hilaris.setConsoleLogLevel(NONE);
	
	hilaris.io()->led()->on();
	
	sleep(2);

	hilaris.io()->led()->on();
	
	
	return 0;
}
