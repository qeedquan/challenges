@REM ()(:) #
@REM "
Challenge: write a single script file foo.cmd which can be invoked from the vanilla Windows cmd.exe prompt (not PowerShell, not in administrator mode), to execute arbitrary Windows-specific code...

> .\foo.cmd
Hello Windows! 
...but also be invoked unaltered from a typical POSIX-compliant (Linux/OSX) shell prompt (bash, tcsh, or zsh), to execute arbitrary POSIX-specific code:

$ chmod a+x foo.cmd
$ ./foo.cmd
Hello POSIX!
...without requiring installation or creation of third-party interpreters/tools.

I know this is possible, but with cruft (i.e. on Windows, one or two lines of garbage/error-message are printed to stderr or stdout before "Hello Windows!").

The winning criterion is minimization of (first) the number of cruft lines, and (second) the number of cruft characters.

Cruft can be defined as any console output (stdout or stderr) that is not produced by the (arbitrary) payload code. Blank lines are counted in the line count. Newlines are not counted in the character count. Cruft scores should be summed across both platforms. Let's disregard mechanisms like cls that sweep away the cruft but at the cost of also blanking out previous terminal output. If Windows echos your commands because you haven't turned @echo off yet, let's exclude the characters it spends in printing the current directory and prompt.

A secondary criterion is the simplicity/elegance of the solution inside foo.cmd: if "infrastructure" is defined as any character not directly involved in the arbitrary payload code, then minimize first the number of lines that contain infrastructure characters, and second the total number of infrastructure characters.

Extra kudos if the POSIX part will work despite the file having CRLF line-endings! (Am not sure that last part is even possible.)

My existing solution, which I will post here once others have had a chance, uses 6 lines of infrastructure code (52 chars excluding newlines). It produces 5 lines of cruft, two of which are blank, all of which occur on Windows (30 chars excluding newlines and excluding the current directory/prompt string that appears on two of those lines).
@REM "

@REM "
@ECHO Hello Windows!
@EXIT /B
@REM "
echo Hello POSIX!

