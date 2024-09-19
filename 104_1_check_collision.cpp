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
    // 아군 우주선 
    sf::CircleShape blue(30.f);
    blue.setFillColor(sf::Color::Blue);

    // 원의 위치 설정 (창의 중앙)
    circle1.setPosition(300, y1);
    circle2.setPosition(200, y2);
    blue.setPosition(320, 430);

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // 아래의 키보드처리 코드는 event 방식. 속도가 빠르다. 
            /*else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)

                    blue.move(-10.f, 0.f); // 왼쪽으로 이동
                else if (event.key.code == sf::Keyboard::D)
                    blue.move(10.f, 0.f); // 오른쪽으로 이동
            }*/
        }
        // 아래 키보드 처리 코드는 polling 방식. 속도가 빠르다. 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            blue.move(-5.0f, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            blue.move(5.0f, 0);
        }
        y1++;
        if (y1 > 480) {
            y1 = (rand() % 200) * -1;
            x1 = rand() % 640;
        }
        y2++;
        if (y2 > 480) {
            y2 = (rand() % 200) * -1;
            x2 = rand() % 640;
        }

        // ckeck collision 
        sf::Rect<float> c1_rect;
        sf::Rect<float> c2_rect;
        sf::Rect<float> blue_rect;

        c1_rect = circle1.getGlobalBounds();
        c2_rect = circle2.getGlobalBounds();
        blue_rect = blue.getGlobalBounds();

        bool isCollide = false;
        isCollide = c1_rect.intersects(blue_rect);

        if (isCollide == true)
            window.close();

        isCollide = c2_rect.intersects(blue_rect);
        if (isCollide == true)
            window.close();

        circle1.setPosition(x1, y1);
        circle2.setPosition(x2, y2);
        window.clear(sf::Color::Black);
        window.draw(circle1); // 원 그리기
        window.draw(circle2); // 원 그리기
        window.draw(blue);
        window.display();
    }
    return 0;
}