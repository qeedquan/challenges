/*

Description
In the popular Pokémon games all moves and Pokémons have types that determine how effective certain moves are against certain Pokémons.

These work by some very simple rules, a certain type can be super effective, normal, not very effective or have no effect at all against another type. These translate respectively to 2x, 1x, 0.5x and 0x damage multiplication. If a Pokémon has multiple types the effectiveness of a move against this Pokémon will be the product of the effectiveness of the move to it's types.

Formal Inputs & Outputs
Input
The program should take the type of a move being used and the types of the Pokémon it is being used on.

Example inputs

 fire -> grass
 fighting -> ice rock
 psychic -> poison dark
 water -> normal
 fire -> rock
Output
The program should output the damage multiplier these types lead to.

Example outputs

2x
4x
0x
1x
0.5x
Notes/Hints
Since probably not every dailyprogrammer user is an avid Pokémon player that knows the type effectiveness multipliers by heart here is a Pokémon type chart.

Bonus 1
Use the Pokémon api to calculate the output damage.

Like

http://pokeapi.co/api/v2/type/fire/
returns (skipped the long list)

{
    "name":"fire",
    "generation":{
        "url":"http:\/\/pokeapi.co\/api\/v2\/generation\/1\/",
        "name":"generation-i"
    },
    "damage_relations":{
        "half_damage_from":[
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/7\/",
                "name":"bug"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/9\/",
                "name":"steel"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/10\/",
                "name":"fire"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/12\/",
                "name":"grass"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/15\/",
                "name":"ice"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/18\/",
                "name":"fairy"
            }
        ],
        "no_damage_from":[

        ],
        "half_damage_to":[
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/6\/",
                "name":"rock"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/10\/",
                "name":"fire"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/11\/",
                "name":"water"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/16\/",
                "name":"dragon"
            }
        ],
        "double_damage_from":[
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/5\/",
                "name":"ground"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/6\/",
                "name":"rock"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/11\/",
                "name":"water"
            }
        ],
        "no_damage_to":[

        ],
        "double_damage_to":[
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/7\/",
                "name":"bug"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/9\/",
                "name":"steel"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/12\/",
                "name":"grass"
            },
            {
                "url":"http:\/\/pokeapi.co\/api\/v2\/type\/15\/",
                "name":"ice"
            }
        ]
    },
    "game_indices":[
       ...
    ],
    "move_damage_class":{
        ...
    },
    "moves":[
        ...
    ],
    "pokemon":[
        ...
    ],
    "id":10,
    "names":[
        ...
    ]
    }
If you parse this json, you can calculate the output, instead of hard coding it.

Bonus 2
Deep further into the api and give the multiplier for folowing

fire punch -> bulbasaur
wrap -> onix
surf -> dwegong
side note
the api replaces a space with a hypen (-)

Finally
Special thanks to u/Daanvdk for posting the idea on r/dailyprogrammer_ideas.

If you also have a good idea, don't be afraid to put it over their.

*/

package main

import "strings"

func main() {
	assert(damage("fire", "grass") == 2)
	assert(damage("fighting", "ice rock") == 4)
	assert(damage("psychic", "poison dark") == 0)
	assert(damage("water", "normal") == 1)
	assert(damage("fire", "rock") == 0.5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func damage(attack, defenses string) float64 {
	multipliers := []float64{0, 0.5, 1, 2}

	total := 1.0
	for _, defense := range strings.Split(defenses, " ") {
		index := lookup(attack, defense)
		total *= multipliers[index]
	}
	return total
}

func lookup(attack, defense string) uint64 {
	types := map[string]int{
		"normal":   0,
		"fire":     1,
		"water":    2,
		"electric": 3,
		"grass":    4,
		"ice":      5,
		"fighting": 6,
		"poison":   7,
		"ground":   8,
		"flying":   9,
		"psychic":  10,
		"bug":      11,
		"rock":     12,
		"ghost":    13,
		"dragon":   14,
		"dark":     15,
		"steel":    16,
		"fairy":    17,
	}

	hash := []uint64{
		0xaaaaaa4a696faab6,
		0x6eb66aeae6aad6a3,
		0xaa6a9e69d9e6696d,
		0xafaae6eab995cbda,
		0xae96a5a3bb6b89ea,
		0xea9eeab6a6aaafa6,
		0xa869ae59e9b5bab6,
		0x7baa62aaaaeb9aaa,
		0xaaaaae4aaa6aeb99,
		0x95baaaea79aadaaa,
		0xf600000000000000,
	}

	index0, found0 := types[defense]
	index1, found1 := types[attack]
	if !found0 || !found1 {
		return 0
	}

	index := index1*len(types) + index0
	return (hash[index/32] >> (62 - (2 * (index % 32)))) & 3
}
