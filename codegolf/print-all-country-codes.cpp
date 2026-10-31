/*

ISO 3166-1 is the standard that defines all the country codes. The well-known two-letter codes (US, GB, JP, etc.) are called Alpha-2 codes.

With two letters, there are only 262 = 676 possible codes, which can be nicely arranged in a grid. This table can be useful as an overview, to see which codes are actually in use, reserved, etc.

This challenge is simple: you're to print all assigned codes of this grid to STDOUT, using plain ASCII, exactly as shown below:

AA    AC AD AE AF AG    AI       AL AM AN AO AP AQ AR AS AT AU    AW AX    AZ
BA BB    BD BE BF BG BH BI BJ    BL BM BN BO    BQ BR BS BT BU BV BW BX BY BZ
CA    CC CD    CF CG CH CI    CK CL CM CN CO CP    CR CS    CU CV CW CX CY CZ
            DE    DG       DJ DK    DM    DO                            DY DZ
EA    EC    EE EF EG EH             EM       EP    ER ES ET EU EV EW         
                        FI FJ FK FL FM    FO       FR                FX      
GA GB GC GD GE GF GG GH GI       GL GM GN    GP GQ GR GS GT GU    GW    GY   
                              HK    HM HN          HR    HT HU               
   IB IC ID IE                   IL IM IN IO    IQ IR IS IT IU IV IW IX IY IZ
JA          JE                      JM    JO JP                              
            KE    KG KH KI          KM KN    KP    KR             KW    KY KZ
LA LB LC       LF       LI    LK                   LR LS LT LU LV       LY   
MA    MC MD ME MF MG MH       MK ML MM MN MO MP MQ MR MS MT MU MV MW MX MY MZ
NA    NC    NE NF NG    NI       NL       NO NP    NR    NT NU             NZ
OA                                  OM                                       
PA          PE PF PG PH PI    PK PL PM PN          PR PS PT       PW    PY   
QA                                  QM QN QO QP QQ QR QS QT QU QV QW QX QY QZ
RA RB RC    RE       RH RI       RL RM RN RO RP       RS    RU    RW         
SA SB SC SD SE SF SG SH SI SJ SK SL SM SN SO       SR SS ST SU SV    SX SY SZ
TA    TC TD    TF TG TH    TJ TK TL TM TN TO TP    TR    TT    TV TW       TZ
UA                UG          UK    UM                US                UY UZ
VA    VC    VE    VG    VI             VN                   VU               
               WF                WL       WO          WS       WV            
XA XB XC XD XE XF XG XH XI XJ XK XL XM XN XO XP XQ XR XS XT XU XV XW XX XY XZ
            YE                                           YT YU YV            
ZA                                  ZM             ZR             ZW       ZZ
(If I made any mistakes copying it down, the table here in this post is normative for the challenge, not the one on Wikipedia.)

You may or may not use trailing whitespace in each line which doesn't contain the *Z code, but not beyond the 77th character in that line (i.e., at most, you can make it a rectangular block, ending in Zs and spaces). Also, you may or may not use a single trailing new line at the end.

This is code golf, so the shortest answer (in bytes) wins.

*/

#include <iostream>
#include <string>

using namespace std;

const string countries = R"(
AA    AC AD AE AF AG    AI       AL AM AN AO AP AQ AR AS AT AU    AW AX    AZ
BA BB    BD BE BF BG BH BI BJ    BL BM BN BO    BQ BR BS BT BU BV BW BX BY BZ
CA    CC CD    CF CG CH CI    CK CL CM CN CO CP    CR CS    CU CV CW CX CY CZ
            DE    DG       DJ DK    DM    DO                            DY DZ
EA    EC    EE EF EG EH             EM       EP    ER ES ET EU EV EW
                        FI FJ FK FL FM    FO       FR                FX
GA GB GC GD GE GF GG GH GI       GL GM GN    GP GQ GR GS GT GU    GW    GY
                              HK    HM HN          HR    HT HU
   IB IC ID IE                   IL IM IN IO    IQ IR IS IT IU IV IW IX IY IZ
JA          JE                      JM    JO JP
            KE    KG KH KI          KM KN    KP    KR             KW    KY KZ
LA LB LC       LF       LI    LK                   LR LS LT LU LV       LY
MA    MC MD ME MF MG MH       MK ML MM MN MO MP MQ MR MS MT MU MV MW MX MY MZ
NA    NC    NE NF NG    NI       NL       NO NP    NR    NT NU             NZ
OA                                  OM
PA          PE PF PG PH PI    PK PL PM PN          PR PS PT       PW    PY
QA                                  QM QN QO QP QQ QR QS QT QU QV QW QX QY QZ
RA RB RC    RE       RH RI       RL RM RN RO RP       RS    RU    RW
SA SB SC SD SE SF SG SH SI SJ SK SL SM SN SO       SR SS ST SU SV    SX SY SZ
TA    TC TD    TF TG TH    TJ TK TL TM TN TO TP    TR    TT    TV TW       TZ
UA                UG          UK    UM                US                UY UZ
VA    VC    VE    VG    VI             VN                   VU
               WF                WL       WO          WS       WV
XA XB XC XD XE XF XG XH XI XJ XK XL XM XN XO XP XQ XR XS XT XU XV XW XX XY XZ
            YE                                           YT YU YV
ZA                                  ZM             ZR             ZW       ZZ
)";

int main()
{
	cout << countries << endl;
	return 0;
}
