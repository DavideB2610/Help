#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");
    window.setFramerateLimit(144);

    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(600, 350);
    
    rect.setPosition(rectanglePosition);

    rect.setSize(sf::Vector2f(100, 100));

    float xVelocity = 3;
    float yVelocity = 3;

    sf::Event event;

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        }

        //Physics

        if (rectanglePosition.x < 0 || rectanglePosition.x > 1280) xVelocity *= -1;
        if (rectanglePosition.y < 0 || rectanglePosition.y > 720) yVelocity *= -1;

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);



        //Rendering
        window.clear();

        window.draw(rect);

        window.display();


    }

    return 0;
}