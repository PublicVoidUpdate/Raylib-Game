/** PlayerScene.h
 *
 * @author Hans de Ruiter
 *
 * @copyright (c) 2022 by Kea Sigma Delta Limited, all rights reserved
 *
 * See License.txt for license.
 */

#pragma once

#include "Scene.h"
#include "Player.h"

/** A scene for scarfy to walk around in.
 */
class PlayerScene : public Scene {
public:
	PlayerScene();
	
	virtual ~PlayerScene();
	
	virtual void loadResources();
};

 
