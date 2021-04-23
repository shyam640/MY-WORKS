#include<bits/stdc++.h>
using namespace std;
class Box{
	private:
		double length,breadth,height;
	public:
		void getLen(int len){
			length = this->len;
		}
		void getBre(int bre){
			breadth = this->bre;
		}
		void getHgt(int het){
			height = this->het;
		}
		double getVolume(){
			return length*breadth*height;
		}
		Box operator -(const Box &b){
			Box box;
			box.length=this->length-b.length;
			box.breadth=this->breadth-b.breadth;
			box.height=this->height-b.height;
			return box;
		}
};

int main(){
	Box box1,box2,box3;
	box1.length(2.0);
	box1.length(7.6);
	box1.length(2.7);
	cout<<"Volume of box1 is "<<box1.getVolume()<<endl;

	box1.length(1.3);
	box1.length(2.3);
	box1.length(5.7);
	cout<<"Volume of box2 is "<<box2.getVolume()<<endl;

	box3 = box1-box2;
	cout<<"Volume of box3 is "<<box3.getVolume()<<endl;

	
}