/*

Here it is:

^(?:(?:(?:(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?:(?:\.|:|,)(\d+(?:\.\d+)?)?)?)?(?:,|,(?:(?:(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?:(?:\.|:|,)(\d+(?:\.\d+)?)?)?)?$
What am I doing:

Matching any ranged timestamp (HH:MM:SS:MS,HH:MM:SS:MS) with a few "leniences"

Any length digits - we do NOT need restrictions to strict 24 hr, 59 min / sec, \d{1,9} milliseconds. I do automatic conversions for this and shift in my code allowing lenience
Likewise, I'm not strict on requiring the : as the delimiter. It can be one of: : OR , OR . OR |
Similarly, they don't NEED to strictly put digits into any specific slot. They can be blank. :MM:SS:MS, HH::SS:MS, etc in all combinatorial possibilites
Yes, I know that I COULD do simple string replacement / injections given how markedly repetitive this is. Thing is, in most coding languages G-Zip compresses better w/o this.

So, that's it.

I need:

Each capture group (HH:MM:SS:MS) for EACH range. I am mapping these from captured groups -> milliseconds conversion -> human readable time (e.g. - 4 hours, 15 minutes, 30 seconds, 4234 milliseconds, 300 nanoseconds, ...)

Language: JavaScript

*/

package main

import "regexp"

/*

@guest4308

lessons that can be learned:
in general, regex tends to be simpler than you think it is. often, if you're thinking of including a non-capturing group, it's easier to just get rid of the group altogether;
non-capturing groups don't increase the 'power' of a regex at all (ie, there is no pattern a non-capturing group lets you capture that you couldn't have already matched without it).
also, you should only use | alternation for exact strings; [] character classes are much easier to use for individual characters.
additionally, alternation can be very slow in terms of big-O if you have * or + counts on the individual elements.
finally, if you're using ? for a group, rethink about why you want that group in the first place.
it's often easier to read a regex with less groups where each element has its count directly following it and allowing groups to match without a specified count.

*/

func main() {
	regexp.MustCompile(`^(?:(?:(?:(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?:(?:\.|:|,)(\d+(?:\.\d+)?)?)?)?(?:,|,(?:(?:(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?::|\.|,))?(\d+(?:\.\d+)?)?(?:(?:\.|:|,)(\d+(?:\.\d+)?)?)?)?$`)
	regexp.MustCompile(`^(\d*)[:|,.](\d*)[:|,.](\d*)[:|,.](\d*)$`)
}
