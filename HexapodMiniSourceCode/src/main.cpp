#include "main.hpp"
#include <Robot.hpp>



void setup() {
//  Robot &a = Robot::getInstance();
  // put your setup code here, to run once:
 
     
}

void loop() {
  Robot &a = Robot::getInstance();
  
  static  int counter=0;
  if(counter >20)
    counter = 0;
  else
  {
   //a.setAngle(counter,Leg6::joint_2);
   a.setPosition(-counter,counter,10,Leg6::jo1nts);
    counter+=5;
  }
  delay(500);
}
