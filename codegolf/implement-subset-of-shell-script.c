/*

This site had a lot of problems involving implementing various languages in interpreter tag. However, practically all of them were esoteric languages that nobody uses.
Time to make an interpreter for a practical language that most of users here probably already know.
Yes, it's shell script, in case you have problems reading the title (not that you have). (yes, I intentionally made this challenge, as I'm bored of languages like GolfScript and Befunge winning everything, so I put some challenge where more practical programming language have bigger chances of winning)

However, the shell script is a relatively big language, so I won't ask you to implement it. Instead, I'm going to make a small subset of shell script functionality.

The subset I decided on is the following subset:

Executing programs (programs will only contain letters, however, even if single quotes are allowed)
Program arguments
Single quotes (accepting any printable ASCII character, including whitespace, excluding single quote)
Unquoted strings (allowing ASCII letters, numbers, and dashes)
Pipes
Empty statements
Multiple statements separated by new line
Trailing/leading/multiple spaces
In this task, you have to read the input from STDIN, and run every requested command. You can safely assume POSIX-compatible operating system, so there is no need for portability with Windows, or anything like that. You can safely assume that the programs that aren't piped to other programs won't read from STDIN. You can safely assume that the commands will exist. You can safely assume that nothing else will be used. If some safe assumption is broken, you can do anything. You can safely assume at most 15 arguments, and lines below 512 characters (if you need explicit memory allocation, or something - I'm really going to give small chances of winning for C, even if they are still small). You don't have to clean up file descriptors.

You are allowed to execute programs at any point - even after receiving the full line, or after STDIN ends. Choose any approach you want.

Simple testcase that lets you test your shell (note the trailling whitespace after third command):

echo hello world
printf '%08X\n' 1234567890
'echo'   'Hello,   world!'

echo heeeeeeelllo | sed 's/\(.\)\1\+/\1/g'
  yes|head -3
echo '\\'
echo 'foo bar baz' | sed 's/bar/BAR/' | sed 's/baz/zap/'
The program above should output following result:

hello world
499602D2
Hello,   world!
helo
y
y
y
\\
foo BAR zap
You aren't allowed to execute the shell itself, unless you don't have any arguments for the command (this exception was made for Perl, which runs command in shell when put just argument in system, but feel free to abuse this exception for other languages too, if you can do that in a way that saves characters), or the command you run is shell itself. This is probably the biggest problem in this challenge, as many languages have system functions that execute shell. Instead use language APIs that call programs directly, like subprocess module in Python. This is a good idea for security anyway, and well, you wouldn't want to create an insecure shell, would you want to? This most likely stops PHP, but there are other languages to choose anyway.

If you are going to make your program in shell script, you aren't allowed to use eval, source, or . (as in, a function, not a character). It would make the challenge too easy in my opinion.

Clever rule abuse allowed. There are lots of things I explicitly disallowed, but I'm almost sure that you are still allowed to do things I haven't though of. Sometimes I'm surprised about how people interpret my rules. Also, remember that you can do anything for anything I haven't mentioned. For example, if I try to use variables, you can wipe the hard disk (but please don't).

The shortest code wins, as this is codegolf.

*/

// ported from xv6 shell
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

enum {
	EXEC = 1,
	REDIR,
	PIPE,
	LIST,
	BACK,
};

enum {
	MAXARGS = 10,
};

struct cmd {
	int type;
};

struct execcmd {
	int type;
	char *argv[MAXARGS];
	char *eargv[MAXARGS];
};

struct redircmd {
	int type;
	struct cmd *cmd;
	char *file;
	char *efile;
	int mode;
	int fd;
};

struct pipecmd {
	int type;
	struct cmd *left;
	struct cmd *right;
};

struct listcmd {
	int type;
	struct cmd *left;
	struct cmd *right;
};

struct backcmd {
	int type;
	struct cmd *cmd;
};

int fork1(void);
[[noreturn]] void panic(char *);
struct cmd *parsecmd(char *);

void *
xmalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		abort();
	return ptr;
}

[[noreturn]] void
runcmd(struct cmd *cmd)
{
	int p[2];
	struct backcmd *bcmd;
	struct execcmd *ecmd;
	struct listcmd *lcmd;
	struct pipecmd *pcmd;
	struct redircmd *rcmd;

	if (cmd == 0)
		exit(0);

	switch (cmd->type) {
	default:
		panic("runcmd");

	case EXEC:
		ecmd = (struct execcmd *)cmd;
		if (ecmd->argv[0] == 0)
			exit(0);
		execvp(ecmd->argv[0], ecmd->argv);
		dprintf(2, "exec %s failed\n", ecmd->argv[0]);
		break;

	case REDIR:
		rcmd = (struct redircmd *)cmd;
		close(rcmd->fd);
		if (open(rcmd->file, rcmd->mode, 0644) < 0) {
			dprintf(2, "open %s failed\n", rcmd->file);
			exit(2);
		}
		runcmd(rcmd->cmd);
		break;

	case LIST:
		lcmd = (struct listcmd *)cmd;
		if (fork1() == 0)
			runcmd(lcmd->left);
		wait(NULL);
		runcmd(lcmd->right);
		break;

	case PIPE:
		pcmd = (struct pipecmd *)cmd;
		if (pipe(p) < 0)
			panic("pipe");
		if (fork1() == 0) {
			close(1);
			dup(p[1]);
			close(p[0]);
			close(p[1]);
			runcmd(pcmd->left);
		}
		if (fork1() == 0) {
			close(0);
			dup(p[0]);
			close(p[0]);
			close(p[1]);
			runcmd(pcmd->right);
		}
		close(p[0]);
		close(p[1]);
		wait(NULL);
		wait(NULL);
		break;

	case BACK:
		bcmd = (struct backcmd *)cmd;
		if (fork1() == 0)
			runcmd(bcmd->cmd);
		break;
	}
	exit(0);
}

int
getcmd(char *buf, int nbuf)
{
	dprintf(2, "$ ");
	memset(buf, 0, nbuf);
	fgets(buf, nbuf, stdin);
	if (buf[0] == 0) // EOF
		return -1;
	return 0;
}

int
main()
{
	static char buf[100];

	// Read and run input commands.
	while (getcmd(buf, sizeof(buf)) >= 0) {
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ') {
			// Chdir must be called by the parent, not the child.
			buf[strlen(buf) - 1] = 0; // chop \n
			if (chdir(buf + 3) < 0)
				dprintf(2, "cannot cd %s\n", buf + 3);
			continue;
		}
		if (fork1() == 0)
			runcmd(parsecmd(buf));
		wait(NULL);
	}
	return 0;
}

void
panic(char *s)
{
	dprintf(2, "%s\n", s);
	exit(1);
}

int
fork1(void)
{
	int pid;

	pid = fork();
	if (pid == -1)
		panic("fork");
	return pid;
}

struct cmd *
execcmd(void)
{
	struct execcmd *cmd;

	cmd = xmalloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = EXEC;
	return (struct cmd *)cmd;
}

struct cmd *
redircmd(struct cmd *subcmd, char *file, char *efile, int mode, int fd)
{
	struct redircmd *cmd;

	cmd = xmalloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = subcmd;
	cmd->file = file;
	cmd->efile = efile;
	cmd->mode = mode;
	cmd->fd = fd;
	return (struct cmd *)cmd;
}

struct cmd *
pipecmd(struct cmd *left, struct cmd *right)
{
	struct pipecmd *cmd;

	cmd = xmalloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return (struct cmd *)cmd;
}

struct cmd *
listcmd(struct cmd *left, struct cmd *right)
{
	struct listcmd *cmd;

	cmd = xmalloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = LIST;
	cmd->left = left;
	cmd->right = right;
	return (struct cmd *)cmd;
}

struct cmd *
backcmd(struct cmd *subcmd)
{
	struct backcmd *cmd;

	cmd = xmalloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = BACK;
	cmd->cmd = subcmd;
	return (struct cmd *)cmd;
}

const char whitespace[] = " \t\r\n\v";
const char symbols[] = "<|>&;()";

int
gettoken(char **ps, char *es, char **q, char **eq)
{
	char *s;
	int ret;

	s = *ps;
	while (s < es && strchr(whitespace, *s))
		s++;
	if (q)
		*q = s;
	ret = *s;
	switch (*s) {
	case 0:
		break;
	case '|':
	case '(':
	case ')':
	case ';':
	case '&':
	case '<':
		s++;
		break;
	case '>':
		s++;
		if (*s == '>') {
			ret = '+';
			s++;
		}
		break;
	default:
		ret = 'a';
		while (s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
			s++;
		break;
	}
	if (eq)
		*eq = s;

	while (s < es && strchr(whitespace, *s))
		s++;
	*ps = s;
	return ret;
}

int
peek(char **ps, char *es, char *toks)
{
	char *s;

	s = *ps;
	while (s < es && strchr(whitespace, *s))
		s++;
	*ps = s;
	return *s && strchr(toks, *s);
}

struct cmd *parseline(char **, char *);
struct cmd *parsepipe(char **, char *);
struct cmd *parseexec(char **, char *);
struct cmd *nulterminate(struct cmd *);

struct cmd *
parsecmd(char *s)
{
	char *es;
	struct cmd *cmd;

	es = s + strlen(s);
	cmd = parseline(&s, es);
	peek(&s, es, "");
	if (s != es) {
		dprintf(2, "leftovers: %s\n", s);
		panic("syntax");
	}
	nulterminate(cmd);
	return cmd;
}

struct cmd *
parseline(char **ps, char *es)
{
	struct cmd *cmd;

	cmd = parsepipe(ps, es);
	while (peek(ps, es, "&")) {
		gettoken(ps, es, 0, 0);
		cmd = backcmd(cmd);
	}
	if (peek(ps, es, ";")) {
		gettoken(ps, es, 0, 0);
		cmd = listcmd(cmd, parseline(ps, es));
	}
	return cmd;
}

struct cmd *
parsepipe(char **ps, char *es)
{
	struct cmd *cmd;

	cmd = parseexec(ps, es);
	if (peek(ps, es, "|")) {
		gettoken(ps, es, 0, 0);
		cmd = pipecmd(cmd, parsepipe(ps, es));
	}
	return cmd;
}

struct cmd *
parseredirs(struct cmd *cmd, char **ps, char *es)
{
	int tok;
	char *q, *eq;

	while (peek(ps, es, "<>")) {
		tok = gettoken(ps, es, 0, 0);
		if (gettoken(ps, es, &q, &eq) != 'a')
			panic("missing file for redirection");
		switch (tok) {
		case '<':
			cmd = redircmd(cmd, q, eq, O_RDONLY, 0);
			break;
		case '>':
			cmd = redircmd(cmd, q, eq, O_WRONLY | O_CREAT, 1);
			break;
		case '+': // >>
			cmd = redircmd(cmd, q, eq, O_WRONLY | O_CREAT, 1);
			break;
		}
	}
	return cmd;
}

struct cmd *
parseblock(char **ps, char *es)
{
	struct cmd *cmd;

	if (!peek(ps, es, "("))
		panic("parseblock");
	gettoken(ps, es, 0, 0);
	cmd = parseline(ps, es);
	if (!peek(ps, es, ")"))
		panic("syntax - missing )");
	gettoken(ps, es, 0, 0);
	cmd = parseredirs(cmd, ps, es);
	return cmd;
}

struct cmd *
parseexec(char **ps, char *es)
{
	char *q, *eq;
	int tok, argc;
	struct execcmd *cmd;
	struct cmd *ret;

	if (peek(ps, es, "("))
		return parseblock(ps, es);

	ret = execcmd();
	cmd = (struct execcmd *)ret;

	argc = 0;
	ret = parseredirs(ret, ps, es);
	while (!peek(ps, es, "|)&;")) {
		if ((tok = gettoken(ps, es, &q, &eq)) == 0)
			break;
		if (tok != 'a')
			panic("syntax");
		cmd->argv[argc] = q;
		cmd->eargv[argc] = eq;
		argc++;
		if (argc >= MAXARGS)
			panic("too many args");
		ret = parseredirs(ret, ps, es);
	}
	cmd->argv[argc] = 0;
	cmd->eargv[argc] = 0;
	return ret;
}

struct cmd *
nulterminate(struct cmd *cmd)
{
	int i;
	struct backcmd *bcmd;
	struct execcmd *ecmd;
	struct listcmd *lcmd;
	struct pipecmd *pcmd;
	struct redircmd *rcmd;

	if (cmd == 0)
		return 0;

	switch (cmd->type) {
	case EXEC:
		ecmd = (struct execcmd *)cmd;
		for (i = 0; ecmd->argv[i]; i++)
			*ecmd->eargv[i] = 0;
		break;

	case REDIR:
		rcmd = (struct redircmd *)cmd;
		nulterminate(rcmd->cmd);
		*rcmd->efile = 0;
		break;

	case PIPE:
		pcmd = (struct pipecmd *)cmd;
		nulterminate(pcmd->left);
		nulterminate(pcmd->right);
		break;

	case LIST:
		lcmd = (struct listcmd *)cmd;
		nulterminate(lcmd->left);
		nulterminate(lcmd->right);
		break;

	case BACK:
		bcmd = (struct backcmd *)cmd;
		nulterminate(bcmd->cmd);
		break;
	}
	return cmd;
}
