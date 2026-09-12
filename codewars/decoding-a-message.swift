/*

You have managed to intercept an important message and you are trying to read it.

You realise that the message has been encoded and can be decoded by switching each letter with a corresponding letter.

You also notice that each letter is paired with the letter that it coincides with when the alphabet is reversed.

For example: "a" is encoded with "z", "b" with "y", "c" with "x", etc

You read the first sentence:

"r slkv mlylwb wvxlwvh gsrh nvhhztv"

After a few minutes you manage to decode it:

"i hope nobody decodes this message"

Create a function that will instantly decode any of these messages

You can assume no punctuation or capitals, only lower case letters, but remember spaces!

*/

func decode(_ string: String) -> String {
    var result = ""
    for symbol in string {
        if "a" <= symbol && symbol <= "z" {
            result += String(UnicodeScalar(219 - symbol.asciiValue!))
        } else {
            result += String(symbol)
        }
    }
    return result
}

assert(decode("r slkv mlylwb wvxlwvh gsrh nvhhztv") == "i hope nobody decodes this message")
assert(decode("sr") == "hi")
assert(decode("svool") == "hello")
assert(decode("r slkv mlylwb wvxlwvh gsrh nvhhztv") == "i hope nobody decodes this message")
assert(decode("qzezxirkg rh z srts ovevo wbmznrx fmgbkvw zmw rmgvikivgvw kiltiznnrmt ozmtfztv rg szh yvvm hgzmwziwravw rm gsv vxnzxirkg ozmtfztv hkvxrurxzgrlm zolmthrwv sgno zmw xhh rg rh lmv lu gsv gsivv vhhvmgrzo gvxsmloltrvh lu dliow drwv dvy xlmgvmg kilwfxgrlm gsv nzqlirgb lu dvyhrgvh vnkolb rg zmw rg rh hfkkligvw yb zoo nlwvim dvy yildhvih drgslfg koftrmh") == "javacript is a high level dynamic untyped and interpreted programming language it has been standardized in the ecmacript language specification alongside html and css it is one of the three essential technologies of world wide web content production the majority of websites employ it and it is supported by all modern web browsers without plugins")
assert(decode("gsv vrtsgs hbnkslmb dzh qvzm hryvorfh urmzo nzqli xlnklhrgrlmzo kilqvxg lxxfkbrmt srn rmgvinrggvmgob") == "the eighth symphony was jean sibelius final major compositional project occupying him intermittently")
assert(decode("husbands ask repeated resolved but laughter debating") == "sfhyzmwh zhp ivkvzgvw ivhloevw yfg ozftsgvi wvyzgrmt")
assert(decode("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")
assert(decode(" ") == " ")
assert(decode("") == "")
assert(decode("thelastrandomsentence") == "gsvozhgizmwlnhvmgvmxv")
