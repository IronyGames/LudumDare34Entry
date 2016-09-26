#include "SpriteFont.h"
#include "Image.h"
#include "Offset2D.h"
#include "Animation2D.h"
#include "cinder/gl/gl.h"

SpriteFont::SpriteFont(Image* _image, Offset2D* _offset, int _tile_width, int _tile_height, int _num_tiles, bool _loops, std::map<char, int> _characterMap)
:Animation2D(_image, _offset, _tile_width, _tile_height, _num_tiles, _loops)
, characterMap(_characterMap)
{

}

void SpriteFont::draw(String text, Offset2D *offset, bool fromCenter /*= false*/)
{
	int opx = offset->getTranslation().x;
	int opy = offset->getTranslation().y;
	int tx = tile_width*offset->getScale().x;
	int ty = tile_height*offset->getScale().y;

	cinder::Rectf pos(
		opx, opy,
		opx+tx, opy+ty
		);


	cinder::gl::pushMatrices();
	//TODO if fromCenter
	cinder::gl::rotate(offset->getRotation());

	for (int i = 0; i < text.size(); i++){
		int index = getCharIndex(text.at(i));

		if (index == -2){
			pos.x1 = opx-tx;
			pos.x2 = opx;
			pos.y1 += ty;
			pos.y2 += ty;
		}else if (index != -1){
			int rows = (index / image_columns);
			int cols = (index % image_columns);
			cinder::Area sub(	tile_width*cols,		tile_height*rows,
								tile_width*(cols + 1),	tile_height*(rows + 1));
			cinder::gl::draw(image->getGlImageRef(), sub, pos);
		}
		
		pos.x1 += tx;
		pos.x2 += tx;
	}

	cinder::gl::popMatrices();
}

int SpriteFont::getCharIndex(char c)
{
	if (c == '/'){
		return -2; //return
	}
	auto it = characterMap.find(c);

	if (it == characterMap.end()){
		return -1; //space
	}

	return it->second;
}
