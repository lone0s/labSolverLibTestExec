#include "pch.h"

#include "../labSolverLib/Player.h"
#include "../labSolverLib/Action.h"
#include "../labSolverLib/Tracer.h"

TEST(TracerTest, testTracerConstructor) {
	Player player;
	
	Tracer tracer = player.getTracer();
	
	EXPECT_EQ(size_t(player), 1);
	
	EXPECT_EQ(std::get<0>(tracer.getPath()[0]), 1);
	EXPECT_EQ(std::get<1>(tracer.getPath()[0]), 1);
}

TEST(TracerTest, testTracerGoForward) {
	Player player;

	player.doAction(Action::GO_FORWARD);

	Tracer tracer = player.getTracer();

	EXPECT_EQ(size_t(player), 2);

	EXPECT_EQ(std::get<0>(tracer.getPath()[1]), 2);
	EXPECT_EQ(std::get<1>(tracer.getPath()[1]), 1);
}

TEST(TracerTest, testTracerTurnLeft) {
	Player player;

	player.doAction(Action::TURN_LEFT);
	player.doAction(Action::GO_FORWARD);

	Tracer tracer = player.getTracer();

	EXPECT_EQ(size_t(player), 3);

	EXPECT_EQ(std::get<0>(tracer.getPath()[2]), 1);
	EXPECT_EQ(std::get<1>(tracer.getPath()[2]), 0);
}