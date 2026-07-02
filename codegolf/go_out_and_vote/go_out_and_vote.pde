/*

Today is November 8th, 2016, Election Day in the United States of America.

If you are a U.S. citizen eligible to vote, then go out and vote if you haven't already before answering this challenge. Do not discuss who you voted for. It only matters that you voted.

If you are not a U.S. citizen or not eligible to vote, then, before answering this challenge, do the U.S. a favor by telling anyone you know who is an eligible citizen to go out and vote if they haven't already.

Challenge
Write a program that indicates that you voted, like a digital "I Voted" sticker.

It should take no input and must output in a reasonable way the phrase I Voted where the I, o, and e are red (#FF0000) and the V, t, and d are blue (#0000FF). The background must be white (#FFFFFF).

For example:

"I Voted" example graphic

These colors are of course representative of the American flag (though not the official colors). Red comes first simply because it comes first in the common idiom "red white and blue".

To be valid, an answer must:

Use the colors specified in the arrangement specified.

Use a single legible font and font size. The example uses 72pt Times New Roman bold but any common font above 6pt is probably fine.

Have just the phrase I Voted on a single line, capitalized correctly, with a clear space between the two words. It shouldn't look like IVoted.

Not indicate who the answerer voted for or supports for president or any down-ballot races. Let's not start any internet debates. This is about celebrating voting, not candidates.

Any reasonable way of displaying or producing the output is valid, such as:

Drawing the text to an image that is then displayed, saved, or output raw.

Writing the text to a console using color formatting. In this case you may approximate pure red and blue if necessary, and it's ok if only the area directly behind the text can be made white.

Displaying the text on a WPF/Windows form.

Outputting an HTML/RTF/PDF file with the text.

Please post an image of your output.

The shortest answer in bytes wins.

*/

void setup() {
  size(320, 128);
  textSize(96);
}

void draw() {
  background(255);
  alttext("I Voted", 20, 85, color(255, 0, 0), color(0, 0, 255));
}

void alttext(String str, int x, int y, color col1, color col2) {
  color col = col1;
  for (int i = 0; i < str.length(); i++) {
    char ch = str.charAt(i);
    if (ch != ' ') {
      fill(col);
      text(ch, x, y);
      col = (col == col1) ? col2 : col1;
    }
    x += textWidth(ch);
  }
}
