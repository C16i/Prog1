#include "string"
#include "iostream"
#include "vector"
using namespace std;
template<typename T> struct S{
	S(T vv=0) : val{vv}{};
	T& get();
	const T& get() const;
	void set(T new_t){val=new_t;} 
	void operator =(const T&);
	
	private:
		T val;
	
};

template<typename T> 
T& S<T>::get(){
		return val;
}

template<typename T> 
const T& S<T>::get() const {
		return val;
}

template<typename T>
void S<T>::operator=(const T& s){
		val=s;
}
template<typename T> void read_val(T& v){
		cin >> v;
}

template<typename T> ostream & operator<<(ostream & os, vector<T> & v) {

		os<<"{";
		for(int i=0; i=v.size(); ++i){
				os<<v[i]<<(i<v.size()-1 ? "," : " ");
		}
		os<<"}";
		return os;
}

template<typename T> 
istream & operator>>(istream & is, vector<T> & v) {
	char ch=0;
	is>>ch;
	if(ch!='{'){
		is.unget();
		return is;
	}
	for(T val; is>> val;){
		v.push_back(val);
		is>>ch;
		if(ch != ',') break;
	}
	return is;
}


int main(){

	S<int> s;  
	S<int> si{55};
	S<char> sc{'E'};
	S<double> sd{9.8};
	S<string> ss{"hehe"};
	S<vector<int>> svi {vector<int>{1,4,4,4,8,9}};

	cout	<<"S<int>" <<s.get() <<endl;
	cout	<<"S<int>" <<si.get() <<endl;
	cout	<<"S<char>" <<sc.get() <<endl;
	cout	<<"S<double>" <<sd.get() <<endl;
	cout<<"S<string>" <<ss.get() <<endl;
	
	//cout<<"S<vector<int>>" <<svi.val <<endl;
	
	for(auto &a : svi.get()){
			cout<<a<<' ';
	}
	cout << endl;
	
	sc.set('k');
	cout<<"S<char>"<<sc.get()<<endl;
	
	si=66;
	cout<< "S<int> : " << si.get() <<endl;

	int jj;
	read_val(jj);
	S<int> si2{jj};
	cout<<"S<int>"<<si2.get()<<endl;
	
	
	string st;
	read_val(st);
	S<string> si3{st};
	cout<<"S<string>"<<si3.get()<<endl;
	
	vector<int> vect;
	read_val(vect);
	S<vector<int>> svect {vect};
	
cout<< "S<vector<int"<< svect.get()<<endl;
	
	
}
