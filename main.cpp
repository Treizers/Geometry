#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    float rad = 0;
    int x = 0, y = 0;

    cin » rad » x » y;

    RenderWindow window(VideoMode(800, 800), "Geometry", Style::Default);
    window.setFramerateLimit(60);

    CircleShape Circle(rad);
    Circle.setPosition(x, y);
    Circle.setFillColor(Color(73, 119, 170));

    while (window.isOpen()) {
        Event WindowClosing;
        while (window.pollEvent(WindowClosing)) {
            if (WindowClosing.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Circle);
        window.display();
    }
}
