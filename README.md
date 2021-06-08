# PDA
In the theory of computation, a branch of theoretical computer science, a pushdown automaton (PDA) is a type of automaton that employs a stack.

Pushdown automata are used in theories about what can be computed by machines. They are more capable than finite-state machines but less capable than Turing machines (see below). Deterministic pushdown automata can recognize all deterministic context-free languages while nondeterministic ones can recognize all context-free languages, with the former often used in parser design.

The term "pushdown" refers to the fact that the stack can be regarded as being "pushed down" like a tray dispenser at a cafeteria, since the operations never work on elements other than the top element. A stack automaton, by contrast, does allow access to and operations on deeper elements. Stack automata can recognize a strictly larger set of languages than pushdown automata.[1] A nested stack automaton allows full access, and also allows stacked values to be entire sub-stacks rather than just single finite symbols.
(Text from https://en.wikipedia.org/wiki/Pushdown_automaton)

This project, originally created December 2020 by Annika Fagerstrom (me) and Becca Lees to implement a Push Down Automnata that accepts a context-free language string and processes it. It was implemented in C++ by creating a class that can take a language string and has built in methods to process it. 
