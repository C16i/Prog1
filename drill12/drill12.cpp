#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{150,150}, 600, 400, "My Window" };
    Axis xa(Axis::x, Point(20,300), 300, 12, "x axis");
    win.attach(xa);

    Axis ya(Axis::y, Point(20,300), 150, 8, "y axis");
    ya.set_color(Color:: blue);
    ya.label.set_color(Color:: green);
    win.attach(ya);

    Function sine(cos,20,100,Point(-1000,200),1000,50,50); 
    sine.set_color(Color::yellow);
    win.attach(sine);

    Polygon poly;                       
    poly.add(Point(250,175));
    poly.add(Point(300,75));
    poly.add(Point(390,200));
    poly.add(Point(280,220));
    poly.set_color(Color:: red);
    poly.set_style(Line_style::solid);
    win.attach(poly);

    Rectangle r(Point(250,150), 100, 50);
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point(150,50));
    poly_rect.add(Point(150,50));
    poly_rect.add(Point(300,100));
    poly_rect.add(Point(150,75));
    poly_rect.add(Point(175, 80));
    win.attach(poly_rect);

    r.set_fill_color(Color:: dark_blue);
    poly.set_style(Line_style(Line_style::dash,4)) ;
    poly_rect.set_style(Line_style(Line_style::dash,2)) ;

    Text t(Point(150,300), "You don't know the power of the dark side") ;
    t.set_font(Font::times_bold);
    t.set_font_size(18) ;
    win.attach(t);

    Image as(Point(150,400),"vader.jpg");
    win.attach(as);

    Circle c {Point{100,300},50};
	Ellipse e {Point{150,200}, 75,50};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image starwars {Point{400,100},"starwars.jpg"}; 
	starwars.set_mask(Point{40,40},150,77);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(starwars);

	win.wait_for_button();
}
