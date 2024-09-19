#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
public:
    sf::CircleShape c;
    float radius = 20.f;
    Enemy() {
        c.setPosition(rand() % 640, 0);
        c.setFillColor(sf::Color::Yellow);
        c.setRadius(radius);
    }
    // 오버로드 사용예 
    Enemy(float x, float y) {
        c.setPosition(x, y);
        c.setFillColor(sf::Color::Green);
        c.setRadius(radius);
    }

    void update(sf::RenderWindow& win) {
        c.move(0.f, 1.f);
        win.draw(c);
    }
private:

};

class ZigZag : public Enemy {

public:
    // 오버라이드의 사용예 
    void update(sf::RenderWindow &win) {
        zigzag *= -1;
        c.move(zigzag, 1.f);
        win.draw(c);
    }
private:
    int zigzag = 20;
};



int main()
{
    Enemy e1;
    Enemy e2(0, 240);
    ZigZag z1;
  
    sf::RenderWindow window(sf::VideoMode(640, 480), "My SFML Window");
  
    sf::CircleShape blue(30.f);
    blue.setFillColor(sf::Color::Blue);

    blue.setPosition(320, 400);

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)

                    blue.move(-5.f, 0.f); // 왼쪽으로 이동
                else if (event.key.code == sf::Keyboard::D)
                    blue.move(5.f, 0.f); // 오른쪽으로 이동
            }
        }
     
        window.clear(sf::Color::Black);
        e1.update(window);
        e2.update(window);
        z1.update(window);
        window.draw(blue);
        window.display();
    }
    return 0;
}