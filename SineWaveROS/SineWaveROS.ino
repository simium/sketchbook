/*

 Sine wave
 
 */

#include <math.h>
#include <ros.h>
#include <std_msgs/Float32.h>

const float myPI = 3.141593;
float alpha = 0.0;

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

std_msgs::Float32 sineWave;
ros::Publisher p("sinewave", &sineWave);
ros::NodeHandle nh;

long publisher_timer = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     

  nh.initNode();
  nh.advertise(p);
}

// the loop routine runs over and over again forever:
void loop() {
  if (millis() > publisher_timer) {
    alpha = alpha + 0.1;
    if (alpha>2*myPI)
    {
      alpha = 0;
    }

    sineWave.data = sin(alpha);
    p.publish( &sineWave );
    publisher_timer = millis() + 1000; //publish once a second
  }
  nh.spinOnce();
}

