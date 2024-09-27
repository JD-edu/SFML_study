#include <SFML/Graphics.hpp>

int main()
{
    // 윈도우 생성
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Text Example");

    // 폰트 파일 로드
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // 폰트 로드 실패 시 에러 처리
        return EXIT_FAILURE;
    }

    // 텍스트 객체 생성
    sf::Text text;
    text.setFont(font);
    text.setString("Hello, SFML!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(100, 100);

    // 게임 루프
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }

    return 0;
}