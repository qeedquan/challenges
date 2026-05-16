package main

import "fmt"

type Rule int

const (
	EMPTY Rule = iota
	SENTENCE
	TRANS_SENTENCE
	INTRANS_SENTENCE
	SUBJECT
	OBJECT
	NOUN_PHRASE
	MODIFIED_NOUN
	MODIFIER
	VERB_PHRASE
	INTRANS_VERB_PHRASE
	PREP_PHRASE
	NOUN
	TRANS_VERB
	INTRANS_VERB
	ARTICLE
	ADJECTIVE
	ADVERB
	PREPOSITION
)

type Grammar struct {
	state    int
	substate int
}

func main() {
	solve([]string{"sentence", "noun", "sentence"})
}

func solve(lines []string) {
	var grammar Grammar
	for _, line := range lines {
		fmt.Println(grammar.Parse(line))
	}
}

func (g *Grammar) Parse(input string) string {
	rules := map[string]Rule{
		"sentence":            SENTENCE,
		"trans-sentence":      TRANS_SENTENCE,
		"intrans-sentence":    INTRANS_SENTENCE,
		"subject":             SUBJECT,
		"object":              OBJECT,
		"noun-phrase":         NOUN_PHRASE,
		"modified-noun":       MODIFIED_NOUN,
		"modifier":            MODIFIER,
		"verb-phrase":         VERB_PHRASE,
		"intrans-verb-phrase": INTRANS_VERB_PHRASE,
		"prep-phrase":         PREP_PHRASE,
		"noun":                NOUN,
		"trans-verb":          TRANS_VERB,
		"intrans-verb":        INTRANS_VERB,
		"article":             ARTICLE,
		"adjective":           ADJECTIVE,
		"adverb":              ADVERB,
		"preposition":         PREPOSITION,
		"empty":               EMPTY,
	}
	return g.Generate(rules[input])
}

func (g *Grammar) Generate(rule Rule) string {
	switch rule {
	case SENTENCE:
		g.substate++
		switch g.substate%2 + 1 {
		case 1:
			return g.Generate(TRANS_SENTENCE)
		default:
			return g.Generate(INTRANS_SENTENCE)
		}

	case TRANS_SENTENCE:
		a := g.Generate(SUBJECT)
		b := g.Generate(VERB_PHRASE)
		c := g.Generate(OBJECT)
		d := g.Generate(PREP_PHRASE)
		return fmt.Sprintf("%s %s %s%s", a, b, c, d)

	case INTRANS_SENTENCE:
		a := g.Generate(SUBJECT)
		b := g.Generate(INTRANS_VERB_PHRASE)
		c := g.Generate(PREP_PHRASE)
		return fmt.Sprintf("%s %s %s", a, b, c)

	case SUBJECT, OBJECT:
		return g.Generate(NOUN_PHRASE)

	case NOUN_PHRASE:
		a := g.Generate(ARTICLE)
		b := g.Generate(MODIFIED_NOUN)
		return fmt.Sprintf("%s %s", a, b)

	case MODIFIED_NOUN:
		g.substate++
		if g.substate%2+1 == 1 {
			return g.Generate(NOUN)
		} else {
			a := g.Generate(MODIFIER)
			b := g.Generate(NOUN)
			return a + " " + b
		}

	case MODIFIER:
		g.substate++
		if g.substate%2+1 == 1 {
			return g.Generate(ADJECTIVE)
		} else {
			a := g.Generate(ADVERB)
			b := g.Generate(ADJECTIVE)
			return a + " " + b
		}

	case VERB_PHRASE:
		g.substate++
		if g.substate%2+1 == 1 {
			return g.Generate(TRANS_VERB)
		} else {
			a := g.Generate(ADVERB)
			b := g.Generate(TRANS_VERB)
			return a + " " + b
		}

	case INTRANS_VERB_PHRASE:
		g.substate++
		if g.substate%2+1 == 1 {
			return g.Generate(INTRANS_VERB)
		} else {
			a := g.Generate(ADVERB)
			b := g.Generate(INTRANS_VERB)
			return a + " " + b
		}

	case PREP_PHRASE:
		g.substate++
		if g.substate%2+1 == 1 {
			a := g.Generate(PREPOSITION)
			b := g.Generate(NOUN_PHRASE)
			return a + " " + b
		} else {
			return g.Generate(EMPTY)
		}

	case NOUN:
		g.substate++
		switch g.substate%5 + 1 {
		case 1:
			return "man"
		case 2:
			return "dog"
		case 3:
			return "fish"
		case 4:
			return "computer"
		case 5:
			return "waves"
		}

	case TRANS_VERB:
		g.substate++
		switch g.substate%4 + 1 {
		case 1:
			return "struck"
		case 2:
			return "saw"
		case 3:
			return "bit"
		case 4:
			return "took"
		}

	case INTRANS_VERB:
		g.substate++
		switch g.substate%4 + 1 {
		case 1:
			return "slept"
		case 2:
			return "jumped"
		case 3:
			return "walked"
		case 4:
			return "swam"
		}

	case ARTICLE:
		g.substate++
		if g.substate%2+1 == 1 {
			return "the"
		} else {
			return "a"
		}

	case ADJECTIVE:
		g.substate++
		switch g.substate%4 + 1 {
		case 1:
			return "green"
		case 2:
			return "small"
		case 3:
			return "rabid"
		case 4:
			return "quick"
		}

	case ADVERB:
		g.substate++
		switch g.substate%3 + 1 {
		case 1:
			return "nearly"
		case 2:
			return "suddenly"
		case 3:
			return "restlessly"
		}

	case PREPOSITION:
		g.substate++
		switch g.substate%3 + 1 {
		case 1:
			return "on"
		case 2:
			return "over"
		case 3:
			return "through"
		}

	case EMPTY:
	}
	return ""
}
