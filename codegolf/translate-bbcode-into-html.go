/*

BBCode is a markup language commonly used in webforum software in the 2000s and 2010s.
Your task is to write a program or function that translates BBCode to HTML according to the following spec.
(BBCode has wildly varying implementations in the real world, but for this challenge we're defining it like this):

Tags
[b]foo[/b] → <strong>foo</strong>
[i]foo[/i] → <em>foo</em>
[u]foo[/u] → <u>foo</u>
[s]foo[/s] → <s>foo</s>
[code]foo[/code] → <code>foo</code>. Tags inside [code] are not parsed.
[url]https://www.example.com[/url] → <a href="https://www.example.com">https://www.example.com</a>
[url=https://www.example.com]foo[/url] → <a href="https://www.example.com">foo</a>
[img]https://www.example.com[/img] → <img src="https://www.example.com"> (no HTML closing tag)
[color=value]foo[/color] → <span style="color:value">foo</span>
[size=value]foo[/size] → <span style="font-size:value">foo</span>
[quote]foo[/quote] → <blockquote>foo</blockquote>
[quote=author]foo[/quote] → <blockquote><cite>author</cite>foo</blockquote>
Details
BBCode tags are case insensitive [b][/b] and [B][/b] and [B][/B] are all valid), but HTML output tags must be lowercase.
Nested tags are valid (see Nesting section for further details): [b][i]text[/i][/b] → <strong><em>text</em></strong>
Unmatched, malformed, or unknown tags are left as literal text: [b]foo → [b]foo, [b ]foo[/b] → [b ]foo[/b], [/b] → [/b], [bar]foo[/bar] → [bar]foo[/bar]
All attributes are valid; don't worry about URI validation, color/size name validation, anti-XSS, etc.
Empty tags are valid: [b][/b] → <strong></strong>
Input attributes and input text inside (valid) tags (except for [code]) will not contain[, ], =, or ".

Nesting
Tags close in LIFO order (like a stack).

Inputs will always have properly nesting tags.

Test cases
Input: [b]bold[/b]
Output: <strong>bold</strong>

Input: [B]BOLD[/B]
Output: <strong>BOLD</strong>

Input: [b][i]bold italic[/i][/b]
Output: <strong><em>bold italic</em></strong>

Input: [url]http://example.com[/url]
Output: <a href="http://example.com">http://example.com</a>

Input: [url=http://example.com]click here[/url]
Output: <a href="http://example.com">click here</a>

Input: [img]http://example.com/image.png[/img]
Output: <img src="http://example.com/image.png">

Input: [color=red]red text[/color]
Output: <span style="color:red">red text</span>

Input: [size=20px]big text[/size]
Output: <span style="font-size:20px">big text</span>

Input: [quote]someone said this[/quote]
Output: <blockquote>someone said this</blockquote>

Input: [quote=John]someone said this[/quote]
Output: <blockquote><cite>John</cite>someone said this</blockquote>

Input: [b]unclosed tag
Output: [b]unclosed tag

Input: unopened tag[/b]
Output: unopened tag[/b]

Input: [unknown]text[/unknown]
Output: [unknown]text[/unknown]

Input: [b]nested [i]tags[/i] work[/b]
Output: <strong>nested <em>tags</em> work</strong>

Input: [url=http://test.com][b]bold link[/b][/url]
Output: <a href="http://test.com"><strong>bold link</strong></a>

Input: plain text with no tags
Output: plain text with no tags

Input: [code]<script>alert('hi')</script>[/code]
Output: <code><script>alert('hi')</script></code>

Input: [CoLoR=blue]case test[/color]
Output: <span style="color:blue">case test</span>

Input: [code][b]not bold[/b][/code]
Output: <code>[b]not bold[/b]</code>

Input: [code][url=http://test.com]link[/url][/code]
Output: <code>[url=http://test.com]link[/url]</code>

Input: [b][code]tags[/code] outside[/b]
Output: <strong><code>tags</code> outside</strong>

Input: [b][i][u]triple nested[/u][/i][/b]
Output: <strong><em><u>triple nested</u></em></strong>

Input: [color=red][b]colored bold[/b][/color]
Output: <span style="color:red"><strong>colored bold</strong></span>

Input: [quote=Alice][b]bold quote[/b][/quote]
Output: <blockquote><cite>Alice</cite><strong>bold quote</strong></blockquote>

Input: [url=http://test.com][color=blue]styled link[/color][/url]
Output: <a href="http://test.com"><span style="color:blue">styled link</span></a>

Input: [code][code]nested code[/code][/code]
Output: <code>[code]nested code[/code]</code>

Input: [u]foo[/u]
Output: <u>foo</u>

Input: plaintext
Output: plaintext

Input: [code]left[/code][code]right[/code]
Output: <code>left</code><code>right</code>
This is code-golf. Standard loopholes are forbidden.

*/

package main

import (
	"fmt"
	"strings"
)

type Parser struct {
	input string

	eof  bool
	tok  int
	tag  string
	attr string
	text string

	stack []Tag
	ncode int
}

type Tag struct {
	tag  string
	attr string
	text string
}

func main() {
	test(`[b]bold[/b]`, `<strong>bold</strong>`)
	test(`[B]BOLD[/B]`, `<strong>BOLD</strong>`)
	test(`[b][i]bold italic[/i][/b]`, `<strong><em>bold italic</em></strong>`)
	test(`[url]http://example.com[/url]`, `<a href="http://example.com">http://example.com</a>`)
	test(`[url=https://www.example.com]foo[/url]`, `<a href="https://www.example.com">foo</a>`)
	test(`[img]http://example.com/image.png[/img]`, `<img src="http://example.com/image.png">`)
	test(`[color=red]red text[/color]`, `<span style="color:red">red text</span>`)
	test(`[size=20px]big text[/size]`, `<span style="font-size:20px">big text</span>`)
	test(`[quote]someone said this[/quote]`, `<blockquote>someone said this</blockquote>`)
	test(`[quote=John]someone said this[/quote]`, `<blockquote><cite>John</cite>someone said this</blockquote>`)
	test(`[b]unclosed tag`, `[b]unclosed tag`)
	test(`unopened tag[/b]`, `unopened tag[/b]`)
	test(`[unknown]text[/unknown]`, `[unknown]text[/unknown]`)
	test(`[b]nested [i]tags[/i] work[/b]`, `<strong>nested <em>tags</em> work</strong>`)
	test(`[url=http://test.com][b]bold link[/b][/url]`, `<a href="http://test.com"><strong>bold link</strong></a>`)
	test(`plain text with no tags`, `plain text with no tags`)
	test(`[code]<script>alert('hi')</script>[/code]`, `<code><script>alert('hi')</script></code>`)
	test(`[CoLoR=blue]case test[/color]`, `<span style="color:blue">case test</span>`)
	test(`[code][b]not bold[/b][/code]`, `<code>[b]not bold[/b]</code>`)
	test(`[code][url=http://test.com]link[/url][/code]`, `<code>[url=http://test.com]link[/url]</code>`)
	test(`[b][code]tags[/code] outside[/b]`, `<strong><code>tags</code> outside</strong>`)
	test(`[b][i][u]triple nested[/u][/i][/b]`, `<strong><em><u>triple nested</u></em></strong>`)
	test(`[color=red][b]colored bold[/b][/color]`, `<span style="color:red"><strong>colored bold</strong></span>`)
	test(`[quote=Alice][b]bold quote[/b][/quote]`, `<blockquote><cite>Alice</cite><strong>bold quote</strong></blockquote>`)
	test(`[url=http://test.com][color=blue]styled link[/color][/url]`, `<a href="http://test.com"><span style="color:blue">styled link</span></a>`)
	test(`[code][code]nested code[/code][/code]`, `<code>[code]nested code[/code]</code>`)
	test(`[u]foo[/u]`, `<u>foo</u>`)
	test(`plaintext`, `plaintext`)
	test(`[code]left[/code][code]right[/code]`, `<code>left</code><code>right</code>`)
	test(`[b][/b]`, `<strong></strong>`)
	test(`[code][code][code]double nested code[/code][/code][/code]`, `<code>[code][code]double nested code[/code][/code]</code>`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(input, expected string) {
	output := convert(input)
	fmt.Println(output)
	fmt.Println(expected)
	fmt.Println()
	assert(output == expected)
}

func convert(input string) string {
	p := Parser{
		input: input,
		stack: make([]Tag, 1),
	}
	for {
		p.scan()
		if p.eof {
			break
		}

		switch p.tok {
		case '[':
			p.tagstart()
		case ']':
			p.tagend()
		case 'T':
			p.tagtext(p.text)
		default:
			panic("unreachable")
		}
	}
	return p.flush()
}

func (p *Parser) scan() {
	if len(p.input) == 0 {
		p.eof = true
	}
	if p.eof {
		return
	}

	i := strings.IndexByte(p.input, '[')
	if i < 0 {
		i = len(p.input)
	}
	if i > 0 {
		p.tok = 'T'
		p.text = p.input[:i]
		p.input = p.input[i:]
		return
	}

	j := strings.IndexByte(p.input, ']')
	if j < 0 {
		p.tok = 'T'
		p.text = p.input
		p.input = ""
		return
	}

	p.tok = '['
	p.tag = p.input[i+1 : j]
	p.text = p.input[i : j+1]
	p.attr = ""
	if strings.HasPrefix(p.tag, "/") {
		p.tag = p.tag[1:]
		p.tok = ']'
	}
	k := strings.IndexByte(p.tag, '=')
	if k > 0 {
		p.attr = p.tag[k+1:]
		p.tag = p.tag[:k]
	}
	p.tag = strings.ToLower(p.tag)
	p.input = p.input[j+1:]
}

func (p *Parser) flush() string {
	output := ""
	for len(p.stack) > 0 {
		tos := p.pop()

		output = tos.text + output
		if tos.tag == "" {
			continue
		}

		output = "]" + output
		if tos.attr != "" {
			output = "=" + tos.attr + output
		}
		output = "[" + tos.tag + output
	}
	return output
}

func (p *Parser) top() *Tag {
	return &p.stack[len(p.stack)-1]
}

func (p *Parser) pop() *Tag {
	tos := p.top()
	p.stack = p.stack[:len(p.stack)-1]
	return tos
}

func (p *Parser) tagtext(text string) {
	tos := p.top()
	tos.text += text
}

func (p *Parser) tagstart() {
	lut := map[string]bool{
		"b":     false,
		"i":     false,
		"u":     false,
		"s":     false,
		"code":  false,
		"url":   true,
		"img":   false,
		"color": true,
		"size":  true,
		"quote": true,
	}
	if p.tag == "code" {
		if p.ncode += 1; p.ncode > 1 {
			p.tagtext(p.text)
			return
		}
	} else if p.ncode >= 1 {
		p.tagtext(p.text)
		return
	}

	hasattr, found := lut[p.tag]
	if found && (!(hasattr && p.attr == "") || hasattr) {
		p.stack = append(p.stack, Tag{
			tag:  p.tag,
			attr: p.attr,
		})
	} else {
		p.tagtext(p.text)
	}
}

func (p *Parser) tagend() {
	tos := p.top()
	if tos.tag == "code" && p.ncode > 1 {
		p.ncode -= 1
		p.tagtext(p.text)
		return
	}
	if tos.tag == p.tag {
		text := ""
		switch tos.tag {
		case "b":
			text += fmt.Sprintf("<strong>%s</strong>", tos.text)
		case "i":
			text += fmt.Sprintf("<em>%s</em>", tos.text)
		case "code":
			p.ncode -= 1
			fallthrough
		case "u", "s":
			text += fmt.Sprintf("<%s>%s</%s>", tos.tag, tos.text, tos.tag)
		case "url":
			attr := tos.attr
			if attr == "" {
				attr = tos.text
			}
			text += fmt.Sprintf("<a href=\"%s\">%s</a>", attr, tos.text)
		case "img":
			text += fmt.Sprintf("<img src=\"%s\">", tos.text)
		case "color":
			text += fmt.Sprintf("<span style=\"color:%s\">%s</span>", tos.attr, tos.text)
		case "size":
			text += fmt.Sprintf("<span style=\"font-size:%s\">%s</span>", tos.attr, tos.text)
		case "quote":
			if tos.attr == "" {
				text += fmt.Sprintf("<blockquote>%s</blockquote>", tos.text)
			} else {
				text += fmt.Sprintf("<blockquote><cite>%s</cite>%s</blockquote>", tos.attr, tos.text)
			}
		}
		p.pop()
		p.tagtext(text)
	} else {
		p.tagtext(p.text)
	}
}
