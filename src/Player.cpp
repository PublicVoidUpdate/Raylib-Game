/** Player.cpp
 *
 * See header file for details.
 */

#include "Player.h"

// static const int UpWalk = 1;
// static const int DownWalk = 0;
// static const int LeftWalk= 3;
// static const int RightWalk = 2;

// static bool isFootstepFrame(int frameIndex) {
	
// 	if(frameIndex == footstepFrame1 || frameIndex == footstepFrame2) {
// 		return true;
// 	} else {
// 		return false;
// 	}
// }


Player::Player() : 
		texture("./Resources/Sprites/Body/char1.png")
		//footstepSound("Single-footstep-in-grass-A-www.fesliyanstudios.com.mp3"),
		//landingSound("Single-footstep-in-grass-B-www.fesliyanstudios.com.mp3") 
{
	texture.width *=3; // # is scale
	texture.height *=3;
	
	const int xframes = 8;
	const int vframes = 49;
	frameWidth = texture.width / xframes;
	frameHeight = texture.height / vframes;
	frameRec = raylib::Rectangle(0.0f, 0.0f, (float)frameWidth, (float)frameHeight);
	
    int currentFrame = 0;           // current sprite frame

    int framesCounter = 0;          // frames till next sprite change
    const int framesSpeed = 6;            // Number of spritesheet frames shown per second
    bool moving = false;
	
	walkSpeed = 5;
}
	
Player::~Player() {
}
	
bool Player::update() {


	framesCounter++;
        if (framesCounter >= 10) //60 / framesSpeed
        {
        	if (currentFrame >= 8) {currentFrame = 0;};
            if (moving)
            {
                framesCounter = 0;
                currentFrame++;
            } 
            if (!moving)
            {
                currentFrame = 0;
            }
        
			frameRec.x = (float) frameWidth * currentFrame;
		}
	
	
	return true;
}

	
void Player::draw() {
	raylib::Vector2 ulPosition = getUpperLeftPosition();
	DrawTextureRec(texture, frameRec, ulPosition, WHITE);
}
	
raylib::Rectangle Player::getBoundingBox() {
	raylib::Vector2 ulPosition = getUpperLeftPosition();
	return raylib::Rectangle(ulPosition.x, ulPosition.y, texture.width, texture.height);
}
	

void Player::goNowhere() {
		//currentFrame = 0;
}
	
void Player::Movement(Vector2 InputDir) {

		//frameRec.y = frameHeight*1;

		if(InputDir.x == 0 && InputDir.y == 0)
		{
			moving = false;
			currentFrame = 0;
		} else{
			moving = true;
		}

		if(fabs(InputDir.y) > fabs(InputDir.x)) //sets movement anim based on input dir
        {

            if(InputDir.y > 0) //sets movement anim based on input dir
                {
                    frameRec.y = (float)(texture.height/49)*0;
                } else if (InputDir.y < 0)
                {
                    frameRec.y = (float)(texture.height/49)*1;
                }

            } 
            if(fabs(InputDir.y) < fabs(InputDir.x)) {
                if (InputDir.x > 0)
                {
                    frameRec.y = (float)(texture.height/49)*2;
                } else if (InputDir.x < 0)
                {
                    frameRec.y = (float)(texture.height/49)*3;
                } 
            } 
            if(fabs(InputDir.y) == fabs(InputDir.x))
            {
                if(InputDir.y > 0) //sets movement anim based on input dir
                {
                    frameRec.y = (float)(texture.height/49)*0;
                } else if (InputDir.y < 0)
                {
                    frameRec.y = (float)(texture.height/49)*1;
                }
            }
            velocity = InputDir;
		
}
	
void Player::PrimaryInteract() {
}
void Player::SecondaryInteract() {
}

raylib::Vector2 Player::getUpperLeftPosition() {
	return raylib::Vector2(position.x - frameWidth / 2, position.y - frameHeight);
} 
