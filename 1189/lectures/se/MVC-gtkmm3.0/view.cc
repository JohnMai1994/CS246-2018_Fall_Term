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


#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <iostream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_{m}, controller_{c}, panels{},
    butBox{ Gtk::ORIENTATION_VERTICAL, 10 }, // box orientation and space between children in pixels
    next_button{ "next" }, reset_button{ "reset" }, card{ deck.null() }
{
    // Sets some properties of the window.
    set_title( "CS247 MVC example" );
    set_border_width( 10 );    
	set_default_size( 250, 100 ); // width, height in pixels
	
    // Add panels to the window
    add( panels );
	panels.set_spacing( 10 ); // amount of space between children of panels

    // Add button box and card image to the panels box
    panels.pack_start( butBox );
    panels.pack_start( card );
    card.set( deck.null() );	

    // Add buttons to the box (a container). Buttons initially invisible
    butBox.pack_start( next_button, Gtk::PACK_EXPAND_WIDGET, 10 );
    butBox.pack_start( reset_button, Gtk::PACK_EXPAND_WIDGET, 10 );

    // Associate button "clicked" events with local onButtonClicked() method defined below.
    next_button.signal_clicked().connect( sigc::mem_fun( *this, &View::nextButtonClicked ) );
    reset_button.signal_clicked().connect( sigc::mem_fun( *this, &View::resetButtonClicked ) );
	
    // The final step is to display the buttons (they display themselves).
    show_all();

    // Register view as observer of model.
    model_->subscribe(this);
} // View::View

View::~View() {}


void View::update() {
    Suits suit = model_->suit();
    Faces face = model_->face();
    if ( suit == NOSUIT ) 
		card.set( deck.null() );
    else
		card.set( deck.image(face, suit) );
}

void View::nextButtonClicked() {
    controller_->nextButtonClicked();
} // View::nextButtonClicked

void View::resetButtonClicked() {
    controller_->resetButtonClicked();
} // View::resetButtonClicked
