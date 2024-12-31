#include "Circle.h"
#define pi 3.141592

Circle::Circle(): center(Point2D()) , Shape(), radius(1) {}
Circle::Circle(std::string color,Point2D center,double radius): Shape(color) , center(center) , radius(radius) {}
Point2D Circle::get_center() const{


    return center;

}
void Circle::set_center(Point2D p) {


    center=p;


}
double Circle::get_radius() const{

 
    return radius;


}
void Circle::set_radius(double r){


    radius= r;


}
std::ostream& operator<<(std::ostream &out, const Circle &c){

    out<<"Shape:Circle=  "<<"color: "<<c.get_color()<<"  center: "<<c.get_center()<<"  radius: "<<c.get_radius()<<std::endl;
    return out;


}
double Circle::area() const{
    
   return pi*pow(get_radius(),2);
}
double Circle::perimeter() const{

    return 2*pi*get_radius();


}
void Circle::translate(double incX,double incY){

     center.x+=incX;
     center.y+=incY;

}
void Circle::print(){


std::cout<<(*this)<<std::endl;   



}
