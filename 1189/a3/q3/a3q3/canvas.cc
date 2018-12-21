#include "canvas.h"
#include <iostream>
#include <string>
using namespace std;
using std::swap;
using std::move;

// do i need to add rectangle here????????
Canvas::Canvas():point{Point(0,0)}, height_name(0), width_name(0), size(0), cap(1), total(nullptr) {}


Canvas::Canvas( const Canvas & other ){   // deep copy you wen ti
         point = other.point;
         height_name = other.height_name; 
         width_name = other.width_name;
         size = other.size;
         cap = other.cap; 
         Rectangle ** new_total = new Rectangle *[other.cap];
         for (int i = 0; i < size; ++i) {
             new_total[i] = new Rectangle(*other.total[i]);
         }
         //delete [] total;
         total = new_total;
}


Canvas::Canvas( Canvas && other ):
      point(other.point), height_name(other.height_name), 
      width_name(other.width_name), size(other.size), 
      cap(other.cap), total(other.total)  {
      other.point = Point(0,0);
      other.height_name = 0;
      other.width_name = 0;
      other.size = 0;
      other.cap = 0;
      other.total = nullptr;
} 


Canvas::~Canvas(){
    for (int i = 0; i < size; ++i) delete total[i];
    delete [] total;
}


Canvas & Canvas::operator=(const Canvas & other ){
    if (this == &other) return *this;
    point = other.point;
    height_name = other.height_name;
    width_name = other.width_name;
    size = other.size;
    cap = other.cap;
    Rectangle ** new_total = new Rectangle *[other.cap];
         for (int i = 0; i < size; ++i) {
             new_total[i] = new Rectangle(*other.total[i]);
         }
    // delete total;
    total = new_total;
    return *this;
}


Canvas & Canvas::operator=( Canvas && other ){   // ????????
   swap(point, other.point);
   swap(height_name, other.height_name);
   swap(width_name, other.width_name);
   swap(size, other.size);
   swap(cap, other.cap);
   swap(total, other.total);
   return *this;
}

void Canvas::add( const Rectangle & rectangle ){ // add rectangle after all others
     if (size >= cap) {                                     // resize, when size > cap
        Rectangle **new_total = new Rectangle *[2*cap];     
        for (int i = 0; i < size; ++i) {
           new_total[i] = total[i];
        }
        delete [] total;
        total = new_total;
        cap *= 2;
     }
     if (size == 0) {                                         // size is zero , create a dynamic array
        total = new Rectangle *[cap];
        total[size] = new Rectangle{rectangle};
     } else {
        total[size] = new Rectangle{rectangle};
     }

     if (rectangle.point().x() + rectangle.width() > width_name) {     //update the width
        width_name = rectangle.point().x() + rectangle.width();
     }
     if (rectangle.point().y() + rectangle.height() > height_name) {    //update the height
        height_name = rectangle.point().y() + rectangle.height();
     }
     size +=1;
}

int Canvas::numRectangles() const{ // returns number of rectangles in the canvas
    return size;
}

int Canvas::width() const{ // returns the width of the canvas
    return width_name;
}

int Canvas::height() const{ // returns the height of the canvas
    return height_name;
}

Rectangle Canvas::get( int rectangleId ) const{
    return *(total[rectangleId]);
}


void Canvas::translate( int rectangleId, int x, int y ){                
    total[rectangleId]->translate(x,y);
}

void Canvas::scale( int rectangleId, float heightFactor, float widthFactor ){
    total[rectangleId]->scale(heightFactor,widthFactor);
    if (total[rectangleId]->height() + total[rectangleId]->point().y() > height_name) {  // update height
          height_name = total[rectangleId]->height() + total[rectangleId]->point().y();
    }
    if (total[rectangleId]->width() + total[rectangleId]->point().x()  > width_name) {    // update width
          width_name = total[rectangleId]->width() + total[rectangleId]->point().x();
    }
}

void Canvas::change( int rectangleId, Rectangle::Colour newColour ){
    total[rectangleId]->change(newColour);
}


void Canvas::remove( int rectangleId ){                     
    delete total[rectangleId];
    for (int i = rectangleId; i < size-1; ++i) {
       total[i] = total[i+1]; 
    }
    size -= 1;
    
    int max_height = 0;
    int max_width = 0;
    for (int k = 0; k < size; ++k) {                                   // update height and width
       if (total[k]->height() + total[k]->point().y() > max_height) {
          max_height = total[k]->height() + total[k]->point().y();
       } 
       if (total[k]->width() + total[k]->point().x()  > max_width) {
          max_width = total[k]->width() + total[k]->point().x();
       }
    }
   height_name = max_height;
   width_name = max_width;
}



std::ostream & operator<<( std::ostream & out, const Canvas & canvas ){
     out << "Dimensions: " << canvas.height() << "x" << canvas.width() << endl;
     out << "Number of rectangles: " << canvas.numRectangles() << endl;
     for (int i = 0; i < canvas.numRectangles(); ++i) {
        out << '\t' << canvas.get(i) << endl;
     }
     return out;
}






















