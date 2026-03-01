#!/usr/bin/env/python3

r"""

When I see code-golf entries that knock a few characters off, whittling down the code, I go look at the edit history for a side-by-side diff. See and learn :)

This challenge is to make a program that produces the prettiest animated diffs.

The input will be any ordered series of text versions.
The program may be written in any programming language.
It is allowed that the program limit itself to input data in some specific programming languages.
The program should not be tuned to the specific input data; the program should be generic and work for any ordered series of text versions.
For each version in the input there must be a corresponding time in the output animation where the full text of the version is displayed. You must animate the diff between version stages, and all version stages must be present and in order in the output. On these key frames, the version size must be shown and the viewer should understand this is a complete version they are seeing at that point.
The program may not use any third party code to compute the diffs.
Syntax highlighting output is optional. If the program colours syntax, it may not use any third party code to do so.
The output will be an animated GIF.
The program may use a third party library to author the GIF.
This is a popularity-contest, so as per the definition of popularity-contest on this site, the entry with the most votes wins.

Here's a simple example script that uses Python's ndiff and Pillow's rudimentary animated GIF support and animates each add and remove step:
https://gist.github.com/williame/263bf661f0d0ba173c44#file-anim_code_golf-py-L144

https://i.sstatic.net/I68Hk.gif

Personally, I think this a pretty poor job. It doesn't do syntax highlighting, it doesn't try and move code chunks that get rearranged, it doesn't feel like someone is live editing it, and so on. It also breaks the rules regards showing the size of the input in bytes on key frames, and it uses a third party library to do the diffing. Lots of room for improvement!

And hopefully the popular entries will become useful fun tools for the codegolf.stackexchange.com community too. So its appreciated if the programs are easy for others to get running and use.

"""


versions = [version.strip() for version in (
"""
def t(b):
 L=len;w,n=L(b[0])+3,-1;b=list("@"*w+"@@".join(b)+"@"*w);w+=n;I=b.index
 for i in range(L(b)):
  c=b[i];d={"^":-w,"<":n,">":1,"v":w}.get(c)
  if d:
   while c!='@':
    i+=d;c=b[i]
    if c=='*':b[i]='.'
    elif c in "123456789":i+=I(c)-i or I(c,i+1)-i
    elif c in '/\\':d={-w:n,w:1,1:w,n:-w}[d]*(-1 if c=='/' else 1)
 return "*" not in b
""",
"""
def t(b):
 L=len;w=L(b[0])+3;b=list("@"*w+"@@".join(b)+"@"*w);w-=1;I=b.index
 for i in range(L(b)):
  c=b[i];d={"^":-w,"<":-1,">":1,"v":w}.get(c)
  if d:
   while c!='@':
    i+=d;c=b[i]
    if c=='*':b[i]='.'
    elif c in "123456789":i+=I(c)-i or I(c,i+1)-i
    elif c in '/\\':d={-w:-1,w:1,1:w,-1:-w}[d]*(-1 if c=='/' else 1)
 return "*" not in b
""",
"""
def t(b):
 L=len;w=L(b[0])+3;b=list("@"*w+"@@".join(b)+"@"*w);w-=1;I=b.index
 for i in range(L(b)):
  c=b[i];d={"^":-w,"<":-1,">":1,"v":w}.get(c)
  if d:
   while c!='@':
    i+=d;c=b[i]
    if c=='*':b[i]='.'
    elif c in '/\\':d={-w:-1,w:1,1:w,-1:-w}[d]*(-1 if c=='/' else 1)
    elif c>'0':i+=I(c)-i or I(c,i+1)-i
 return "*" not in b
""",
"""
def t(b):
 w=len(b[0])+2;B=list('@'*w+'@@'.join(b)+'@'*w);l=len(B);C="<>v^";D=[-1,1,w,-w];i=0
 while i<l:
    d=C.find(B[i])
    if-1<d:
     j=i;n=l*4
     while('@'!=B[j])*n:
        c=B[j]
        if'+'>c:B[j]=''
        if'/'==c:d=(d+2)%4
        if'\\'==c:d=3-d
        if c.isdigit():j=(B*2).index(c,j+1)%l
        j+=D[d];n-=1
    i+=1
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+2;B=list('@'*w+'@@'.join(b)+'@'*w);l=len(B);i=0
 while i<l:
    d="<>v^".find(B[i])
    if-1<d:
     j=i;n=l*4
     while(B[j]!='@')*n:
        c=B[j]
        if'+'>c:B[j]=''
        if'/'==c:d=(d+2)%4
        if'\\'==c:d=3-d
        if c.isdigit():j=(B*2).index(c,j+1)%l
        j+=[-1,1,w,-w][d];n-=1
    i+=1
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+2;B=list('@'*w+'@@'.join(b)+'@'*w);l=len(B);i=0
 while i<l:
    d="<>v^".find(B[i])
    if-1<d:
     j=i;c='.'
     while c not in"@<>v^":
        if'+'>c:B[j]=''
        if'/'==c:d^=2
        if'\\'==c:d^=3
        elif'0'<c:j=(B*2).index(c,j+1)%l
        j+=[-1,1,w,-w][d];c=B[j]
    i+=1
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+2;B=list('@'*w+'@@'.join(b)+'@'*w);l=len(B);i=0
 while i<l:
    d="<>v^".find(B[i]);j=i;c='.'
    while c not in"@<>v^":
     if'+'>c:B[j]=''
     if'/'==c:d^=2
     if'\\'==c:d^=3
     elif'0'<c:j=(B*2).index(c,j+1)%l
     j+=[-1,1,w,-w,-i][d];c=B[j]
    i+=1
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+1;B=list('@'*w+'@'.join(b)+'@'*w);l=len(B);i=0
 while i<l:
    d="<>v^".find(B[i]);j=i;c='.'
    while c not in"@<>v^":
     if'+'>c:B[j]=''
     if'/'==c:d^=2
     if'\\'==c:d^=3
     elif'0'<c:j=(B*2).index(c,j+1)%l
     j+=[-1,1,w,-w,-j][d];c=B[j]
    i+=1
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+1;B=list('@'*w+'@'.join(b));i=l=len(B);C="<>^v@"
 while i:
    j=l-i;i-=1;d=C.find(B[j]);c='.'
    while c not in C:
     if'+'>c:B[j]='.'
     if'0'<c<C:j=(B*2).index(c,j+1)%l
     elif'.'<c:d^=2+(c<C)
     j-=[1,-1,w,-w,j][d];c=B[j%l]
 return'*'not in B
""",
"""
def t(b):
 w=len(b[0])+1;B=list('@'*w+'@'.join(b));i=l=len(B);C="<>^v@"
 while i:
  i-=1;d,j,c=C.find(B[i]),i,'.'
  while(c in C)-1:
   if'+'>c:B[j]='.'
   if'0'<c<C:j=(B*2).index(c,j+1)%l
   elif'.'<c:d^=2+(c<C)
   j-=[1,-1,w,-w,j][d];c=B[j%l]
 return('*'in B)-1
""")]

width = max(len(line) for version in versions for line in version.split("\n"))
height = max(len(version.split("\n")) for version in versions)

import difflib
from PIL import Image, ImageFont, ImageDraw, ImageChops, GifImagePlugin

font = ImageFont.truetype("courier_new.ttf", 15)
em, lineheight = 9, 14
anim_frames = 1

def render(text, ofs, diff, diff_ch, frames):
    for frame in range(anim_frames if ofs is not None else 1):
        image = Image.new("RGB", (width * em + int(em * 1.5), height * lineheight + int(lineheight/2)), "white")
        frames.append(image)
        draw = ImageDraw.Draw(image)
        x, y = 0, 0
        for i, ch in enumerate(text): 
            if ch == '\n':
                x = 0
                y += lineheight
            else:
                if i == ofs:
                    draw.rectangle((x, y, x + em, y + lineheight),
                        fill='red' if diff=='+' else 'blue')
                    scale = 1.0 / 3 * frame
                    if diff == '-':
                        scale = 1.0 - scale
                    draw.text((x, y), ch, font=font,
                        fill='yellow')
                    draw.rectangle((x + em, y, x + em + em, y + lineheight),
                        fill='white')
                    x += int(round(float(em) * scale))
                draw.text((x, y), ch, font=font, fill=0)
                x += em
        del draw
                
frames = []
render(versions[0], None, None, None, frames)

prev = versions[0]
for i in range(3, len(versions)):
    curr = versions[i]
    print("==== %d (%d %d) ====" % (i, len(curr), len(prev)-len(curr)))
    adjust = 0
    for ofs, diff in enumerate(difflib.ndiff(prev, curr)):
        diff, ch = diff[0], diff[-1]
        if diff in "+-":
            render(prev, ofs-adjust, diff, ch, frames)
            if diff == "+":
                prev = prev[:ofs-adjust] + ch + prev[ofs-adjust:]
            else:
                assert prev[ofs-adjust] == ch, (ofs, prev[:ofs+1], ch)
                prev = prev[:ofs-adjust] + prev[ofs-adjust+1:]
                adjust += 1
    assert prev == curr
render(versions[-1], None, None, None, frames)
        
with open("anim.gif", "wb") as f:
    prev = None
    for frame in frames:
        frame = frame.convert('P', palette=Image.WEB)
        if not prev:
            for s in GifImagePlugin.getheader(frame)[0]:
                f.write(s)
            prev = frame.copy()
            frame = GifImagePlugin.getdata(frame)
        else:
            delta = ImageChops.subtract_modulo(frame, prev)
            prev = frame.copy()
            bbox = delta.getbbox()
            if bbox:
                frame = GifImagePlugin.getdata(frame.crop(bbox), offset = bbox[:2])
            else:
                continue
        for s in frame:
            f.write(s)
    f.write(b";")

