#include <SFML/Graphics.hpp>
#include <iostream>

// 네임스페이스의 만드는 예
namespace uga {
    int dol = 0;
}

int main()
{
    // uga 네임스페이스에 속한 변수 사용법 
    std::cout << uga::dol << std::endl;
    //sf::VideoMode vd(640, 480);
    //sf::RenderWindow window(vd, "Ugauga doldol");
    sf::RenderWindow window(sf::VideoMode(640, 480), "My SFML Window");
    // 빨간 원 생성 (반지름 20) ============
    sf::CircleShape circle1(20.f);
    circle1.setFillColor(sf::Color::Red);

    // 원의 위치 설정 (창의 중앙)
    circle1.setPosition(200, 200);

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

        circle1.setPosition(200, 200);
        window.clear(sf::Color::Black);
        window.draw(circle1); // 원 그리기
        window.display();
    }
    return 0;
}