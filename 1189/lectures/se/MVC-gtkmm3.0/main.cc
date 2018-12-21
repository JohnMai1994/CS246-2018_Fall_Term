/*
 * MVC example of GTKmm program
 *
 * Displays top card of sorted deck of cards. When "next" button is clicked, 
 * the next card is displayed on top of deck.  When the "reset" button is
 * clicked, the top card of a full sorted deck is displayed
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */


#include <gtkmm/application.h> // Bring in Gtk::Application
#include "model.h"
#include "controller.h"
#include "view.h"

int main( int argc, char * argv[] ) {
    // Initialize gtkmm with the command line arguments, as appropriate.
    auto app = Gtk::Application::create( argc, argv, "MVC example" );
    
    Model      model;		                // Create model
    Controller controller( &model );        // Create controller
    View       view( &controller, &model ); // Create the view -- is passed handle to controller and model.
    
    return app->run( view );                // Show the window and return when it is closed.
} // main
