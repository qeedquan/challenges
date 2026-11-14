/*

Santa is handing out gifts in the kindergarten. Many toddlers are around there and everyone should have the opportunity to have a seat on Santa's lap. But there's Peter, a 5 year old boy, who is a bit naughty. He tries to get two gifts. After he got the first one, he lines up again in the queue of children.

But fortunately Santa is not alone. His elves keep a list with the names of the children, which already were on Santa's lap. We know, that each child name is unique. If a child tries to get a second gift, the elves will tell Santa.

OK, let's help Santa and his elves with a simple function handOutGift() (hand_out_gift in Ruby, HandOutGift in C# ) which takes the name of the next child. If this child already got a gift, it must throw an error in order to remind Santa.

Example:

handOutGift("Peter");
handOutGift("Alison");
handOutGift("John");
handOutGift("Maria");
handOutGift("Peter"); // <-- must throw an error

*/

class Charity {
    enum GiftError: Error {
        case EXISTS
    }

    var names = [String: Bool]()

    func handout(_ name: String) throws {
        if names[name] != nil {
            throw GiftError.EXISTS
        }
        names[name] = true
    }
}

var charity = Charity()
do {
    try charity.handout("Peter")
    try charity.handout("Alison")
    try charity.handout("John")
    try charity.handout("Maria")
    try charity.handout("Peter")
} catch {
    print("Error: \(error)")
}
print(charity.names)
