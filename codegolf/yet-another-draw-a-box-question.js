/*


The following problem is a common interview question, thus dull answers are discouraged. Go short or creative, best if both:

Create the following pattern

###########
##       ##
# #     # #
#  #   #  #
#   # #   #
#    #    #
#   # #   #
#  #   #  #
# #     # #
##       ##
###########

In case you cry "dupe", I see your point but this is a slight variation and I hope it differs enough to be greenlit.

*/

function box() {
	let n = 11;
	for (let y = 0; y < n; y++) {
		for (let x = 0; x < n; x++) {
			let c = ' ';
			if (x == 0 || x == n-1 || y == 0 || y == n-1 || x == y || x == n-y-1)
				c = '#';
			process.stdout.write(c);
		}
		console.log();
	}
}

function main() {
	box();
}

box();
