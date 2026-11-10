Mock: 
So, to make sure I'm understanding, is it true that for each 
chain, every step in the chain removes one letter and that 
every item in the chain needs to be contained in the original 
list of valid words.

Can there ever be an empty string in the list?
You can assume that every string in the list will have a length of one

What happens of we receive an empty list? Should we return an empty string
or maybe an error status?
We can assusme the return value will always be a string. So in this case, let's
just return an empty string. 

Now, for the case where none of the words in the valid word list can have 
a letter removed and remain valid, should we also return an empty string?
For example, if I was given a list with the words cat and dog.
Yes, let's return an empty string in this case too

Those are all the clarifying questions I had for now

Let me think about what a solution would look like

One thing that immediately jumps out to me is that I'm going to be doing
a lot of lookups in the list of valid words which will be expensive if
I constantly have to iterate over the list to find a word. Since this would 
be an O(X) lookup with X being the number of words in the valid list.

I could optimeze this by creating a set containing the data which would 
given me an O(1) lookup. But this would cause me to create a copy of the input
data.

Should I be optimizing for space or time complexity?
For now, let's focus on optimizing time complexity? 

So, I plan on using a set to keep track of the valid words. Now, let
me think about how to compute the chains. 

Looking at the example, it seems like it could be a good fit for a 
recursive solution. Since there's a common pattern of removing a letter
and checking the validity of the new word, all building towards a base
case of a single letter, let me try walking through a high approach
that I could do for computing the chain lenght of a single word.

First, I would want to check if the word is valid. If it's not, I can 
return something like negative one to indicate this. 
If the word is valid, I would want to see which letter I have to remove
to produce the maximum subchain length.
I can do this by iterating over each letter, removing it, calling the
same function recursively on the result to see what the subchain length
is for that case.

I'll keep track of the longest subchain length I see and use the best one 
when computing the maximum chain for my original word.
Since this operates on a single word. I can call this something like
compute max chain length. Then I can call this function on every word
in the input list and see which one gives me the largest result.

What happens of we get to a single letter that's valid?
I need to make sure that base case added in compute max chain length
because we don't want to make more recursive calls at that point.

If the length is one and it's in the set, we know we've reached the end
if the chain. So, we can just return one. 

Let me check how I'm doing on time complexity for this proposed solution.
Let's say we're given X words as input with the longest word having 
Y letters

We would need to iterate over all X words. And for every word, we would
want to examine all Y letters and make a recursive call to compute 
max chain length. In this recursive call, we would either choose not 
to proceed and just return negative one because the resulting word 
isn't in the set or we'll continue to make recursive calls if it is.

To compute the max chain length for a single word:
- If the word is not valid, return -1
- Iterate over every letter and try removing it
    - Compute the maximum sub-chain length for each letter removal and
    track the longest one we've seen
- Return 1 + maximum sub-chain length

The maximum number of recursive calls, which is Y corresponding to 
the length of the word, would happen if we can get all the way down to 
a single valid letter. This give us O(X*Y^2) in the word case.


compute_max_chain_length(word):
- If the word is not valid, return -1
- If the word is valid and has a length of 1, return 1
- Iterate over evert letter and try removing it
    - Compute the maximum sub-chain length for each letter removal
    and track the longest one we've seen
- Return 1 + maximum sub-chain length

For every word in the input list: 
- Call compute_max_chain_length
- Return the word that produces the largest result

Now, that I have a general approach, I'm going to take a second to
see of there's any other optimizations I can make

So, there is quite a bit of duplicate work that would happen because 
we're not caching the results. So, going back to the original example 
you provided, we do all this computation when we see restated to
check the length of its chain. But when we get to restarted and 
remove a letter to get restated, we do the same computation again.
Instead, we should remember what we computed for restated. 

compute_max_chain_length(word):
- If the word is not valid, return -1
- If the word is valid and has a length of 1, return 1
- If the word is in the cache, return the cached result
- Iterate over evert letter and try removing it
    - Compute the maximum sub-chain length for each letter removal
    and track the longest one we've seen
- Add (1 + maximum sub-chain length) to the cache for this word
- Return (1 + maximum sub-chain length)

For every word in the input list: 
- Call compute_max_chain_length
- Return the word that produces the largest result

A hash map seems like it would be a good fit for this, It would
allow us to perform a lookup in constant time to see if we have a result
for a word already computed before making all the recursive calls.
If we already have a result computed, we can just return that.