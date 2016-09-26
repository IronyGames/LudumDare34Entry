#pragma once
#include "Typedef.h"
/*
*	Methods to log information and errors in an external file.
*	TODO: link debugLogPath into another variable, in a bigger scope.
*/
namespace Logger{
	bool logBasic(const String &input);
	bool logWarning(const String &input);
	bool logError(const String &input);
	bool logInputError(const String &input);
	bool logOutputError(const String &input);
};