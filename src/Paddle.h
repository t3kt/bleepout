//
//  Paddle.h
//  bleepout
//
//  Created by tekt on 12/2/14.
//
//

#ifndef __bleepout__Paddle__
#define __bleepout__Paddle__

#include "Player.h"
#include "GameObject.h"
#include <ofxBox2d.h>
#include <ofTypes.h>

class Paddle : public GameObject, public ofxBox2dRect {
public:
  Paddle(ofPtr<Player> player);
  ~Paddle() override;
  
  ofPtr<Player> player() { return _player; }
  
  void output(std::ostream& os) const override;
private:
  ofPtr<Player> _player;
};


#endif /* defined(__bleepout__Paddle__) */
