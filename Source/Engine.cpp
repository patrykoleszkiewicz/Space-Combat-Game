#include "Engine.hpp"

#include "PilotPlayer.hpp"

Engine::Engine()
{
	_view = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f));
    tickCount = 0;
}

int Engine::start()
{
	_spaceships.clear();
	_bullets.clear();
    
	return 0;
}

int Engine::tickPhysics()
{
    ++tickCount;
    
	tickBullets();
	
	tickSpaceships();
	
	removeBullets();
	
	return 0;
}

int Engine::tickBullets()
{
    for(auto& bullet : _bullets)
	{
		bullet.tickPhysics();
	}
    return 0;
}

int Engine::tickSpaceships()
{
    for(auto& spaceship : _spaceships)
	{
		spaceship.tickPhysics();
		
		std::vector<Bullet> bullets = spaceship.fireGuns();
		
		for(auto& bullet : bullets)
		{
			_bullets.push_back(bullet);
		}
	}
    return 0;
}

int Engine::removeBullets()
{
    if(_bullets.size() > 0)
	{
		for(unsigned int deleter = 0; deleter < _bullets.size();++deleter)
		{
			if(_bullets.at(deleter).getLifetimeLeft() <= 0)
			{
				_bullets.erase(_bullets.begin() + deleter);
				--deleter;
			}
		}
	}
    return 0;
}

int Engine::drawFrame(sf::RenderWindow &window, double framePercentage)
{
	window.clear();
	
    Spaceship* player = findPlayer();
	
	setupView(window, player);
	
	drawSpaceships(window, framePercentage);
	
	drawBullets(window, framePercentage);
	
    drawHUD(window, player);
    
	window.display();
    
	return 0;
}

Spaceship* Engine::findPlayer()
{
    Spaceship* player = nullptr;
	
	for(auto& spaceship : _spaceships)
	{
		if(spaceship.getPilot()->getType() == PilotType::Player)
		{
			player = &spaceship;
		}
	}
    
    return player;
}

void Engine::setupView(sf::RenderWindow &window, Spaceship* player)
{
    sf::Vector2f windowSize(window.getSize());
	
	_view.setSize(windowSize);
	
	window.setView(_view);
}

int Engine::drawSpaceships(sf::RenderWindow &window, double framePercentage)
{
    for(auto& spaceship : _spaceships)
	{
		
	}
    return 0;
}

int Engine::drawBullets(sf::RenderWindow &window, double framePercentage)
{
    for(auto& bullet : _bullets)
	{
		
	}
    return 0;
}

int Engine::drawHUD(sf::RenderWindow &window, Spaceship* player)
{
    return 0;
}

int Engine::renderModel(sf::RenderWindow &window, Model &model, Camera &camera)
{
    const Matrix4x4& projMat = camera.getProjectionMatrix();
    for(auto& triangle : model._triangles)
    {
        Triangle triProjected, triTranslated;
        triTranslated.point1 = triangle.point1 + Vector3d(0.0,0.0,3.0);
        triTranslated.point2 = triangle.point2 + Vector3d(0.0,0.0,3.0);
        triTranslated.point3 = triangle.point3 + Vector3d(0.0,0.0,3.0);
        
        triProjected.point1 = projMat.multiplyByVector(triTranslated.point1);
        triProjected.point2 = projMat.multiplyByVector(triTranslated.point2);
        triProjected.point3 = projMat.multiplyByVector(triTranslated.point3);
        
        Vector2d screenSize(camera.getView().getSize());
        
        triProjected.point1.x *= 0.5 * screenSize.x;
        triProjected.point1.y *= 0.5 * screenSize.y;
        triProjected.point2.x *= 0.5 * screenSize.x;
        triProjected.point2.y *= 0.5 * screenSize.y;
        triProjected.point3.x *= 0.5 * screenSize.x;
        triProjected.point3.y *= 0.5 * screenSize.y;
        
        sf::Vertex line1[2] = {
            sf::Vertex(triProjected.point1.sfVector2f()),
            sf::Vertex(triProjected.point2.sfVector2f())
        };
        
        sf::Vertex line2[2] = {
            sf::Vertex(triProjected.point2.sfVector2f()),
            sf::Vertex(triProjected.point3.sfVector2f())
        };
        
        sf::Vertex line3[2] = {
            sf::Vertex(triProjected.point3.sfVector2f()),
            sf::Vertex(triProjected.point1.sfVector2f())
        };
        
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
    }
    return 0;
}

int Engine::reset()
{
	return 0;
}

void Engine::setTextures(std::vector<Texture> txt)
{
	_textures = txt;
}