#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>

using namespace sf;
using namespace std;

int i = 0;
int main()
{
    float p = 3.14;

    int j = 0, k = 0, f = 0, c = 0, n = 0;
    int count = 0;

    float mur = 0;
    int mur1 = 0;
    int mur2 = 0;
    float fir = 0;
    int fir1 = 0;
    int fir2 = 0;
    float wow = 0;
    int wow1 = 0;
    int wow2 = 0;
    bool flag = true;

    string enter;
    string circle = "circle";
    string rad = "      ";
    string moveX = "      ";
    string moveY = "      ";
    string rad2 = "      ";
    string moveX2 = "      ";
    string moveY2 = "      ";
    string rad3 = "      ";
    string moveX3 = "      ";
    string moveY3 = "      ";
    getline(cin, enter);
    n = enter.find(circle);
    i = n + 7;

    while (1) {
        if (enter[i] != ')' && enter[i] != ',') {
            while (enter[i] != ' ') {
                moveX[k] = enter[i];
                k++;
                i++;
            }
            i++;
            while (enter[i] != ',') {
                moveY[f] = enter[i];
                f++;
                i++;
            }
            i++;
            while (enter[i] != ')') {
                rad[c] = enter[i];
                c++;
                i++;
            }
        }
        count++;
        break;
    }

    if (enter[i + 1] == '\0') {
        flag = false;
    } else {
        count++;
        i += 9;
        k = f = c = 0;
    }

    while (flag) {
        if (enter[i] != ')') {
            while (enter[i] != ' ') {
                moveX2[k] = enter[i];
                k++;
                i++;
            }
            i++;
            while (enter[i] != ',') {
                moveY2[f] = enter[i];
                f++;
                i++;
            }
            i++;
            while (enter[i] != ')') {
                rad2[c] = enter[i];
                c++;
                i++;
            }
        }
        break;
    }

    if (enter[i + 1] == '\0') {
        flag = false;
    } else {
        count++;
        i += 9;
        k = f = c = 0;
    }

    while (flag) {
        if (enter[i] != ')') {
            while (enter[i] != ' ') {
                moveX3[k] = enter[i];
                k++;
                i++;
            }
            i++;
            while (enter[i] != ',') {
                moveY3[f] = enter[i];
                f++;
                i++;
            }
            i++;
            while (enter[i] != ')') {
                rad3[c] = enter[i];
                c++;
                i++;
            }
        }
        break;
    }

    mur = atof(rad.c_str());
    mur1 = atoi(moveX.c_str());
    mur2 = atoi(moveY.c_str());
    fir = atof(rad2.c_str());
    fir1 = atoi(moveX2.c_str());
    fir2 = atoi(moveY2.c_str());
    wow = atof(rad3.c_str());
    wow1 = atoi(moveX3.c_str());
    wow2 = atoi(moveY3.c_str());

    if (count == 1) {
        cout << p * mur * mur << endl;
        cout << 2 * p * mur << endl;
    } else if (count == 2) {
        cout << p * mur * mur << endl;
        cout << 2 * p * mur << endl;
        cout << p * fir * fir << endl;
        cout << 2 * p * fir << endl;
    } else if (count == 3) {
        cout << p * mur * mur << endl;
        cout << 2 * p * mur << endl;
        cout << p * fir * fir << endl;
        cout << 2 * p * fir << endl;
        cout << p * wow * wow << endl;
        cout << 2 * p * wow << endl;
    }

    cout << count << endl;

    RenderWindow window(VideoMode(800, 800), "SFMLworks");

    VertexArray line(Lines, 4);
    line[0].position = Vector2f(400, 0);
    line[2].position = Vector2f(0, 400);
    line[1].position = Vector2f(400, 800);
    line[3].position = Vector2f(800, 400);

    CircleShape circ(mur);
    circ.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circ.move(-mur, -mur);
    circ.move(mur1, -mur2);
    circ.setFillColor(Color(3, 213, 255, 150));

    CircleShape circ2(fir);
    circ2.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circ2.move(-fir, -fir);
    circ2.move(fir1, -fir2);
    circ2.setFillColor(Color(200, 20, 22, 140));

    CircleShape circ3(wow);
    circ3.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    circ3.move(-wow, -wow);
    circ3.move(wow1, -wow2);
    circ3.setFillColor(Color(200, 20, 221, 180));

    if (circ.getGlobalBounds().intersects(circ2.getGlobalBounds())) {
        cout << "peresechenie 1 and 2 kruga" << endl;
    }

    if (circ.getGlobalBounds().intersects(circ3.getGlobalBounds())) {
        cout << "peresechenie 1 and 3 kruga" << endl;
    }
    if (circ2.getGlobalBounds().intersects(circ3.getGlobalBounds())) {
        cout << "peresechenie 2 and 3 kruga" << endl;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(line);
        window.draw(circ);
        window.draw(circ2);
        window.draw(circ3);
        window.display();
    }
    return 0;
}
