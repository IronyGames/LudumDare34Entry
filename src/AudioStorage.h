#pragma once;
#include <map>
#include "Typedef.h"
#include "cinder/audio/Voice.h"

class AudioStorage{
public:
	static ciVoicePointer get(const String &path);
private:
	static std::map<String, ciVoicePointer> store;
};