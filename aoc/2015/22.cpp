/*

--- Day 22: Wizard Simulator 20XX ---
Little Henry Case decides that defeating bosses with swords and stuff is boring. Now he's playing the game with a wizard. Of course, he gets stuck on another boss and needs your help again.

In this version, combat still proceeds with the player and the boss taking alternating turns. The player still goes first. Now, however, you don't get any equipment; instead, you must choose one of your spells to cast. The first character at or below 0 hit points loses.

Since you're a wizard, you don't get to wear armor, and you can't attack normally. However, since you do magic damage, your opponent's armor is ignored, and so the boss effectively has zero armor as well. As before, if armor (from a spell, in this case) would reduce damage below 1, it becomes 1 instead - that is, the boss' attacks always deal at least 1 damage.

On each of your turns, you must select one of your spells to cast. If you cannot afford to cast any spell, you lose. Spells cost mana; you start with 500 mana, but have no maximum limit. You must have enough mana to cast a spell, and its cost is immediately deducted when you cast it. Your spells are Magic Missile, Drain, Shield, Poison, and Recharge.

Magic Missile costs 53 mana. It instantly does 4 damage.
Drain costs 73 mana. It instantly does 2 damage and heals you for 2 hit points.
Shield costs 113 mana. It starts an effect that lasts for 6 turns. While it is active, your armor is increased by 7.
Poison costs 173 mana. It starts an effect that lasts for 6 turns. At the start of each turn while it is active, it deals the boss 3 damage.
Recharge costs 229 mana. It starts an effect that lasts for 5 turns. At the start of each turn while it is active, it gives you 101 new mana.
Effects all work the same way. Effects apply at the start of both the player's turns and the boss' turns. Effects are created with a timer (the number of turns they last); at the start of each turn, after they apply any effect they have, their timer is decreased by one. If this decreases the timer to zero, the effect ends. You cannot cast a spell that would start an effect which is already active. However, effects can be started on the same turn they end.

For example, suppose the player has 10 hit points and 250 mana, and that the boss has 13 hit points and 8 damage:

-- Player turn --
- Player has 10 hit points, 0 armor, 250 mana
- Boss has 13 hit points
Player casts Poison.

-- Boss turn --
- Player has 10 hit points, 0 armor, 77 mana
- Boss has 13 hit points
Poison deals 3 damage; its timer is now 5.
Boss attacks for 8 damage.

-- Player turn --
- Player has 2 hit points, 0 armor, 77 mana
- Boss has 10 hit points
Poison deals 3 damage; its timer is now 4.
Player casts Magic Missile, dealing 4 damage.

-- Boss turn --
- Player has 2 hit points, 0 armor, 24 mana
- Boss has 3 hit points
Poison deals 3 damage. This kills the boss, and the player wins.
Now, suppose the same initial conditions, except that the boss has 14 hit points instead:

-- Player turn --
- Player has 10 hit points, 0 armor, 250 mana
- Boss has 14 hit points
Player casts Recharge.

-- Boss turn --
- Player has 10 hit points, 0 armor, 21 mana
- Boss has 14 hit points
Recharge provides 101 mana; its timer is now 4.
Boss attacks for 8 damage!

-- Player turn --
- Player has 2 hit points, 0 armor, 122 mana
- Boss has 14 hit points
Recharge provides 101 mana; its timer is now 3.
Player casts Shield, increasing armor by 7.

-- Boss turn --
- Player has 2 hit points, 7 armor, 110 mana
- Boss has 14 hit points
Shield's timer is now 5.
Recharge provides 101 mana; its timer is now 2.
Boss attacks for 8 - 7 = 1 damage!

-- Player turn --
- Player has 1 hit point, 7 armor, 211 mana
- Boss has 14 hit points
Shield's timer is now 4.
Recharge provides 101 mana; its timer is now 1.
Player casts Drain, dealing 2 damage, and healing 2 hit points.

-- Boss turn --
- Player has 3 hit points, 7 armor, 239 mana
- Boss has 12 hit points
Shield's timer is now 3.
Recharge provides 101 mana; its timer is now 0.
Recharge wears off.
Boss attacks for 8 - 7 = 1 damage!

-- Player turn --
- Player has 2 hit points, 7 armor, 340 mana
- Boss has 12 hit points
Shield's timer is now 2.
Player casts Poison.

-- Boss turn --
- Player has 2 hit points, 7 armor, 167 mana
- Boss has 12 hit points
Shield's timer is now 1.
Poison deals 3 damage; its timer is now 5.
Boss attacks for 8 - 7 = 1 damage!

-- Player turn --
- Player has 1 hit point, 7 armor, 167 mana
- Boss has 9 hit points
Shield's timer is now 0.
Shield wears off, decreasing armor by 7.
Poison deals 3 damage; its timer is now 4.
Player casts Magic Missile, dealing 4 damage.

-- Boss turn --
- Player has 1 hit point, 0 armor, 114 mana
- Boss has 2 hit points
Poison deals 3 damage. This kills the boss, and the player wins.
You start with 50 hit points and 500 mana points. The boss's actual stats are in your puzzle input. What is the least amount of mana you can spend and still win the fight? (Do not include mana recharge effects as "spending" negative mana.)

--- Part Two ---
On the next run through the game, you increase the difficulty to hard.

At the start of each player turn (before any other effects apply), you lose 1 hit point. If this brings you to or below 0 hit points, you lose.

With the same starting stats for you and the boss, what is the least amount of mana you can spend and still win the fight?

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

enum Attack
{
	MAGIC_MISSLE = 1,
	DRAIN,
	SHIELD,
	POISON,
	RECHARGE,
};

struct Player
{
	int mana;
	int hp;
	int shield_timer;
	int poison_timer;
	int recharge_timer;
	int armor;
};

struct Enemy
{
	int damage;
	int hp;
};

struct State
{
	Player player;
	Enemy enemy;
	int mana_spent;
};

struct Compare
{
	bool operator()(State lhs, State rhs)
	{
		return lhs.mana_spent > rhs.mana_spent;
	}
};

typedef priority_queue<State, vector<State>, Compare> Queue;

void load(const char *name, Player &player, Enemy &enemy)
{
	auto file = fopen(name, "rb");
	if (!file)
	{
		printf("Failed to load file: %s\n", strerror(errno));
		exit(1);
	}

	player = {};
	player.mana = 500;
	player.hp = 50;

	enemy = {};
	fscanf(file, "Hit Points: %d\n", &enemy.hp);
	fscanf(file, "Damage: %d\n", &enemy.damage);
	fclose(file);
}

int apply_effects(Player &player, Enemy &enemy, int mana_spent)
{
	if (player.shield_timer > 0)
	{
		player.armor = 7;
		player.shield_timer -= 1;
	}

	if (player.poison_timer > 0)
	{
		enemy.hp -= 3;
		player.poison_timer -= 1;
	}

	if (player.recharge_timer > 0)
	{
		player.mana += 101;
		player.recharge_timer -= 1;
	}
	return (enemy.hp <= 0) ? mana_spent : 0;
}

bool get_attack(Attack attack, Player player, Enemy enemy, int mana_spent, Player &new_player, Enemy &new_enemy, int &new_mana_spent)
{
	new_player = player;
	new_player.armor = 0;
	new_enemy = enemy;
	new_mana_spent = mana_spent;

	auto mana_cost = 0;
	switch (attack)
	{
	case MAGIC_MISSLE:
		mana_cost = 53;
		if (!(player.mana >= mana_cost))
			return false;

		new_enemy.hp -= 4;
		break;

	case DRAIN:
		mana_cost = 73;
		if (!(player.mana >= mana_cost))
			return false;

		new_player.hp += 2;
		break;

	case SHIELD:
		mana_cost = 113;
		if (!(player.mana >= mana_cost && player.shield_timer == 0))
			return false;

		new_player.shield_timer = 6;
		break;

	case POISON:
		mana_cost = 173;
		if (!(player.mana >= mana_cost && player.poison_timer == 0))
			return false;

		new_player.poison_timer = 6;
		break;

	case RECHARGE:
		mana_cost = 229;
		if (!(player.mana >= mana_cost && player.recharge_timer == 0))
			return false;

		new_player.recharge_timer = 5;
		break;

	default:
		abort();
	}

	new_mana_spent += mana_cost;
	new_player.mana -= mana_cost;

	return true;
}

int apply_attack(Attack attack, Player player, Enemy enemy, int mana_spent, Queue &queue)
{
	Player new_player;
	Enemy new_enemy;
	int new_mana_spent;

	if (!get_attack(attack, player, enemy, mana_spent, new_player, new_enemy, new_mana_spent))
		return 0;

	auto value = apply_effects(new_player, new_enemy, new_mana_spent);
	if (value)
		return value;

	new_player.hp -= max(enemy.damage - player.armor, 1);
	if (new_player.hp > 0)
		queue.push(State{ new_player, new_enemy, new_mana_spent });

	return 0;
}

int solve(Player player, Enemy enemy, bool hard)
{
	static const Attack attacks[] = {
		MAGIC_MISSLE, DRAIN, SHIELD, POISON, RECHARGE
	};

	Queue queue;
	queue.push(State{ player, enemy, 0 });
	while (!queue.empty())
	{
		auto state = queue.top();
		auto player = state.player;
		auto enemy = state.enemy;
		auto mana_spent = state.mana_spent;

		queue.pop();

		if (hard)
		{
			player.hp -= 1;
			if (player.hp <= 0)
				continue;
		}

		if (apply_effects(player, enemy, mana_spent))
			break;

		for (auto attack : attacks)
		{
			auto value = apply_attack(attack, player, enemy, mana_spent, queue);
			if (value)
				return value;
		}
	}

	return -1;
}

int main()
{
	Player player;
	Enemy enemy;

	load("22.txt", player, enemy);
	printf("%d\n", solve(player, enemy, false));
	printf("%d\n", solve(player, enemy, true));

	return 0;
}
