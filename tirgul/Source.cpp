 #include<iostream>
 using namespace std;
 class Ratio {
 private:
	int up, down; 
 public:
	Ratio(); 
		Ratio(int u, int d);
		Ratio operator+(int toAdd);
	 //Ratio operator+(Ratio first, int second);
		
 Ratio() : up(2), down(3) {}
 Ratio(int u, int d) : up(u), down(d) {}
  Ratio operator+(int toAdd) {
	Ratio r(up + toAdd, down + toAdd); 
		return r; 
		
}
 //Ratio operator+(Ratio first, int second) {
	//Ratio r(first.up + second, first.down + second); 
		//return r; 
		
}
 int main() {
	Ratio Num1, Num2; 
		int Num3 = 2; 
		Num1 = Num2 + Num3; 
		return 0; 
	
}