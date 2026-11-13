//================================================================
//activity4:POLYMORHIC DRAWING PROGRAM
//learning outcome:create a polymorphic application
//================================================================

#include<iostream>
#include<vector>
using namespace std;

//1.ABSRATCT BASE CLASS
class shape{
    public:
      //pure virtual function.Every shape MUST implement this.
        virtual void draw()=0;
      
        
      //virtual destructor:crucial for cleaning up derived objects properly!
      virtual ~shape(){}
};

//2.DERIVED CLASSES
class circle:public shape {
    
    public:
        void draw() override{//'override' is a safety feature to ensure we are correctly overriding
            cout<<"drawing a circle O"<<endl;
        }
};

class rectangle:public shape {
    public:
        void draw() override{
            cout<<"drawing a rectangle []"<<endl;
        }
};

class triangle:public shape {
    public:
        void draw() override{
            cout<<"drawing a triangle /\\"<<endl;
        }
};

//3.POLYMORHIC FUNCTION
//this function doesn't care what kind shape is.it just knows it's a shape.
void renderCanvas(shape*s){
    s->draw();//dynamic binding decides which draw()to call!
}


int main(){
    //we use avector to store pointers to our shapes
    vector<shape*>canvas;

    //we add different derived objects to the vector
    canvas.push_back(new circle());
    canvas.push_back(new rectangle());
    canvas.push_back(new triangle());
    canvas.push_back(new circle());


    cout<<"---rendering canvas---"<<endl;


    //loop through the canvas and draw everthing
    for(int i=0;i<canvas.size();i++){
        renderCanvas(canvas[i]);
    }


    cout<<"\n---Cleaning Up Memory---"<<endl;
    //clean up the heap memory
    for(int i=0;i<canvas.size();i++){
        delete canvas[i];
    }


    return 0;
}
