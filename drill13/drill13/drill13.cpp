 #include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;
double RND()
{
	std::random_device rd;	
	std::mt19937 eng(rd());	
	std::uniform_int_distribution<> range(0, 7);	

	return range(eng) * 100;	
}
int main(){
	try {
			Point t1(300, 50);
			Simple_window win(t1, 1000, 800, "My window");
			
			Lines grid;
			int x_size = 800;
			int y_size = 800;
			for (int i=100; i<=x_size; i+=100) {
					grid.add(Point(i,0), Point(i, y_size));
					grid.add(Point(0,i), Point(x_size, i));
			}
			
			
			
			Vector_ref <Rectangle>v;
			for (int i=0; i<8; i++){
				v.push_back(new Rectangle (Point(i*100, i*100), 100, 100));
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
			}
			
			
			Image i1{ Point{500, 100}, "swars.jpg" }; win.attach(i1);
			Image i2{ Point{000, 200}, "swars.jpg" }; win.attach(i2);
			Image i3{ Point{200, 600}, "swars.jpg" }; win.attach(i3);
			
			
			win.attach(grid);
			while (1)
			{
				int rngX = RND();
				int rngY = RND();
				Image i4{ Point{rngX, rngY}, "starw.jpg" }; win.attach(i4);
				win.wait_for_button();
			}
	
	
	
	} catch (exception& e) {
			cerr << "exception: " << e.what() <<endl;
			return 1;
	} catch (...) {
			cerr<< "exception\n";
			return 2;
	}
	}
