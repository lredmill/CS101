#include <iostream>
using namespace std;

void HelloWorld(){
    std::cout<<"I am Printing From Subroutine"<<std::endl;
}
int sumOf(int a,int b){
    int addIn;
    addIn=a+b;
    return addIn;

}
int main() {
    int sum;
    int a=-14;
    int b=12;

  sum=sumOf(a,b);
  cout<<sum<<endl;
    HelloWorld();

   return 0;
}
