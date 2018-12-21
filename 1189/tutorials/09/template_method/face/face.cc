#include <iostream>
#include "window.h"

using namespace std;

struct Face {
    int x, y, size, colour;
    Xwindow *w;

    Face(int x, int y, int colour, Xwindow *win, int size = 24)
            : x{x}, y{y}, size{size}, colour{colour}, w{win} {}
    virtual ~Face() {}

private:
    void drawBackground() {
        w->fillRectangle(x, y, size, size, colour);
    }
    void drawEyes() {
        int eyeSize = size / 6;
        w->fillCircle(y + eyeSize, x + eyeSize, eyeSize, 1);
        w->fillCircle(y + eyeSize * 4, x + eyeSize, eyeSize, 1);
    }
    virtual void drawMouth() = 0;

public:
    // The behavior of interface method should not change, The face 
    // would look spooky if any of the components of a face is missing.
    void drawFace() {
        drawBackground();
        drawEyes();
        drawMouth();
    }
};

struct HappyFace : public Face {
    HappyFace(int x, int y, int colour, Xwindow *win, int size = 24)
        : Face{x, y, colour, win, size} {}
private:
    void drawMouth() override {
        int x1 = x + size / 4 * 2;
        int y1 = y + size / 6;
        int width = size / 6 * 4;
        int height = size / 5;
        w->drawArc(y1, x1, width, height, 0, -180);
    }
};

struct SadFace : public Face {
    SadFace(int x, int y, int colour, Xwindow *win, int size = 24)
            : Face{x, y, colour, win, size} {}
private:
    void drawMouth() override {
        int x1 = x + size / 4 * 3;
        int y1 = y + size / 6;
        int width = size / 6 * 4;
        int height = size / 5;
        w->drawArc(y1, x1, width, height, 0, 180);
    }
};

int main() {
    Xwindow win;
    HappyFace face1{150, 150, 3, &win, 40};
    SadFace face2{200, 200, 4, &win, 60};
    SadFace *face3 = new SadFace{50, 50, 6, &win, 50};

    face1.drawFace();
    face2.drawFace();
    face3->drawFace();

    char x;
    std::cin >> noskipws;
    std::cin >> x;
    delete face3;
}
