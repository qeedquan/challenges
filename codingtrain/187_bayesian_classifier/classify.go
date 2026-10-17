/*

https://en.wikipedia.org/wiki/Naive_Bayes_classifier
https://en.wikipedia.org/wiki/Additive_smoothing

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"regexp"
	"strings"
)

var flags struct {
	sentence string
	file     string
}

func main() {
	parseFlags()

	frankenstein := loadStrings("books/frankenstein.txt")
	prideprejudice := loadStrings("books/pride_and_prejudice.txt")
	warworlds := loadStrings("books/war_of_the_worlds.txt")

	classifier := NewClassifier()
	for _, line := range frankenstein {
		classifier.Train(line, "horror")
	}
	for _, line := range prideprejudice {
		classifier.Train(line, "romance")
	}
	for _, line := range warworlds {
		classifier.Train(line, "scifi")
	}

	fmt.Println(classifier.Guess(flags.sentence))
}

func parseFlags() {
	flag.Usage = usage
	flag.StringVar(&flags.file, "file", "", "specify input as a file")
	flag.Parse()

	flags.sentence = "It was a dark and stormy night."
	if flag.NArg() >= 1 {
		flags.sentence = strings.Join(flag.Args(), " ")
	}

	if flags.file != "" {
		data, err := os.ReadFile(flags.file)
		if err != nil {
			log.Fatal(err)
		}
		flags.sentence = string(data)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] sentence")
	flag.PrintDefaults()
	os.Exit(2)
}

func loadStrings(name string) []string {
	data, err := os.ReadFile(name)
	if err != nil {
		log.Fatal(err)
	}
	return strings.Split(string(data), "\n")
}

type Dictionary map[string]int

type Category struct {
	documentCount int
	wordCount     int
}

type Classifier struct {
	// Dictionary to store word counts per category
	// Structure: { word: { category1: count, category2: count, ... } }
	wordCounts map[string]Dictionary

	// Store category statistics
	// Structure: { category: { documentCount: N, wordCount: N } }
	// documentCount: how many texts for this category
	// wordCount: total words across all texts for this category
	categories map[string]*Category

	// Total number of documents across all categories
	totalDocuments int

	// Total unique words (vocabulary size)
	// Used for Laplace smoothing to handle unseen words
	vocabularySize int
}

func NewClassifier() *Classifier {
	return &Classifier{
		wordCounts: make(map[string]Dictionary),
		categories: make(map[string]*Category),
	}
}

// Add a word to the vocabulary for a specific category
// This is called during training to build our word frequency database
func (c *Classifier) AddWord(word, category string) {
	// First time seeing this word? Add it to vocabulary
	_, found := c.wordCounts[word]
	if !found {
		c.wordCounts[word] = make(Dictionary)
		c.vocabularySize += 1
	}

	// Increment: how many times this word appears in this category
	c.wordCounts[word][category] += 1

	// Also increment total word count for this category
	if c.categories[category] == nil {
		c.categories[category] = new(Category)
	}
	c.categories[category].wordCount += 1
}

// Train the classifier with a text sample and its category
func (c *Classifier) Train(text, category string) {
	// Initialize category if first time seeing it
	if c.categories[category] == nil {
		c.categories[category] = new(Category)
	}

	// Increment document count for this category
	c.categories[category].documentCount += 1
	c.totalDocuments += 1

	// Split text into words and process each one
	for _, word := range splitWords(text) {
		c.AddWord(word, category)
	}
}

// Calculate P(word|category)
// How likely is this word given the category?
func (c *Classifier) wordProbability(word, category string) float64 {
	// How many times did this word appear in this category?
	// Is this a word we've seen?
	wordCount := 0
	if c.wordCounts[word] != nil && c.wordCounts[word][category] != 0 {
		wordCount = c.wordCounts[word][category]
	}

	// Total words in this category
	categoryWordCount := c.categories[category].wordCount

	// LAPLACE SMOOTHING (add-one smoothing):
	// We add 1 to this word's count to prevent zero probabilities
	// But we also add vocabularySize to denominator since we are essentially
	// adding 1 count for every possible word

	// Example: Category has 500 real words, vocabulary has 1000 unique words
	//   P("amazing") = (0 + 1) / (500 + 1000) = 1/1500 (unseen word)
	//   P("happy") = (10 + 1) / (500 + 1000) = 11/1500 (seen 10 times)
	//   All 1000 word probabilities will sum to exactly 1.0 ✓
	return float64(wordCount+1) / float64(categoryWordCount+c.vocabularySize)
}

// Calculate P(category) - the prior probability of each category
// This is how common each category is in our training data
func (c *Classifier) categoryProbability(category string) float64 {
	if c.categories[category] == nil {
		return 0
	}
	return float64(c.categories[category].documentCount) / float64(c.totalDocuments)
}

// Classify new text using Naive Bayes theorem
// Returns probability that the text belongs to each category
func (c *Classifier) Guess(text string) map[string]float64 {
	// Clean and split the input text into words
	words := splitWords(text)
	results := make(map[string]float64)

	// Calculate probability for each category we've trained on
	for category := range c.categories {
		// Start with the prior probability P(category)
		// How common is this category in our training data?
		probability := c.categoryProbability(category)

		// For each word, multiply by P(word|category)
		// This assumes words are independent (the "naive" assumption)
		for _, word := range words {
			probability *= c.wordProbability(word, category)
		}
		results[category] = probability
	}

	// NORMALIZATION: Make all probabilities sum to 1
	// This converts raw scores to proper probabilities
	probabilitySum := 0.0
	for category := range c.categories {
		probabilitySum += results[category]
	}
	for category := range c.categories {
		if probabilitySum != 0 {
			results[category] /= probabilitySum
		}
		results[category] *= 100
	}
	return results
}

// Split the text and filter words in the text
func splitWords(text string) []string {
	text = strings.ToLower(text)
	re := regexp.MustCompile(`\W+`)
	words := []string{}
	for _, word := range re.Split(text, -1) {
		if word != "" {
			words = append(words, word)
		}
	}
	return words
}
