#!/usr/bin/env python3

"""

We shall soon have a new logo & site design, let us use this last breath of the simple times and golf this ASCII version of the speech bubble beta logo:

+-------------------------------------------+
|    .---------------------------------.    |
|   .EPEpEpBPEpEGCXCgCgCGJgCgP&PWP&P&P&Y`   |
|  .RSRsRWRSRsRsHoNoNONxNONONuJuSUSUSVSUS`  |
|  :o@OTO@O@O@W@IDiDIWiDIDIDWZEZeZEWEZeZE-  |
|  :GWGFGfGFKFGFMEMwMEMEMeXEMZLZLWLZLzLZH-  |
|  :rLRLRLXLRLrLMBMGMGmGXGMGMLzTZLZLZLYLZ-  |
|  :AOAoBOAOAOAYAOAoAoBOAOAoAWZEZEZEVEZEZ-  |
|  :MGVGm!'""'!GRLr!'""'!LRKRS!'""'!uSuSU-  |
|  :XEME' .''% !Gf' .;G% 'GFG' .;P% '&PVP-  |
|  :IDID  !DI! !V! .OPoYOPOP!  -gCGCGHGCG-  |
|  :NONw  ``` .OR! .RWRRRRRR! !ONo* 'ONON-  |
|  :GBGC  !CXCGCP! !POP; !xOP  `IJ; `!IDW-  |
|  :P&P&._!&P&P&F~.____.;GFGF~.____.;eJEM-  |
|  :USUSVSUSuSuTLRlRLRWRLRlRLWMGMGmGwGmGM-  |
|  :ZeWEZEZeZWZeOAOaKAOAOaOwOOAoAOXoAoAOA-  |
|  :wLZLZLzHZLZLGMxMgMGMgBGMGLRLXLRLrLRTr-  |
|  :LZLZLYLZLZLzBMEMEMEyEmEMEfBFGFGfGWGFG-  |
|  :EZEVEZEZeZVZDIdIDYdIdIDIx@O@o@oKO@O@o-  |
|  `SkSuSuSUXUSuONOVONOnONWNOSRSRWRSRSRS-   |
|   `.&P&PVP&P&PCXcGCGCGVGcGCEPYPEpEPE?.-   |
|      ```````````````````:STACKE-`````     |
|                         :XCHA-`           |
|                         :NG-`             |
|           ?=W...HWYWVWB :E`               |
+-------------------------------------------+
This is kolmogorov-complexity code-golf, so it's straight forward, output all the text that appears in the above code-block in as few bytes of code as possible, without any funny-business.

input
None

Output
The ASCII content of the code-block above as a return value or printed to STDOUT or equivalent;
carriage returns (13) and/or new lines (10) are acceptable;
a trailing empty line is also allowed.

Update
The original aim of this challenge was to have a puzzle aspect. It seems this has not been noticed, so I have decided to make the puzzle portion significantly easier, but still present, by performing a couple of steps to get you going:

There is a use of the string "STACKEXCHANGE" in the very bottom portion of the speech-bubble.

If one reads the rows of text in the main-portion of the speech-bubble, one might notice an almost repetitive nature of pairs of letters, for example the fourth row reads "GWGFGfGFKFGFMEMwMEMEMeXEMZLZLWLZLzLZH" which is almost "GFGFGFGFGFGFMEMEMEMEMEMEMZLZLZLZLZLZH", except some letters have been changed either to another letter (e.g. the second letter from F to W), to lower-case (e.g. the sixth letter from F to f), or both (e.g. the sixteenth letter from E to w). The rows seem to all conform to such a pattern with a 12-13-12 character split (ignoring the mess of the PPG logo's white space and border).

The process described in (2), once noticed, should be quite easy to undo for the unmasked rows of the speech-bubble (the top six and bottom seven), by first converting the whole text to upper-case and then replacing the odd-ones-out and results in:

+-------------------------------------------+
|    .---------------------------------.    |
|   .EPEPEPEPEPEGCGCGCGCGCGCGP&P&P&P&P&P`   |
|  .RSRSRSRSRSRSNONONONONONONUSUSUSUSUSUS`  |
|  :O@OTO@O@O@O@IDIDIWIDIDIDIZEZEZEZEZEZE-  |
|  :GFGFGFGFGFGFMEMEMEMEMEMEMZLZLZLZLZLZL-  |
|  :RLRLRLRLRLRLMGMGMGMGMGMGMLZLZLZLZLZLZ-  |
|  :AOAOAOAOAOAOAOAOAOBOAOAOAEZEZEZEZEZEZ-  |
|  :MGVGm!'""'!GRLr!'""'!LRKRS!'""'!uSuSU-  |
|  :XEME' .''% !Gf' .;G% 'GFG' .;P% '&PVP-  |
|  :IDID  !DI! !V! .OPoYOPOP!  -gCGCGHGCG-  |
|  :NONw  ``` .OR! .RWRRRRRR! !ONo* 'ONON-  |
|  :GBGC  !CXCGCP! !POP; !xOP  `IJ; `!IDW-  |
|  :P&P&._!&P&P&F~.____.;GFGF~.____.;eJEM-  |
|  :USUSUSUSUSURLRLRLRLRLRLRLGMGMGMGMGMGM-  |
|  :ZEZEZEZEZEZEOAOAOAOAOAOAOOAOAOAOAOAOA-  |
|  :ZLZLZLZLZLZLGMGMGMGMGMGMGLRLRLRLRLRLR-  |
|  :LZLZLZLZLZLZEMEMEMEMEMEMEFGFGFGFGFGFG-  |
|  :EZEZEZEZEZEZDIDIDIDIDIDID@O@O@O@O@O@O-  |
|  `SUSUSUSUSUSUONONONONONONOSRSRSRSRSRS-   |
|   `.&P&P&P&P&PCGCGCGCGCGCGCEPEPEPEPEP.-   |
|      ```````````````````:STACKE-`````     |
|                         :XCHA-`           |
|                         :NG-`             |
|           ?=W...HWYWVWB :E`               |
+-------------------------------------------+
While carrying out (3) one may notice a couple of things. First the least obvious: that the only ?, in the very bottom-right became a P, whereas the extra text at the bottom says ?=W..., and that a large proportion of replaced characters were also W. Second that the odd-ones out in upper-case were B,H,J,K,T,V,W,X,Y. Third that the odd-ones out occurred every seven letters. The second and third observation helps to fill in the middle rows - which, if we remove the PCG mask of spaces and non-letters, non & (used in the top and bottom row) and replace it with the letters yields:
+-------------------------------------------+
|    .---------------------------------.    |
|   .EPEPEPEPEPEGCGCGCGCGCGCGP&P&P&P&P&P`   |
|  .RSRSRSRSRSRSNONONONONONONUSUSUSUSUSUS`  |
|  :O@O@O@O@O@O@IDIDIWIDIDIDIZEZEZEZEZEZE-  |
|  :GFGFGFGFGFGFMEMEMEMEMEMEMZLZLZLZLZLZL-  |
|  :RLRLRLRLRLRLMGMGMGMGMGMGMLZLZLZLZLZLZ-  |
|  :AOAOAOAOAOAOAOAOAOBOAOAOAEZEZEZEZEZEZ-  |
|  :MGMGMGMGMGMGRLRLRLRLRLRLRSUSUSUSUSUSU-  |
|  :MEMEMEMEMEMEGFGFGFGFGFGFG&P&P&P&P&P&P-  |
|  :IDIDIDIDIDIDOPOPOPOPOPOPOCGCGCGCGCGCG-  |
|  :NONONONONONORRRRRRRRRRRRRONONONONONON-  |
|  :GCGCGCGCGCGCPOPOPOPOPOPOPDIDIDIDIDIDI-  |
|  :P&P&P&P&P&P&FGFGFGFGFGFGFEMEMEMEMEMEM-  |
|  :USUSUSUSUSURLRLRLRLRLRLRLGMGMGMGMGMGM-  |
|  :ZEZEZEZEZEZEOAOAOAOAOAOAOOAOAOAOAOAOA-  |
|  :ZLZLZLZLZLZLGMGMGMGMGMGMGLRLRLRLRLRLR-  |
|  :LZLZLZLZLZLZEMEMEMEMEMEMEFGFGFGFGFGFG-  |
|  :EZEZEZEZEZEZDIDIDIDIDIDID@O@O@O@O@O@O-  |
|  `SUSUSUSUSUSUONONONONONONOSRSRSRSRSRS-   |
|   `.&P&P&P&P&PCGCGCGCGCGCGCEPEPEPEPEP.-   |
|      ```````````````````:STACKE-`````     |
|                         :XCHA-`           |
|                         :NG-`             |
|           ?=W...HWYWVWB :E`               |
+-------------------------------------------+
Now reading the columns one can see that the "input" text to make this base grid was PROGRAMMINGPUZZLES&CODEGOLFPROGRAMMINGPUZZLES&CODEGOLF@SE.
The lower-casing and replacement characters are to be determined by you, but also note that the ten remaining letters in the alphabet after removing those present in that string are B,H,J,K,Q,T,V,W,X,Y - the replacements plus Q.

"""

LOGO = """
+-------------------------------------------+
|    .---------------------------------.    |
|   .EPEpEpBPEpEGCXCgCgCGJgCgP&PWP&P&P&Y`   |
|  .RSRsRWRSRsRsHoNoNONxNONONuJuSUSUSVSUS`  |
|  :o@OTO@O@O@W@IDiDIWiDIDIDWZEZeZEWEZeZE-  |
|  :GWGFGfGFKFGFMEMwMEMEMeXEMZLZLWLZLzLZH-  |
|  :rLRLRLXLRLrLMBMGMGmGXGMGMLzTZLZLZLYLZ-  |
|  :AOAoBOAOAOAYAOAoAoBOAOAoAWZEZEZEVEZEZ-  |
|  :MGVGm!'""'!GRLr!'""'!LRKRS!'""'!uSuSU-  |
|  :XEME' .''% !Gf' .;G% 'GFG' .;P% '&PVP-  |
|  :IDID  !DI! !V! .OPoYOPOP!  -gCGCGHGCG-  |
|  :NONw  ``` .OR! .RWRRRRRR! !ONo* 'ONON-  |
|  :GBGC  !CXCGCP! !POP; !xOP  `IJ; `!IDW-  |
|  :P&P&._!&P&P&F~.____.;GFGF~.____.;eJEM-  |
|  :USUSVSUSuSuTLRlRLRWRLRlRLWMGMGmGwGmGM-  |
|  :ZeWEZEZeZWZeOAOaKAOAOaOwOOAoAOXoAoAOA-  |
|  :wLZLZLzHZLZLGMxMgMGMgBGMGLRLXLRLrLRTr-  |
|  :LZLZLYLZLZLzBMEMEMEyEmEMEfBFGFGfGWGFG-  |
|  :EZEVEZEZeZVZDIdIDYdIdIDIx@O@o@oKO@O@o-  |
|  `SkSuSuSUXUSuONOVONOnONWNOSRSRWRSRSRS-   |
|   `.&P&PVP&P&PCXcGCGCGVGcGCEPYPEpEPE?.-   |
|      ```````````````````:STACKE-`````     |
|                         :XCHA-`           |
|                         :NG-`             |
|           ?=W...HWYWVWB :E`               |
+-------------------------------------------+
"""

print(LOGO)
