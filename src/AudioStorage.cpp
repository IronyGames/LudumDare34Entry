#include "AudioStorage.h"
#include "Image.h"
#include "cinder/audio/Source.h"
#include "cinder/app/App.h"

std::map<String, ciVoicePointer> AudioStorage::store = std::map<String, ciVoicePointer>();

ciVoicePointer AudioStorage::get(const String &path)
{
	auto it = store.find(path);

	if (it == store.end()){//doesn't exist, so load it.
		//cinder::audio::Node n = context->createOutputDeviceNode(;
		
		/*    audio::SourceFileRef sourceFile = audio::load( app::loadAsset( "soundfile.wav" ) );
	mVoice = audio::Voice::create( sourceFile );*/

		/*	cinder::DataSourceRef d = cinder::loadFile(path);
	cinder::audio::SourceFileRef s = cinder::audio::load(d);
	cinder::audio::VoiceRef v = cinder::audio::Voice::create(s);*/
		
		cinder::DataSourceRef dsr = (cinder::app::loadAsset(path));
		cinder::audio::SourceFileRef sfr = cinder::audio::load(dsr);
		ciVoicePointer n = cinder::audio::Voice::create(sfr);
		
		
		store[path] = n;
	}

	return store.at(path);
}
