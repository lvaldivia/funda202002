#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
using namespace std;

TextureCache::TextureCache()
{
}

TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	//std::map<std::string, GLTexture>::iterator textureCacheIterator =
		//textureMap.find(texturePath);
	auto textureCacheIterator = textureMap.find(texturePath);
	cout << "buscando " << texturePath << endl;
	if (textureCacheIterator == textureMap.end()) {
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		//std::pair<std::string, GLTexture> newPair(texturePath, texture);
		//textureMap.insert(newPair);
		textureMap[texturePath] = texture;
		return texture;
	}
	return textureCacheIterator->second;
}
