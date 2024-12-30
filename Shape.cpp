#include "Shape.h"


Shape::Shape() : color("red"){}
Shape::Shape(std::string c){

	if(c != "red" &&  c != "blue" && c != "green"){
                throw std::invalid_argument("color invalido");
        }
        color = c;
}
std::string Shape::get_color() const{


    return color;


}
void Shape::set_color(std::string c) {
    if(c != "red" && c != "blue" && c != "green"){
        throw std::invalid_argument("color invalido");

    }
    color = c;
}


