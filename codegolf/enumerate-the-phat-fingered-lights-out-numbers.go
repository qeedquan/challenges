/*

Even though the concept of phat-fingered-lights-out number should be pretty self-explanatory here is a definition:

Given a nonnegative integer in binary representation a phat-fingered double-bit-flip or phatflip for short replaces a pair of adjacent, equal bits with their complement.

For example given the number 0b111010010000101

0b111010010000101 -> 0b100010010000101

0b111010010000101 -> 0b111011110000101

0b111010010000101 -> 0b1010010000101

are phatflips whereas

0b111010010000101 -> 0b111000000000101 (not adjacent)

0b111010010000101 -> 0b111010001000101 (not equal)

0b111010010000101 -> 0b111010010111101 (not a pair)

are not.

A phat-fingered-lights-out number (or "pflon") is a nonnegative integer that can be completely erased by a finite sequence of phatflips.

The first 1000 pflons are:

0, 3, 6, 9, 12, 15, 18, 24, 27, 30, 33, 36, 39, 45, 48, 51, 54, 57, 60, 63, 66, 72, 75, 78, 90, 96, 99, 102, 105, 108, 111, 114, 120, 123, 126, 129, 132, 135, 141, 144, 147, 150, 153, 156, 159, 165, 177, 180, 183, 189, 192, 195, 198, 201, 204, 207, 210, 216, 219, 222, 225, 228, 231, 237, 240, 243, 246, 249, 252, 255, 258, 264, 267, 270, 282, 288, 291, 294, 297, 300, 303, 306, 312, 315, 318, 330, 354, 360, 363, 366, 378, 384, 387, 390, 393, 396, 399, 402, 408, 411, 414, 417, 420, 423, 429, 432, 435, 438, 441, 444, 447, 450, 456, 459, 462, 474, 480, 483, 486, 489, 492, 495, 498, 504, 507, 510, 513, 516, 519, 525, 528, 531, 534, 537, 540, 543, 549, 561, 564, 567, 573, 576, 579, 582, 585, 588, 591, 594, 600, 603, 606, 609, 612, 615, 621, 624, 627, 630, 633, 636, 639, 645, 657, 660, 663, 669, 693, 705, 708, 711, 717, 720, 723, 726, 729, 732, 735, 741, 753, 756, 759, 765, 768, 771, 774, 777, 780, 783, 786, 792, 795, 798, 801, 804, 807, 813, 816, 819, 822, 825, 828, 831, 834, 840, 843, 846, 858, 864, 867, 870, 873, 876, 879, 882, 888, 891, 894, 897, 900, 903, 909, 912, 915, 918, 921, 924, 927, 933, 945, 948, 951, 957, 960, 963, 966, 969, 972, 975, 978, 984, 987, 990, 993, 996, 999, 1005, 1008, 1011, 1014, 1017, 1020, 1023, 1026, 1032, 1035, 1038, 1050, 1056, 1059, 1062, 1065, 1068, 1071, 1074, 1080, 1083, 1086, 1098, 1122, 1128, 1131, 1134, 1146, 1152, 1155, 1158, 1161, 1164, 1167, 1170, 1176, 1179, 1182, 1185, 1188, 1191, 1197, 1200, 1203, 1206, 1209, 1212, 1215, 1218, 1224, 1227, 1230, 1242, 1248, 1251, 1254, 1257, 1260, 1263, 1266, 1272, 1275, 1278, 1290, 1314, 1320, 1323, 1326, 1338, 1386, 1410, 1416, 1419, 1422, 1434, 1440, 1443, 1446, 1449, 1452, 1455, 1458, 1464, 1467, 1470, 1482, 1506, 1512, 1515, 1518, 1530, 1536, 1539, 1542, 1545, 1548, 1551, 1554, 1560, 1563, 1566, 1569, 1572, 1575, 1581, 1584, 1587, 1590, 1593, 1596, 1599, 1602, 1608, 1611, 1614, 1626, 1632, 1635, 1638, 1641, 1644, 1647, 1650, 1656, 1659, 1662, 1665, 1668, 1671, 1677, 1680, 1683, 1686, 1689, 1692, 1695, 1701, 1713, 1716, 1719, 1725, 1728, 1731, 1734, 1737, 1740, 1743, 1746, 1752, 1755, 1758, 1761, 1764, 1767, 1773, 1776, 1779, 1782, 1785, 1788, 1791, 1794, 1800, 1803, 1806, 1818, 1824, 1827, 1830, 1833, 1836, 1839, 1842, 1848, 1851, 1854, 1866, 1890, 1896, 1899, 1902, 1914, 1920, 1923, 1926, 1929, 1932, 1935, 1938, 1944, 1947, 1950, 1953, 1956, 1959, 1965, 1968, 1971, 1974, 1977, 1980, 1983, 1986, 1992, 1995, 1998, 2010, 2016, 2019, 2022, 2025, 2028, 2031, 2034, 2040, 2043, 2046, 2049, 2052, 2055, 2061, 2064, 2067, 2070, 2073, 2076, 2079, 2085, 2097, 2100, 2103, 2109, 2112, 2115, 2118, 2121, 2124, 2127, 2130, 2136, 2139, 2142, 2145, 2148, 2151, 2157, 2160, 2163, 2166, 2169, 2172, 2175, 2181, 2193, 2196, 2199, 2205, 2229, 2241, 2244, 2247, 2253, 2256, 2259, 2262, 2265, 2268, 2271, 2277, 2289, 2292, 2295, 2301, 2304, 2307, 2310, 2313, 2316, 2319, 2322, 2328, 2331, 2334, 2337, 2340, 2343, 2349, 2352, 2355, 2358, 2361, 2364, 2367, 2370, 2376, 2379, 2382, 2394, 2400, 2403, 2406, 2409, 2412, 2415, 2418, 2424, 2427, 2430, 2433, 2436, 2439, 2445, 2448, 2451, 2454, 2457, 2460, 2463, 2469, 2481, 2484, 2487, 2493, 2496, 2499, 2502, 2505, 2508, 2511, 2514, 2520, 2523, 2526, 2529, 2532, 2535, 2541, 2544, 2547, 2550, 2553, 2556, 2559, 2565, 2577, 2580, 2583, 2589, 2613, 2625, 2628, 2631, 2637, 2640, 2643, 2646, 2649, 2652, 2655, 2661, 2673, 2676, 2679, 2685, 2709, 2757, 2769, 2772, 2775, 2781, 2805, 2817, 2820, 2823, 2829, 2832, 2835, 2838, 2841, 2844, 2847, 2853, 2865, 2868, 2871, 2877, 2880, 2883, 2886, 2889, 2892, 2895, 2898, 2904, 2907, 2910, 2913, 2916, 2919, 2925, 2928, 2931, 2934, 2937, 2940, 2943, 2949, 2961, 2964, 2967, 2973, 2997, 3009, 3012, 3015, 3021, 3024, 3027, 3030, 3033, 3036, 3039, 3045, 3057, 3060, 3063, 3069, 3072, 3075, 3078, 3081, 3084, 3087, 3090, 3096, 3099, 3102, 3105, 3108, 3111, 3117, 3120, 3123, 3126, 3129, 3132, 3135, 3138, 3144, 3147, 3150, 3162, 3168, 3171, 3174, 3177, 3180, 3183, 3186, 3192, 3195, 3198, 3201, 3204, 3207, 3213, 3216, 3219, 3222, 3225, 3228, 3231, 3237, 3249, 3252, 3255, 3261, 3264, 3267, 3270, 3273, 3276, 3279, 3282, 3288, 3291, 3294, 3297, 3300, 3303, 3309, 3312, 3315, 3318, 3321, 3324, 3327, 3330, 3336, 3339, 3342, 3354, 3360, 3363, 3366, 3369, 3372, 3375, 3378, 3384, 3387, 3390, 3402, 3426, 3432, 3435, 3438, 3450, 3456, 3459, 3462, 3465, 3468, 3471, 3474, 3480, 3483, 3486, 3489, 3492, 3495, 3501, 3504, 3507, 3510, 3513, 3516, 3519, 3522, 3528, 3531, 3534, 3546, 3552, 3555, 3558, 3561, 3564, 3567, 3570, 3576, 3579, 3582, 3585, 3588, 3591, 3597, 3600, 3603, 3606, 3609, 3612, 3615, 3621, 3633, 3636, 3639, 3645, 3648, 3651, 3654, 3657, 3660, 3663, 3666, 3672, 3675, 3678, 3681, 3684, 3687, 3693, 3696, 3699, 3702, 3705, 3708, 3711, 3717, 3729, 3732, 3735, 3741, 3765, 3777, 3780, 3783, 3789, 3792, 3795, 3798, 3801, 3804, 3807, 3813, 3825, 3828, 3831, 3837, 3840, 3843, 3846, 3849, 3852, 3855, 3858, 3864, 3867, 3870, 3873, 3876, 3879, 3885, 3888, 3891, 3894, 3897, 3900, 3903, 3906, 3912, 3915, 3918, 3930, 3936, 3939, 3942, 3945, 3948, 3951, 3954, 3960, 3963, 3966, 3969, 3972, 3975, 3981, 3984, 3987, 3990, 3993, 3996, 3999, 4005, 4017, 4020, 4023, 4029, 4032, 4035, 4038, 4041, 4044, 4047, 4050, 4056, 4059, 4062, 4065, 4068, 4071, 4077, 4080, 4083, 4086, 4089, 4092, 4095, 4098, 4104, 4107, 4110, 4122, 4128, 4131, 4134, 4137, 4140, 4143, 4146, 4152, 4155, 4158, 4170, 4194, 4200, 4203, 4206, 4218, 4224, 4227, 4230, 4233, 4236, 4239, 4242, 4248, 4251, 4254, 4257, 4260, 4263, 4269, 4272, 4275, 4278, 4281, 4284, 4287, 4290, 4296, 4299, 4302, 4314, 4320, 4323, 4326, 4329, 4332, 4335, 4338, 4344, 4347, 4350, 4362, 4386, 4392, 4395, 4398, 4410, 4458, 4482, 4488, 4491, 4494, 4506, 4512, 4515, 4518, 4521, 4524, 4527, 4530, 4536

This is code-golf and asequence challenge; standard rules apply:

shortest code in bytes (full program or function) wins; each language or major language version is their own competition
you can either take a number n and return the n-th pflon or the first n pflons; counting can be 0- or 1-based
or you can take no input and output the sequence til kingdom come
Note: The main idea for this challenge is not mine. I'll give proper credit in a few days.

*/

package main

import (
	"math"
	"slices"
	"strconv"
	"strings"
)

func main() {
	tab := []int64{0, 3, 6, 9, 12, 15, 18, 24, 27, 30, 33, 36, 39, 45, 48, 51, 54, 57, 60, 63, 66, 72, 75, 78, 90, 96, 99, 102, 105, 108, 111, 114, 120, 123, 126, 129, 132, 135, 141, 144, 147, 150, 153, 156, 159, 165, 177, 180, 183, 189, 192, 195, 198, 201, 204, 207, 210, 216, 219, 222, 225, 228, 231, 237, 240, 243, 246, 249, 252, 255, 258, 264, 267, 270, 282, 288, 291, 294, 297, 300, 303, 306, 312, 315, 318, 330, 354, 360, 363, 366, 378, 384, 387, 390, 393, 396, 399, 402, 408, 411, 414, 417, 420, 423, 429, 432, 435, 438, 441, 444, 447, 450, 456, 459, 462, 474, 480, 483, 486, 489, 492, 495, 498, 504, 507, 510, 513, 516, 519, 525, 528, 531, 534, 537, 540, 543, 549, 561, 564, 567, 573, 576, 579, 582, 585, 588, 591, 594, 600, 603, 606, 609, 612, 615, 621, 624, 627, 630, 633, 636, 639, 645, 657, 660, 663, 669, 693, 705, 708, 711, 717, 720, 723, 726, 729, 732, 735, 741, 753, 756, 759, 765, 768, 771, 774, 777, 780, 783, 786, 792, 795, 798, 801, 804, 807, 813, 816, 819, 822, 825, 828, 831, 834, 840, 843, 846, 858, 864, 867, 870, 873, 876, 879, 882, 888, 891, 894, 897, 900, 903, 909, 912, 915, 918, 921, 924, 927, 933, 945, 948, 951, 957, 960, 963, 966, 969, 972, 975, 978, 984, 987, 990, 993, 996, 999, 1005, 1008, 1011, 1014, 1017, 1020, 1023, 1026, 1032, 1035, 1038, 1050, 1056, 1059, 1062, 1065, 1068, 1071, 1074, 1080, 1083, 1086, 1098, 1122, 1128, 1131, 1134, 1146, 1152, 1155, 1158, 1161, 1164, 1167, 1170, 1176, 1179, 1182, 1185, 1188, 1191, 1197, 1200, 1203, 1206, 1209, 1212, 1215, 1218, 1224, 1227, 1230, 1242, 1248, 1251, 1254, 1257, 1260, 1263, 1266, 1272, 1275, 1278, 1290, 1314, 1320, 1323, 1326, 1338, 1386, 1410, 1416, 1419, 1422, 1434, 1440, 1443, 1446, 1449, 1452, 1455, 1458, 1464, 1467, 1470, 1482, 1506, 1512, 1515, 1518, 1530, 1536, 1539, 1542, 1545, 1548, 1551, 1554, 1560, 1563, 1566, 1569, 1572, 1575, 1581, 1584, 1587, 1590, 1593, 1596, 1599, 1602, 1608, 1611, 1614, 1626, 1632, 1635, 1638, 1641, 1644, 1647, 1650, 1656, 1659, 1662, 1665, 1668, 1671, 1677, 1680, 1683, 1686, 1689, 1692, 1695, 1701, 1713, 1716, 1719, 1725, 1728, 1731, 1734, 1737, 1740, 1743, 1746, 1752, 1755, 1758, 1761, 1764, 1767, 1773, 1776, 1779, 1782, 1785, 1788, 1791, 1794, 1800, 1803, 1806, 1818, 1824, 1827, 1830, 1833, 1836, 1839, 1842, 1848, 1851, 1854, 1866, 1890, 1896, 1899, 1902, 1914, 1920, 1923, 1926, 1929, 1932, 1935, 1938, 1944, 1947, 1950, 1953, 1956, 1959, 1965, 1968, 1971, 1974, 1977, 1980, 1983, 1986, 1992, 1995, 1998, 2010, 2016, 2019, 2022, 2025, 2028, 2031, 2034, 2040, 2043, 2046, 2049, 2052, 2055, 2061, 2064, 2067, 2070, 2073, 2076, 2079, 2085, 2097, 2100, 2103, 2109, 2112, 2115, 2118, 2121, 2124, 2127, 2130, 2136, 2139, 2142, 2145, 2148, 2151, 2157, 2160, 2163, 2166, 2169, 2172, 2175, 2181, 2193, 2196, 2199, 2205, 2229, 2241, 2244, 2247, 2253, 2256, 2259, 2262, 2265, 2268, 2271, 2277, 2289, 2292, 2295, 2301, 2304, 2307, 2310, 2313, 2316, 2319, 2322, 2328, 2331, 2334, 2337, 2340, 2343, 2349, 2352, 2355, 2358, 2361, 2364, 2367, 2370, 2376, 2379, 2382, 2394, 2400, 2403, 2406, 2409, 2412, 2415, 2418, 2424, 2427, 2430, 2433, 2436, 2439, 2445, 2448, 2451, 2454, 2457, 2460, 2463, 2469, 2481, 2484, 2487, 2493, 2496, 2499, 2502, 2505, 2508, 2511, 2514, 2520, 2523, 2526, 2529, 2532, 2535, 2541, 2544, 2547, 2550, 2553, 2556, 2559, 2565, 2577, 2580, 2583, 2589, 2613, 2625, 2628, 2631, 2637, 2640, 2643, 2646, 2649, 2652, 2655, 2661, 2673, 2676, 2679, 2685, 2709, 2757, 2769, 2772, 2775, 2781, 2805, 2817, 2820, 2823, 2829, 2832, 2835, 2838, 2841, 2844, 2847, 2853, 2865, 2868, 2871, 2877, 2880, 2883, 2886, 2889, 2892, 2895, 2898, 2904, 2907, 2910, 2913, 2916, 2919, 2925, 2928, 2931, 2934, 2937, 2940, 2943, 2949, 2961, 2964, 2967, 2973, 2997, 3009, 3012, 3015, 3021, 3024, 3027, 3030, 3033, 3036, 3039, 3045, 3057, 3060, 3063, 3069, 3072, 3075, 3078, 3081, 3084, 3087, 3090, 3096, 3099, 3102, 3105, 3108, 3111, 3117, 3120, 3123, 3126, 3129, 3132, 3135, 3138, 3144, 3147, 3150, 3162, 3168, 3171, 3174, 3177, 3180, 3183, 3186, 3192, 3195, 3198, 3201, 3204, 3207, 3213, 3216, 3219, 3222, 3225, 3228, 3231, 3237, 3249, 3252, 3255, 3261, 3264, 3267, 3270, 3273, 3276, 3279, 3282, 3288, 3291, 3294, 3297, 3300, 3303, 3309, 3312, 3315, 3318, 3321, 3324, 3327, 3330, 3336, 3339, 3342, 3354, 3360, 3363, 3366, 3369, 3372, 3375, 3378, 3384, 3387, 3390, 3402, 3426, 3432, 3435, 3438, 3450, 3456, 3459, 3462, 3465, 3468, 3471, 3474, 3480, 3483, 3486, 3489, 3492, 3495, 3501, 3504, 3507, 3510, 3513, 3516, 3519, 3522, 3528, 3531, 3534, 3546, 3552, 3555, 3558, 3561, 3564, 3567, 3570, 3576, 3579, 3582, 3585, 3588, 3591, 3597, 3600, 3603, 3606, 3609, 3612, 3615, 3621, 3633, 3636, 3639, 3645, 3648, 3651, 3654, 3657, 3660, 3663, 3666, 3672, 3675, 3678, 3681, 3684, 3687, 3693, 3696, 3699, 3702, 3705, 3708, 3711, 3717, 3729, 3732, 3735, 3741, 3765, 3777, 3780, 3783, 3789, 3792, 3795, 3798, 3801, 3804, 3807, 3813, 3825, 3828, 3831, 3837, 3840, 3843, 3846, 3849, 3852, 3855, 3858, 3864, 3867, 3870, 3873, 3876, 3879, 3885, 3888, 3891, 3894, 3897, 3900, 3903, 3906, 3912, 3915, 3918, 3930, 3936, 3939, 3942, 3945, 3948, 3951, 3954, 3960, 3963, 3966, 3969, 3972, 3975, 3981, 3984, 3987, 3990, 3993, 3996, 3999, 4005, 4017, 4020, 4023, 4029, 4032, 4035, 4038, 4041, 4044, 4047, 4050, 4056, 4059, 4062, 4065, 4068, 4071, 4077, 4080, 4083, 4086, 4089, 4092, 4095, 4098, 4104, 4107, 4110, 4122, 4128, 4131, 4134, 4137, 4140, 4143, 4146, 4152, 4155, 4158, 4170, 4194, 4200, 4203, 4206, 4218, 4224, 4227, 4230, 4233, 4236, 4239, 4242, 4248, 4251, 4254, 4257, 4260, 4263, 4269, 4272, 4275, 4278, 4281, 4284, 4287, 4290, 4296, 4299, 4302, 4314, 4320, 4323, 4326, 4329, 4332, 4335, 4338, 4344, 4347, 4350, 4362, 4386, 4392, 4395, 4398, 4410, 4458, 4482, 4488, 4491, 4494, 4506, 4512, 4515, 4518, 4521, 4524, 4527, 4530, 4536}

	assert(slices.Equal(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A039004
func phat(n int64) bool {
	s := strconv.FormatInt(n, 4)
	return strings.Count(s, "1") == strings.Count(s, "2")
}

func gen(n int) []int64 {
	r := []int64{}
	for i := int64(0); len(r) < n && i < math.MaxInt64; i++ {
		if phat(i) {
			r = append(r, i)
		}
	}
	return r
}