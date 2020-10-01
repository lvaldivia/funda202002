#pragma once
#include "GLTexture.h"
#include "TextureCache.h"
#include <string>
class ResourceManager
{
private:
	static TextureCache textureCache;
public:
	static GLTexture getTexture(std::string texturePath);
};

