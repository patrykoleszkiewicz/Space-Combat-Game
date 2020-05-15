#pragma once

#include "Texture.hpp"
#include "Spaceship.hpp"
#include "Model.hpp"
#include "Camera.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Engine
{
public:
	Engine();
    
	int tickPhysics();
	int drawFrame(sf::RenderWindow &window, double framePercentage);
	
    void setSpaceships(std::vector<Spaceship>& ships);
    
private:

    int tickBullets();
    int tickSpaceships();
    int removeBullets();

    void setupView(sf::RenderWindow &window, Spaceship* player);
    int drawSpaceships(sf::RenderWindow &window, double framePercentage);
    int drawBullets(sf::RenderWindow &window, double framePercentage);
    int drawHUD(sf::RenderWindow &window, Spaceship* player);
    
    int renderModel(sf::RenderWindow &window, Model* model, const Matrix4x4& transform);
    
    Spaceship* findPlayer();
    
    Camera _playerCamera;
    
    long long tickCount;
    
	sf::View _view;
	
	std::vector<Spaceship> _spaceships;
	std::vector<Bullet> _bullets;
};