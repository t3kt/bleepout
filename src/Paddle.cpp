//
//  Paddle.cpp
//  bleepout
//
//  Created by tekt on 12/2/14.
//
//

#include "Paddle.h"

Paddle::Paddle(ofPtr<Player> player)
: GameObject(GAME_OBJECT_PADDLE), _player(player) {
  ofLogVerbose() << "Create Paddle";
}

Paddle::~Paddle() {
  ofLogVerbose() << "Destroy Paddle";
  destroy();
}

void Paddle::output(std::ostream &os) const {
  auto pos = const_cast<Paddle*>(this)->getPosition();
  os << "Paddle{id:" << id() << ", pos:(" << pos.x << "," << pos.y << ")";
  if (_player)
    os << ", player:" << _player->id();
  else
    os << ", player: NONE";
  os << "}";
}
