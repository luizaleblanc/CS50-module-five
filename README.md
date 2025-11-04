<h1>CS50 Problem Set 5 Solutions</h1>
p>This file contains the corrected and completed solutions for Problem Set 5 (Pset5) from Harvard's CS50 course: Introduction to Computer Science.</p>

<div class="warning-box">
        <p><strong>&#9888; Important Requirement:</strong></p>
        <p>These files (<code>inheritance.c</code> and <code>dictionary.c</code>) contain <strong>only the solution implementations</strong>. They are not standalone programs.</p>
        <p>To compile and run this code, you <strong>must</strong> use the specific development environment, dependencies, and helper libraries provided by the CS50 course (such as the CS50 Library and the original Makefiles).</p>
    </div>

<h2>About the Solutions</h2>

<h3>1. Pset5: Inheritance</h3>
    <ul>
        <li><strong>File:</strong> <code>inheritance.c</code></li>
        <li><strong>Description:</strong> This program simulates the genetic inheritance of blood types over several generations. The solution demonstrates the use of recursion and dynamic memory allocation (<code>malloc</code> and <code>free</code>) to build and destroy a family tree structure.</li>
        <li><strong>Key functions implemented:</strong> <code>create_family</code> and <code>free_family</code>.</li>
    </ul>

<h3>2. Pset5: Speller</h3>
    <ul>
        <li><strong>File:</strong> <code>dictionary.c</code></li>
        <li><strong>Description:</strong> This program is a high-performance spell-checker. The solution implements a hash table from scratch to load a large dictionary into memory and efficiently check the spelling of words from a given text file.</li>
        <li><strong>Key functions implemented:</strong> <code>load</code>, <code>hash</code>, <code>size</code>, <code>check</code>, and <code>unload</code>.</li>
    </ul>

<h2>How to Compile and Run</h2>
    <p>This code will not compile on its own. It must be compiled with the distribution code provided by CS50.</p>
    <ol>
        <li>Download the original Pset5 distribution files (<code>speller.zip</code>, <code>inheritance.zip</code>) from the CS50 course website.</li>
        <li>Place the corrected solution file (e.g., <code>dictionary.c</code>) into its corresponding problem folder, replacing the empty skeleton file.</li>
        <li>Open a terminal in the CS50 IDE or an environment where the CS50 Library is installed.</li>
        <li>Navigate to the problem directory (e.g., <code>cd speller</code>).</li>
        <li>Compile the program using the provided <code>Makefile</code>: <code>make inheritance</code> or <code>make speller</code>.</li>
        <li>Run the program as specified in the problem set (e.g., <code>./speller texts/lalaland.txt</code>).</li>
    </ol>

</body>
</html>
```
