// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_POOL_APP_H_
#define FINALPROJECT_APPS_POOL_APP_H_

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <pool/cue.h>
#include <pool/engine.h>
#include <pool/table.h>
#include <pool/contact.h>

namespace poolapp {

using cinder::Color;
using cinder::Rectf;
using cinder::app::MouseEvent;
using std::string;
using std::vector;

enum class GameState {
  kStartScreen,
  kHelpScreen,
  kBeginGame,
  kSetup,
  kInProgress,
  kTurnDone,
  kFoul,
  kFoulSetup,
  kGameOver,
};

class PoolApp : public cinder::app::App {
 public:

  // cinder default functions
  PoolApp();
  void setup() override;
  void update() override;
  void draw() override;

  // All mouse actions used
  void mouseDown(cinder::app::MouseEvent) override;
  void mouseDrag(cinder::app::MouseEvent) override;
  void mouseMove(cinder::app::MouseEvent) override;
  void mouseUp(cinder::app::MouseEvent) override;

 private:

  // Determines if the play is in progress by checking if any balls are
  // still moving
  bool BodyMoving();

  // Helper methods that draw certain aspects of the game
  void DrawStartScreen() const;
  void DrawHelpScreen() const;
  void DrawPoolTable() const;
  void DrawPoolBalls() const;
  void DrawCueStick() const;
  void DrawHelpRay() const;
  void DrawGuideLine() const;
  void DrawScoreText() const;
  void DrawEndScreen() const;

 private:
  // Box2D world containing all bodies
  b2World* pool_world_;

  // Contact listener that inherits b2ContactListener
  pool::Contact contact_;

  // Table object holds information about the table's body and surface
  pool::Table table_;

  // Cue stick object holds information about the cue stick's body
  pool::Cue cue_stick_;

  // Engine with important functions and information about positioning
  pool::Engine engine_;

  // Current state of the game
  GameState state_;

  // Keeps track if blue or orange ball was scored in the last turn
  bool blue_scored_;
  bool orange_scored_;

  // Color of each player
  Color player1_color_;
  Color player2_color_;

  // Keeps track if the turn was the first one
  bool is_first_turn_;

  // name of the winner
  string winner_;

};

}  // namespace poolapp

#endif  // FINALPROJECT_APPS_POOL_APP_H_
