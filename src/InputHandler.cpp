 /** InputHandler.cpp
  *
  * See header file for details.
  * 
  * 
  * i has modified this to fit my project. it is no longer the original code :3
  */

 #include "InputHandler.h"

 #include "CommandListener.h"

 #include "raylib-cpp.hpp"
 #include "raymath.h"

 InputHandler::InputHandler() {
 	p1GamepadID = 0;
 }
 	
 InputHandler::~InputHandler() {
 }

 void InputHandler::handleInput(CommandListener &listener) {
 	// bool moving = false;
    float x;
    float y;
 	
 	// Up/down
    if(IsKeyDown(KEY_D) == true)
    {
        x = 1;
    }
    if(IsKeyDown(KEY_A) == true)
    {
        x = -1;
    }
    if(IsKeyDown(KEY_W) == true)
    {
        y = -1;
    }
    if(IsKeyDown(KEY_S) == true)
    {
        y = 1;
    }
    Vector2 InputDir = (Vector2){x , y};
    listener.Movement(Vector2Normalize(InputDir));
 	
 	// if(!moving) {
 	// 	listener.goNowhere();
 	// }
 	
 	// Select, push, pull, etc.
 	if(IsMouseButtonDown(KEY_RIGHT) || 
 			IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_LEFT_TRIGGER_1)){
 		listener.PrimaryInteract();
 	}

 	if(IsGamepadButtonDown(p1GamepadID, GAMEPAD_BUTTON_RIGHT_TRIGGER_1) || IsMouseButtonDown(KEY_LEFT))
 	{
 		listener.SecondaryInteract();
 	}
 } 
