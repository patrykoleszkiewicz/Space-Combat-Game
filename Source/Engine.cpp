#include "Engine.hpp"

#include "PilotPlayer.hpp"

Engine::Engine()
:_playerCamera(sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f)), Vector3d(0.0, 0.0, 0.0),
    Vector3d(0.0, 0.0, -1.0), 90.0, 0.1, 1000.0)
{
    _view = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f));
    tickCount = 0;
}

void Engine::setSpaceships(std::vector<Spaceship>& ships)
{
    _spaceships = ships;
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
        renderModel(window, spaceship.getModel(), spaceship.getTransformMatrix());
    }
    return 0;
}

int Engine::drawBullets(sf::RenderWindow &window, double framePercentage)
{
    for(auto& bullet : _bullets)
    {
        renderModel(window, bullet.getModel(), bullet.getTransformMatrix());
    }
    return 0;
}

int Engine::drawHUD(sf::RenderWindow &window, Spaceship* player)
{
    return 0;
}

int Engine::renderModel(sf::RenderWindow &window, Model* model, const Matrix4x4& transform)
{
    const Matrix4x4& projMat = _playerCamera.getProjectionMatrix();
    for(auto& triangle : model->_triangles)
    {
        Triangle triTransormed, triProjected;
        
        triTransormed.point1 = transform.multiplyByVector(triangle.point1);
        triTransormed.point2 = transform.multiplyByVector(triangle.point2);
        triTransormed.point3 = transform.multiplyByVector(triangle.point3);
        
        triProjected.point1 = projMat.multiplyByVector(triTransormed.point1);
        triProjected.point2 = projMat.multiplyByVector(triTransormed.point2);
        triProjected.point3 = projMat.multiplyByVector(triTransormed.point3);
        
        Vector2d screenSize(_playerCamera.getView().getSize());
        
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