#include "SpriteFontManager.h"
#include "cinder/app/App.h"
#include "cinder/Xml.h"
#include "Model.h"
#include "ImageStorage.h"
#include "Image.h"
#include "Offset2D.h"
#include "SpriteFont.h"
#include "Logger.h"

SpriteFontManager::SpriteFontManager(Model *m)
{
	cinder::XmlTree *list = new cinder::XmlTree(cinder::app::loadAsset("fonts.xml"));

	auto it = list->begin();
	for (; it != list->end(); it++){
		Image *img = m->images->get(it->getChild("image").getValue());
		String name = it->getChild("name").getValue();

		std::map<char, int> cmap;
		cinder::XmlTree xmlmap = it->getChild("map");
		auto it2 = xmlmap.begin();
		for (; it2 != xmlmap.end(); it2++){
			String att = it2->getTag();
			
			String val = it2->getValue();
			char cc = parseXMLCharacter(att);

			cmap[cc] = stoi(val);
		}

		SpriteFont *sf = new SpriteFont(img, new Offset2D(),
			stoi(it->getChild("width").getValue()), stoi(it->getChild("height").getValue()), 0, false, cmap);
		fonts[name] = sf;
	}
		
}

void SpriteFontManager::draw(Offset2D *offset, String text, String fontName /*= ""*/, bool fromCenter /*= false*/)
{
	if (fonts.size() == 0){
		Logger::logError("No fonts loaded in SpriteFontManager");
		return;
	}

	auto it = fonts.find(fontName);

	if (it == fonts.end()){
		Logger::logError("Font " + fontName + " not found in SpriteFontManager");
		return;
	}

	it->second->draw(text, offset, fromCenter);
}

char SpriteFontManager::parseXMLCharacter(String c)
{
	char out; 

	if (c.size() > 1 && c.at(0) == '&' && c.at(1) == '#'){
		int l = c.size() - 3;
		String aux = c.substr(2, l);
		int a = stoi(aux);
		switch (a){
		case 123:
			out = '{';
			break;
		case 125:
			out = '}';
			break;
		case 40:
			out = '(';
			break;
		case 41:
			out = ')';
			break;
		case 43:
			out = '+';
			break;
		case 91:
			out = '[';
			break;
		case 93:
			out = ']';
			break;
		case 36:
			out = '$';
			break;
		case 62:
			out = '>';
			break;
		default:
			out = ' ';
			break;
		}
	}
	else{
		out = *c.c_str();
	}
	return out;
}

