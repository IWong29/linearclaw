import controlP5.*;
import processing.serial.*;

int gripValue;

Serial port;
ControlP5 cp5; //creates object

void setup(){
  size(600, 800); //window
  
  printArray(Serial.list());
  
  port = new Serial(this, "COM3", 9600); //CHANGE COM PORT STRING
  
  cp5 = new ControlP5(this);
  cp5.addSlider("Percent")
    .setPosition(50, 125)
    .setRange(0, 100)
    .setSize(300, 25)
    .setNumberOfTickMarks(101)
    .showTickMarks(false)
    .setLabelVisible(true)
    .setSliderMode(Slider.FLEXIBLE)
  ;
  cp5.getController("Percent").getCaptionLabel().align(ControlP5.LEFT, ControlP5.TOP_OUTSIDE).setPaddingX(0);
  cp5.getController("Percent").getCaptionLabel().setSize(15);
  
  cp5.addButton("Grip")
    .setPosition(410, 95)
    .setSize(135, 85)
    .setFont(createFont("calibri light", 20))
  ;
}

void draw(){ //loop() in arduino
    background(112, 164, 204); //RGB
    textSize(50);
    fill(255, 255, 255); //text color
    textFont(createFont("Arial Bold", 50));
    text("ROBOTIC CONTROL", 55, 65); //text title
    
    gripValue = (int)cp5.getController("Percent").getValue();
    
}

void Grip(int value){
  port.write("grip" + gripValue);
  delay(500);
}
