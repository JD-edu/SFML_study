#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy();
    void update(sf::RenderWindow& win);
    void changeSize(int r);
    sf::CircleShape c;
private:

};

void Enemy::changeSize(int r) {
    c.setRadius(r);
}

Enemy::Enemy() {
    c.setFillColor(sf::Color::Yellow);
    c.setPosition(rand() % 640, 0);
    c.setRadius(40);
}

void Enemy::update(sf::RenderWindow& win) {
    c.move(0, 5);
    if (c.getPosition().y > 480) {
        c.setPosition(rand() % 640, 0);
    }
    win.draw(c);
}

// zigzag ENemy 클래스의 상속받는 클래스 
class Zigzag : public Enemy {
public:
    void update(sf::RenderWindow& win);
    int i = 1;
};

void Zigzag::update(sf::RenderWindow& win) {
    c.move(i*( - 1) * 20, 5);
    if (c.getPosition().y > 480) {
        c.setPosition(rand() % 640, 0);
    }
    win.draw(c);
}

int main()
{
    Enemy e1, e2, e3, e4;
    Zigzag z1;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::Texture texture;
    texture.loadFromFile("./ddong.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(100, 100);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        e1.update(window);
        e2.update(window);
        e3.update(window);
        e4.update(window);
        e1.changeSize(rand() % 100);
        z1.update(window);
        window.display();
    }

    return 0;
}