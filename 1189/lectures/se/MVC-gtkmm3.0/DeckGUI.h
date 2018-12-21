/*
 *  Deck.h
 *  
 * Loads a series of pixmaps used for displaying the cards, as well as a card back used as a place marker in the
 * display when we don't have a card yet to display. Use pixel buffers to share images since widgets cannot be
 * shared.
 *
 *  Created by Caroline Kierstead on 25/05/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */
#ifndef __DECK_GUI_H
#define __DECK_GUI_H
#include <gdkmm/pixbuf.h>
#include <vector>
#include "model.h"

class DeckGUI {
  public:
    DeckGUI();
    virtual ~DeckGUI();
    Glib::RefPtr<Gdk::Pixbuf> image( Faces f, Suits s );   // Returns the image for the specified card.
    Glib::RefPtr<Gdk::Pixbuf> null();                      // Returns the image to use for the placeholder.

  private:
    std::vector<Glib::RefPtr<Gdk::Pixbuf>> deck;           // Contains the pixel buffer images.
}; // DeckGUI

#endif
