#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
   
    int y1 = 0;
    int x1 = 100;
    int y2 = 0;
    int x2 = 200;

    sf::RenderWindow window(sf::VideoMode(640, 480), "My SFML Window");
    // 빨간 원 생성 (반지름 20) ============
    sf::CircleShape circle1(20.f);
    circle1.setFillColor(sf::Color::Red);
    sf::CircleShape circle2(20.f);
    circle2.setFillColor(sf::Color::Red);

    // 원의 위치 설정 (창의 중앙)
    circle1.setPosition(300,y1);
    circle2.setPosition(200,y2);
    
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        y1++;
        if (y1 > 480) {
            y1 = (rand() % 200)*-1;
            x1 = rand() % 640;
        }
        y2++;
        if (y2 > 480) {
            y2 = (rand() % 200) * -1;
            x2 = rand() % 640;
        }
        circle1.setPosition(x1, y1);
        circle2.setPosition(x2, y2);
        window.clear(sf::Color::Black);
        window.draw(circle1); // 원 그리기
        window.draw(circle2); // 원 그리기
        window.display();
    }
    return 0;
}