Problem Understanding

We are given a sentence text and a set of brokenLetters. A word can be typed only if none of its characters belong to the brokenLetters set. The task is to count how many words can be typed.

Approach

Bitmask for broken letters
Convert brokenLetters into a bitmask, where each bit represents whether a character is broken (1 means broken).
Example: "ad" → mask with a and d set.

Traverse the sentence
For each character in text:
If it belongs to broken letters → mark current word as broken.
On encountering a space (' ') or end of string:
If the word was not broken → increment the count.
Reset flag for next word.
Return the count at the end.

Pseudocode
function canBeTypedWords(text, brokenLetters):
    mask = 0
    for ch in brokenLetters:
        mask = mask OR (1 << (ch - 'a'))

    count = 0
    wordHasBroken = false

    for i = 0 to text.length:
        if i < text.length AND isLetter(text[i]) AND (mask & (1 << (text[i] - 'a'))) != 0:
            wordHasBroken = true

        if i == text.length OR text[i] == ' ':
            if wordHasBroken == false:
                count++
            wordHasBroken = false

    return count

Time Complexity (TC)

Building mask → O(m) where m = brokenLetters.length.
Traversing text → O(n) where n = text.length.
Total → O(n + m).
Space Complexity (SC)
Bitmask uses only O(1) space.