/*

.i xu .e'o lo zunsnagri cu drani loka jboge'a

Given an input of a string consisting of two characters, output whether it is a valid consonant cluster in Lojban.

Here is a quote from CLL 3.6 detailing the rules for a valid consonant cluster pair (or rather, an invalid one):

1) It is forbidden for both consonants to be the same, as this would
   violate the rule against double consonants.

2) It is forbidden for one consonant to be voiced and the other unvoiced.
   The consonants “l”, “m”, “n”, and “r” are exempt from this restriction.
   As a result, “bf” is forbidden, and so is “sd”, but both “fl” and “vl”,
   and both “ls” and “lz”, are permitted.

3) It is forbidden for both consonants to be drawn from the set “c”, “j”,
   “s”, “z”.

4) The specific pairs “cx”, “kx”, “xc”, “xk”, and “mz” are forbidden.
The quote references "voiced" and "unvoiced" consonants. Here is a table of the unvoiced consonants and their voiced counterparts (also from CLL 3.6):

UNVOICED    VOICED
   p          b
   t          d
   k          g
   f          v
   c          j
   s          z
   x          -
Note that {x} has no voiced counterpart. For completeness, the remaining consonants that are not on this list (which can be either voiced or unvoiced for the purposes of the quote) are lmnr. (y is a vowel, and the letters hqw are not used.)

The input must be a single string, but you may assume that it will always consist of exactly two consonants, with optional trailing newline if you wish. The output may be any truthy or falsy value.

This is code-golf, so the shortest code in bytes wins.

Test cases (these are all possible input strings placed in the proper categories):

Valid consonant clusters:
 bd bg bj bl bm bn br bv bz cf ck cl cm cn cp cr ct db dg dj dl dm dn dr dv
 dz fc fk fl fm fn fp fr fs ft fx gb gd gj gl gm gn gr gv gz jb jd jg jl jm
 jn jr jv kc kf kl km kn kp kr ks kt lb lc ld lf lg lj lk lm ln lp lr ls lt
 lv lx lz mb mc md mf mg mj mk ml mn mp mr ms mt mv mx nb nc nd nf ng nj nk
 nl nm np nr ns nt nv nx nz pc pf pk pl pm pn pr ps pt px rb rc rd rf rg rj
 rk rl rm rn rp rs rt rv rx rz sf sk sl sm sn sp sr st sx tc tf tk tl tm tn
 tp tr ts tx vb vd vg vj vl vm vn vr vz xf xl xm xn xp xr xs xt zb zd zg zl
 zm zn zr zv

Invalid consonant clusters:
 bb bc bf bk bp bs bt bx cb cc cd cg cj cs cv cx cz dc dd df dk dp ds dt dx
 fb fd ff fg fj fv fz gc gf gg gk gp gs gt gx jc jf jj jk jp js jt jx jz kb
 kd kg kj kk kv kx kz ll mm mz nn pb pd pg pj pp pv pz rr sb sc sd sg sj ss
 sv sz tb td tg tj tt tv tz vc vf vk vp vs vt vv vx xb xc xd xg xj xk xv xx
 xz zc zf zj zk zp zs zt zx zz

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
valid(const char *s)
{
	static const char cluster[] = "bd bg bj bl bm bn br bv bz cf ck cl cm cn cp cr ct db dg dj dl dm dn dr dv dz fc fk fl fm fn fp fr fs ft fx gb gd gj gl gm gn gr gv gz jb jd jg jl jm jn jr jv kc kf kl km kn kp kr ks kt lb lc ld lf lg lj lk lm ln lp lr ls lt lv lx lz mb mc md mf mg mj mk ml mn mp mr ms mt mv mx nb nc nd nf ng nj nk nl nm np nr ns nt nv nx nz pc pf pk pl pm pn pr ps pt px rb rc rd rf rg rj rk rl rm rn rp rs rt rv rx rz sf sk sl sm sn sp sr st sx tc tf tk tl tm tn tp tr ts tx vb vd vg vj vl vm vn vr vz xf xl xm xn xp xr xs xt zb zd zg zl zm zn zr zv";

	if (!isalpha(s[0]) || !isalpha(s[1]) || s[2])
		return false;
	return strstr(cluster, s) != NULL;
}

int
main(void)
{
	assert(valid("mr") == true);
	assert(valid("zx") == false);
	assert(valid("poe") == false);
	assert(valid("") == false);

	return 0;
}
