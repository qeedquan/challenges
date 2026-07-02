/*

The goal of this challenge is to encode and decode records in a compact and/or efficient self contained manner. Because the more I type, the more confusing the challenge is interpreted, I will avoid discussing process as much as I can.

1. fixed length records: birthdays
Database systems prefer tables of fixed length records because it is easy and fast to retrieve any single record that way.

A customer birthday is:

A tuple of Year, Month, Day

The year is in the past, and can be assumed to not be earlier than 1900

So the year, month, day can be stored as 1 byte each, and this arrangement makes it easiest to search on year or other components. (the year can be coded as the offset to 1900)

challenge (encode following dates)

1944/11/22
1982/3/14
1986/2/11

2. add a header to the file
Database management software needs to know what is in the file. Create a strategy to describe what is in the file, such that it can be read and written to.

Information to include in the header:

Fixed vs variable sized records (above is fixed)

code to unpack into native format

code to pack from native into file format

method to tell where header ends and data begins.

TIP: An easy way to provide language agnostic packing code is to provide a minimum and maximum allowed range to integer (or float for that matter) data.

3. variable length fields/records
A subject touched upon in Monday's part 1 challenge, was that there are 2 general strategies to coding the field length of variable length data with the data. There are in fact 3 strategies:

interleave length with data elements. Disadvantage is that file must be read sequentially to retrieve any element.

place a key of lengths or (easily derived) offsets to data starts as a header element to the data. Relatively fast specific data access. More memory used. 2 updates needed when record/field changed.

Use a seperator, non-legal-data-value. Still sequential read disadvantage, but a faster sequential read. Requires that a non-legal-data value or escape sequence exists.

FYI, most database (and in memory) systems allocate variable string data by using a "too big" text field and left aligning data within the larger space. Provides quickest indexed access and in place updates.

challenge for 3 fields: FirstName LastName DateOfBirth:

Bill Gates 1947/1/14
Mark Zuckerberg 1987/11/4
Steve Jobs 1955/3/7

Where firstname and lastname are variable length fields. Can use whatever strategy you wish, but include a header that self describes how to unpack the data into native memory.

4. Multiple variable file
Variation to number 3 (and may do one or the other), instead of encoding a table as a single variable, encode the data as 3 variables which are each lists of 3 items. This is known as an inverted table or column-oriented database.

The 3 variables correspond to FirstName, LastName, DateofBirth

*/

#include <iostream>
#include <fstream>
#include <string>
#include "database.pb.h"

using namespace std;

void add_default_people(Database &database)
{
	auto person = database.add_people();
	person->set_first_name("Bill");
	person->set_last_name("Gates");
	person->set_phone_number("1947/1/14");

	person = database.add_people();
	person->set_first_name("Mark");
	person->set_last_name("Zuckerberg");
	person->set_phone_number("1987/11/4");

	person = database.add_people();
	person->set_first_name("Steve");
	person->set_last_name("Jobs");
	person->set_phone_number("1955/3/7");
}

void list_people(Database &database)
{
	for (auto index = 0; index < database.people_size(); index++)
	{
		auto &person = database.people(index);
		cout << person.first_name() << " " << person.last_name() << " " << person.phone_number() << endl;
	}
}

int main(int argc, char *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	if (argc != 2)
	{
		cerr << "Usage:  " << argv[0] << " PEOPLE_BOOK_FILE" << endl;
		return 1;
	}

	Database database;
	fstream input(argv[1], ios::in | ios::binary);
	if (!input)
	{
		cout << argv[1] << ": File not found.  Creating a new file." << endl;
		add_default_people(database);
	}
	else if (!database.ParseFromIstream(&input))
	{
		cerr << "Failed to parse address book." << endl;
		return 1;
	}
	else
		list_people(database);

	fstream output(argv[1], ios::out | ios::trunc | ios::binary);
	database.SerializeToOstream(&output);

	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}
