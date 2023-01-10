#include "pch.h"

#include "../labSolverLib/Player.h"
#include "../labSolverLib/Action.h"
TEST(PlayerTest, testPlayerConstructor) {
	Player player;
	EXPECT_EQ(player.getX(), 1);
	EXPECT_EQ(player.getY(), 1);
}

TEST(PlayerForward, testPlayerGoForward) {
	Player player;
	player.doAction(Action::GO_FORWARD);
	EXPECT_EQ(player.getX(), 2);
	EXPECT_EQ(player.getY(), 1);
}

TEST(PlayerLeft, testPlayerTurnLeft) {
	Player player;
	
	player.doAction(Action::TURN_LEFT);
	EXPECT_EQ(player.getOrientation(), Orientation::up);
	
	player.doAction(Action::GO_FORWARD);
	EXPECT_EQ(player.getX(), 1);
	EXPECT_EQ(player.getY(), 0);

}

TEST(PlayerRight, testPlayerTurnRight) {
	Player player;
	
	player.doAction(Action::TURN_RIGHT);
	EXPECT_EQ(player.getOrientation(), Orientation::down);

	player.doAction(Action::GO_FORWARD);
	EXPECT_EQ(player.getX(), 1);
	EXPECT_EQ(player.getY(), 2);
}

TEST(PlayerBack, testPlayerTurnBack) {
	Player player;

	player.doAction(Action::TURN_BACK);
	EXPECT_EQ(player.getOrientation(), Orientation::left);

	player.doAction(Action::GO_FORWARD);
	EXPECT_EQ(player.getX(), 0);
	EXPECT_EQ(player.getY(), 1);
}

TEST(PlayerAbsoluteUp, testPlayerAbsoluteUp) {
	Player player;
	
	player.doAction(Action::GO_UP);
	EXPECT_EQ(player.getX(), 1);
	EXPECT_EQ(player.getY(), 0);
}


TEST(PlayerAbsoluteRight, testPlayerAbsoluteRight) {
	Player player;

	player.doAction(Action::GO_RIGHT);
	EXPECT_EQ(player.getX(), 2);
	EXPECT_EQ(player.getY(), 1);
}

TEST(PlayerAbsoluteDown, testPlayerAbsoluteDown) {
	Player player;

	player.doAction(Action::GO_DOWN);
	EXPECT_EQ(player.getX(), 1);
	EXPECT_EQ(player.getY(), 2);
}

TEST(PlayerAbsoluteLeft, testPlayerAbsoluteLeft) {
	Player player;

	player.doAction(Action::GO_LEFT);
	EXPECT_EQ(player.getX(), 0);
	EXPECT_EQ(player.getY(), 1);
}



