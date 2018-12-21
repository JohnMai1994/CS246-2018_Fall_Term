#include "window.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

Xwindow::Xwindow(int width, int height) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                            BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    Pixmap pix = XCreatePixmap(d, w, width, height,
                               DefaultDepth(d, DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0, (XGCValues *)0);

    XFlush(d);
    XFlush(d);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[11][11] = {"white",  "black", "red",      "green",
                               "blue",   "cyan",  "yellow",   "magenta",
                               "orange", "brown", "darkgreen"};

    cmap = DefaultColormap(d, DefaultScreen(d));
    for (int i = 0; i < 11; ++i) {
        if (!XParseColor(d, cmap, color_vals[i], &xcolour)) {
            cerr << "Bad colour: " << color_vals[i] << endl;
        }
        if (!XAllocColor(d, cmap, &xcolour)) {
            cerr << "Bad colour: " << color_vals[i] << endl;
        }
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[Black]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize);
    hints.height = hints.base_height = hints.min_height = hints.max_height =
            height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    XSynchronize(d, True);

    XSelectInput(d, w, ExposureMask);
    XFlush(d);
    XEvent event;
    XNextEvent(d, &event); // Hang until the window is ready.
    XSelectInput(d, w, 0);
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XDrawString(d, w, gc, x, y, msg.c_str(), msg.length());
    XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawLine(int x1, int y1, int x2, int y2) {
    XDrawLine(d, w, gc, x1, y1, x2, y2);
}

void Xwindow::drawArc(int x1, int y1, int width, int height, int sAngle,
                      int eAngle) {
    XDrawArc(d, w, gc, x1, y1, width, height, sAngle * 64, eAngle * 64);
}

void Xwindow::fillArc(int x, int y, int width, int height, int angle1,
                      int angle2, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillArc(d, w, gc, x, y, width, height, angle1 * 64, angle2 * 64);
    XSetForeground(d, gc, colours[Black]);
}

void Xwindow::fillCircle(int x, int y, int r, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillArc(d, w, gc, x, y, r, r, 0 * 64, 360 * 64);
    XSetForeground(d, gc, colours[Black]);
}
