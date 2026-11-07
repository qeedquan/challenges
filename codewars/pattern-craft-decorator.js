/*

Your Task
Complete the code so that when a Marine gets a WeaponUpgrade it increases the damage by 1, and if it is a ArmorUpgrade then increase the armor by 1.

You have 3 classes:

Marine: has a damage and an armor properties
MarineWeaponUpgrade and MarineArmorUpgrade: upgrades to apply on marine. Accepts a Marine in the constructor and has the same properties as the Marine

*/

class Marine {
	constructor(_damage, _armor) {
		this._damage = _damage;
		this._armor = _armor;
	}

	get damage() {
		return this._damage;
	}

	set damage(value) {
		this._damage = value;
	}

	get armor() {
		return this._armor;
	}

	set armor(value) {
		this._armor = value;
	}
}

class MarineWeaponUpgrade {
	constructor(marine) {
		this.marine = marine;
	}

	get damage() {
		return this.marine.damage + 1;
	}

	set damage(value) {
		this.marine.damage = value - 1;
	}

	get armor() {
		return this.marine.armor;
	}

	set armor(value) {
		this.marine.armor = value;
	}
}

class MarineArmorUpgrade {
	constructor(marine) {
		this.marine = marine;
	}

	get damage() {
		return this.marine.damage;
	}

	set damage(value) {
		this.marine.damage = value;
	}

	get armor() {
		return this.marine.armor + 1;
	}

	set armor(value) {
		this.marine.armor = value - 1;
	}
}

let marine = new Marine(30, 40);
let weapon = new MarineWeaponUpgrade(marine);
let armor = new MarineArmorUpgrade(marine);
console.log(marine.damage);
console.log(marine.armor);
console.log(weapon.damage);
console.log(weapon.armor);
console.log(armor.damage);
console.log(armor.armor);
