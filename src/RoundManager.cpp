//
//  RoundManager.cpp
//  bleepout
//
//  Created by tekt on 12/2/14.
//
//

#include "Common.h"
#include "RoundManager.h"
#include "BleepoutConfig.h"
#include "RendererBase.h"
#include "SimpleRenderer.h"

RoundController::RoundController(RoundConfig config)
  : _config(config) {
}

RoundController::~RoundController() {
}

void RoundController::setup() {
  //...
  _state.players().push_back(ofPtr<Player>(new Player()));
  
  _spaceController.reset(new SpaceController(_state, _config));
  _logicController.reset(new LogicController(_state, _config));
  _spaceController->setup();
  _logicController->setup();
  
  _renderer.reset(new SimpleRenderer());
  //...
}

void RoundController::draw() {
  _renderer->draw(_state);
  //...
}

void RoundController::update() {
  //ofLogVerbose() << "OMG UPDATE!!!";
  _spaceController->update();
  _logicController->update();
}

void RoundController::keyPressed(int key) {
  if (key == 'l') {
    dumpToLog();
  }
}

void RoundController::setPaddlePosition(GameObjectId playerId, float xPercent) {
  ofPtr<Player> player = _state.players().getById(playerId);
  if (!player) {
    ofLogError() << "Player not found: " << playerId;
    return;
  }

  ofPtr<Paddle> paddle = player->paddle();
  if (!paddle) {
    ofLogError() << "Unable to set paddle position for player: " << playerId;
    return;
  }
  
  ofVec2f pos = paddle->getPosition();
//  ofLogVerbose() << "Paddle position was " << pos;
  pos.x = xPercent * ofGetWidth();
//  ofLogVerbose() << "Setting paddle position to " << pos;
  paddle->setPosition(pos);
  //...
}

void RoundController::mouseMoved(int x, int y) {
  //...
  if (_state.players().size()) {
    ofPtr<Player> player = _state.players()[0];
    setPaddlePosition(player->id(), (float)x / ofGetWidth());
  }
}

void RoundController::mouseDragged(int x, int y, int button) {
  //...
}

void RoundController::dumpToLog() {
  ofLogVerbose() << "--BEGIN round state--";
  _state.dumpToLog();
  ofLogVerbose() << "--  END round state--";
}
