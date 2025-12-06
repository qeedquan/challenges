/*

In the smallest amount of steps, prove

(p ⟹ q) ⟺¬ p ∨ q

We base the proof system on this website. The related functionalities are:

Assumption. Assume that some statement is true. This creates a new scope in which this statement and all proven statements in the outside scope are true. (Obviously, the (p⟹q)⟺¬p∨q proof must contain this statement in the outermost scope without any assumptions.)

Reiteration. Restate a statement in this scope or an outer scope. This is required since...

Implication Introduction. Introduces the implication of ϕ⟹ψ in the outer scope if the last statement ψ is inside the ϕ scope.

Implication Elimination. Given ϕ and ϕ⟹ψ, deduce ψ.

Biconditional Introduction. Given ϕ⟹ψ and ψ⟹ϕ, deduce ϕ⟺ψ.

Biconditional Elimination. Given ϕ⟺ψ, deduce ϕ⟹ψ and ψ⟹ϕ.

Negation Introduction. Given ϕ⟹ψ and ϕ⟹¬ψ, deduce ¬ϕ.

Negation Elimination. Given ¬¬ϕ, deduce ϕ.

And Introduction. Given ϕ and ψ, deduce ϕ∧ψ.

And Elimination. Given ϕ∧ψ, deduce ϕ and ψ.

Or Introduction. Given ϕ, deduce ϕ∨ψ and ψ∨ϕ.

Or Elimination. Given ϕ∨ψ, ϕ⟹χ, and ψ⟹χ, deduce χ.

Delete. Only relevant with the online implementation of the proof system, which gives all possible results. Delete any unnecessary results.
(For instance, applying Biconditional Introduction gives both ϕ⟺ψ and ψ⟺ϕ. These extra results do not count to the line total and can be deleted.

Here's my proof (on the website, select Load and upload this file) with 41 steps, which may be optimal (but I doubt it):

<proof>
  <step>
    <number>1</number>
    <sentence>p => q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>2</number>
    <sentence>~(~p | q)</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>3</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>4</number>
    <sentence>~(~p | q)</sentence>
    <justification>Reiteration</justification>
    <antecedent>2</antecedent>
  </step>
  <step>
    <number>5</number>
    <sentence>p => ~(~p | q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>3</antecedent>
    <antecedent>4</antecedent>
  </step>
  <step>
    <number>6</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>7</number>
    <sentence>q</sentence>
    <justification>Implication Elimination</justification>
    <antecedent>1</antecedent>
    <antecedent>6</antecedent>
  </step>
  <step>
    <number>8</number>
    <sentence>~p | q</sentence>
    <justification>Or Introduction</justification>
    <antecedent>7</antecedent>
  </step>
  <step>
    <number>9</number>
    <sentence>p => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>6</antecedent>
    <antecedent>8</antecedent>
  </step>
  <step>
    <number>10</number>
    <sentence>~p</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>9</antecedent>
    <antecedent>5</antecedent>
  </step>
  <step>
    <number>11</number>
    <sentence>~(~p | q) => ~p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>2</antecedent>
    <antecedent>10</antecedent>
  </step>
  <step>
    <number>12</number>
    <sentence>~(~p | q)</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>13</number>
    <sentence>~p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>14</number>
    <sentence>~(~p | q)</sentence>
    <justification>Reiteration</justification>
    <antecedent>12</antecedent>
  </step>
  <step>
    <number>15</number>
    <sentence>~p => ~(~p | q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>13</antecedent>
    <antecedent>14</antecedent>
  </step>
  <step>
    <number>16</number>
    <sentence>~p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>17</number>
    <sentence>~p | q</sentence>
    <justification>Or Introduction</justification>
    <antecedent>16</antecedent>
  </step>
  <step>
    <number>18</number>
    <sentence>~p => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>16</antecedent>
    <antecedent>17</antecedent>
  </step>
  <step>
    <number>19</number>
    <sentence>~~p</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>18</antecedent>
    <antecedent>15</antecedent>
  </step>
  <step>
    <number>20</number>
    <sentence>~(~p | q) => ~~p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>12</antecedent>
    <antecedent>19</antecedent>
  </step>
  <step>
    <number>21</number>
    <sentence>~~(~p | q)</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>11</antecedent>
    <antecedent>20</antecedent>
  </step>
  <step>
    <number>22</number>
    <sentence>~p | q</sentence>
    <justification>Negation Elimination</justification>
    <antecedent>21</antecedent>
  </step>
  <step>
    <number>23</number>
    <sentence>(p => q) => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>1</antecedent>
    <antecedent>22</antecedent>
  </step>
  <step>
    <number>24</number>
    <sentence>~p | q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>25</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>26</number>
    <sentence>~p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>27</number>
    <sentence>~q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>28</number>
    <sentence>p</sentence>
    <justification>Reiteration</justification>
    <antecedent>25</antecedent>
  </step>
  <step>
    <number>29</number>
    <sentence>~q => p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>27</antecedent>
    <antecedent>28</antecedent>
  </step>
  <step>
    <number>30</number>
    <sentence>~q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>31</number>
    <sentence>~p</sentence>
    <justification>Reiteration</justification>
    <antecedent>26</antecedent>
  </step>
  <step>
    <number>32</number>
    <sentence>~q => ~p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>30</antecedent>
    <antecedent>31</antecedent>
  </step>
  <step>
    <number>33</number>
    <sentence>~~q</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>29</antecedent>
    <antecedent>32</antecedent>
  </step>
  <step>
    <number>34</number>
    <sentence>q</sentence>
    <justification>Negation Elimination</justification>
    <antecedent>33</antecedent>
  </step>
  <step>
    <number>35</number>
    <sentence>~p => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>26</antecedent>
    <antecedent>34</antecedent>
  </step>
  <step>
    <number>36</number>
    <sentence>q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>37</number>
    <sentence>q => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>36</antecedent>
    <antecedent>36</antecedent>
  </step>
  <step>
    <number>38</number>
    <sentence>q</sentence>
    <justification>Or Elimination</justification>
    <antecedent>24</antecedent>
    <antecedent>35</antecedent>
    <antecedent>37</antecedent>
  </step>
  <step>
    <number>39</number>
    <sentence>p => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>25</antecedent>
    <antecedent>38</antecedent>
  </step>
  <step>
    <number>40</number>
    <sentence>~p | q => (p => q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>24</antecedent>
    <antecedent>39</antecedent>
  </step>
  <step>
    <number>41</number>
    <sentence>p => q <=> ~p | q</sentence>
    <justification>Biconditional Introduction</justification>
    <antecedent>23</antecedent>
    <antecedent>40</antecedent>
  </step>
</proof>

*/

package main

import "fmt"

func main() {
	fmt.Println(PROOF)
}

/*

@Anders Kaseorg

sentence                     justification
1.	 p => q	                 Assumption
2.	 ~(~p | q)	             Assumption
3.	 p	                     Assumption
4.	 q	                     Implication Elimination: 1, 3
5.	 ~p | q	                 Or Introduction: 4
6.	 p => ~p | q             Implication Introduction: 3, 5
7.	 p                       Assumption
8.	 ~(~p | q)               Reiteration: 2
9.	 p => ~(~p | q)          Implication Introduction: 7, 8
10.	 ~p                      Negation Introduction: 6, 9
11.	 ~p | q                  Or Introduction: 10
12.	 ~(~p | q) => ~p | q     Implication Introduction: 2, 11
13.	 ~(~p | q)               Assumption
14.	 ~(~p | q) => ~(~p | q)	 Implication Introduction: 13, 13
15.	 ~~(~p | q)              Negation Introduction: 12, 14
16.	 ~p | q                  Negation Elimination: 15
17.	(p => q) => ~p | q       Implication Introduction: 1, 16
18.	 ~p | q                  Assumption
19.	 p                       Assumption
20.	 ~p                      Assumption
21.	 ~q                      Assumption
22.	 p                       Reiteration: 19
23.	 ~q => p                 Implication Introduction: 21, 22
24.	 ~q                      Assumption
25.	 ~p	                     Reiteration: 20
26.	 ~q => ~p                Implication Introduction: 24, 25
27.	 ~~q                     Negation Introduction: 23, 26
28.	 q                       Negation Elimination: 27
29.	 ~p => q                 Implication Introduction: 20, 28
30.	 q                       Assumption
31.	 q => q                  Implication Introduction: 30, 30
32.	 q                       Or Elimination: 18, 29, 31
33.	 p => q                  Implication Introduction: 19, 32
34.	~p | q => (p => q)       Implication Introduction: 18, 33
35.	p => q <=> ~p | q        Biconditional Introduction: 17, 34

*/

const PROOF = `
<proof>
  <step>
    <number>1</number>
    <sentence>p => q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>2</number>
    <sentence>~(~p | q)</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>3</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>4</number>
    <sentence>q</sentence>
    <justification>Implication Elimination</justification>
    <antecedent>1</antecedent>
    <antecedent>3</antecedent>
  </step>
  <step>
    <number>5</number>
    <sentence>~p | q</sentence>
    <justification>Or Introduction</justification>
    <antecedent>4</antecedent>
  </step>
  <step>
    <number>6</number>
    <sentence>p => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>3</antecedent>
    <antecedent>5</antecedent>
  </step>
  <step>
    <number>7</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>8</number>
    <sentence>~(~p | q)</sentence>
    <justification>Reiteration</justification>
    <antecedent>2</antecedent>
  </step>
  <step>
    <number>9</number>
    <sentence>p => ~(~p | q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>7</antecedent>
    <antecedent>8</antecedent>
  </step>
  <step>
    <number>10</number>
    <sentence>~p</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>6</antecedent>
    <antecedent>9</antecedent>
  </step>
  <step>
    <number>11</number>
    <sentence>~p | q</sentence>
    <justification>Or Introduction</justification>
    <antecedent>10</antecedent>
  </step>
  <step>
    <number>12</number>
    <sentence>~(~p | q) => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>2</antecedent>
    <antecedent>11</antecedent>
  </step>
  <step>
    <number>13</number>
    <sentence>~(~p | q)</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>14</number>
    <sentence>~(~p | q) => ~(~p | q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>13</antecedent>
    <antecedent>13</antecedent>
  </step>
  <step>
    <number>15</number>
    <sentence>~~(~p | q)</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>12</antecedent>
    <antecedent>14</antecedent>
  </step>
  <step>
    <number>16</number>
    <sentence>~p | q</sentence>
    <justification>Negation Elimination</justification>
    <antecedent>15</antecedent>
  </step>
  <step>
    <number>17</number>
    <sentence>(p => q) => ~p | q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>1</antecedent>
    <antecedent>16</antecedent>
  </step>
  <step>
    <number>18</number>
    <sentence>~p | q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>19</number>
    <sentence>p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>20</number>
    <sentence>~p</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>21</number>
    <sentence>~q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>22</number>
    <sentence>p</sentence>
    <justification>Reiteration</justification>
    <antecedent>19</antecedent>
  </step>
  <step>
    <number>23</number>
    <sentence>~q => p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>21</antecedent>
    <antecedent>22</antecedent>
  </step>
  <step>
    <number>24</number>
    <sentence>~q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>25</number>
    <sentence>~p</sentence>
    <justification>Reiteration</justification>
    <antecedent>20</antecedent>
  </step>
  <step>
    <number>26</number>
    <sentence>~q => ~p</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>24</antecedent>
    <antecedent>25</antecedent>
  </step>
  <step>
    <number>27</number>
    <sentence>~~q</sentence>
    <justification>Negation Introduction</justification>
    <antecedent>23</antecedent>
    <antecedent>26</antecedent>
  </step>
  <step>
    <number>28</number>
    <sentence>q</sentence>
    <justification>Negation Elimination</justification>
    <antecedent>27</antecedent>
  </step>
  <step>
    <number>29</number>
    <sentence>~p => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>20</antecedent>
    <antecedent>28</antecedent>
  </step>
  <step>
    <number>30</number>
    <sentence>q</sentence>
    <justification>Assumption</justification>
  </step>
  <step>
    <number>31</number>
    <sentence>q => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>30</antecedent>
    <antecedent>30</antecedent>
  </step>
  <step>
    <number>32</number>
    <sentence>q</sentence>
    <justification>Or Elimination</justification>
    <antecedent>18</antecedent>
    <antecedent>29</antecedent>
    <antecedent>31</antecedent>
  </step>
  <step>
    <number>33</number>
    <sentence>p => q</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>19</antecedent>
    <antecedent>32</antecedent>
  </step>
  <step>
    <number>34</number>
    <sentence>~p | q => (p => q)</sentence>
    <justification>Implication Introduction</justification>
    <antecedent>18</antecedent>
    <antecedent>33</antecedent>
  </step>
  <step>
    <number>35</number>
    <sentence>p => q <=> ~p | q</sentence>
    <justification>Biconditional Introduction</justification>
    <antecedent>17</antecedent>
    <antecedent>34</antecedent>
  </step>
</proof>
`
