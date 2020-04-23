// Copyright (c) 2020 Ashley Yeah. All rights reserved.

#include <pool/pool_balls.h>
#include <pool/table.h>

namespace pool {

void Table::CreateTable(b2World *pool_world, float center_x, float center_y) {
  b2BodyDef body_def;
  body_def.type = b2_kinematicBody;


  body_def.position.Set(center_x - 300, center_y - 300);
  bottom_edge1_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x + 300, center_y - 300);
  bottom_edge2_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x - 600, center_y);
  left_edge_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x - 300, center_y + 300);
  top_edge1_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x + 300, center_y + 300);
  top_edge2_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x + 600, center_y);
  right_edge_ = pool_world->CreateBody(&body_def);

  body_def.position.Set(center_x, center_y);
  table_body_ = pool_world->CreateBody(&body_def);

  b2PolygonShape edge_x;
  b2PolygonShape edge_y;
  b2PolygonShape table_box;

  edge_x.SetAsBox(2.5f, 300.0f - kPocketRadius - 10);
  edge_y.SetAsBox( 300.0f - kPocketRadius - 10, 2.5f );
  table_box.SetAsBox(600.0f, 300.0f);

  b2FixtureDef fixture_def;
  fixture_def.shape = &edge_x;
  left_edge_->CreateFixture(&fixture_def);
  right_edge_->CreateFixture(&fixture_def);

  fixture_def.shape = &edge_y;
  top_edge1_->CreateFixture(&fixture_def);
  top_edge2_->CreateFixture(&fixture_def);
  bottom_edge1_->CreateFixture(&fixture_def);
  bottom_edge2_->CreateFixture(&fixture_def);

  fixture_def.shape = &table_box;
  fixture_def.isSensor = true;
  fixture_def.friction = 1.0f;
  table_body_->CreateFixture(&fixture_def);
}

b2Body* Table::GetTableBody() const {
  return table_body_;
}

}  // namespace pool