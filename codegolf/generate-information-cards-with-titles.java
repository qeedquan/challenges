/*

You must take input in the form of

title|line1|line2|(...)|line[n]
And output an information card. It's hard to explain how to make the card, so here's a quick example:

Input

1234567890|12345|1234567890123|pie|potato|unicorn
Output

/===============\
|  1234567890   |
|===============|
| 12345         |
| 1234567890123 |
| pie           |
| potato        |
| unicorn       |
\---------------/
Detailed specifications:

The title must be centered (if there are an odd number of characters you can decide whether to put an extra space after or before it).
The remaining lines must be left-aligned.
All of them must have at least one space of padding before and after.
Each line must be the same length.
The lines must be the smallest length possible in order to fit all of the text.
The first and last character of each row (except for the first and last rows) must be a |.
There must be a /, a row of =s, and a \ in the line right before the title. (the first line)
There must be a |, a row of =s. and a | in the line right after the title. (the third line)
There must be a \, a row of -s, and a / in the last line.
For the example input provided, your program's output must exactly match the example output provided.
The input will always contain at least one |; your programs behaivior when a string like badstring is input does not matter.
This is code-golf so the shortest code in character count wins.

*/

class InformationCard {
    public static void main(String[] args) {
        informationCard("1234567890|12345|1234567890123|pie|potato|unicorn");
        informationCard("RFC|None|Description|Functions|Letters|END");
    }

    public static void informationCard(String input) {
        String[] lines = input.split("\\|");
        int maxWidth = getMaxWidth(lines);

        print(buildTopBorder(maxWidth));
        printCenteredHeader(lines[0], maxWidth);
        print(buildSeparator(maxWidth));
        for (int i = 1; i < lines.length; i++) {
            print(String.format("| %-" + maxWidth + "s |", lines[i]));
        }
        print(buildBottomBorder(maxWidth));
    }

    private static <T> void print(T value) {
        System.out.println(value);
    }

    private static int getMaxWidth(String[] lines) {
        int maxWidth = 0;
        for (String line : lines)
            maxWidth = Math.max(maxWidth, line.length());
        return maxWidth;
    }

    private static String buildTopBorder(int width) {
        return "/=" + "=".repeat(width) + "=\\";
    }

    private static String buildSeparator(int width) {
        return "|=" + "=".repeat(width) + "=|";
    }

    private static String buildBottomBorder(int width) {
        return "\\-" + "-".repeat(width) + "-/";
    }

    private static String centeredHeader(String text, int width) {
        int totalPadding = width - text.length();
        int leftPadding = totalPadding / 2;
        int rightPadding = totalPadding - leftPadding;
        return " ".repeat(leftPadding) + text + " ".repeat(rightPadding);
    }

    private static String centeredHeaderLine(String text, int width) {
        return "| " + centeredHeader(text, width) + " |";
    }

    private static void printCenteredHeader(String text, int width) {
        print(centeredHeaderLine(text, width));
    }
}
