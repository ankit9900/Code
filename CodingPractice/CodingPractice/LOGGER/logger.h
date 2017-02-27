
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>

using namespace std;

	mutex mm;
	class logger {
		ofstream myFile;
		static logger* log;
	//	static mutex mm;
		mutex m;
		logger() {
			myFile.open("D://log.txt");
		}
		logger(const logger&){}
		logger& operator=(const logger&){}
		~logger() {
			myFile.close();
		}
	public:
		static logger* LOG();
		static void DELOG();

		static void INFO(string str);
		static void WARN(string str);

		static void DEBUG(string str);

		static void FATAL(string str);

	protected:
		void WRITE(string str);

	};

	

#endif