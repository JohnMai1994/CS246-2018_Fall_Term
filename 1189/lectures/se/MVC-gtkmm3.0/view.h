/*
 * MVC example of GTKmm program
 *
 * View class.  Is responsible for buttons (that user clicks) and for displaying
 * the top card of the deck.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */


#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <gtkmm.h>
#include "DeckGUI.h"
#include "observer.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
  public:
    View( Controller*, Model* );
    virtual ~View();
    virtual void update();	// Observer Pattern: concrete update() method

  private:
    // Observer Pattern: to access Model accessors without having to downcast subject
    Model *model_;
	
    // Strategy Pattern member (plus signal handlers)
    Controller *controller_;

    // Card Images
    DeckGUI deck;

    // Member widgets:
    Gtk::Box panels;         // Main window divided into two horizontal panels.
    Gtk::Box butBox;         // Box for stacking buttons vertically (default layout is horizontal)
    Gtk::Button next_button; // Action buttons: next card
    Gtk::Button reset_button;//                 reset deck
    Gtk::Image card;         // Image to display.

    // Signal handlers:
    void nextButtonClicked();
    void resetButtonClicked();
}; // View

#endif
