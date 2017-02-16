#include "logger.h"

logger* logger::log = NULL;
logger* logger::LOG() {
	if (log == NULL) {
		lock_guard<mutex> guard(mm);
		if (log == NULL) {
			log = new logger;
			return log;
		}
	}
	return log;
}
void logger::DELOG() {
	delete log;
	log = NULL;
}

void logger::INFO(string str) {
	LOG()->WRITE("INFO: " + str);
}
void logger::WARN(string str) {
	LOG()->WRITE("WARNING: " + str);
}

void logger::DEBUG(string str) {
	LOG()->WRITE("DEBUG: " + str);
}

void logger::FATAL(string str) {
	LOG()->WRITE("FATAL: " + str);
}

void logger::WRITE(string str) {
		lock_guard<mutex> guard(m);
		myFile << str;
		myFile << endl;
}
