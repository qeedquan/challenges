-- Now our goal is to learn the loops - i.e. repeated actions. Let us find the sum of several numbers (more than two). It will be useful to do this in a loop. As shown in the picture above - you can create variable sum and add every value from the list to it. Perhaps "for" loop will suit nicely since the amount of numbers is known beforehand.
--
-- If you have troubles, try Sums In Loop first - it is, probably, easier.
--
-- Input data has the following format:
--
-- first line contains N - amount of values to sum;
-- second line contains N values themselves.
-- Answer should contain a single value - the sum of N values.
--
-- Example:
--
-- input data:
-- 8
-- 10 20 30 40 5 6 7 8
--
-- answer:
-- 126
--
-- Note since there are several dozens of numbers, you should not copy them manually to your program. Instead make your program reading them from standard input (where you can copy them all at once). Note that if you run code at our server, the data are automatically copied to standard input for convenience.

with Ada.Text_IO; use Ada.Text_IO;

procedure Sum_List is
   type Number_Array is array (Positive range <>) of Integer;

   function Sum_Array (List : Number_Array) return Integer is
      Total : Integer := 0;
   begin
      for Item of List loop
         Total := Total + Item;
      end loop;
      return Total;
   end Sum_Array;

   My_Numbers : constant Number_Array := (10, 20, 30, 40, 5, 6, 7, 8);
begin
   Put_Line("The sum is: " & Integer'Image(Sum_Array(My_Numbers)));
end Sum_List;
