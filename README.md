# linearclaw
Code for Arduino servo-powered linear motion robotic claw controlled by Processing GUI over serial

Arduino functions:
- sendGrip: takes a integer percentage of grip as a parameter, converts it to an angle, sends to Servo myservo to rotate, and returns void.
- getGrip: redundant function that was designed to be the inverse of sendGrip. 
- mapp: copy of the C++ map function. Created because previous function would only return rounded doubles.

Processing GUI:
- uses ControlP5 library
- When grip button is pressed, Processing sends current slider value over serial.

Changes required for personal use:
- COM port name change in line 14 of Processing
- Servo attach pin in Arduino line 13
- Change values for type double variables 'open' and 'close' by what servo angle gives a fully open and fully closed grip.
