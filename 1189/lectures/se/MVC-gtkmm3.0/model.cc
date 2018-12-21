/*
 * MVC example of GTKmm program
 *
 * Model class.  Is responsible keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 *  Created by Jo Atlee on 06/07/09.
 *  Updated to GTKmm 3.0 (version 3.10.1) from 2.4 on February 13, 2017.
 *  Copyright 2009, 2017 UW. All rights reserved.
 *
 */

#include "model.h"


Model::Model() : topCard_{ -1 } {}

Suits Model::suit() {
  if (topCard_ == -1) return NOSUIT;
  
  return static_cast<Suits>( topCard_ % numSuits );
}

Faces Model::face() {
  if (topCard_ == -1) return NOFACE;

  return static_cast<Faces>( topCard_ / numSuits );
}

void Model::nextCard() {
  if (topCard_ == numCards-1) return;

  topCard_ += 1;
  notify();
}

void Model::resetCards() {
  topCard_ = -1;
  notify();
}
