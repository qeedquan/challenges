/*

There is a Boolean Logic, you know :) Logic formulas include variables, which only could be false or true and operations between them. In this problem we have description of some logic function, built as a chain of operations on few input variables - and want to transform it to more plain form, namely full disjunctive normal form.

Details
Input consists of set of rules, each taking only 2 variables and naming result as some new variable.

it is easier for you to parse such rules
some variables could be reused, making full description more compact
Syntax for the rule is Z := X op Y where Z is result variable, X and Y could be prepended with negation operator, and the operation (op) itself could be one of:

and - conjunction (both operands need to be true)
or - disjunction (at least one needs to be true)
-> - implication (if X is true, then Y needs too)
eq - equality (operands should be equal)
xor - exclusive disjunction (operands should be different)
All variables are denoted with small latin letters (a ... z). Of them first four (a, b, c, d) are input variables, while others appear as results in rules. There are no loops in rule definitions (no feedbacks). One of variables (latest of letters) is considered output.

Full Disjunctive Normal Form consists of disjunction (or) of several parts, where every of those parts is conjunction (and) of all input variables with different set of negations applied to them each time. For example implication (mentioned above) is represented in FDNF as following:

x&y | ~x&y | ~x&~y
However, while x&y | ~x is also DNF, it is not "full" (rather, contracted by combining two parts of full form).

In the answer we use &, | signs instead and, or respectively - simply for compactness.

Input gives number of rules and the name of output variable.
Then rules follow, one per line.
Answer should provide full disjunctive normal form of four variables. Order and spaces do not matter.

Example:

input:
8 l
l := k and f
k := f -> j
e := d xor ~c
f := ~e xor a
g := ~e -> ~b
h := d eq g
i := h -> b
j := b or i

answer:
a&b&c&d | a&b&~c&~d | a&~b&~c&~d | ~a&b&~c&d | ~a&b&c&~d | ~a&~b&c&~d

*/

package main

import (
	"fmt"
	"go/ast"
	"go/token"
)

type Inst struct {
	op token.Token
	rt int
	ra int
	rb int
}

func main() {
	solve("l", []string{
		"l := k and f",
		"k := f -> j",
		"e := d xor ~c",
		"f := ~e xor a",
		"g := ~e -> ~b",
		"h := d eq g",
		"i := h -> b",
		"j := b or i",
	})

	solve("x", []string{
		"x := a and b",
	})

	solve("z", []string{
		"z := ~c eq ~d",
	})

	solve("r", []string{
		"r := a -> b",
	})

	solve("y", []string{
		"y := a xor b",
	})
}

func solve(name string, lines []string) error {
	vars, err := parse(lines)
	if err != nil {
		return err
	}
	if vars[name] == nil {
		return fmt.Errorf("variable %q does not exist", name)
	}

	insts, regn, regv := compile(vars[name])
	regs := make([]int, regn)

	fdnf(insts, regs, regv)
	return nil
}

func fdnf(insts []Inst, regs []int, regv int) {
	solutions := 0
	for a := range 2 {
		for b := range 2 {
			for c := range 2 {
				for d := range 2 {
					vals := []int{a, b, c, d}
					execute(insts, regs, vals)
					if regs[regv] == 0 {
						continue
					}

					if solutions > 0 {
						fmt.Printf(" | ")
					}
					for i := range vals {
						if i > 0 {
							fmt.Printf("&")
						}
						if vals[i] == 0 {
							fmt.Printf("~")
						}
						fmt.Printf("%c", 'a'+i)
					}
					solutions += 1
				}
			}
		}
	}
	fmt.Println()
	fmt.Println(solutions, "solutions found")
	fmt.Println()
}

func parse(lines []string) (vars map[string]ast.Expr, err error) {
	defer func() {
		if xerr := recover(); xerr != nil {
			err = xerr.(error)
		}
	}()

	vars = make(map[string]ast.Expr)
	for _, line := range lines {
		var (
			expr  ast.Expr
			name  string
			left  string
			op    string
			right string
		)
		_, err = fmt.Sscanf(line, "%s := %s %s %s", &name, &left, &op, &right)
		if err != nil {
			return nil, fmt.Errorf("invalid expression: %q", line)
		}

		expr, err = parsebinary(left, op, right)
		if err != nil {
			return nil, fmt.Errorf("invalid expression: %q", line)
		}

		if vars[name] != nil {
			return nil, fmt.Errorf("variable %q has already been assigned to", name)
		}

		if varloc(name) >= 0 {
			return nil, fmt.Errorf("cannot assign to reserved variables")
		}
		vars[name] = expr
	}

	for {
		var (
			fixpoint = true
			expand   bool
		)
		for name := range vars {
			vars[name], expand = expandvar(vars[name], vars)
			if expand {
				fixpoint = false
			}
		}
		if fixpoint {
			break
		}
	}
	return vars, nil
}

func parsebinary(left, op, right string) (ast.Expr, error) {
	binary := map[string]token.Token{
		"or":  token.OR,
		"and": token.AND,
		"xor": token.XOR,
		"eq":  token.EQL,
		"->":  token.ARROW,
	}

	if _, found := binary[op]; !found {
		return nil, fmt.Errorf("invalid binary expression")
	}

	lhs, err0 := parseunary(left)
	rhs, err1 := parseunary(right)
	if err0 != nil || err1 != nil {
		return nil, fmt.Errorf("invalid binary expression")
	}

	return &ast.BinaryExpr{
		X:  lhs,
		Op: binary[op],
		Y:  rhs,
	}, nil
}

func parseunary(value string) (ast.Expr, error) {
	var not bool
	for len(value) > 0 && value[0] == '~' {
		value = value[1:]
		not = !not
	}
	if len(value) == 0 {
		return nil, fmt.Errorf("invalid unary expression")
	}

	var expr ast.Expr = &ast.BasicLit{Value: value}
	if not {
		expr = &ast.UnaryExpr{Op: token.NOT, X: expr}
	}
	return expr, nil
}

func expandvar(expr ast.Expr, vars map[string]ast.Expr) (ast.Expr, bool) {
	var expandx, expandy bool
	switch node := expr.(type) {
	case *ast.BinaryExpr:
		node.X, expandx = expandvar(node.X, vars)
		node.Y, expandy = expandvar(node.Y, vars)
		return node, expandx || expandy

	case *ast.UnaryExpr:
		node.X, expandx = expandvar(node.X, vars)
		return node, expandx

	case *ast.BasicLit:
		if vars[node.Value] != nil {
			return vars[node.Value], true
		}
		if varloc(node.Value) < 0 {
			panic(fmt.Errorf("invalid variable %q", node.Value))
		}
		return node, false

	default:
		panic("unreachable")
	}
}

func compile(expr ast.Expr) ([]Inst, int, int) {
	var (
		insts []Inst
		regn  int
		regi  int
		regv  int
	)
	regv = treecompile(expr, &insts, &regi, &regn)
	return insts, regn, regv
}

func treecompile(expr ast.Expr, insts *[]Inst, regi, regn *int) int {
	switch node := expr.(type) {
	case *ast.BinaryExpr:
		regl := treecompile(node.X, insts, regi, regn)
		regr := treecompile(node.Y, insts, regi, regn)
		*insts = append(*insts, Inst{
			op: node.Op,
			rt: regl,
			ra: regl,
			rb: regr,
		})
		*regi -= 1
		return regl

	case *ast.UnaryExpr:
		regl := treecompile(node.X, insts, regi, regn)
		*insts = append(*insts, Inst{
			op: node.Op,
			rt: regl,
			ra: regl,
		})
		return regl

	case *ast.BasicLit:
		regl := *regi
		*regi += 1
		*regn = max(*regn, *regi)
		*insts = append(*insts, Inst{
			op: token.VAR,
			rt: regl,
			ra: varloc(node.Value),
		})

		return regl

	default:
		panic("unreachable")
	}
}

func execute(insts []Inst, regs, vals []int) {
	for _, inst := range insts {
		rt := inst.rt
		ra := inst.ra
		rb := inst.rb

		switch inst.op {
		case token.NOT:
			regs[rt] = ^regs[ra] & 1
		case token.OR:
			regs[rt] = regs[ra] | regs[rb]
		case token.AND:
			regs[rt] = regs[ra] & regs[rb]
		case token.XOR:
			regs[rt] = regs[ra] ^ regs[rb]
		case token.EQL:
			if regs[ra] == regs[rb] {
				regs[rt] = 1
			} else {
				regs[rt] = 0
			}
		case token.ARROW:
			regs[rt] = (^regs[ra] | regs[rb]) & 1
		case token.VAR:
			regs[rt] = vals[ra]
		default:
			panic("unreachable")
		}
	}
}

func varloc(name string) int {
	switch name {
	case "a":
		return 0
	case "b":
		return 1
	case "c":
		return 2
	case "d":
		return 3
	}
	return -1
}
