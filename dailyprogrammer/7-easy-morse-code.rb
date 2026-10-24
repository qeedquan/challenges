#!/usr/bin/env ruby

=begin

Write a program that can translate Morse code in the format of ...---...

A space and a slash will be placed between words. ..- / --.-

For bonus, add the capability of going from a string to Morse code.

Super-bonus if your program can flash or beep the Morse.

This is your Morse to translate:

.... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--

=end

alphabet = Hash[*%w/
        A .-            N -.
        B -...          O ---
        C -.-.          P .--.
        D -..           Q --.-
        E .             R .-.
        F ..-.          S ...
        G --.           T -
        H ....          U ..-
        I ..            V ...-
        J .---          W .--
        K -.-           X -..-
        L .-..          Y -.--
        M --            Z --..
     /].invert    

encrypted = ".... . .-.. .-.. --- / -.. .- .. .-.. -.-- / .--. .-. --- --. .-. .- -- -- . .-. / --. --- --- -.. / .-.. ..- -.-. -.- / --- -. / - .... . / -.-. .... .- .-.. .-.. . -. --. . ... / - --- -.. .- -.--"
decrypted = ""

encrypted.split.each do |letter| 
  unless letter == "/"
    decrypted += alphabet[letter]
  else
    decrypted += " "
  end
end

puts "#{encrypted} \ntranslates to \n#{decrypted}"
