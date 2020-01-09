#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTreeInt.h"

using namespace std;

TEST_CASE("Constructors", "[ctors]")
{
	BSTreeInt s;
	
	REQUIRE(s.size() == 0);
}

TEST_CASE("Insert", "[Insert]")
{
	BSTreeInt s;
	
	REQUIRE(s.insert(60));
	REQUIRE(s.size() == 1);
	REQUIRE(s.path() == "");
	
	REQUIRE(s.insert(40));
	REQUIRE(s.size() == 2);
	REQUIRE(s.path == "L");
	
	REQUIRE(s.insert(80));
	REQUIRE(s.size() == 3);
	REQUIRE(s.path == "R");
	
	REQUIRE(s.insert(20));
	REQUIRE(s.size() == 4);
	REQUIRE(s.path == "LL");
	
	REQUIRE(s.insert(50));
	REQUIRE(s.size() == 5);
	REQUIRE(s.path == "LR");
	
	REQUIRE(s.insert(70));
	REQUIRE(s.size() == 6);
	REQUIRE(s.path == "RL");
	
	REQUIRE(s.insert(90));
	REQUIRE(s.size() == 7);
	REQUIRE(s.path == "RR");
	
}