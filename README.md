# SFML C++ tutorial 
This tutorial provide example code to build SFML based C++ application.
SFML is 2D game library written C++. For detail information for SFML refer here  [SFML's official page](https://www.sfml-dev.org).
It is easiest way to learn C++ through game development. SFML is easy way to learn C++. 

# How to start 
1. Open sfml_circle folder
2. run Visual Studio 2022 with double clicking "sfml_circle.sln" file.
3. You can see "sfml_circle.cpp" on your Visual Studio 2022 editor window.
4. Build it and run it.
```
﻿#include <SFML/Graphics.hpp>

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
```

If you want chamge code, select one of following code files. And copy text of the file, and paste text to "sfml_circle.sln".
An build it and run it. 

# To make SFML Visual Stduio 2022 project 
### Setting Up SFML for a Visual Studio Project

#### 1. **Download SFML Library**
   - Go to [SFML's official download page](https://www.sfml-dev.org/download.php).
   - Download the **64-bit (x64)** version of SFML for **Visual C++ 17 2022 (64-bit)** if possible.
   - Extract the downloaded files to the following location:
     ```
     C:\SFML-2.6.1
     ```

#### 2. **Create a New Console Project**
   - Create a new console project in Visual Studio.
   - Set the project configuration to **Debug mode** and **x64** platform.
   - Configure the project settings as follows:
     1. **Include Directories:**
        - Go to `Project -> Properties -> C/C++ -> General -> Additional Include Directories`.
        - Add the following path:
          ```
          C:\SFML-2.6.1\include
          ```
     2. **Library Directories:**
        - Go to `Project -> Properties -> Linker -> General -> Additional Library Directories`.
        - Add the following path:
          ```
          C:\SFML-2.6.1\lib
          ```
     3. **Linker Input:**
        - Go to `Project -> Properties -> Linker -> Input -> Additional Dependencies`.
        - Add the following dependencies:
          ```
          sfml-graphics-d.lib; sfml-window-d.lib; sfml-system-d.lib; sfml-audio-d.lib;
          ```
     4. **Copy DLLs:**
        - Copy all DLL files from the following directory:
          ```
          C:\SFML-2.6.1\bin
          ```
        - Paste them into your project's `x64/Debug` folder.

#### 3. **Test Your Setup**
   - Replace the contents of your project's main source file with the following code:
     ```cpp
     #include <iostream>
     #include "SFML/Graphics.hpp"
     #include "SFML/Window.hpp"
     #include "SFML/System.hpp"
     using namespace sf;

     int main() {
         RenderWindow window(VideoMode(640, 480), "This is a test");
         while (window.isOpen()) {
             Event event;
             while (window.pollEvent(event)) {
                 if (event.type == Event::Closed) {
                     window.close();
                 }
                 if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                     window.close();
                 }
             }
         }
     }
     ```
   - Build and run the project.

#### 4. **Validation**
   - If a blank window opens with the title "This is a test," the project build is successful, and SFML is set up correctly.
