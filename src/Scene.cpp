/** Scene.cpp
 *
 * See header file for details.
 */

#include "Scene.h"

#include "Actor.h"
#include "raylib.h"

Scene::Scene() {
	int sceneHeight = GetRenderHeight();
}
	
Scene::~Scene() {
	freeResources();
}
	
void Scene::loadResources() {
}
	
void Scene::freeResources() {
	playerAvatar.reset();
	actors.clear();
}
	
void Scene::start() {
}
	
std::shared_ptr<Scene> Scene::update() {
	for(auto &actor : actors) {
		actor->position += actor->velocity;
		
		auto boundingRect = actor->getBoundingBox();


		actor->update();
	}
	
	return nullptr;
}
	
void Scene::draw() {
	ClearBackground(RAYWHITE);
		
	if(actors.size()) {
		for(auto &actor: actors) {
			actor->draw();
		}
	} else {
		DrawText("This scene has no content. Add some actors, or override Scene::draw()", 20, 20, 20, RED);
	}
}
void Scene::Movement(Vector2 temp) {
	if(playerAvatar) {
		playerAvatar->Movement(temp);
	}
}
	

void Scene::goNowhere() {
	if(playerAvatar) {
		playerAvatar->goNowhere();
	}
}
	
void Scene::PrimaryInteract() {
	if(playerAvatar) {
		playerAvatar->PrimaryInteract();
	}
}
void Scene::SecondaryInteract() {
	if(playerAvatar) {
		playerAvatar->SecondaryInteract();
	}
} 
