/** PlayerScene.cpp
 *
 * See header file for details.
 */

#include "PlayerScene.h"

PlayerScene::PlayerScene() {
}
	
PlayerScene::~PlayerScene() {
}
	
void PlayerScene::loadResources() {
	std::shared_ptr<Player> player = std::make_shared<Player>();
	
	int sceneheight = GetRenderHeight();
	player->position = raylib::Vector2(sceneheight / 2);
	
	playerAvatar = player;
	actors.emplace_back(player);
}
 
