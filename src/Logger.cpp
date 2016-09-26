#include "Logger.h"

bool Logger::logBasic(const String &input){
	std::ofstream myfile;
	myfile.open("./log.txt"); //TODO: un-hardcode the log path.
	if (myfile.fail()){
		std::cout << "Can't even write in the debug log... oh dear.";
		return false;
	}
	myfile << input;
	myfile.close();
	return true;
}

bool Logger::logWarning(const String &input){
	return Logger::logBasic("*WARNING*" + input);
}

bool Logger::logError(const String &input){
	return Logger::logBasic("*ERROR*" + input);
}

bool Logger::logInputError(const String &input){
	return Logger::logError("[INPUT]" + input);
}

bool Logger::logOutputError(const String &input){
	return Logger::logError("[OUTPUT]" + input);
}