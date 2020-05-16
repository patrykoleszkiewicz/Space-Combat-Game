#include "PilotPlayer.hpp"

#include <SFML/Graphics.hpp>

Steer PilotPlayer::update()
{
    Steer steer = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, false };
    steer.mainThrottle = 1.0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        steer.progradeAxis = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        steer.progradeAxis = -1.0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        steer.strafeAxis = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        steer.strafeAxis = -1.0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        steer.elevationAxis = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        steer.elevationAxis = -1.0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        steer.pitch = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        steer.pitch = -1.0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
    {
        steer.yaw = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        steer.yaw = -1.0;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        steer.roll = 1.0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
    {
        steer.roll = -1.0;
    }
    
    steer.trigger = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    
    return steer;
}

PilotType PilotPlayer::getType() const
{
    return PilotType::Player;
}