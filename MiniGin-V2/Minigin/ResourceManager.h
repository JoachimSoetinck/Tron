#pragma once
#include "Singleton.h"
//#include "Sound.h"

namespace dae
{
	class Texture2D;
	class Font;
	class ResourceManager final : public Singleton<ResourceManager>
	{
	public:
		void Init(const std::string& data);
		Texture2D* LoadTexture(const std::string& file);
		std::shared_ptr<Font> LoadFont(const std::string& file, unsigned int size) const;
		//std::shared_ptr<Sound> LoadSound(const std::string& file) const;
	private:
		friend class Singleton<ResourceManager>;
		ResourceManager() = default;
		std::string m_DataPath;

		std::vector< std::shared_ptr<Texture2D>> m_pTextures{};
	};
}
