#include <ctime>
#include <iostream>
#include "window.h"

class Turtle {
protected:
    int x;
    int y;
    Xwindow *w;

private:
    void drawHead() {
        w->fillCircle(x, y, 15, 3);
    }

    void drawFeet() {
        w->fillCircle(x + 17, y + 14, 6, 3);
        w->fillCircle(x + 37, y + 14, 6, 3);
    }

    virtual void drawShell() = 0;

public:
    Turtle(int x, int y, Xwindow *w) : x{x}, y{y}, w{w} {}

    void drawTurtle() {
        drawHead();
        drawFeet();
        drawShell();
    }
};

class RedTurtle : public Turtle {
    void drawShell() override {
        w->fillArc(x + 10, y - 5, 40, 40, 180, -180, 2);
    }

public:
    RedTurtle(int x, int y, Xwindow *w) : Turtle{x, y, w} {}
};

class GreenTurtle : public Turtle {
    void drawShell() override {
        w->fillArc(x + 10, y - 5, 40, 40, 180, -180, 10);
    }

public:
    GreenTurtle(int x, int y, Xwindow *w) : Turtle{x, y, w} {}
};

class NinjaTurtle : public GreenTurtle {
    void drawShell() override {
        w->fillArc(x + 10, y - 5, 40, 40, 180, -180, 10);
        drawSash();
    }

    virtual void drawSash() = 0;

public:
    NinjaTurtle(int x, int y, Xwindow *w) : GreenTurtle{x, y, w} {}
};

class Leo : public NinjaTurtle {
    void drawSash() override {
        w->fillRectangle(x + 27, y - 5, 5, 20, 5);
    }

public:
    Leo(int x, int y, Xwindow *w) : NinjaTurtle{x, y, w} {}
};

class Don : public NinjaTurtle {
    void drawSash() override {
        w->fillRectangle(x + 27, y - 5, 5, 20, 7);
    }

public:
    Don(int x, int y, Xwindow *w) : NinjaTurtle{x, y, w} {}
};

class Raph : public NinjaTurtle {
    void drawSash() override {
        w->fillRectangle(x + 27, y - 5, 5, 20, 2);
    }

public:
    Raph(int x, int y, Xwindow *w) : NinjaTurtle{x, y, w} {}
};

class Mike : public NinjaTurtle {
    void drawSash() override {
        w->fillRectangle(x + 27, y - 5, 5, 20, 8);
    }

public:
    Mike(int x, int y, Xwindow *w) : NinjaTurtle{x, y, w} {}
};

int main() {
    Xwindow win;
    RedTurtle rt{100, 50, &win};
    GreenTurtle gt{100, 100, &win};
    Leo leo{200, 200, &win};
    Don don{250, 200, &win};
    Raph raph{300, 200, &win};
    Mike mike{350, 200, &win};

    rt.drawTurtle();
    gt.drawTurtle();
    leo.drawTurtle();
    don.drawTurtle();
    raph.drawTurtle();
    mike.drawTurtle();

    char c;
    std::cin >> std::noskipws;
    std::cin >> c;
}
