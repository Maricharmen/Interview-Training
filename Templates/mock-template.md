# Technical Interview Framework

## 1. Understand

Before solving:

* Restate the problem in my own words.
* Confirm inputs and expected output.
* Ask about constraints.
* Clarify edge cases and assumptions.

### Questions I can ask

* Can the input be empty?
* Are there duplicate values?
* Is the input sorted?
* What is the expected input size?
* Should I optimize for time or memory?
* Can I modify the input?

---

## 2. Explore

Explain my thinking before coding.

### Brute force

* What is the simplest correct solution?
* What is its time and space complexity?
* What makes it inefficient?

### Better approach

* Which pattern or data structure could help?
* Can I avoid repeated work?
* Can I reduce time by using additional memory?
* Are there multiple possible solutions?

### Communication

I should explain:

* My approach.
* Why it works.
* The main trade-offs.
* Why I selected this solution.

---

## 3. Design

Before implementation, clearly describe:

* The algorithm step by step.
* The data structures I will use.
* Important variables.
* Time complexity.
* Space complexity.

### Confirmation

> My proposed solution is to ____.
> It works because ____.
> The time complexity is ____ and the space complexity is ____.
> Does this approach sound reasonable before I implement it?

---

## 4. Implement

While coding:

* Continue communicating.
* Explain important decisions.
* Use clear variable and function names.
* Keep the solution simple.
* Avoid repeated or unnecessary code.
* Use small abstractions when helpful.

I do not need to narrate every character, but I should avoid long periods of silence.

### Useful phrases

* I am creating this variable to track...
* This condition handles...
* Here I update...
* I am separating this logic because...
* One important detail is...

---

## 5. Test

Test systematically instead of saying, “It looks correct.”

### Test order

1. Typical case.
2. Smallest valid input.
3. Empty input, when allowed.
4. Duplicate values.
5. Boundary values.
6. Cases that could break the algorithm.

### Manual walkthrough

For each step:

* What line is executing?
* What are the current variable values?
* How does the data structure change?
* Is the result still correct?

If I find a bug:

1. Explain the issue.
2. Correct it.
3. Repeat the affected test.

---

## 6. Conclude

At the end:

* Summarize the solution.
* Confirm time complexity.
* Confirm space complexity.
* Mention an alternative or trade-off.
* Discuss possible extensions if time remains.

> The final solution uses ____ to ____.
> Its time complexity is ____ and its space complexity is ____.
> An alternative would be ____, but the trade-off is ____.

---

# Communication Checklist

* [ ] I asked relevant clarifying questions.
* [ ] I explained my approach before coding.
* [ ] I communicated my rationale and trade-offs.
* [ ] I continued speaking while coding.
* [ ] My explanation was organized and concise.
* [ ] The interviewer could follow my thought process without repeatedly asking for clarification.

---

# Problem-Solving Checklist

* [ ] I understood the problem and constraints.
* [ ] I approached it systematically.
* [ ] I explained a brute-force solution.
* [ ] I identified the bottleneck.
* [ ] I developed an optimized solution.
* [ ] I calculated time complexity correctly.
* [ ] I calculated space complexity correctly.
* [ ] I considered multiple approaches when appropriate.
* [ ] I explained why my selected approach was best.
* [ ] I solved it without major hints.

---

# Technical Competency Checklist

* [ ] My code matches the approach I explained.
* [ ] The solution works with minimal or no bugs.
* [ ] The implementation is straightforward.
* [ ] I avoided unnecessary or repeated code.
* [ ] Variable and function names are clear.
* [ ] Formatting and indentation are consistent.
* [ ] I used the language correctly.
* [ ] I selected appropriate abstractions and data structures.

---

# Testing Checklist

* [ ] I tested a typical case.
* [ ] I tested relevant edge cases.
* [ ] I walked through the code step by step.
* [ ] I tracked variable and data-structure changes.
* [ ] I identified bugs independently.
* [ ] I corrected bugs and tested again.
* [ ] I explained why the solution is correct.

---

# Mock Interview Scorecard

Use a score from 1 to 4:

* **4 — Strong Hire**
* **3 — Leaning Hire**
* **2 — Leaning No Hire**
* **1 — Strong No Hire**

## Communication: __ / 4

**4 — Strong Hire**
The thought process was thorough, organized, succinct and consistently clear. The interviewer could easily follow the understanding, approach and trade-offs.

**3 — Leaning Hire**
Communication was generally clear and organized, but some follow-up questions were required.

**2 — Leaning No Hire**
Communication was insufficient, disorganized or unclear. The candidate may have started coding without explaining the approach.

**1 — Strong No Hire**
The candidate remained mostly silent or could not communicate the thought process clearly.

## Problem Solving: __ / 4

**4 — Strong Hire**
Completed all basic signals comfortably and had time to compare solutions, discuss trade-offs or explore extensions.

**3 — Leaning Hire**
Completed the core problem correctly but did not reach advanced discussion.

**2 — Leaning No Hire**
Demonstrated only some basic signals or required significant help.

**1 — Strong No Hire**
Could not develop a correct and organized solution.

## Technical Competency: __ / 4

**4 — Strong Hire**
Produced clean, correct code and demonstrated strong language knowledge and good abstractions.

**3 — Leaning Hire**
Produced a working solution with minor difficulty or suboptimal language usage.

**2 — Leaning No Hire**
Struggled to translate the approach into working code and made several mistakes.

**1 — Strong No Hire**
Could not produce a working implementation.

## Testing: __ / 4

**4 — Strong Hire**
Tested typical and edge cases systematically, identified issues and corrected them independently.

**3 — Leaning Hire**
Tested the solution but missed some relevant edge cases.

**2 — Leaning No Hire**
Performed limited testing and struggled to identify or correct bugs.

**1 — Strong No Hire**
Did not meaningfully test the solution.

---

# Final Reflection

**Total score:** __ / 16

## **What I did well:**

## **Main weakness:**

## **One improvement for the next mock:**

**Problem to revisit:**
Yes / No
