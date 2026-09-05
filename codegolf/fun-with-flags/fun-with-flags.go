/*

Write a full program with a source code of 256 bytes or less that looks at an image of a flag and determines what country that flag is from. A zip file containing the 196 different flags in the challenge can be downloaded from here. Source: [Flagpedia]. These 196 flag images are the only inputs your program has to handle.

Your program will take no input. The flag image will be in the same directory as your program and named "f.png". Your program will open this file, identify it, and print the two letter abbreviation for that country. If you use a language that can't open files, it's also acceptable to run your program as ./program < f.png.

Each flag file is named the same as the expected output. All output above 2 letters will be ignored.

Here is a list of all the outputs/filenames:

ad, ae, af, ag, al, am, ao, ar, at, au, az, ba, bb, bd, be, bf, bg, bh, bi, bj,
bn, bo, br, bs, bt, bw, by, bz, ca, cd, cf, cg, ch, ci, cl, cm, cn, co, cr, cu,
cv, cy, cz, de, dj, dk, dm, do, dz, ec, ee, eg, eh, er, es, et, fi, fj, fm, fr,
ga, gb, gd, ge, gh, gm, gn, gq, gr, gt, gw, gy, hn, hr, ht, hu, id, ie, il, in,
iq, ir, is, it, jm, jo, jp, ke, kg, kh, ki, km, kn, kp, kr, ks, kw, kz, la, lb,
lc, li, lk, lr, ls, lt, lu, lv, ly, ma, mc, md, me, mg, mh, mk, ml, mm, mn, mr,
mt, mu, mv, mw, mx, my, mz, na, ne, ng, ni, nl, no, np, nr, nz, om, pa, pe, pg,
ph, pk, pl, pt, pw, py, qa, ro, rs, ru, rw, sa, sb, sc, sd, se, sg, si, sk, sl,
sm, sn, so, sr, st, sv, sy, sz, td, tg, th, tj, tl, tm, tn, to, tr, tt, tv, tw,
tz, ua, ug, us, uy, uz, va, vc, ve, vn, vu, ws, ye, za, zm, zw,
Scoring
Here is a short python script that I will use to score each submission.

import os
import subprocess
import random

botlist = []
with open("bots.txt") as bots:
    for line in bots:
        line = line.split(", ")
        if len(line) >= 2:
            botLine = line + [0]
            botlist.append(botLine)

files = os.listdir(os.getcwd() + "/flags")
random.shuffle(files)

def test(bot_command):
    score = 0
    for filename in files:
        command = "COPY flags\\{} f.png".format(filename)
        os.system(command)

        print bot_command

        result = subprocess.check_output(bot_command, shell = True)
        if result[:2] == filename[:2]:
            score += 1

    return score

for i in range(len(botlist)):
    command = botlist[i][1]
    botlist[i][2] = test(command)

with open("output.txt", "w+") as output:
    for bot in botlist:
        output.write("{} got a score of {}.".format(bot[0], bot[2]))

os.system("del f.png")
Your score is the total number of flags correctly identified. In case of a tie, the earlier submission wins.

Rules
For my testing convenience, any language with a freely available interpreter/compiler for Windows 10 or Ubuntu can be used.

Image processing libraries are allowed, but any builtins related to flags or countries are not allowed. (cough Mathematica cough)

Please provide the full command needed to run your program along with links to any necessary libraries.

Submissions may not interact with any file except "f.png".

I don't have any hard time-limit on submissions, but please keep it relatively quick. I don't want the scoring script to take hours.

*/

package main

import (
	"crypto/sha512"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"path/filepath"
	"strings"
)

var (
	download = flag.Bool("d", false, "download flag dataset")
)

func main() {
	flag.Usage = usage
	flag.Parse()

	if *download {
		check(getflags())
		return
	}

	if flag.NArg() < 1 {
		usage()
	}

	db, err := gendb("flags")
	check(err)

	sum, err := checksum(flag.Arg(0))
	id := db[sum]
	if id == "" {
		id = "unknown"
	}
	fmt.Println(id)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <file>")
	flag.PrintDefaults()
	os.Exit(2)
}

func gendb(path string) (map[[sha512.Size]byte]string, error) {
	pattern := filepath.Join(path, "*.png")
	matches, err := filepath.Glob(pattern)
	if err != nil {
		return nil, err
	}

	db := make(map[[sha512.Size]byte]string)
	for _, name := range matches {
		base := filepath.Base(name)
		ext := filepath.Ext(name)
		id := base[:len(base)-len(ext)]

		sum, err := checksum(name)
		if err != nil {
			return nil, err
		}

		db[sum] = id
	}
	return db, nil
}

func checksum(name string) (sum [sha512.Size]byte, err error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return
	}

	sum = sha512.Sum512(data)
	return
}

func getflags() error {
	for _, code := range strings.Split(CODES, ",") {
		code = strings.TrimSpace(code)
		name := fmt.Sprintf("%s.png", code)
		url := fmt.Sprintf("https://flagcdn.com/h20/%s", name)

		fmt.Println("Downloading", url)

		resp, err := http.Get(url)
		if err != nil {
			return err
		}

		data, err := io.ReadAll(resp.Body)
		if err != nil {
			return err
		}

		err = os.WriteFile(name, data, 0644)
		if err != nil {
			return err
		}
	}
	return nil
}

const CODES = `ad, ae, af, ag, al, am, ao, ar, at, au, az, ba, bb, bd, be, bf, bg, bh, bi, bj,
bn, bo, br, bs, bt, bw, by, bz, ca, cd, cf, cg, ch, ci, cl, cm, cn, co, cr, cu,
cv, cy, cz, de, dj, dk, dm, do, dz, ec, ee, eg, eh, er, es, et, fi, fj, fm, fr,
ga, gb, gd, ge, gh, gm, gn, gq, gr, gt, gw, gy, hn, hr, ht, hu, id, ie, il, in,
iq, ir, is, it, jm, jo, jp, ke, kg, kh, ki, km, kn, kp, kr, ks, kw, kz, la, lb,
lc, li, lk, lr, ls, lt, lu, lv, ly, ma, mc, md, me, mg, mh, mk, ml, mm, mn, mr,
mt, mu, mv, mw, mx, my, mz, na, ne, ng, ni, nl, no, np, nr, nz, om, pa, pe, pg,
ph, pk, pl, pt, pw, py, qa, ro, rs, ru, rw, sa, sb, sc, sd, se, sg, si, sk, sl,
sm, sn, so, sr, st, sv, sy, sz, td, tg, th, tj, tl, tm, tn, to, tr, tt, tv, tw,
tz, ua, ug, us, uy, uz, va, vc, ve, vn, vu, ws, ye, za, zm, zw
`
