#pragma once
#pragma once
#include <string>
#include <fstream>  
#include <iostream>  


#include "CollisionComponent.h"
#include "Scene.h"
#include "SpriteComponent.h"
#include "WallComponent.h"


namespace dae
{
	class LevelParser
	{
	public:
		
		static bool ParseOBJ(const std::string& filename, Scene& scene, bool )
		{
			std::ifstream file(filename);
			if (!file)
				return false;



			std::string sCommand;
			// start a while iteration ending when the end of file is reached (ios::eof)
			while (!file.eof())
			{
				//read the first word of the string, use the >> operator (istream::operator>>) 
				file >> sCommand;
				//use conditional statements to process the different commands	
				if (sCommand == "#")
				{

				}
				else if (sCommand == "w")
				{
					int x, y, w,h;
					file >> x >> y >> w >> h;
					SDL_Rect wallInfo{ x,y,w,h };

					CreateWall(scene,wallInfo );

				}


			}

			return  true;
		}

	private:
		static void CreateWall( Scene& scene, SDL_Rect wallInfo)
		{
			auto wall{ std::make_shared<dae::GameObject>() };
			wall->AddComponent(new WallComponent{ wall.get(), wallInfo });
			wall->AddComponent(new CollisionComponent{ wall.get(), wallInfo });
			scene.Add(wall);
		}





	};


}

