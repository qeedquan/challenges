/*

I'm afraid you're in a rather unfortunate situation. You've injured your leg, and are unable to walk, and a number of zombies are shuffling towards you, intent on eating your brains. Luckily, you're a crack shot, and have your trusty rifle to hand.

The zombies start at range metres, and move at 0.5 metres per second. Each second, you first shoot one zombie, and then the remaining zombies shamble forwards another 0.5 metres.

If any zombies manage to get to 0 metres, you get eaten. If you run out of ammo before shooting all the zombies, you'll also get eaten. To keep things simple, we can ignore any time spent reloading.

Write a function that accepts the total number of zombies, a range in metres, and the number of bullets you have.

If you shoot all the zombies, return "You shot all X zombies." If you get eaten before killing all the zombies, and before running out of ammo, return "You shot X zombies before being eaten: overwhelmed." If you run out of ammo before shooting all the zombies, return "You shot X zombies before being eaten: ran out of ammo."

(If you run out of ammo at the same time as the remaining zombies reach you, return "You shot X zombies before being eaten: overwhelmed.".)

Good luck! (I think you're going to need it.)

*/

import Foundation

func shootout(_ zombies: Int, _ range: Float64, _ ammo: Int) -> String {
    var (zombies, range, ammo, kill) = (zombies, range, ammo, 0)
    while range > 0 && zombies > 0 && ammo > 0 {
        range -= 0.5
        zombies -= 1
        ammo -= 1
        kill += 1
    }

    if zombies < 1 {
        return String(format: "You shot all %d zombies.", kill)
    }
    if range <= 0 {
        return String(format: "You shot %d zombies before being eaten: overwhelmed.", kill)
    }
    return String(format: "You shot %d zombies before being eaten: ran out of ammo.", kill)
}

assert(shootout(3, 10, 10) == "You shot all 3 zombies.")
assert(shootout(100, 8, 200) == "You shot 16 zombies before being eaten: overwhelmed.")
assert(shootout(50, 10, 8) == "You shot 8 zombies before being eaten: ran out of ammo.")
