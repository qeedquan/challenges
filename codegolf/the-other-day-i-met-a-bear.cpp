/*

Your challenge is to output this text:

The other day,
The other day,
I met a bear,
I met a bear,
A great big bear,
A great big bear,
Oh way out there.
Oh way out there.

The other day,
I met a bear,
A great big bear,
Oh way out there.

He looked at me,
He looked at me,
I looked at him,
I looked at him,
He sized up me,
He sized up me,
I sized up him.
I sized up him.

He looked at me,
I looked at him,
He sized up me,
I sized up him.

He said to me,
He said to me,
"Why don't you run?
"Why don't you run?
I see you ain't,
I see you ain't,
Got any gun."
Got any gun."

He said to me,
"Why don't you run?
I see you ain't,
Got any gun."

I says to him,
I says to him,
"That's a good idea."
"That's a good idea."
"Now legs get going,
"Now legs get going,
get me out of here!"
get me out of here!"

I says to him,
"That's a good idea."
"Now legs get going,
get me out of here!"

And so I ran,
And so I ran,
Away from there,
Away from there,
But right behind me,
But right behind me,
Was that bear.
Was that bear.

And so I ran,
Away from there,
But right behind me,
Was that bear.

In front of me,
In front of me,
There was a tree,
There was a tree,
A great big tree,
A great big tree,
Oh glory be!
Oh glory be!

In front of me,
There was a tree,
A great big tree,
Oh glory be!

The lowest branch,
The lowest branch,
Was ten feet up,
Was ten feet up,
So I thought I'd jump,
So I thought I'd jump,
And trust my luck.
And trust my luck.

The lowest branch,
Was ten feet up,
So I thought I'd jump,
And trust my luck.

And so I jumped,
And so I jumped,
Into the air,
Into the air,
But I missed that branch,
But I missed that branch,
A way up there.
A way up there.

And so I jumped,
Into the air,
But I missed that branch,
A way up there.

Now don't you fret,
Now don't you fret,
And don't you frown,
And don't you frown,
I Caught that branch,
I Caught that branch,
On the way back down!
On the way back down!

Now don't you fret,
And don't you frown,
I Caught that branch,
On the way back down!

This is the end,
This is the end,
There aint no more,
There aint no more,
Unless I see,
Unless I see,
That bear once more.
That bear once more.

This is the end,
There aint no more,
Unless I see,
That bear once more.
Pattern:
First, each line is repeated once, linebreak-separated, and then 2 newlines, and then the above stanza is printed without the repetition. Then the next stanza.

Rules
Trailing whitespace is allowed at the end of the output, but the rest must be printed as-is.

*/

#include <iostream>
#include <string>

using namespace std;

const string POEM = R"(
The other day,
The other day,
I met a bear,
I met a bear,
A great big bear,
A great big bear,
Oh way out there.
Oh way out there.

The other day,
I met a bear,
A great big bear,
Oh way out there.

He looked at me,
He looked at me,
I looked at him,
I looked at him,
He sized up me,
He sized up me,
I sized up him.
I sized up him.

He looked at me,
I looked at him,
He sized up me,
I sized up him.

He said to me,
He said to me,
"Why don't you run?
"Why don't you run?
I see you ain't,
I see you ain't,
Got any gun."
Got any gun."

He said to me,
"Why don't you run?
I see you ain't,
Got any gun."

I says to him,
I says to him,
"That's a good idea."
"That's a good idea."
"Now legs get going,
"Now legs get going,
get me out of here!"
get me out of here!"

I says to him,
"That's a good idea."
"Now legs get going,
get me out of here!"

And so I ran,
And so I ran,
Away from there,
Away from there,
But right behind me,
But right behind me,
Was that bear.
Was that bear.

And so I ran,
Away from there,
But right behind me,
Was that bear.

In front of me,
In front of me,
There was a tree,
There was a tree,
A great big tree,
A great big tree,
Oh glory be!
Oh glory be!

In front of me,
There was a tree,
A great big tree,
Oh glory be!

The lowest branch,
The lowest branch,
Was ten feet up,
Was ten feet up,
So I thought I'd jump,
So I thought I'd jump,
And trust my luck.
And trust my luck.

The lowest branch,
Was ten feet up,
So I thought I'd jump,
And trust my luck.

And so I jumped,
And so I jumped,
Into the air,
Into the air,
But I missed that branch,
But I missed that branch,
A way up there.
A way up there.

And so I jumped,
Into the air,
But I missed that branch,
A way up there.

Now don't you fret,
Now don't you fret,
And don't you frown,
And don't you frown,
I Caught that branch,
I Caught that branch,
On the way back down!
On the way back down!

Now don't you fret,
And don't you frown,
I Caught that branch,
On the way back down!

This is the end,
This is the end,
There aint no more,
There aint no more,
Unless I see,
Unless I see,
That bear once more.
That bear once more.

This is the end,
There aint no more,
Unless I see,
That bear once more.
)";

int main()
{
	cout << POEM << endl;
	return 0;
}
