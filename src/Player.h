/** Player.h
 *
 * @author Hans de Ruiter
 *
 * @copyright (c) 2022 by Kea Sigma Delta Limited, all rights reserved
 *
 * See License.txt for license.
 */

#pragma once

#include "Actor.h"

#include "raylib-cpp.hpp"

/** Our Player character.
 */
class Player : public Actor {
public:
	/** Create Player.
	 */
	Player();
	
	virtual ~Player();
	
	virtual bool update();
	
	virtual void draw();
	
	virtual raylib::Rectangle getBoundingBox();
	
	
	virtual void Movement(Vector2);
	
	virtual void goNowhere();
	
	/** Select, push, pull, punch, fire, etc.
	 */
	virtual void PrimaryInteract();
	virtual void SecondaryInteract();
	
private:
	/** Calculates the position of this object's upper-left corner.
	 */
	raylib::Vector2 getUpperLeftPosition();

	raylib::Texture2D texture;
	
	// Animation state
	unsigned vframes;
	unsigned xframes;
	int frameWidth;
	int frameHeight;
    unsigned currentFrame;           
    unsigned framesCounter;          
    unsigned framesSpeed;
    bool moving;

	raylib::Rectangle frameRec;
	
	float walkSpeed;

}; 
