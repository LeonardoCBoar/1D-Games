#include "AssetManager.h"
#include <assert.h>


AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance==nullptr);
    sInstance = this;


};

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{

    auto& texMap = sInstance->m_Textures;

    auto pairFound = texMap.find(filename);


    //The texture was already loaded
    if(pairFound != texMap.end()){
        return pairFound->second;

    }
    //The texture was not loaded
    else
    {
        auto& texture = texMap[filename];
        texture.loadFromFile("Assets/"+filename);
        return texture;
    }



};