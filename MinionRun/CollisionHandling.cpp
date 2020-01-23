#include "stdafx.h"
#include "CollisionHandling.h"
#include "Player.h"
#include "Booster.h"
#include "Coin.h"
#include "Treasure.h"
#include "Rock.h"
#include "Bridge.h"
#include <typeindex>


namespace { 

	// primary collision-processing functions
	void PlayerCoin(Object & coin, Object &player) {

		Player& player1 = dynamic_cast<Player&>(player);
		player1.setScore(200);
		DataBase::instance().getCoinSound().setVolume(2);
		DataBase::instance().getCoinSound().play();
	}

	void PlayerTreasure(Object & treasure, Object &player) {
		Player& player1 = dynamic_cast<Player&>(player);
		player1.setScore(500);
		DataBase::instance().getCoinSound().setVolume(2);
		DataBase::instance().getCoinSound().play();
	}

	void PlayerRock(Object & rock, Object &player) {
		Player& player1 = dynamic_cast<Player&>(player);
		player1.setScore(-400);
		DataBase::instance().getRockSound().setVolume(15);
		DataBase::instance().getRockSound().play();
	}

	void PlayerBridge(Object & bridge, Object &player) {
		Player& player1 = dynamic_cast<Player&>(player);
		DataBase::instance().getBridgeSound().setVolume(40);
		DataBase::instance().getBridgeSound().play();
		player1.setLives(-1);
	}

	void PlayerBooster(Object & Player, Object &booster){
	}

	// secondary collision-processing functions that just
	// implement symmetry: swap the parameters and call a
	// primary function

	void BoosterPlayer(Object &booster, Object & player) {
		PlayerBooster(player, booster);
	}

	void CoinPlayer(Object &coin, Object & player) {
		PlayerCoin(player, coin);
	}

	void TreasurePlayer(Object &treasure, Object &player) {
		PlayerTreasure(player, treasure);
	}

	void RockPlayer(Object &rock, Object & player) {
		PlayerRock(player, rock);
	}

	void BridgePlayer(Object &Bridge, Object &player) {
		PlayerBridge(player, Bridge);
	}

	//----------------------------------------------------------------
	using std::type_index;
	using std::pair;
	using std::map;
	using HitFunctionPtr = void(*)(Object & Player, Object &collect);
	using Key = pair<type_index, type_index>;
	using HitMap = map<Key, HitFunctionPtr>;
	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player &), typeid(Booster&))] = &PlayerBooster;
		phm[Key(typeid(Player &), typeid(Coin&))] = &PlayerCoin;
		phm[Key(typeid(Player &), typeid(Treasure&))] = &PlayerTreasure;
		phm[Key(typeid(Player &), typeid(Rock&))] = &PlayerRock;
		phm[Key(typeid(Player &), typeid(Bridge&))] = &PlayerBridge;
		phm[Key(typeid(Booster&), typeid(Player &))] = &BoosterPlayer;
		phm[Key(typeid(Coin&), typeid(Player &))] = &CoinPlayer;
		phm[Key(typeid(Treasure&), typeid(Player &))] = &TreasurePlayer;
		phm[Key(typeid(Rock&), typeid(Player &))] = &RockPlayer;
		phm[Key(typeid(Bridge&), typeid(Player &))] = &BridgePlayer;

		return phm;
	}
	//check if a collision is setup for the two objects that are sent
	HitFunctionPtr lookup(const type_index& class1, const type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));

		if (mapEntry == collisionMap.end())
			return nullptr;

		return mapEntry->second;
	}
} // end namespace


//send to collide handler
void processCollision(Object & Player, Object &collect)
{
	auto phf = lookup(typeid(collect), typeid(Player));
	if (phf)
		phf(Player, collect);
}