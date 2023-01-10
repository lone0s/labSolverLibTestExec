#include "pch.h"
#include <fstream>
#include "../labSolverLib/Grid.h"

TEST(GridTest, testGridConstructor) {
	
	Grid grid("../../labyz/lab3.txt");
	
	EXPECT_EQ(grid.getPlayer().getX(), 1);
	EXPECT_EQ(grid.getPlayer().getY(), 1);

	size_t width = grid.getLabyrinth()[0].size();
	size_t height = grid.getLabyrinth().size();
	
	EXPECT_EQ(width, 7);
	EXPECT_EQ(height, 7);

	EXPECT_EQ(grid.getLabyrinth()[0][0], Cells::WALL);
	EXPECT_EQ(grid.getLabyrinth()[width - 2][height - 2], Cells::EXIT);

}

TEST(gridIsExit, testGridIsExit) {
	Grid grid("../../labyz/minilab.txt");

	EXPECT_EQ(grid.isExit(), false);
	
	grid.getPlayer().doAction(Action::GO_FORWARD);
	grid.getPlayer().doAction(Action::GO_FORWARD);
	grid.getPlayer().doAction(Action::GO_FORWARD);
	grid.getPlayer().doAction(Action::GO_FORWARD);

	EXPECT_EQ(grid.isExit(), true);
}

TEST(gridHasNothingFront, testGridHasNothingFront) {
	Grid grid("../../labyz/minilab.txt");

	EXPECT_EQ(grid.playerHasNothingInFront(), true);

	grid.getPlayer().doAction(Action::TURN_LEFT);

	EXPECT_EQ(grid.playerHasNothingInFront(), false);
}

TEST(gridHasNothingLeft, testGridHasNothingLeft) {
	Grid grid("../../labyz/minilab.txt");

	EXPECT_EQ(grid.playerHasNothingOnLeft(), false);

	grid.getPlayer().doAction(Action::TURN_RIGHT);

	EXPECT_EQ(grid.playerHasNothingOnLeft(), true);
}

TEST(gridHasNothingRight, testGridHasNothingRight) {
	Grid grid("../../labyz/minilab.txt");

	EXPECT_EQ(grid.playerHasNothingOnRight(), false);

	grid.getPlayer().doAction(Action::TURN_LEFT);

	EXPECT_EQ(grid.playerHasNothingOnRight(), true);
}

TEST(gridPossibleRelativeActions, testGridPossibleRelativeActions) {
	Grid grid("../../labyz/minilab.txt");

	std::vector<Action> actions = grid.possibleRelativeActions();

	EXPECT_EQ(actions.size(), 1);
	EXPECT_EQ(actions[0], Action::GO_FORWARD);

}

TEST(gridCheckAbsoluteActions, testGridCheckAbsoluteActions) {
	Grid grid("../../labyz/minilab.txt");

	EXPECT_EQ(grid.checkAbsoluteActions(Action::GO_RIGHT), true);
	
	EXPECT_EQ(grid.checkAbsoluteActions(Action::GO_LEFT), false);
	EXPECT_EQ(grid.checkAbsoluteActions(Action::GO_DOWN), false);
	EXPECT_EQ(grid.checkAbsoluteActions(Action::GO_UP), false);


}
